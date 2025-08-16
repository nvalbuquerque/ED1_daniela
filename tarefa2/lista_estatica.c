#include "lista_estatica.h"   

// Inicializa a lista Playlist com tamanho 0
void criarPlaylist(Playlist *p) {
    p->total = 0;     // Lista começa vazia
}

// Retorna 1 se a lista não tiver elementos
int estaVazia(Playlist *p) {
    return (p->total == 0);
}

// Retorna 1 se a lista estiver no tamanho máximo
int estaCheia(Playlist *p) {
    return (p->total == MAX);
}

// Insere elemento no final da lista
int adicionarMusica(Playlist *p, int idMusica) {
    if (estaCheia(p)) return 0;     // Falha se cheia
    p->musicas[p->total] = idMusica;   // Insere no final
    p->total++;   // Incrementa tamanho
    return 1;   // Sucesso
}

// Remove música de uma posição específica da playlist
// Retorna 1 se conseguiu remover, 0 se posição inválida
int removerMusica(Playlist *p, int posicao) {
    int i;
    // Validação: lista vazia ou posição inválida
    if (estaVazia(p) || posicao < 0 || posicao >= p->total)
        return 0;
    // Desloca elementos à esquerda para preencher a posição removida
    for (i = posicao; i < p->total - 1; i++) {
        p->musicas[i] = p->musicas[i + 1];
    }
    p->total--;  // Atualiza tamanho da playlist
    return 1;        // Sucesso
}

// Busca musica e retorna posição ou -1 se não encontrado
int buscarMusica(Playlist *p, int idMusica) {
    int i;
    for(i = 0; i < p->total; i++) {
        if (p->musicas[i] == idMusica) return i; // Encontrado
    }
    return -1;  // Não encontrado
}

// Imprime todos os elementos da lista
void mostrarPlaylist(Playlist *p) {
    int i;
    printf("Playlist: [ ");
    for (i = 0; i < p->total; i++) {
        printf("%d ", p->musicas[i]);
    }
    printf("]\n");
}