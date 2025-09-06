#include <stdio.h>
#include <stdlib.h>
#include "lista-dupla.h"

int main() {
    ListaDupla* lista = criarListaDupla();

    inserirInicio(lista, 10);
    inserirInicio(lista, 20);
    inserirFim(lista, 30);
    inserirFim(lista, 40);

    printf("Lista da frente: ");
    exibirFrente(lista);

    printf("Lista de tras: ");
    exibirTras(lista);

    printf("Tamanho da lista: %d\n", tamanho(lista));

    printf("Removendo do inicio: %d\n", removerInicio(lista));
    printf("Removendo do fim: %d\n", removerFim(lista));

    printf("Lista apos remoções: ");
    exibirFrente(lista);

    destruirListaDupla(lista);
    return 0;
}
