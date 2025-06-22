===============================
  Máquina de Pilha - Interpretador C
===============================
Segunda etapa do projeto
Alunos:
CARLOS EDUARDO PEREIRA DE SOUSA
CHRISTIANO DE SOUSA BRANDAO
ELIZABETH SANTOS PENHA
MARIANA BOGEA LIMA
SAMUEL DE MORAES OLIVEIRA
Descrição:
Este projeto é um interpretador de comandos baseado em pilha,
feito em linguagem C, que suporta operações aritméticas básicas
e uso de variáveis.

-------------------------------
Como Compilar:

1) Abra o terminal ou prompt de comando.
2) Navegue até a pasta do projeto (onde estão os arquivos .c e .h).
3) Execute o comando:

   gcc main.c stack.c list.c interpret.c -o interprete-de-pilha -Wall -Wextra -std=c99

-------------------------------
Como Executar:

No terminal, rode o programa compilado:

- Linux/macOS:
   ./interprete-de-pilha

- Windows (Prompt ou PowerShell):
   .\interprete-de-pilha.exe

-------------------------------
Uso:

- Digite os comandos do interpretador, exemplo:

   push 42
   push 5
   add
   push 8
   sub
   pop a
   push a
   print
   exit

- Para sair do programa, digite:
   exit

-------------------------------
Estrutura do Projeto:

main.c
interpret.c
interpret.h
stack.c
stack.h
list.c
list.h
README.md
-------------------------------
descrição da nova funcionalidade:
Ampliar a funcionalidade do interpretador da máquina virtual baseado em pilha, implementando uma memória de variáveis usando uma lista encadeada. Esta etapa introduz o uso de variáveis nomeadas e operações entre elas.
