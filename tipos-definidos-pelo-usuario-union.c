#include <stdio.h>
#include <stdlib.h>

/**
* Seção: Union
*/
int _03main() {
    // uma struct reserva um espaço de memória para todos os seus elementos;
    struct cliente {
        char nome[50];
    };

    struct cliente meus_clientes[2];

    // uma union reserva um espaço de memória para o seu maior elemento, e compartilha
    // esse espaço de memória com todos os seus elementos;
    union tipo {
        short int x;        // geralmente, ocupa 2 bytes;
        unsigned char c;    // ocupa, 1 byte;
    };

    // a partir da definição da union chamada 'tipo', é possível afirmar que ela
    // quando instanciada no programa, ocupará um espaço total de 2 bytes, pois o maior
    // elemento que compôe essa union, tem o tamanho de 2 bytes;

    // em uma union, somente um elemento pode ser armazenado por vez; isso faz sentido porque
    // ela compartilha o mesmo espaço de memória entre seus elementos;

    // as instruções abaixo comprovam que os constituintes da union ocupam o mesmo endereço
    // na memória do computador;
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
