#include <stdio.h>
#include <stdlib.h>

/**
*   seção: alocação dinâmica de memória;
*/

struct ponto {
    int x;
    int y;
};

int _12main() {
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

    printf("\nexemplo de uso da funcao 'malloc'\n");
    // exemplo: usando a função 'malloc';
    {
        int *p = NULL;

        // aloca um array com 5 posições do tipo 'int';
        p = (int *) malloc(5 * sizeof(int));

        // verifica se o resultado da operação de alocação dinâmica de memória
        // através da função 'malloc' ocorreu com sucesso; se for NULL, é
        // porque houve um erro na alocação de memória;
        if (p == NULL) {
            printf("Erro na alocacao de memoria atraves da funcao 'malloc'\n");
            // termina o programa em caso de erro na alocação dinâmica de memória;
            exit(1);
        }

        for (int i = 0; i < 5; i++) {
            printf("Digite o valor da posicao %d: ", i);
            scanf("%d", &p[i]);
        }
    }

    printf("\nexemplo de uso da funcao 'calloc'\n");
    // exemplo: usando a função 'calloc';
    {
        // declara um ponteiro para o tipo 'int';
        int *p = NULL;

        // verifica se o resultado da operação de alocação dinâmica de memória
        // através da função 'calloc' ocorreu com sucesso; se for NULL, é
        // porque houve um erro na alocação de memória;
        // existe uma diferença entre as funções: malloc, e calloc; a função 'calloc'
        // inicializa os bits do espaço de memória alocado com o valor zeros (0);
        p = (int *) calloc(5, sizeof(int));
        if (p == NULL) {
            printf("Erro na alocacao de memoria atraves da funcao 'calloc'\n");
            // termina o programa em caso de erro na alocação dinâmica de memória;
            exit(2);
        }

        for (int i = 0; i < 5; i++) {
            printf("o valor no endereco[%p] = %d\n", &p[i], p[i]);
        }
    }

    printf("\nexemplo de uso da funcao 'realloc'\n");
    // exemplo: usando a função 'realloc';
    {
        // declara um ponteiro para o tipo 'int';
        int *p = NULL;

        // primeiro, é necessário fazer a alocação de memória com alguma das
        // funções de alocação dinâmica de memória, como por exemplo, 'malloc'
        // ou 'calloc';
        p = (int *) malloc(5 * sizeof(int));
        if (p == NULL) {
            printf("Erro na alocacao de memoria atraves da funcao 'calloc'\n");
            // termina o programa em caso de erro na alocação dinâmica de memória;
            exit(3);
        }

        // atribui um valor inicial para cada posição da memória alocada acima;
        int i;
        for (i = 0; i < 5; i++) {
            p[i] = i + 1;
        }

        // imprime os valores que foram atribuídos no laço for anterior;
        for (i = 0; i < 5; i++) {
            printf("%d\n", p[i]);
        }

        printf("\n");

        // a seguinte instrução, que usa a função 'realloc', diminui o tamanho
        // do espaço de memória alocado anteriormente pela função 'malloc';
        p = (int *) realloc(p, 3 * sizeof(int));

        // imprime os valores que restaram na memória que foi ajustada;
        for (i = 0; i < 3; i++) {
            printf("%d\n", p[i]);
        }

        printf("\n");

        // a seguinte instrução, que usa a função 'realloc', aumenta o tamanho
        // do espaço de memória alocado anteriormente pela função 'malloc';
        p = (int *) realloc(p, 10 * sizeof(int));

        // atribui um valor inicial para cada posição da memória alocada acima;
        for (i = 0; i < 10; i++) {
            p[i] = i + 1;
        }

        // imprime os valores que restaram na memória que foi ajustada;
        for (i = 0; i < 10; i++) {
            printf("%d\n", p[i]);
        }

        // explicação:
        // a função 'realloc' retorna um ponteiro (void *) para o novo bloco
        // alocado; isso é necessário porque a função 'realloc' pode precisar
        // mover o bloco antigo para aumentar seu tamanho; se isso ocorrer, o
        // conteúdo do bloco antigo é copiado para o novo bloco e nenhuma
        // informação é perdida.
    }

    printf("\nsegundo exemplo de uso da funcao 'realloc'\n");
    // exemplo: usando a função 'realloc';
    // se o ponteiro para o bloco de memória previamente alocado por 'NULL'
    // a função 'realloc' alocará memória da mesma forma que a função 'malloc';
    {
        // declara um ponteiro para o tipo 'int';
        int *p = NULL;
        p = (int *) realloc(NULL, 5 * sizeof(int));
        if (p == NULL) {
            printf("Erro na alocacao de memoria atraves da funcao 'realloc'\n");
            // termina o programa em caso de erro na alocação dinâmica de memória;
            exit(4);
        }

        // atribui um valor inicial para cada posição da memória alocada acima;
        int i;
        for (i = 0; i < 5; i++) {
            p[i] = i + 1;
        }

        // imprime os valores que foram atribuídos para a memória que acabou
        // de ser alocada pela função 'realloc';
        for (i = 0; i < 3; i++) {
            printf("%d\n", p[i]);
        }

        // explicação:
        // se não houver memória suficiente para a realocação, um ponteiro
        // nulo é devolvido e o bloco original é deixado inalterado;
    }

    printf("\nterceiro exemplo de uso da funcao 'realloc'\n");
    // exemplo: usando a função 'realloc';
    // se o tamanho de memória solicitado (num) for igual a zero, a memória
    // apontada por *ptr (primeiro argumento) será liberada.
    {
        // declara um ponteiro para o tipo 'int';
        int *p = NULL;

        p = (int *) malloc(5 * sizeof(int));
        if (p == NULL) {
            printf("Erro na alocacao de memoria atraves da funcao 'malloc'\n");
            // termina o programa em caso de erro na alocação dinâmica de memória;
            exit(5);
        }

        // atribui um valor inicial para cada posição da memória alocada acima;
        int i;
        for (i = 0; i < 5; i++) {
            p[i] = i + 1;
        }

        // imprime os valores que foram atribuídos para a memória que acabou
        // de ser alocada pela função 'malloc';
        for (i = 0; i < 5; i++) {
            printf("%d\n", p[i]);
        }

        // libera a memória alocada;
        p = (int *) realloc(p, 0);

        // explicação:
        // nesse exemplo, a função 'realloc' funciona da mesma maneira que
        // a função 'free', que veremos na próxima seção;
    }

    // sempre que alocamos memória de forma dinâmica ('malloc', 'calloc' ou
    // 'realloc'), é necessário liberar essa memória quando ela não for
    // mais necessária;
    // a função 'free' recebe apenas um parâmetro de entrada: o ponteiro para
    // o início do bloco de memória alocado, que deve ser desalocado;

    // para liberar a memória alocada, basta passar para o parâmetro da função
    // 'free', o ponteiro que aponta para o início do bloco de memória alocado;

    // exemplo: usando a função 'free';
    {
        // declara um ponteiro para o tipo 'int';
        int *p = NULL;

        p = (int *) malloc(5 * sizeof(int));
        if (p == NULL) {
            printf("Erro na alocacao de memoria atraves da funcao 'malloc'\n");
            exit(1);
        }

        // atribui um valor inicial para cada posição da memória alocada acima;
        int i;
        for (i = 0; i < 5; i++) {
            p[i] = i + 1;
        }

        // imprime os valores que foram atribuídos para a memória que acabou
        // de ser alocada pela função 'malloc';
        for (i = 0; i < 5; i++) {
            printf("%d\n", p[i]);
        }

        // libera a memória;
        // neste momento está sendo feita a desalocação do bloco de memória alocado
        // dinâmicamente no trecho de código acima;
        free(p);

        // explicação:
        // como o programa sabe quantos bytes devem ser liberados? Quando
        // se aloca a memória, o programa guarda o número de bytes alocados numa
        // “tabela de alocação” interna;

        // cuidado:
        // apenas libere a memória quando tiver certeza de que ela não será mais
        // usada; do contrário, um erro pode acontecer ou o programa poderá não
        // funcionar como esperado;

        // exemplo: usando a função 'free';
        {
            // declara um ponteiro para o tipo 'int';
            int *p = NULL;

            p = (int *) malloc(5 * sizeof(int));
            if (p == NULL) {
                printf("Erro na alocacao de memoria atraves da funcao 'malloc'\n");
                exit(1);
            }

            // atribui um valor inicial para cada posição da memória alocada acima;
            int i;
            for (i = 0; i < 5; i++) {
                p[i] = i + 1;
            }

            // libera a memória alocado anteriormente;
            free(p);

            // tenta imprimir os valores que foram atribuídos para a memória que
            // foi alocada por 'malloc', mas que, já foi liberada;
            for (i = 0; i < 5; i++) {
                printf("%d\n", p[i]);
            }

            // nesse exemplo, nenhum erro ocorre porque a função 'free' apenas
            // libera a memória; o ponteiro 'p', continua com o endereço para onde
            // ela estava reservada; sendo assim, podemos tentar acessá-la; como
            // ela não nos pertence mais (já foi liberada), não há garantias do
            // que possa estar sendo guardado nela;

            // importante:
            // além disso, convém não deixar ponteiros “soltos” (dangling pointers) no
            // programa; portanto, depois de chamar a função 'free', atribua 'NULL' ao
            // ponteiro;

            p = NULL;
        }
    }

    return 0;
}
