#include <stdio.h>

/**
* se��o: ponteiros gen�ricos;
*/
int _10main() {
    // normalmente, um ponteiro aponta para um tipo em espec�fico de dado;
    // por�m, pode-ser criar um ponteiro gen�rico;
    // esse tipo de ponteiro pode apontar para qualquer tipo de dado, seja
    // um tido de dado primitivo, ou que seja criado pelo programador;
    // em linguagem C, a declara��o de um ponteiro gen�rico segue esta
    // forma geral: void *nome_do_ponteiro;
    // um ponteiro gen�rico � um ponteiro que pode apontar para qualquer
    // tipo de dado, inclusive para outro ponteiro;
    {
        void *pp;
        int *p1, p2 = 10;

        // 'p1' � um ponteiro para 'int';
        // recebe o endere�o da vari�vel 'p2';
        p1 = &p2;

        // 'pp' � um ponteiro gen�rico;
        // recebe o endere�o da vari�vel 'p2';
        pp = &p2;
        printf("Endereco em pp: %p.\n", pp);

        // 'pp' recebe o endere�o do ponteiro 'p1';
        // recebe o endere�o de um ponteiro para 'int';
        pp = &p1;
        printf("Endereco em pp: %p.\n", pp);

        // recebe o endere�o guardado em 'p1' (endere�o de p2);
        pp = p1;
        printf("Endereco em pp: %p.\n", pp);
    }

    // note que um ponteiro gen�rico permite guardar o endere�o de
    // qualquer tipo de dado; essa vantagem tamb�m carrega uma desvantagem;
    // sempre que tivermos de acessar o conte�do de um ponteiro gen�rico,
    // ser� preciso utilizar o operador de typecast (casting), sobre ele
    // antes de acessar o seu conte�do;

    // sempre que se trabalhar com um ponteiro gen�rico � preciso
    // convert�-lo para o tipo de ponteiro com o qual se deseja trabalhar
    // antes de acessar o seu conte�do;

    {
        void *pp;
        int p2 = 10;

        // recebe o endere�o de 'p2' (uma vari�vel normal);
        pp = &p2;
        // tentar acessar o conte�do do ponteiro gen�rico, gera um erro;
        // essa linha foi comentada porque gera um erro em tempo de compila��o;
        //printf("Conteudo: %d\n", *pp);

        // antes de tentar obter o valor apontado pelo ponteiro gen�rico,
        // � preciso fazer um casting expl�cito no ponteiro gen�rico, para um
        // tipo qualquer; para que ent�o, possa ser feito a tentativa de ler
        // o valor armazenado no endere�o apontado pelo ponteiro gen�rico;
        printf("Conteudo: %d\n", *(int *)pp);
    }

    // somente � poss�vel acessar o seu conte�do depois de uma opera��o
    // de typecast; outro cuidado que devemos ter com ponteiros gen�ricos: como
    // ele n�o possui tipo definido, deve-se tomar cuidado ao realizar
    // opera��es aritm�ticas;

    // as opera��es aritm�ticas n�o funcionam em ponteiros gen�ricos da
    // mesma forma como em ponteiros de tipos definidos. Elas s�o sempre
    // realizadas com base em uma unidade de mem�ria (1 byte);
    {
        void *p = 0x5dc;
        printf("p = hexadecimal: %p, decimal: %d\n", p, p);

        // incrementa 'p' em 1 posi��o;
        p++;

        printf("p = hexadecimal: %p, decimal: %d\n", p, p);

        // incrementa 'p' em 15 posi��es;
        p = p + 15;
        printf("p = hexadecimal: %p, decimal: %d\n", p, p);

        // decrementa 'p' em 1 posi��o;
        p = p - 2;
        printf("p = hexadecimal: %p, decimal: %d\n", p, p);
    }

    // nesse exemplo, como o compilador n�o sabe qual o tipo do ponteiro
    // gen�rico, nas opera��es de adi��o e subtra��o � adicionado/subtra�do
    // um total de 1 byte por incremento/decremento, pois esse � o tamanho
    // de uma unidade de mem�ria; portanto, se o endere�o guardado for, por
    // exemplo, de um inteiro, o incremento de uma posi��o no ponteiro gen�rico
    // (1 byte) n�o levar� ao pr�ximo inteiro (4 bytes);

    return 0;
}
