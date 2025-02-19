#include <stdio.h>
#include <stdlib.h>

/**
*   seção: alocação dinâmica de memória;
*/

struct ponto {
    int x;
    int y;
};

int main() {
    // exemplo: uso da função sizeof;
    // a função 'sizeof' é capaz de retornar o número de bytes que um tipo de dado,
    // ou variável, ocupa na memória;
    {
        printf("Tamanho 'char': %d bytes.\n", sizeof(char));
        printf("Tamanho 'int': %d bytes.\n", sizeof(int));
        printf("Tamanho 'float': %d bytes.\n", sizeof(float));
        printf("Tamanho 'double': %d bytes.\n", sizeof(double));

        int x = 10;
        double y = 20;

        printf("Tamanho da variavel 'x': %d bytes.\n", sizeof x);
        printf("Tamanho da variavel 'y': %d bytes.\n", sizeof y);
    }

    // seção: função malloc;
    // a função malloc() serve para alocar memória durante a execução do programa;
    // a função malloc() possui o seguinte protótipo:
    // void *malloc(unsigned int n);
    // neste caso, o valor de 'n', o parâmetro da função 'malloc', é a quantidade
    // de bytes de memória que devem ser alocados;
    // caso aconteça um erro, a função 'malloc' retorna a constante 'NULL';
    // note que, a função 'malloc' retorna um ponteiro genérico (void*); esse
    // ponteiro pode ser atribuído a qualquer tipo de ponteiro via 'type cast';

    // exemplo: usando a função malloc;
    {
        int *p = NULL;
        // aloca um array com 5 posições do tipo 'int';
        p = (int *) malloc(5 * sizeof(int));

        // verifica se o resultado da operação de alocação dinâmica de memória
        // através da função 'malloc' ocorreu com sucesso; se for NULL, é
        // porque houve um erro na alocação de memória;
        if (p == NULL) {
            printf("Erro na alocacao de memoria\n");
            // termina o programa em caso de erro na alocação dinâmica de memória;
            exit(1);
        }

        for (int i = 0; i < 5; i++) {
            printf("Digite o valor da posicao %d: ", i);
            scanf("%d", &p[i]);
        }
    }

    return 0;
}
