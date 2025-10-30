#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 8

#define LARANJA "\x1b[48;5;214m"
#define PRETO "\x1b[48;5;0m"
#define RESET "\x1b[0m"

char tabuleiro[TAMANHO][TAMANHO] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                    {' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
                                    {' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '},
                                    {' ', 'N', ' ', ' ', ' ', ' ', ' ', ' '},
                                    {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

void imprimir_tabuleiro(char destaque[TAMANHO][TAMANHO]) {
  printf("\n    ");
  for (int c = 0; c < TAMANHO; c++)
    printf(" %c ", 'a' + c);
  printf("\n");

  for (int l = 0; l < TAMANHO; l++) {
    printf(" %d ", 8 - l);
    for (int c = 0; c < TAMANHO; c++) {
      bool eh_destaque = (destaque[l][c] == '*');
      bool eh_claro = ((l + c) % 2 == 0);

      if (eh_destaque) {
        printf(LARANJA " * " RESET);
      } else {
        char peca = tabuleiro[l][c];
        if (eh_claro) {
          printf(LARANJA " %c " RESET, peca == ' ' ? ' ' : peca);
        } else {
          printf(PRETO " %c " RESET, peca == ' ' ? ' ' : peca);
        }
      }
    }
    printf(" %d\n", 8 - l);
  }

  printf("    ");
  for (int c = 0; c < TAMANHO; c++)
    printf(" %c ", 'a' + c);
  printf("\n\n");
}

void movimentos_torre(int l, int c, bool movs[TAMANHO][TAMANHO]) {
  int direcoes[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  for (int d = 0; d < 4; d++) {
    int dl = direcoes[d][0], dc = direcoes[d][1];
    for (int passo = 1; passo < TAMANHO; passo++) {
      int nl = l + dl * passo;
      int nc = c + dc * passo;
      if (nl < 0 || nl >= TAMANHO || nc < 0 || nc >= TAMANHO)
        break;
      movs[nl][nc] = true;
      if (tabuleiro[nl][nc] != ' ')
        break;
    }
  }
}

void movimentos_bispo(int l, int c, bool movs[TAMANHO][TAMANHO]) {
  int direcoes[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
  for (int d = 0; d < 4; d++) {
    int nl = l + direcoes[d][0];
    int nc = c + direcoes[d][1];
    while (nl >= 0 && nl < TAMANHO && nc >= 0 && nc < TAMANHO) {
      movs[nl][nc] = true;
      if (tabuleiro[nl][nc] != ' ')
        break;
      nl += direcoes[d][0];
      nc += direcoes[d][1];
    }
  }
}

void movimentos_rainha(int l, int c, bool movs[TAMANHO][TAMANHO]) {
  movimentos_torre(l, c, movs);
  movimentos_bispo(l, c, movs);
}

void movimentos_cavalo(int l, int c, bool movs[TAMANHO][TAMANHO]) {
  for (int dl = -2; dl <= 2; dl++) {
    for (int dc = -2; dc <= 2; dc++) {
      if ((abs(dl) == 2 && abs(dc) == 1) || (abs(dl) == 1 && abs(dc) == 2)) {
        int nl = l + dl;
        int nc = c + dc;
        if (nl >= 0 && nl < TAMANHO && nc >= 0 && nc < TAMANHO) {
          movs[nl][nc] = true;
        }
      }
    }
  }
}

bool caminho_livre(int l1, int c1, int l2, int c2, char peca) {
  if (peca == 'N')
    return true;

  if (peca == 'R') {
    if (l1 != l2 && c1 != c2)
      return false;
    int step_l = (l2 > l1) ? 1 : (l2 < l1 ? -1 : 0);
    int step_c = (c2 > c1) ? 1 : (c2 < c1 ? -1 : 0);
    int l = l1 + step_l, c = c1 + step_c;
    while (l != l2 || c != c2) {
      if (tabuleiro[l][c] != ' ')
        return false;
      l += step_l;
      c += step_c;
    }
    return true;
  }

  if (peca == 'B') {
    if (abs(l1 - l2) != abs(c1 - c2))
      return false;
    int step_l = (l2 > l1) ? 1 : -1;
    int step_c = (c2 > c1) ? 1 : -1;
    int l = l1 + step_l, c = c1 + step_c;
    while (l != l2 || c != c2) {
      if (tabuleiro[l][c] != ' ')
        return false;
      l += step_l;
      c += step_c;
    }
    return true;
  }

  if (peca == 'Q') {
    return caminho_livre(l1, c1, l2, c2, 'R') ||
           caminho_livre(l1, c1, l2, c2, 'B');
  }

  return false;
}

bool movimento_valido(int l1, int c1, int l2, int c2) {
  char peca = tabuleiro[l1][c1];
  if (peca == ' ')
    return false;
  if (l2 < 0 || l2 >= TAMANHO || c2 < 0 || c2 >= TAMANHO)
    return false;

  if (tabuleiro[l2][c2] != ' ')
    return false;

  if (peca == 'R')
    return (l1 == l2 || c1 == c2) && caminho_livre(l1, c1, l2, c2, 'R');
  if (peca == 'B')
    return (abs(l1 - l2) == abs(c1 - c2)) && caminho_livre(l1, c1, l2, c2, 'B');
  if (peca == 'Q')
    return ((l1 == l2 || c1 == c2 || abs(l1 - l2) == abs(c1 - c2))) &&
           caminho_livre(l1, c1, l2, c2, 'Q');
  if (peca == 'N') {
    int dl = abs(l1 - l2), dc = abs(c1 - c2);
    return (dl == 2 && dc == 1) || (dl == 1 && dc == 2);
  }
  return false;
}

void destacar_validos(int l, int c, char destaque[TAMANHO][TAMANHO]) {
  bool movs[TAMANHO][TAMANHO] = {false};

  if (tabuleiro[l][c] == 'R')
    movimentos_torre(l, c, movs);
  else if (tabuleiro[l][c] == 'B')
    movimentos_bispo(l, c, movs);
  else if (tabuleiro[l][c] == 'Q')
    movimentos_rainha(l, c, movs);
  else if (tabuleiro[l][c] == 'N')
    movimentos_cavalo(l, c, movs);

  for (int i = 0; i < TAMANHO; i++) {
    for (int j = 0; j < TAMANHO; j++) {
      if (movs[i][j] && movimento_valido(l, c, i, j)) {
        destaque[i][j] = '*';
      }
    }
  }
}

bool parse_jogada(char *entrada, int *linha, int *coluna) {
  if (strlen(entrada) < 2)
    return false;
  char col = entrada[0];
  char lin = entrada[1];

  if (col >= 'a' && col <= 'h' && lin >= '1' && lin <= '8') {
    *coluna = col - 'a';
    *linha = 8 - (lin - '0');
    return true;
  }
  return false;
}

int main() {
  char destaque[TAMANHO][TAMANHO] = {{0}};
  char entrada[10];

  printf("=== Xadrez Naruto (Terminal) ===\n");
  printf("Peças: R=Torre, B=Bispo, Q=Rainha, N=Cavalo\n");
  printf("Digite a posição da peça (ex: a2) para ver movimentos válidos.\n");
  printf("Digite 'sair' para encerrar.\n\n");

  while (1) {
    for (int i = 0; i < TAMANHO; i++)
      for (int j = 0; j < TAMANHO; j++)
        destaque[i][j] = 0;

    imprimir_tabuleiro(destaque);

    printf("Selecione uma peça (ex: a2) ou digite 'sair': ");
    if (scanf("%9s", entrada) != 1)
      break;

    if (strcmp(entrada, "sair") == 0)
      break;

    int l, c;
    if (parse_jogada(entrada, &l, &c)) {
      if (tabuleiro[l][c] != ' ') {
        destacar_validos(l, c, destaque);
        printf("\nMovimentos válidos para %c em %c%d:\n", tabuleiro[l][c],
               'a' + c, 8 - l);
        imprimir_tabuleiro(destaque);
        printf("Pressione Enter para continuar...");
        while (getchar() != '\n')
          ;
        getchar();
      } else {
        printf("Nenhuma peça nesta posição!\n");
      }
    } else {
      printf("Entrada inválida! Use formato como 'e4'.\n");
    }
  }

  printf("Obrigado por jogar! Dattebayo! 🍥\n")
  return 0;
}
