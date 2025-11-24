#include <stdio.h>
#include "lib.h"

// essa variável por ter sido declarada com 'static' não é permitido acessá-la em
// nenhum outro arquivo; se essa variável for declarada, mesmo que com o modificador
// 'static', no arquivo de cabeçalho, ela poderá ser acessada diretamente;
static int contador = 0;

void incrementar() {
    contador++;
    printf("contador incrementado!");
}
