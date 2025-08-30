#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <stdio.h>
#include <stdlib.h>

// Definição do Livro 
typedef enum { DISPONIVEL, EMPRESTADO } Status;

typedef struct {
    char titulo[100];
    char autor[100];
    char isbn[20];
    int ano;
    Status status;
    char nomeUsuario[100];
    char dataEmprestimo[10]; 
} Livro;


// Estrutura do nó 
typedef struct No {
    Livro livro;        // Informação armazenada
    struct No* proximo; // Ponteiro para o próximo nó
} No;


// Estrutura da lista dinâmica 
typedef struct {
    No* inicio;   // Ponteiro para o primeiro nó
    int tamanho;  // Quantidade de elementos
} ListaDinamica;


// Operações
// Inicializar a lista
void inicializarLista(ListaDinamica* lista);
int cadastrarLivro(ListaDinamica *lista, Livro livro);
int buscarLivroPorISBN(ListaDinamica *lista, const char *isbn, Livro *livroEncontrado);
int emprestarLivro(ListaDinamica *lista, const char *isbn, const char *usuario, const char *data);
int devolverLivro(ListaDinamica *lista, const char *isbn);
void listarLivros(ListaDinamica *lista);

#endif