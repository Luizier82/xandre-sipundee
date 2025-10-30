# Xadrez Ninja - Naruto (Terminal)

## Visão Geral
Jogo de xadrez interativo em C com tema Naruto. O projeto combina a lógica do xadrez tradicional com personagens do anime Naruto, criando uma experiência única de aprendizado de programação.

## Estado Atual
Projeto totalmente funcional com menu interativo e demonstração de movimentos.

**Personagens Implementados:**
- Naruto (Rei)
- Hinata (Rainha)
- Kakashi (Torre)
- Sasuke (Bispo)
- Shikamaru (Cavalo)
- Genin (Peão)

## Alterações Recentes (30 de outubro de 2025)

### Versão 2.0 - Menu Interativo
- Implementado menu principal com 3 opções navegáveis
- Adicionada tela de regras com explicação de cada personagem
- Criada demonstração interativa dos movimentos
- Corrigido bug de navegação no menu (duplo Enter)
- Melhorada experiência do usuário com mensagens claras

### Versão 1.0 - Base do Jogo
- Código C corrigido e funcional
- Implementadas funções de movimento para cada peça
- Validação de caminhos livres/bloqueados
- Tabuleiro visual 8x8
- Sistema de coordenadas (a-h, 1-8)

## Arquitetura do Projeto
```
.
├── main.c          # Código principal do jogo
├── xadrez          # Binário compilado
├── README.md       # Documentação para GitHub
├── replit.md       # Documentação do projeto (este arquivo)
└── .gitignore      # Arquivos ignorados pelo Git
```

## Funcionalidades

### Menu Principal
1. **Começar o Jogo** - Executa demonstração dos movimentos
2. **Ver Regras** - Exibe regras e movimentos de cada personagem
3. **Sair** - Encerra o programa

### Validação de Movimentos
- **Kakashi (Torre)**: Linhas retas usando FOR loops
- **Sasuke (Bispo)**: Diagonais usando WHILE loops
- **Hinata (Rainha)**: Combinação de Torre + Bispo
- **Shikamaru (Cavalo)**: Movimento em "L" com loops aninhados

### Sistema de Detecção
- Verifica se o caminho está livre
- Detecta obstáculos (peças bloqueando)
- Valida limites do tabuleiro
- Shikamaru pode pular peças (característica do cavalo)

## Conceitos de Programação Demonstrados

1. **Arrays Bidimensionais** - Representação do tabuleiro
2. **Estruturas de Controle**
   - FOR loops (movimento linear)
   - WHILE loops (movimento diagonal)
   - DO-WHILE loops (validação de caminho)
3. **Funções Modulares** - Cada peça tem sua própria função
4. **Validação de Entrada** - Menu com fgets() e atoi()
5. **Interface de Usuário** - Menu navegável no terminal

## Como Usar

O workflow está configurado para executar automaticamente:
```bash
gcc main.c -o xadrez -lm && ./xadrez
```

**Interação:**
- Digite `1` para ver a demonstração
- Digite `2` para ver as regras
- Digite `3` para sair

## Dependências
- GCC/Clang (c-clang14)
- Bibliotecas padrão C:
  - stdio.h (entrada/saída)
  - stdlib.h (funções utilitárias)
  - stdbool.h (tipo booleano)
  - string.h (manipulação de strings)

## Testes Implementados
O modo demonstração testa:
1. ✅ Kakashi tentando mover de a8 para a5 (bloqueado por Genin)
2. ✅ Sasuke tentando diagonal de c8 para f5 (bloqueado)
3. ✅ Hinata tentando movimento de d8 para f6 (bloqueado)
4. ✅ Shikamaru pulando de b8 para c6 (SUCESSO - pode pular!)

## Próximas Melhorias Sugeridas

### Curto Prazo
- [ ] Implementar jogadas reais (mover peças no tabuleiro)
- [ ] Sistema de turnos alternados
- [ ] Captura de peças adversárias

### Médio Prazo
- [ ] Validação de xeque e xeque-mate
- [ ] Implementar movimento do Rei (Naruto)
- [ ] Implementar movimento do Peão (Genin)
- [ ] Histórico de movimentos

### Longo Prazo
- [ ] Interface gráfica (SDL ou ncurses)
- [ ] Movimentos especiais (roque, en passant, promoção)
- [ ] IA simples para jogar contra o computador
- [ ] Sistema de ranking e pontuação
- [ ] Multiplayer online

## Notas Técnicas

### Estrutura de Dados
O tabuleiro é representado como array 8x8 de chars:
- Maiúsculas = Vilarejo da Folha (jogador 1)
- Minúsculas = Vilarejo da Areia (jogador 2)
- Espaço ' ' = Casa vazia

### Algoritmos de Validação
Cada peça tem uma função específica que:
1. Valida se o movimento segue o padrão da peça
2. Verifica se o caminho está livre
3. Retorna true/false para movimento válido/inválido

## Compatibilidade
- ✅ Linux/Unix (testado)
- ✅ macOS (deve funcionar)
- ⚠️ Windows (requer compilador MinGW ou similar)

---

**Projeto educacional** criado para demonstrar conceitos de programação C através de um jogo divertido com tema Naruto.
