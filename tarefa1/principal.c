#include <stdio.h>
#include "fracao.h"

int main() {
    fracao_t *f1, *f2;
    f1 = criar(1, 2);
    f2 = criar(3, 4);
    fracao_t *f3 = somar(f1, f2);
    fracao_t *f4 = subtrair(f1, f2);
    fracao_t *f5 = multiplicacao(f1, f2);
    fracao_t *f6 = divisao(f1, f2);

    imprimir(f1);
    imprimir(f2);
    imprimir(f3);
    imprimir(f4);
    imprimir(f5);
    imprimir(f6);
    destruir(f1);
    destruir(f2);
    destruir(f3);
    destruir(f4);
    destruir(f5);
    destruir(f6);
    return 0;
}