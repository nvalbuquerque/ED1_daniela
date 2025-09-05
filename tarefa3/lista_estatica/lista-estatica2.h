#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_LIVROS 5000

typedef enum
{
    DISPONIVEL,
    EMPRESTADO
} StatusLivro;

typedef struct
{
    char titulo[101];
    char autor[101];
    int ano;
    char isbn[14];
    StatusLivro status;
    char usuario[101];
    char dataEmprestimo[11]; // na identação correta - DD/MM/AAAA
} Livro;

typedef struct
{
    Livro livros[MAX_LIVROS];
    int total;
} ListaEstatica;

// todas as funções
void inicializarLista(ListaEstatica *lista);
int cadastrarLivro(ListaEstatica *lista, char *titulo, char *autor, int ano, char *isbn);
Livro *consultarLivro(ListaEstatica *lista, char *isbn);
int emprestarLivro(ListaEstatica *lista, char *isbn, char *usuario, char *data);
int devolverLivro(ListaEstatica *lista, char *isbn);
void listarLivros(ListaEstatica *lista);

#endif
