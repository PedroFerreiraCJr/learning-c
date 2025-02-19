#include <stdio.h>
#include <stdlib.h>

/**
*   se��o: aloca��o din�mica de mem�ria;
*/

struct ponto {
    int x;
    int y;
};

int main() {
    // exemplo: uso da fun��o sizeof;
    // a fun��o 'sizeof' � capaz de retornar o n�mero de bytes que um tipo de dado,
    // ou vari�vel, ocupa na mem�ria;
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

    // se��o: fun��o malloc;
    // a fun��o malloc() serve para alocar mem�ria durante a execu��o do programa;
    // a fun��o malloc() possui o seguinte prot�tipo:
    // void *malloc(unsigned int n);
    // neste caso, o valor de 'n', o par�metro da fun��o 'malloc', � a quantidade
    // de bytes de mem�ria que devem ser alocados;
    // caso aconte�a um erro, a fun��o 'malloc' retorna a constante 'NULL';
    // note que, a fun��o 'malloc' retorna um ponteiro gen�rico (void*); esse
    // ponteiro pode ser atribu�do a qualquer tipo de ponteiro via 'type cast';

    // exemplo: usando a fun��o malloc;
    {
        int *p = NULL;
        // aloca um array com 5 posi��es do tipo 'int';
        p = (int *) malloc(5 * sizeof(int));

        // verifica se o resultado da opera��o de aloca��o din�mica de mem�ria
        // atrav�s da fun��o 'malloc' ocorreu com sucesso; se for NULL, �
        // porque houve um erro na aloca��o de mem�ria;
        if (p == NULL) {
            printf("Erro na alocacao de memoria\n");
            // termina o programa em caso de erro na aloca��o din�mica de mem�ria;
            exit(1);
        }

        for (int i = 0; i < 5; i++) {
            printf("Digite o valor da posicao %d: ", i);
            scanf("%d", &p[i]);
        }
    }

    return 0;
}
