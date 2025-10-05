#include <stdio.h>
#include "pilha.h"

// Função recursiva da Torre de Hanói
void torreDeHanoi(int n, Pilha *origem, Pilha *destino, Pilha *auxiliar) {
    if (n == 1) {
        int disco = desempilhar(origem);
        empilhar(destino, disco);
        printf("Mover disco %d de %c -> %c\n", disco, origem->nome, destino->nome);
        return;
    }

    // Move n-1 discos da origem para a auxiliar
    torreDeHanoi(n - 1, origem, auxiliar, destino);

    // Move o último disco da origem para o destino
    int disco = desempilhar(origem);
    empilhar(destino, disco);
    printf("Mover disco %d de %c -> %c\n", disco, origem->nome, destino->nome);

    // Move n-1 discos da auxiliar para o destino
    torreDeHanoi(n - 1, auxiliar, destino, origem);
}

int main() {
    Pilha origem, destino, auxiliar;
    int n;

    inicializar(&origem, 'A');
    inicializar(&auxiliar, 'B');
    inicializar(&destino, 'C');

    printf("Digite o numero de discos: ");
    scanf("%d", &n);

    // Preenche a pilha origem (disco maior embaixo)
    for (int i = n; i >= 1; i--) {
        empilhar(&origem, i);
    }

    printf("\n--- Movimentos ---\n");
    torreDeHanoi(n, &origem, &destino, &auxiliar);

    printf("\n--- Resultado final ---\n");
    exibirPilha(&origem);
    exibirPilha(&auxiliar);
    exibirPilha(&destino);

    return 0;
}