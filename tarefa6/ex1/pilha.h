#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define MAX 100

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p);
bool pilhaVazia(Pilha *p);
bool pilhaCheia(Pilha *p);
void empilhar(Pilha *p, char c);
char desempilhar(Pilha *p);

#endif
