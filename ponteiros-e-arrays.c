#include <stdio.h>

/**
* seção: ponteiros e arrays;
*/
int main() {
    // ponteiros e arrays possuem uma ligação muito forte dentro da linguagem C;
    // arrays são agrupamentos de dados do mesmo tipo na memória;
    // quando declaramos um array, informamos para o computador reserver certa
    // quantidade de memória a fim de armazenar os elementos do array de forma
    // sequencial, ou seja, de maneira adjacente na memória;
    // como resultado desta operação, o computador nos devolve um ponteiro que
    // aponta para o começo dessa sequência de bytes na memória;

    // o nome do array é apenas um ponteiro que aponta para o primeiro elemento
    // do array;

    // na linguagem C, o nome de um array sem índice guarda o endereço para
    // o começo do array na memória, ou seja, ele guarda o endereço do
    // início de uma área de armazenamento dentro da memória;
    // isso significa que as operações envolvendo arrays podem ser feitas
    // utilizando ponteiros e aritmética de ponteiros;

    // exemplo: acessando array utilizando ponteiros;
    {
        int vet[2] = {1, 2};

        // como o nome do array já é um ponteiro, basta atribuí-lo a um ponteiro
        // de tipo correspondente;
        int *p = vet;

        for (int i = 0; i < 2; i++) {
            // a notação de colchetes, aquela utilizada principalmente com arrays
            // também pode ser utilizada com ponteiros;
            // conforme o seguinte exemmplo;
            printf("%d\n", p[i]);
        }
    }

    // exemplo: acessando array utilizando aritmética de ponteiros:
    {
        int vet[2] = {1, 2};

        // como o nome do array já é um ponteiro, basta atribuí-lo a um ponteiro
        // de tipo correspondente;
        int *p = vet;

        for (int i = 0; i < 2; i++) {
            // usando aritmética de ponteiros para percorrer um array;

            // para calcular o endereço no qual o operador de desreferênciamento
            // será aplicado, é realizada a seguinte lógica:
            // para o valor de 'i' igual a 0: multipla o valor de 'i' pelo
            // tamanho do tipo que o ponteiro aponta; neste caso, é um 'int', que
            // geralmente possui 4 bytes; portanto, 0 * 4 = 0;
            // o resultado é somado ao endereço armazenado na
            // variável ponteiro 'p';

            // para o valor de 'i' igual a 1: multiplica o valor de 'i' pelo
            // tamanho do tipo que o ponteiro aponta; neste caso, é um 'int', que
            // geralmente possui 4 bytes; portanto, 1 * 4 = 4;
            // o resultado, que neste caso, é o valor 4, é somado ao endereço
            // armazenado na variável ponteiro 'p';
            // desta forma, o valor armazenado em 'p', será incrementado
            // em 4 bytes;
            // e assim, acontece sucessivamente para cada novo valor da
            // variável 'i';
            printf("%d\n", *(p + i));
        }
    }

    // quanto à atribuição do endereço do array para o ponteiro, podemos
    // fazê-la de duas formas:
    {
        // declara e inicializa um array de inteiros, contendo 5 elementos;
        int vet[5] = {1, 2, 3, 4, 5};

        // primeira forma de atribuir um array, para um ponteiro de tipo
        // correspondente;
        int *p1 = vet;
        printf("Endereco de 'p1': %p\n");

        // segunda forma de atribuir um array, para um ponteiro de tipo
        // correspondente;
        int *p2 = &vet[0];
        printf("Endereco de 'p2': %p\n");
    }

    // IMPORTANTE: o operador colchetes ([]), substitui o uso conjunto
    // de operações aritméticas e de acesso ao conteúdo (operador “*”) no
    // acesso ao conteúdo de uma posição de um array;

    // exemplo: equivalência entre arrays e ponteiros:
    {
        int vet[5] = {1, 2, 3, 4, 5};
        int *p, indice = 2;

        p = vet;

        // essas são duas formas de realizar a mesma operação; que é acessar o
        // elemento no índice 0, o primeiro elemento do array;
        printf("%d\n", *p);
        printf("%d\n", vet[0]);

        // duas formas de realizar a mesma operação; que é acessar o elemento
        // no índice correspondente ao valor da variável 'indice';
        printf("%d\n", vet[indice]);    // utiliza o operador colchetes;
        printf("%d\n", *(p + indice));  // utiliza aritmética de ponteiros;

        // o primeiro é equivalente ao segundo printf;
        printf("%d\n", vet);        // endereço de vet;
        printf("%d\n", &vet[0]);    // endereço de vet, mas usando uma notação explícita;

        // endereço do elemento no índice correspondente ao valor da variável
        // 'indice'; ambas as formas são equivalentes;
        printf("%d\n", &vet[indice]);
        printf("%d\n", (vet + indice));
    }

    printf("-------------------------\n");

    // seção - ponteiros e arrays multidimensionais:
    // os dados dos arrays multidimensionais são armazenados linearmente na memória;
    // é o uso dos colchetes que cria a impressão de estarmos trabalhando com mais de uma
    // dimensão;
    {
        int mat[5][5];

        // apesar de ser bidimensional, é armazenada como um simples array na memória;
        // podemos acessar os elementos de um array multidimensional usando a notação
        // tradicional de colchetes, como por exemplo, 'mat[linha][coluna]', ou a
        // notação de ponteiros, conforme a expressão: *(*(mat + linha) + colua);
    }

    // exemplo: acessando um array multidimensional utilizando ponteiros:
    // usando array
    {
        int mat[2][2] = {
            { 1, 2 }, { 3, 4 }
        };

        int i, j;
        for (i = 0; i < 2; i++) {
            for (j = 0; j < 2; j++) {
                printf("%d\n", mat[i][j]);
            }
        }
    }

    // usando ponteiro
    {
        int mat[2][2] = {
            { 1, 2 }, { 3, 4 }
        };

        int *p = &mat[0][0];

        int i;
        for (i = 0; i < 4; i++) {
            printf("%d\n", *(p + i));
        }
    }

    printf("-------------------------\n");

    // seção - ponteiros e arrays multidimensionais:
    // a linguagem C também permite que declaremos arrays de ponteiros como fazemos com
    // qualquer outro tipo de dado;
    // a declaração de um array de ponteiros segue a esta forma geral:
    // tipo_dado *nome_array[tamanho];

    // assim a declaração de um array de ponteiros para inteiros de tamanho 10 seria;
    int *p[10];

    // quanto ao seu uso, não existem diferenças entre um array de ponteiros e um
    // ponteiro; basta lembrar que um array é sempre indexado; assim, para atribuir
    // o endereço de uma variável x a uma posição do array de ponteiros, podemos
    // utilizar o seguinte código;
    {
        int x = 42;
        int indice = 0;
        p[indice] = &x;

        // e para retornar o conteúdo guardado nessa posição de memória:
        printf("%d\n", *p[indice]);
    }

    // cada posição de um array de ponteiros pode armazenar o endereço de uma
    // variável ou o endereço da posição inicial de um outro array.
    {
        // declara um array de ponteiros para int, com tamanho 2;
        int *ptr_vet[2];

        // declara, e inicializa a variável 'x', do tipo 'int', para o valor '10';
        // nesta mesma instrução de declaração, define um array de inteiros, com tamanho
        // 2, e inicializa os elementos deste array, para os valores '20', e '30';
        int x = 10, y[2] = { 20, 30 };

        // armazena no array de ponteiros do tipo 'int', na primeira posição deste array,
        // o endereço da variável 'x';
        ptr_vet[0] = &x;

        // 'y' é um array de inteiros, logo, seu identificador, é o endereço do
        // primeiro elemento do array;
        ptr_vet[1] = y;

        // imprime o endereço das variáveis;
        // neste caso, o endereço de 'x', que foi armazenado na primeira posição do array 'ptr_vet';
        // assim como, o endereço de 'y', que foi armazenado na segunda posição do array 'ptr_vet';
        printf("O endereco em 'ptr_vet[0]': %p.\n", ptr_vet[0]);
        printf("O endereco em 'ptr_vet[1]': %p.\n", ptr_vet[1]);

        printf("O conteudo em 'ptr_vet[0]': %d.\n", *ptr_vet[0]);
        printf("O conteudo em 'ptr_vet[1][1]': %d.\n", ptr_vet[1][1]);
    }

    printf("-------------------------\n");

    // seção - ponteiro para ponteiro:
    // aprendemos, ao longo deste capítulo que, toda informação que manipulamos está
    // armazenada na memória do computador, e portanto, possui um endereço de memória
    // associado a ela;
    // ponteiros, assim como qualquer variável, também ocupa um espaço na memória do
    // computador, e possuem um endereço de memória associado ao seu nome;
    // como não existem diferenças entre a maneira como uma variável e um ponteiro são
    // guardadas na memória, é possível criar um ponteiro que aponte para o endereço
    // de outro ponteiro;

    // a linguagem C permite criar ponteiros com diferentes níveis de apontamento, isto
    // é, ponteiros que apontam para outros ponteiros;

    // a declaração de um ponteiro para ponteiro criado pelo programador segue esta
    // sintaxe: tipo_do_ponteiro **nome_do_ponteiro;

    // exemplo: ponteiro para ponteiro;
    {
        int x = 10;
        int *ptr = &x;
        int **ptr2 = &ptr;

        printf("Endereco em 'ptr2': %p.\n", ptr2);
        printf("Conteudo em '*ptr2': %p.\n", *ptr2);
        printf("Conteudo em '**ptr2': %d.\n", **ptr2);
        printf("Ocupa %d bytes.\n", sizeof(int*));
    }

    return 0;
}
