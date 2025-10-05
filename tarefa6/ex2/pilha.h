#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int itens[MAX];
    int topo;
    char nome; // para identificar a torre 
} Pilha;

void inicializar(Pilha *p, char nome);
bool pilhaVazia(Pilha *p);
bool pilhaCheia(Pilha *p);
void empilhar(Pilha *p, int valor);
int desempilhar(Pilha *p);
void exibirPilha(Pilha *p);

#endif