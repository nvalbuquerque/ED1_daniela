#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

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
} ListaEncadeada;


// Operações
// Inicializar a lista
void inicializarLista(ListaEncadeada* lista);
int cadastrarLivro(ListaEncadeada *lista, Livro livro);
int buscarLivroPorISBN(ListaEncadeada *lista, const char *isbn, Livro *livroEncontrado);
int emprestarLivro(ListaEncadeada *lista, const char *isbn, const char *usuario, const char *data);
int devolverLivro(ListaEncadeada *lista, const char *isbn);
void listarLivros(ListaEncadeada *lista);

#endif