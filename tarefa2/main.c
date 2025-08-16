#include <stdio.h>
#include "lista_estatica.h"

int main(void) {
    Playlist playlist;

   criarPlaylist(&playlist); // Inicia lista 
   
   int opcao, id, posicao;

   //MENU PRINCIPAL
   do {
        printf("\n=== MINHA PLAYLIST ===\n");
        printf("1. Adicionar musica\n");
        printf("2. Remover musica\n");
        printf("3. Buscar musica\n");
        printf("4. Mostrar playlist\n");
        printf("5. Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: //adiciona musia
            printf("Digite o ID da musica: ");
            scanf("%d", &id);
                 if (adicionarMusica(&playlist, id))
                    printf("Musica %d adicionada\n", id);
                else
                    printf("A playlist esta cheia\n");
                break;
            break;
        
        case 2: //remove musica  
            printf("Digite a posicao para remover: ");
            scanf("%d", &posicao);
            if (removerMusica(&playlist, posicao))
                printf("Musica da posicao %d removida\n", posicao);
            else
                printf("Posicao invalida\n");
                break;

        case 3: // Buscar música
            printf("Digite o ID da musica para buscar: ");
            scanf("%d", &id);
            posicao = buscarMusica(&playlist, id);
            if (posicao != -1)
                printf("Musica %d encontrada na posicao %d! (1)\n", id, posicao);
            else
                printf("Musica %d nao encontrada (-1) \n", id);
            break;

        case 4: // Mostra playlist
            printf("=== PLAYLIST ===\n");
            mostrarPlaylist(&playlist);
            printf("Total: %d musica(s)\n", playlist.total);
            break;

        case 5: // Sair
            printf("Saindo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }

   } while (opcao != 5);
   
    return 0;
}