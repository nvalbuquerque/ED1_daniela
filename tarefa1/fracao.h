typedef struct {
    int num, den;

} fracao_t;

fracao_t *criar(int num, int den);
void imprimir(fracao_t *f);
void destruir(fracao_t *f);
fracao_t *somar(fracao_t *f1, fracao_t *f2);
fracao_t *subtrair(fracao_t *f1, fracao_t *f2);
fracao_t *multiplicacao(fracao_t *f1, fracao_t *f2);

//tarefa:  implementar outras operações (subtracao, multiplicacao, divisao)