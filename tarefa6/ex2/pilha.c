#include <stdio.h>
#include "pilha.h"

void inicializar(Pilha *p, char nome) {
    p->topo = -1;
    p->nome = nome;
}

bool pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

bool pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha *p, int valor) {
    if (!pilhaCheia(p)) {
        p->itens[++p->topo] = valor;
    }
}

int desempilhar(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->itens[p->topo--];
    }
    return -1; // erro
}

void exibirPilha(Pilha *p) {
    printf("Torre %c: ", p->nome);
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}