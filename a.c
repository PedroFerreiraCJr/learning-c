#include <stdio.h>
#include "lib.h"

int main() {
    incrementar();

    // descomente o seguinte código, desta forma, obtendo um erro em
    // tempo de compilação, ao tentar acessar uma variável que não está definida;
    // é preciso lembrar que a definição da variável deve ser feita no arquivo
    // de implementações da lib;
    //printf(contador);

    return 0;
}
