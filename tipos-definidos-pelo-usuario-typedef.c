#include <stdio.h>

/**
* se��o: typedef
*/
int _5main() {
    // define um sin�nimo para o tipo int;
    // um sin�nimo � uma outra forma de se referir a um determinado
    // tipo de dado; que tamb�m pode ser um tipo definido pelo programador;
    typedef int inteiro;

    {
        // defini��o de um novo tipo definido pelo programador;
        // para definir uma struct, � necess�rio informar a palavra-chave struct;
        struct _cadastro {
            char nome[50];
            int idade;
            char rua[50];
            int numero;
        };

        // para declarar uma vari�vel do tipo cadastro, � preciso prefixar a declara��o
        // com a palavra-chave struct; sem o uso da palavra-chave typedef, sempre � necess�rio
        // colocar a palavra-chave struct para declarar uma vari�vel do tipo da struct;
        struct _cadastro meu_cadastro;

        // para simplificar esta nota��o, � poss�vel usar a palavra-chave typedef, conforme
        // o seguinte exemplo; neste caso, foi feito primeiro a defini��o do tipo definido pelo
        // programador atrav�s da palavra-chave struct, e ap�s isso, foi feita a cria��o de um
        // sin�nimo para o tipo da struct definida; conforme a seguinte instru��o;
        typedef struct _cadastro cadastro;
    }

    {
        // � preciso falar que tamb�m � poss�vel usar a palavra-chave typedef juntamente a
        // defini��o do tipo definido pelo programador; conforme o seguinte c�digo;
        typedef struct _cadastro {
            char nome[50];
            int idade;
            char rua[50];
            int numero;
        } cadastro;

        cadastro meu_cadastro;
    }

    {
        // uma outra maneira de fazer a mesma coisa � omitindo o nome da struct logo na
        // defini��o, e somente informando o nome final dela;
        typedef struct {
            char nome[50];
            int idade;
            char rua[50];
            int numero;
        } cadastro;

        cadastro meu_cadastro;
    }

    return 0;
}
