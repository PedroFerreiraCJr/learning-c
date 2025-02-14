#include <stdio.h>

/**
* seção: ponteiros genéricos;
*/
int _10main() {
    // normalmente, um ponteiro aponta para um tipo em específico de dado;
    // porém, pode-ser criar um ponteiro genérico;
    // esse tipo de ponteiro pode apontar para qualquer tipo de dado, seja
    // um tido de dado primitivo, ou que seja criado pelo programador;
    // em linguagem C, a declaração de um ponteiro genérico segue esta
    // forma geral: void *nome_do_ponteiro;
    // um ponteiro genérico é um ponteiro que pode apontar para qualquer
    // tipo de dado, inclusive para outro ponteiro;
    {
        void *pp;
        int *p1, p2 = 10;

        // 'p1' é um ponteiro para 'int';
        // recebe o endereço da variável 'p2';
        p1 = &p2;

        // 'pp' é um ponteiro genérico;
        // recebe o endereço da variável 'p2';
        pp = &p2;
        printf("Endereco em pp: %p.\n", pp);

        // 'pp' recebe o endereço do ponteiro 'p1';
        // recebe o endereço de um ponteiro para 'int';
        pp = &p1;
        printf("Endereco em pp: %p.\n", pp);

        // recebe o endereço guardado em 'p1' (endereço de p2);
        pp = p1;
        printf("Endereco em pp: %p.\n", pp);
    }

    // note que um ponteiro genérico permite guardar o endereço de
    // qualquer tipo de dado; essa vantagem também carrega uma desvantagem;
    // sempre que tivermos de acessar o conteúdo de um ponteiro genérico,
    // será preciso utilizar o operador de typecast (casting), sobre ele
    // antes de acessar o seu conteúdo;

    // sempre que se trabalhar com um ponteiro genérico é preciso
    // convertê-lo para o tipo de ponteiro com o qual se deseja trabalhar
    // antes de acessar o seu conteúdo;

    {
        void *pp;
        int p2 = 10;

        // recebe o endereço de 'p2' (uma variável normal);
        pp = &p2;
        // tentar acessar o conteúdo do ponteiro genérico, gera um erro;
        // essa linha foi comentada porque gera um erro em tempo de compilação;
        //printf("Conteudo: %d\n", *pp);

        // antes de tentar obter o valor apontado pelo ponteiro genérico,
        // é preciso fazer um casting explícito no ponteiro genérico, para um
        // tipo qualquer; para que então, possa ser feito a tentativa de ler
        // o valor armazenado no endereço apontado pelo ponteiro genérico;
        printf("Conteudo: %d\n", *(int *)pp);
    }

    // somente é possível acessar o seu conteúdo depois de uma operação
    // de typecast; outro cuidado que devemos ter com ponteiros genéricos: como
    // ele não possui tipo definido, deve-se tomar cuidado ao realizar
    // operações aritméticas;

    // as operações aritméticas não funcionam em ponteiros genéricos da
    // mesma forma como em ponteiros de tipos definidos. Elas são sempre
    // realizadas com base em uma unidade de memória (1 byte);
    {
        void *p = 0x5dc;
        printf("p = hexadecimal: %p, decimal: %d\n", p, p);

        // incrementa 'p' em 1 posição;
        p++;

        printf("p = hexadecimal: %p, decimal: %d\n", p, p);

        // incrementa 'p' em 15 posições;
        p = p + 15;
        printf("p = hexadecimal: %p, decimal: %d\n", p, p);

        // decrementa 'p' em 1 posição;
        p = p - 2;
        printf("p = hexadecimal: %p, decimal: %d\n", p, p);
    }

    // nesse exemplo, como o compilador não sabe qual o tipo do ponteiro
    // genérico, nas operações de adição e subtração é adicionado/subtraído
    // um total de 1 byte por incremento/decremento, pois esse é o tamanho
    // de uma unidade de memória; portanto, se o endereço guardado for, por
    // exemplo, de um inteiro, o incremento de uma posição no ponteiro genérico
    // (1 byte) não levará ao próximo inteiro (4 bytes);

    return 0;
}
