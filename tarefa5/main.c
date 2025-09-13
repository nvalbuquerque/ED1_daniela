#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

int main() {
    ListaCircular* lista = criarListaCircular();

    printf(">>> insercoes no inicio:\n");
    inserirInicioCircular(lista, 10);
    inserirInicioCircular(lista, 20);
    inserirInicioCircular(lista, 30);
    exibirCircular(lista); 

    printf("\n>>> insercoes no fim:\n");
    inserirFimCircular(lista, 40);
    inserirFimCircular(lista, 50);
    exibirCircular(lista); 

    printf("\n>>> insercao em posicao (indice 2):\n");
    inserirPosicaoCircular(lista, 99, 2);
    exibirCircular(lista); 

    printf("\n>>> busca por valor:\n");
    int valor = 40;
    NoCircular* encontrado = buscarCircular(lista, valor);
    if (encontrado) {
        printf("Valor %d encontrado na lista!\n", valor);
    } else {
        printf("Valor %d NAO encontrado!\n", valor);
    }

    printf("\n>>> busca por posicao:\n");
    int pos = buscarPosicaoCircular(lista, 99);
    if (pos != -1) {
        printf("Valor 99 encontrado na posicao %d!\n", pos);
    } else {
        printf("Valor 99 nao encontrado!\n");
    }

    printf("\n>>> remocao do inicio:\n");
    int removido = removerInicioCircular(lista);
    printf("Removido: %d\n", removido);
    exibirCircular(lista);

    printf("\n>>> remocao do fim:\n");
    removido = removerFimCircular(lista);
    printf("Removido: %d\n", removido);
    exibirCircular(lista);

    printf("\n>>> remocao por posicao (índice 2):\n");
    removido = removerPosicaoCircular(lista, 2);
    printf("Removido: %d\n", removido);
    exibirCircular(lista);

    printf("\n>>> remocao por valor (99):\n");
    removido = removerValorCircular(lista, 99);
    if (removido != -1)
        printf("Removido valor: %d\n", removido);
    else
        printf("Valor 99 nao encontrado para remocao!\n");
    exibirCircular(lista);

    printf("\n>>> Tamanho atual da lista: %d\n", tamanhoCircular(lista));

    printf("\n>>> destruicao lista...\n");
    destruirListaCircular(lista);

    return 0;
}
