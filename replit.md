# Xadrez Naruto - Terminal

## Visão Geral
Aplicação de xadrez em C para terminal com visualização de movimentos válidos de peças. O projeto usa tema visual "Naruto" com cores laranja e preto através de códigos ANSI.

## Estado Atual
Projeto funcional com 4 peças implementadas:
- **R** = Torre (Rook)
- **B** = Bispo (Bishop)
- **Q** = Rainha (Queen)
- **N** = Cavalo (Knight)

## Alterações Recentes (30 de outubro de 2025)
- Corrigido código C original que estava com erros de compilação
- Adicionadas bibliotecas `string.h` (para strlen/strcmp) e `math.h` (para abs)
- Corrigida validação de movimentos para impedir que peças se movam para casas já ocupadas
- Instalado módulo C/Clang14 para compilação
- Configurado workflow para compilar e executar automaticamente
- Criado .gitignore para arquivos binários

## Arquitetura do Projeto
```
.
├── main.c           # Código principal do jogo de xadrez
├── xadrez           # Binário compilado (gerado automaticamente)
└── .gitignore       # Ignora binários e cache
```

## Funcionalidades Implementadas
1. **Tabuleiro 8x8** com coordenadas (a-h, 1-8)
2. **Visualização colorida** usando ANSI (laranja/preto)
3. **Movimentos válidos** com destaque visual (*)
4. **Validação de caminho livre** (peças não pulam umas sobre as outras, exceto cavalo)
5. **Interface interativa** via terminal

### Lógica de Movimentos
- **Torre**: Move em linhas retas (horizontal/vertical) usando FOR loops
- **Bispo**: Move em diagonais usando WHILE loops
- **Rainha**: Combina movimentos de Torre + Bispo
- **Cavalo**: Move em "L" (2+1 casas) usando loops aninhados, pode pular peças

## Como Usar
1. O programa inicia automaticamente através do workflow
2. Digite a posição de uma peça (ex: `a2`, `d5`) para ver seus movimentos válidos
3. Os movimentos válidos são destacados com `*` em laranja
4. Digite `sair` para encerrar

## Comandos
- Compilação manual: `gcc main.c -o xadrez -lm`
- Execução manual: `./xadrez`
- Workflow: Compila e executa automaticamente

## Dependências
- GCC/Clang (c-clang14)
- Biblioteca padrão C: stdio.h, stdlib.h, stdbool.h, string.h, math.h
- Terminal com suporte a cores ANSI

## Próximos Passos Sugeridos
1. Adicionar peões (Pawns) e rei (King)
2. Implementar sistema de turnos (brancas vs pretas)
3. Adicionar captura de peças
4. Implementar verificação de xeque/xeque-mate
5. Adicionar movimentos especiais (roque, en passant, promoção de peão)
