// main.c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"

bool ehPalindromo(char *palavra) {
    Pilha p;
    inicializar(&p);

    int len = strlen(palavra);
    int meio = len / 2;

    // Empilha a primeira metade
    for (int i = 0; i < meio; i++) {
        empilhar(&p, palavra[i]);
    }

    // Se for ímpar, ignora o caractere do meio
    int inicioSegundaMetade = (len % 2 == 0) ? meio : meio + 1;

    // Compara a segunda metade com o que foi empilhado
    for (int i = inicioSegundaMetade; i < len; i++) {
        char c = desempilhar(&p);
        if (c != palavra[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    char palavra[MAX];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    if (ehPalindromo(palavra))
        printf("\"%s\" eh um palindromo!\n", palavra);
    else
        printf("\"%s\" nao eh um palindromo.\n", palavra);

    return 0;
}
