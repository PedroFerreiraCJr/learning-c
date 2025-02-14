#include <stdio.h>

/**
* seção: typedef
*/
int _5main() {
    // define um sinônimo para o tipo int;
    // um sinônimo é uma outra forma de se referir a um determinado
    // tipo de dado; que também pode ser um tipo definido pelo programador;
    typedef int inteiro;

    {
        // definição de um novo tipo definido pelo programador;
        // para definir uma struct, é necessário informar a palavra-chave struct;
        struct _cadastro {
            char nome[50];
            int idade;
            char rua[50];
            int numero;
        };

        // para declarar uma variável do tipo cadastro, é preciso prefixar a declaração
        // com a palavra-chave struct; sem o uso da palavra-chave typedef, sempre é necessário
        // colocar a palavra-chave struct para declarar uma variável do tipo da struct;
        struct _cadastro meu_cadastro;

        // para simplificar esta notação, é possível usar a palavra-chave typedef, conforme
        // o seguinte exemplo; neste caso, foi feito primeiro a definição do tipo definido pelo
        // programador através da palavra-chave struct, e após isso, foi feita a criação de um
        // sinônimo para o tipo da struct definida; conforme a seguinte instrução;
        typedef struct _cadastro cadastro;
    }

    {
        // é preciso falar que também é possível usar a palavra-chave typedef juntamente a
        // definição do tipo definido pelo programador; conforme o seguinte código;
        typedef struct _cadastro {
            char nome[50];
            int idade;
            char rua[50];
            int numero;
        } cadastro;

        cadastro meu_cadastro;
    }

    {
        // uma outra maneira de fazer a mesma coisa é omitindo o nome da struct logo na
        // definição, e somente informando o nome final dela;
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
