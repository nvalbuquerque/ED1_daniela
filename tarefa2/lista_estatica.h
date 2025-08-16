#include <stdio.h>
#ifndef LISTA_ESTATICA_H   // proteção contra inclusões múltiplas

#define MAX 20   // Define o tamanho máximo da Playlist

// Estrutura de dados para a lista estática
// Contém array fixo 'musica' e inteiro 'total'
typedef struct {
    int musicas[MAX];     // Array para guardar os IDs das músicas
    int total;        // Quantas músicas temos na playlist
} Playlist;

// Protótipos das funções
void criarPlaylist(Playlist *p); // deve deixar a playlist vazia (Total = 0)
int estaVazia(Playlist *p);
int estaCheia(Playlist *p);
int adicionarMusica(Playlist *p, int idMusica); // Retorna 1 se conseguiu adicionar, 0 se a playlist está cheia
int removerMusica(Playlist *p, int posicao); // Remove a música da posição indicada
// Retorna 1 se conseguiu remover, 0 se posição inválida
int buscarMusica(Playlist *p, int idMusica); // Retorna a posição da música ou -1 se não encontrou
void mostrarPlaylist(Playlist *p); // Imprime todas as músicas da playlist




#endif // LISTA_ESTATICA_H
