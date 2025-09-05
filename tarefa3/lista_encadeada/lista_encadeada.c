#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"   


// incializar lista - livros biblioteca
void inicializarLista(ListaEncadeada *lista) {
    lista->inicio = NULL;  // Lista vazia (sem nós)
    lista->tamanho = 0;    // Tamanho inicial zero
}

//cadastrar livro - inserir livro no fim da lista
int cadastrarLivro(ListaEncadeada *lista, Livro livro){
    No *novo, *aux;
	// novo = nó a inserir
	// aux = ponteiro auxiliar para percorrer a lista

    // Aloca memória para o novo nó
    novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 0;  // Falha na alocação de memória
    }

    // Preenche os campos do novo nó
    novo->livro = livro;
    novo->proximo = NULL;
    if (lista->inicio == NULL) { 
        // Lista vazia, o novo nó é o primeiro
        lista->inicio = novo;
    } else {
        // Percorre até o fim e adiciona
        No* aux = lista->inicio;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novo;
    }

    lista->tamanho++;
    printf("Livro '%s' cadastrado com sucesso!\n", livro.titulo);
}

// busca por ISBN - retorna a posição e as infos do livro
int buscarLivroPorISBN(ListaEncadeada *lista, const char *isbn, Livro *livroEncontrado) {
    No *aux = lista->inicio;
    int posicao = 0;

    while (aux != NULL) {
        if (strcmp(aux->livro.isbn, isbn) == 0) {
            if (livroEncontrado != NULL) {
                *livroEncontrado = aux->livro;  // copia os dados do livro
            }
            return posicao;  //isbn encontrado na lista
        aux = aux->proximo;
        posicao++;
    }

    return -1;  //n encontrou
}



}

// emprestar livro pelo isbn
int emprestarLivro(ListaEncadeada *lista, const char *isbn, const char *usuario, const char *data) {
    No *aux = lista->inicio;

    while (aux != NULL) {
        if (strcmp(aux->livro.isbn, isbn) == 0) {  // ISBN encontrado
            if (aux->livro.status == EMPRESTADO) {
                printf("Livro '%s' ja esta emprestado.\n", aux->livro.titulo);
                return 0; // falha, já emprestado
            }

            // Atualiza informações do empréstimo
            aux->livro.status = EMPRESTADO;
            strcpy(aux->livro.nomeUsuario, usuario);
            strcpy(aux->livro.dataEmprestimo, data);

            printf("Livro '%s' emprestado para %s na data %s.\n", aux->livro.titulo, usuario, data);
            return 1; // sucesso
        }
        aux = aux->proximo;
    }

    printf("Livro com ISBN %s nao encontrado.\n", isbn);
    return -1; // livro não encontrado
}

// devolver livro pelo isbn
int devolverLivro(ListaEncadeada *lista, const char *isbn) {
    No *aux = lista->inicio;

    while (aux != NULL) {
        if (strcmp(aux->livro.isbn, isbn) == 0) { // ISBN encontrado
            if (aux->livro.status == DISPONIVEL) {
                printf("Livro '%s' ja está disponivel.\n", aux->livro.titulo);
                return 0; // livro já está disponível 
            }

            // Atualiza informações da devolução
            aux->livro.status = DISPONIVEL;
            aux->livro.nomeUsuario[0] = '\0';      // limpa o nome do usuário
            aux->livro.dataEmprestimo[0] = '\0';   // limpa a data do empréstimo

            printf("Livro '%s' devolvido com sucesso.\n", aux->livro.titulo);
            return 1;
        }
        aux = aux->proximo;
    }

    printf("Livro com ISBN %s nao encontrado.\n", isbn);
    return -1; // livro não encontrado
}

void listarLivros(ListaEncadeada *lista) {
    No *aux = lista->inicio;

    if (aux == NULL) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("\nLista de livros cadastrados:\n");
    while (aux != NULL) {
        printf("Totulo: %s | Autor: %s | ISBN: %s | Ano: %d | Status: %s\n",
            aux->livro.titulo,
            aux->livro.autor,
            aux->livro.isbn,
            aux->livro.ano,
            aux->livro.status == DISPONIVEL ? "Disponivel" : "Emprestado");

        if (aux->livro.status == EMPRESTADO) {
            printf("  Usuario: %s | Data de emprestimo: %s\n",
                aux->livro.nomeUsuario,
                aux->livro.dataEmprestimo);
        }

        aux = aux->proximo;
    }
}
