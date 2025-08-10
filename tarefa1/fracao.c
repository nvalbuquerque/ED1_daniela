#include <stdio.h>
#include <stdlib.h>
#include "fracao.h"

fracao_t *criar(int num, int den) {
    if(den == 0) //verifica se o denominador é zero
        return NULL; 

    fracao_t *f = (fracao_t *)malloc(sizeof(fracao_t)); //aloca memória
    if(f == NULL)
        return NULL;
    
    f->num = num;
    f->den = den;

    return f;
}

void imprimir(fracao_t *f) {
    if(f != NULL) {
        printf("%d / %d\n", f->num, f->den);
    }
}

void destruir(fracao_t *f) {
    if(f != NULL) {
        free(f);
        f = NULL;
    }


}

int mdc(int a, int b) {
    if(b == 0) return a;
    else return mdc(b, a % b);
}

int mmc(int a, int b) {
   return a * b / mdc(a, b); 
}

fracao_t *somar(fracao_t *f1, fracao_t *f2) {
    if(f1 == NULL || f2 == NULL)
        return NULL;
    fracao_t *f = (fracao_t *)malloc(sizeof(fracao_t));
    if(f == NULL)
        return NULL;

    f->den = mmc(f1->den, f2->den);
    f->num  = (f->den/ f1->den) * f1->num + (f->den / f2->den) * f2->num;
    
    return f;
}

fracao_t *subtrair(fracao_t *f1, fracao_t *f2) {
    if(f1 == NULL || f2 == NULL)
        return NULL;
    fracao_t *f = (fracao_t *)malloc(sizeof(fracao_t));
    if(f == NULL)
        return NULL;

    f->den = mmc(f1->den, f2->den);
    f->num  = (f->den/ f1->den) * f1->num - (f->den / f2->den) * f2->num;
    
    return f;
}

fracao_t *multiplicacao(fracao_t *f1, fracao_t *f2) {
    if(f1 == NULL || f2 == NULL)
        return NULL;
    fracao_t *f = (fracao_t *)malloc(sizeof(fracao_t));
    if(f == NULL)
        return NULL;

    f->num = f1->num * f2->num;  
    f->den = f1->den * f2->den;
    
    return f;
}

fracao_t *divisao(fracao_t *f1, fracao_t *f2) {
    if(f1 == NULL || f2 == NULL)
        return NULL;
    fracao_t *f = (fracao_t *)malloc(sizeof(fracao_t));
    if(f == NULL)
        return NULL;

    f->num = f1->num * f2->den;  
    f->den = f1->den * f2->num;
    
    return f;
}