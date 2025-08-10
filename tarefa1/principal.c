#include <stdio.h>
#include "fracao.h"

int main() {
    fracao_t *f1, *f2;
    f1 = criar(1, 2);
    f2 = criar(3, 4);
    fracao_t *f3 = somar(f1, f2);
    fracao_t *f4 = subtrair(f1, f2);
    imprimir(f1);
    imprimir(f2);
    imprimir(f3);
    imprimir(f4);
    destruir(f1);
    destruir(f2);
    destruir(f3);
    destruir(f4);
    return 0;
}