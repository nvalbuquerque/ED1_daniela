#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "lista-estatica2.h"

/*int main() {
    ListaEstatica biblioteca;
    inicializarLista(&biblioteca);

    int opcao;
    char isbnBusca[14];
    char usuario[101];
    char data[11];
    Livro livroResultado;
    Livro novoLivro;

    do {
        printf("\n=== Biblioteca ===\n");
        printf("1. Cadastrar livro\n");
        printf("2. Consultar livro por ISBN\n");
        printf("3. Emprestar livro\n");
        printf("4. Devolver livro\n");
        printf("5. Listar todos os livros\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Titulo: ");
                fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
                novoLivro.titulo[strcspn(novoLivro.titulo, "\n")] = '\0';

                printf("Autor: ");
                fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
                novoLivro.autor[strcspn(novoLivro.autor, "\n")] = '\0';

                printf("ISBN: ");
                fgets(novoLivro.isbn, sizeof(novoLivro.isbn), stdin);
                novoLivro.isbn[strcspn(novoLivro.isbn, "\n")] = '\0';

                printf("Ano: ");
                scanf("%d", &novoLivro.ano);
                getchar();

                novoLivro.status = DISPONIVEL;
                novoLivro.usuario[0] = '\0';
                novoLivro.dataEmprestimo[0] = '\0';

                cadastrarLivro(&biblioteca, novoLivro.titulo, novoLivro.autor, novoLivro.ano, novoLivro.isbn);
                break;

            case 2:
                printf("Digite o ISBN do livro: ");
                fgets(isbnBusca, sizeof(isbnBusca), stdin);
                isbnBusca[strcspn(isbnBusca, "\n")] = '\0';

                if (consultarLivro(&biblioteca, isbnBusca) != NULL) {
                    livroResultado = *consultarLivro(&biblioteca, isbnBusca);
                    printf("Titulo: %s\nAutor: %s\nISBN: %s\nAno: %d\nStatus: %s\n",
                           livroResultado.titulo,
                           livroResultado.autor,
                           livroResultado.isbn,
                           livroResultado.ano,
                           livroResultado.status == DISPONIVEL ? "Disponivel" : "Emprestado");
                } else {
                    printf("Livro nao encontrado.\n");
                }
                break;

            case 3:
                printf("Digite o ISBN do livro a emprestar: ");
                fgets(isbnBusca, sizeof(isbnBusca), stdin);
                isbnBusca[strcspn(isbnBusca, "\n")] = '\0';

                printf("Nome do usuario: ");
                fgets(usuario, sizeof(usuario), stdin);
                usuario[strcspn(usuario, "\n")] = '\0';

                printf("Data do emprestimo (dd/mm/aaaa): ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0';

                if (emprestarLivro(&biblioteca, isbnBusca, usuario, data) == 1)
                    printf("Livro emprestado com sucesso!\n");
                else
                    printf("Erro ao emprestar o livro.\n");
                break;

            case 4:
                printf("Digite o ISBN do livro a devolver: ");
                fgets(isbnBusca, sizeof(isbnBusca), stdin);
                isbnBusca[strcspn(isbnBusca, "\n")] = '\0';

                if (devolverLivro(&biblioteca, isbnBusca) == 1)
                    printf("Livro devolvido com sucesso!\n");
                else
                    printf("Erro ao devolver o livro.\n");
                break;

            case 5:
                listarLivros(&biblioteca);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 6);

    printf("\nPressione ENTER para sair...");

    getchar();
    return 0;
} */

int main()
{
    ListaEstatica biblioteca;
    inicializarLista(&biblioteca);

    clock_t inicio, fim;
    double tempo;
    Livro l, resultado;

    int testes[] = {5, 500, 5000}; // diferentes quantidades de livros

    for (int t = 0; t < 3; t++)
    {
        int n = testes[t];
        printf("\n Teste com %d livros \n", n);

        // LIMPA a biblioteca
        inicializarLista(&biblioteca);

        // --- Medir tempo de cadastro ---
        inicio = clock();
        for (int i = 1; i <= n; i++)
        {
            sprintf(l.titulo, "Livro %d", i);
            sprintf(l.autor, "Autor %d", i);
            sprintf(l.isbn, "ISBN%03d", i);
            l.ano = 2000 + i;
            l.status = DISPONIVEL;
            l.usuario[0] = '\0';
            l.dataEmprestimo[0] = '\0';

            cadastrarLivro(&biblioteca, l.titulo, l.autor, l.ano, l.isbn);
        }
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para cadastrar %d livros: %.6f segundos\n", n, tempo);

        // --- Medir tempo de busca do último livro ---
        char isbnBusca[20];
        sprintf(isbnBusca, "ISBN%03d", n);

        inicio = clock();
        Livro *ptr = consultarLivro(&biblioteca, isbnBusca);
        if (ptr != NULL)
        {
            resultado = *ptr; // copia os dados para resultado
            printf("livro:\n");
            printf("titulo: %s\n", resultado.titulo);
            printf("autor: %s\n", resultado.autor);
            printf("ano: %d\n", resultado.ano);
            printf("isbn: %s\n", resultado.isbn);
            printf("status: %s\n", resultado.status == DISPONIVEL ? "Disponivel" : "Emprestado");
        }
        else
        {
            printf("isbn %s não encontrado\n", isbnBusca);
        }
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para buscar o ultimo livro: %.6f segundos\n", tempo);

        // --- Medir tempo de empréstimo do último livro ---
        inicio = clock();
        emprestarLivro(&biblioteca, isbnBusca, "UsuarioTeste", "30/08/2025");
        fim = clock();
        tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("Tempo para emprestar o ultimo livro: %.6f segundos\n", tempo);
    }

    return 0;
} 
