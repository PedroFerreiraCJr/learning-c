#include <stdio.h>
#include <stdlib.h>

/**
* Se��o: Union
*/
int _03main() {
    // uma struct reserva um espa�o de mem�ria para todos os seus elementos;
    struct cliente {
        char nome[50];
    };

    struct cliente meus_clientes[2];

    // uma union reserva um espa�o de mem�ria para o seu maior elemento, e compartilha
    // esse espa�o de mem�ria com todos os seus elementos;
    union tipo {
        short int x;        // geralmente, ocupa 2 bytes;
        unsigned char c;    // ocupa, 1 byte;
    };

    // a partir da defini��o da union chamada 'tipo', � poss�vel afirmar que ela
    // quando instanciada no programa, ocupar� um espa�o total de 2 bytes, pois o maior
    // elemento que comp�e essa union, tem o tamanho de 2 bytes;

    // em uma union, somente um elemento pode ser armazenado por vez; isso faz sentido porque
    // ela compartilha o mesmo espa�o de mem�ria entre seus elementos;

    // as instru��es abaixo comprovam que os constituintes da union ocupam o mesmo endere�o
    // na mem�ria do computador;
    union tipo meu_tipo;
    printf("%p\n", &meu_tipo.x);
    printf("%p\n", &meu_tipo.c);

    union interno {
        short int a;
    };

    union externo {
        union interno inter;
    };

    union externo extern_intern;

    printf("sizeof union interno: %llu\n", sizeof (extern_intern));

    return 0;
}
