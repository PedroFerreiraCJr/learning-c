#include <stdio.h>

/**
* seção: enum
*/
int _4main() {

    {
        enum semana {
            Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado
        };
    }

    {
        enum semana {
            Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado
        } instancia_a, instancia_b;
    }

    {
        enum semana {
            Domingo, Segunda, Terca, Quarta, Quinta, Sexta, Sabado
        };

        enum semana meu_dia = Domingo;
        printf("%d\n", meu_dia);
        printf("%d\n", sizeof(meu_dia));
    }

    {
        enum escapes {
            nova_linha = '\n'
        };
    }

    return 0;
}
