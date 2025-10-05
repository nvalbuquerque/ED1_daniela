# Tarefa 6 - aula 9 pilhas

## Exercício 1: Palíndromo (Nível Básico)
Objetivo: Verificar se uma palavra é um palíndromo usando pilha.

Descrição: Crie uma função que recebe uma string e verifica se ela é um palíndromo (pode ser lida da mesma forma de trás para frente, como "arara", "radar").

Dica: Empilhe metade dos caracteres e compare com a outra metade.



bool ehPalindromo(char *palavra);


## Exercício 2: Torre de Hanói (Nível Intermediário)
Objetivo: Simular o problema clássico da Torre de Hanói usando 3 pilhas.

Descrição: Implemente três pilhas (origem, auxiliar, destino) e mova N discos da torre origem para a torre destino, seguindo as regras: apenas um disco por vez, disco maior nunca sobre disco menor.


void torreDeHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar);