#include <stdio.h>
#include <string.h>
#include "lista-estatica2.h"

// Inicialização da lista
void inicializarLista(ListaEstatica *lista)
{
    lista->total = 0;
}

// Cadastrar livro novo
int cadastrarLivro(ListaEstatica *lista, char *titulo, char *autor, int ano, char *isbn)
{
    if (lista->total >= MAX_LIVROS)
        return 0; // cheio

    Livro *novo = &lista->livros[lista->total];
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->ano = ano;
    strcpy(novo->isbn, isbn);
    novo->status = DISPONIVEL;
    strcpy(novo->usuario, "");
    strcpy(novo->dataEmprestimo, "");

    lista->total++;
    return 1;
}

// Isbn
Livro *consultarLivro(ListaEstatica *lista, char *isbn)
{
    for (int i = 0; i < lista->total; i++)
    {
        if (strcmp(lista->livros[i].isbn, isbn) == 0)
        {
            return &lista->livros[i];
        }
    }
    return NULL;
}

// Emprestar livro
int emprestarLivro(ListaEstatica *lista, char *isbn, char *usuario, char *data)
{
    Livro *livro = consultarLivro(lista, isbn);
    if (livro == NULL)
        return 0; // não achou
    if (livro->status == EMPRESTADO)
        return -1; // já foi emprestado

    livro->status = EMPRESTADO;
    strcpy(livro->usuario, usuario);
    strcpy(livro->dataEmprestimo, data);
    return 1;
}

// Devolver livro
int devolverLivro(ListaEstatica *lista, char *isbn)
{
    Livro *livro = consultarLivro(lista, isbn);
    if (livro == NULL)
        return 0; // não achou
    if (livro->status == DISPONIVEL)
        return -1; // já estava disponível

    livro->status = DISPONIVEL;
    strcpy(livro->usuario, "");
    strcpy(livro->dataEmprestimo, "");
    return 1;
}

// Listar os livros
void listarLivros(ListaEstatica *lista)
{
    printf("\nlista dos livros\n");
    for (int i = 0; i < lista->total; i++)
    {
        Livro l = lista->livros[i];
        printf("[%d] %s - %s (%d)\n", i + 1, l.titulo, l.autor, l.ano);
        printf("isbn: %s  status: %s\n", l.isbn, l.status == DISPONIVEL ? "Disponivel" : "Emprestado");
        if (l.status == EMPRESTADO)
        {
            printf("Usuario: %s Data: %s\n", l.usuario, l.dataEmprestimo);
        }
    }
    printf("========================\n");
}
