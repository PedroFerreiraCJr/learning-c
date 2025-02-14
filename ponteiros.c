#include <stdio.h>
#include <stdlib.h>

/**
* se��o: introdu��o � ponteiros;
*/
int _09main() {
    // essa � uma declara��o de uma vari�vel especial; no caso, esta vari�vel
    // � um ponteiro!; um ponteiro � uma vari�vel especial que tem a capacidade de
    // armazenar, guardar, um endere�o de mem�ria;
    // para informar ao compilador que esta vari�vel � um ponteiro, precisamos
    // utilizar o operador '*' (aster�sco);
    // para declarar um ponteiro � preciso informar para qual tipo de dado, ele
    // ir� armazenar;
    // neste exemplo, estamos declarando uma vari�vel ponteiro, que tem a capacidade
    // de armazenar um endere�o que aponta para o tipo de dado 'int';
    // a nota��o geral para declarar um ponteiro �:
    // tipo_do_ponteiro *identificador;
    int *p;

    // declara um ponteiro para o tipo 'float';
    float *x;

    // declara um ponteiro para o tipo 'char';
    char *y;

    // declara uma vari�vel do tipo 'int' chamada 'resultado'; e tamb�m declara
    // uma vari�vel ponteiro para o tipo 'int';
    int resultado, *p2;

    // quando declaramos um ponteiro, informamos ao compilador para que tipo de
    // vari�vel podemos apont�-lo;
    // um ponteiro do tipo 'int*' s� pode apontar para um vari�vel do tipo int,
    // (ou seja, esse ponteiro s� pode guardar o endere�o de uma vari�vel 'int');
    // outro ponto importante, � que o operador '*' (aster�sco) � sobrecarregado,
    // ou seja, tem mais de um significado dependendo do contexto utilizado;
    // ele � o operador de multiplica��o, quando usado com dois valores, por exemplo,
    // int z = 3 * 5;
    // mas tamb�m pode ser usado em outros locais do c�digo fonte, como por exemplo,
    // na declara��o de uma vari�vel ponteiro, da seguinte forma: int* ptr;

    // inicializa��o e atribui��o de ponteiros:
    // a simples declara��o de um ponteiro n�o o faz �til para o programa, pois �
    // preciso que ele receba um endere�o de mem�ria que possa ser utilizado;
    // ponteiro n�o inicializados apontam para um lugar indefinido;

    // qualquer tentativa de uso desse ponteiro causa um comportamento indefinido
    // no progama;

    // isso ocorre porque seu valor n�o � um endere�o v�lido ou porque sua utiliza��o
    // pode danificar partes diferentes do sistema; por esse motivo, os ponteiros
    // devem ser INICIALIZADOS (apontados para algum lugar conhecido) antes de serem
    // usados;

    // apontando um ponteiro para algum lugar:
    // um ponteiro pode ter um valor especial 'NULL', que � o endere�o de nenhum lugar.
    // conforme o seguinte exemplo;
    int *ptr = NULL;

    // a constante 'NULL' est� definida na biblioteca 'stdlib.h'; trata-se de um
    // valor reservado que indica que aquele ponteiro aponta para uma posi��o de
    // mem�ria inexistente;
    // o valor da constante 'NULL' � 'ZERO' na maioria dos computadores.

    // n�o confunda um ponteiro apontando para 'NULL' com um ponteiro n�o inicializado;
    // o primeiro possui valor fixo, enquanto um ponteiro n�o inicializado pode possuir
    // qualquer valor.

    // apontando um ponteiro para algum lugar da mam�ria:
    // declara uma vari�vel que cont�m o valor '10';
    int count = 10;

    // declara uma vari�vel ponteiro para 'int';
    int *p3;

    // atribui o endere�o da vari�vel 'count', para a vari�vel ponteiro 'p3';
    p3 = &count;

    // tendo um ponteiro armazenado um endere�o de mem�ria, como saber o valor guardado
    // dentro dessa posi��o de mem�ria? Simples: para acessar o conte�do da posi��o de
    // mem�ria para a qual o ponteiro aponta, usa-se o operador asterisco (*) na frente
    // do nome do ponteiro.
    printf("%d\n", *p3);

    // altera o valor armazenado na posi��o de mem�ria apontada pelo ponteiro 'p3';
    *p3 = 100;

    // demonstra que o valor armazenado na posi��o de mem�ria da vari�vel 'count', foi
    // realmente alterado atrav�s do ponteiro 'p3';
    printf("%d\n", count);

    // atribui��o de ponteiros:
    // podemos atribuir para um ponteiro do tipo 'int*', o endere�o de uma vari�vel, por
    // exemplo, do tipo 'float'; mas ao tentar utilizar o ponteiro que recebe a atribui��o
    // temos um comportamento indefinido, devido ao compilador tentar ler uma vari�vel do
    // tipo 'int', mas conter outro endere�o;
    {
        float acumulador = 42.25;
        int *p = &acumulador;

        // essa linha, em determinada execu��o, est� apresentando um valor incorreto;
        printf("%d\n", *p);

        // essa linha, por sua vez, est� apresentando o valor correto da vari�vel
        // 'acumulador';
        printf("%f\n", *((float*)p));
    }

    {
        float *pf = NULL;
        int *pi = NULL;

        float valorDecimal = 14.27;
        pf = &valorDecimal;

        // mesmo sendo ponteiros para tipos de dados diferentes, � poss�vel atribuir um
        // ponteiro para outro ponteiro;
        pi = pf;
    }

    // Um ponteiro pode receber um valor hexadecimal representando um endere�o de
    // mem�ria diretamente. Isso � muito �til quando se trabalha, por exemplo,
    // com microcontroladores.
    {
        int *p = 0x3f8;
        int *p2 = 1500; // o valor decimal � convertido para seu valor hexadecimal;
        printf("Endereco armazenado na variavel ponteiro 'p': %p\n", p);
        printf("Endereco armazenado na variavel ponteiro 'p2': %p\n", p2);
    }

    // aritm�tica de ponteiros:
    // somente podemos realizar as opera�oes de soma e subtra��o de inteiros sobre
    // os endere�os que um ponteiro pode armazenar;
    // as opera��es de adi��o e subtra��o no endere�o dependem do tipo de dado
    // que o ponteiro aponta;

    // opera��es relacionais com ponteiros:
    // a linguagem C permite comparar os endere�os de mem�ria armazenados
    // por dois ponteiros utilizando uma express�o relacional; por exemplo,
    // os operadores == e != s�o usados para saber se dois ponteiros s�o
    // iguais ou diferentes;

    // j� os operadores >, <, >= e <= s�o usados para saber se um ponteiro
    // aponta para uma posi��o mais adiante na mem�ria do que outro;
    // novamente, esse tipo de opera��o � bastante �til quando trabalhamos
    // com arrays, por exemplo; lembre-se: um array nada mais � do
    // que um conjunto de elementos adjacentes na mem�ria;

    return 0;
}
