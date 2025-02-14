#include <stdio.h>
#include <stdlib.h>

/**
* seção: introdução à ponteiros;
*/
int _09main() {
    // essa é uma declaração de uma variável especial; no caso, esta variável
    // é um ponteiro!; um ponteiro é uma variável especial que tem a capacidade de
    // armazenar, guardar, um endereço de memória;
    // para informar ao compilador que esta variável é um ponteiro, precisamos
    // utilizar o operador '*' (asterísco);
    // para declarar um ponteiro é preciso informar para qual tipo de dado, ele
    // irá armazenar;
    // neste exemplo, estamos declarando uma variável ponteiro, que tem a capacidade
    // de armazenar um endereço que aponta para o tipo de dado 'int';
    // a notação geral para declarar um ponteiro é:
    // tipo_do_ponteiro *identificador;
    int *p;

    // declara um ponteiro para o tipo 'float';
    float *x;

    // declara um ponteiro para o tipo 'char';
    char *y;

    // declara uma variável do tipo 'int' chamada 'resultado'; e também declara
    // uma variável ponteiro para o tipo 'int';
    int resultado, *p2;

    // quando declaramos um ponteiro, informamos ao compilador para que tipo de
    // variável podemos apontá-lo;
    // um ponteiro do tipo 'int*' só pode apontar para um variável do tipo int,
    // (ou seja, esse ponteiro só pode guardar o endereço de uma variável 'int');
    // outro ponto importante, é que o operador '*' (asterísco) é sobrecarregado,
    // ou seja, tem mais de um significado dependendo do contexto utilizado;
    // ele é o operador de multiplicação, quando usado com dois valores, por exemplo,
    // int z = 3 * 5;
    // mas também pode ser usado em outros locais do código fonte, como por exemplo,
    // na declaração de uma variável ponteiro, da seguinte forma: int* ptr;

    // inicialização e atribuição de ponteiros:
    // a simples declaração de um ponteiro não o faz útil para o programa, pois é
    // preciso que ele receba um endereço de memória que possa ser utilizado;
    // ponteiro não inicializados apontam para um lugar indefinido;

    // qualquer tentativa de uso desse ponteiro causa um comportamento indefinido
    // no progama;

    // isso ocorre porque seu valor não é um endereço válido ou porque sua utilização
    // pode danificar partes diferentes do sistema; por esse motivo, os ponteiros
    // devem ser INICIALIZADOS (apontados para algum lugar conhecido) antes de serem
    // usados;

    // apontando um ponteiro para algum lugar:
    // um ponteiro pode ter um valor especial 'NULL', que é o endereço de nenhum lugar.
    // conforme o seguinte exemplo;
    int *ptr = NULL;

    // a constante 'NULL' está definida na biblioteca 'stdlib.h'; trata-se de um
    // valor reservado que indica que aquele ponteiro aponta para uma posição de
    // memória inexistente;
    // o valor da constante 'NULL' é 'ZERO' na maioria dos computadores.

    // não confunda um ponteiro apontando para 'NULL' com um ponteiro não inicializado;
    // o primeiro possui valor fixo, enquanto um ponteiro não inicializado pode possuir
    // qualquer valor.

    // apontando um ponteiro para algum lugar da mamória:
    // declara uma variável que contém o valor '10';
    int count = 10;

    // declara uma variável ponteiro para 'int';
    int *p3;

    // atribui o endereço da variável 'count', para a variável ponteiro 'p3';
    p3 = &count;

    // tendo um ponteiro armazenado um endereço de memória, como saber o valor guardado
    // dentro dessa posição de memória? Simples: para acessar o conteúdo da posição de
    // memória para a qual o ponteiro aponta, usa-se o operador asterisco (*) na frente
    // do nome do ponteiro.
    printf("%d\n", *p3);

    // altera o valor armazenado na posição de memória apontada pelo ponteiro 'p3';
    *p3 = 100;

    // demonstra que o valor armazenado na posição de memória da variável 'count', foi
    // realmente alterado através do ponteiro 'p3';
    printf("%d\n", count);

    // atribuição de ponteiros:
    // podemos atribuir para um ponteiro do tipo 'int*', o endereço de uma variável, por
    // exemplo, do tipo 'float'; mas ao tentar utilizar o ponteiro que recebe a atribuição
    // temos um comportamento indefinido, devido ao compilador tentar ler uma variável do
    // tipo 'int', mas conter outro endereço;
    {
        float acumulador = 42.25;
        int *p = &acumulador;

        // essa linha, em determinada execução, está apresentando um valor incorreto;
        printf("%d\n", *p);

        // essa linha, por sua vez, está apresentando o valor correto da variável
        // 'acumulador';
        printf("%f\n", *((float*)p));
    }

    {
        float *pf = NULL;
        int *pi = NULL;

        float valorDecimal = 14.27;
        pf = &valorDecimal;

        // mesmo sendo ponteiros para tipos de dados diferentes, é possível atribuir um
        // ponteiro para outro ponteiro;
        pi = pf;
    }

    // Um ponteiro pode receber um valor hexadecimal representando um endereço de
    // memória diretamente. Isso é muito útil quando se trabalha, por exemplo,
    // com microcontroladores.
    {
        int *p = 0x3f8;
        int *p2 = 1500; // o valor decimal é convertido para seu valor hexadecimal;
        printf("Endereco armazenado na variavel ponteiro 'p': %p\n", p);
        printf("Endereco armazenado na variavel ponteiro 'p2': %p\n", p2);
    }

    // aritmética de ponteiros:
    // somente podemos realizar as operaçoes de soma e subtração de inteiros sobre
    // os endereços que um ponteiro pode armazenar;
    // as operações de adição e subtração no endereço dependem do tipo de dado
    // que o ponteiro aponta;

    // operações relacionais com ponteiros:
    // a linguagem C permite comparar os endereços de memória armazenados
    // por dois ponteiros utilizando uma expressão relacional; por exemplo,
    // os operadores == e != são usados para saber se dois ponteiros são
    // iguais ou diferentes;

    // já os operadores >, <, >= e <= são usados para saber se um ponteiro
    // aponta para uma posição mais adiante na memória do que outro;
    // novamente, esse tipo de operação é bastante útil quando trabalhamos
    // com arrays, por exemplo; lembre-se: um array nada mais é do
    // que um conjunto de elementos adjacentes na memória;

    return 0;
}
