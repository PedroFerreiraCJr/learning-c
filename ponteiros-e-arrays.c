#include <stdio.h>

/**
* se��o: ponteiros e arrays;
*/
int main() {
    // ponteiros e arrays possuem uma liga��o muito forte dentro da linguagem C;
    // arrays s�o agrupamentos de dados do mesmo tipo na mem�ria;
    // quando declaramos um array, informamos para o computador reserver certa
    // quantidade de mem�ria a fim de armazenar os elementos do array de forma
    // sequencial, ou seja, de maneira adjacente na mem�ria;
    // como resultado desta opera��o, o computador nos devolve um ponteiro que
    // aponta para o come�o dessa sequ�ncia de bytes na mem�ria;

    // o nome do array � apenas um ponteiro que aponta para o primeiro elemento
    // do array;

    // na linguagem C, o nome de um array sem �ndice guarda o endere�o para
    // o come�o do array na mem�ria, ou seja, ele guarda o endere�o do
    // in�cio de uma �rea de armazenamento dentro da mem�ria;
    // isso significa que as opera��es envolvendo arrays podem ser feitas
    // utilizando ponteiros e aritm�tica de ponteiros;

    // exemplo: acessando array utilizando ponteiros;
    {
        int vet[2] = {1, 2};

        // como o nome do array j� � um ponteiro, basta atribu�-lo a um ponteiro
        // de tipo correspondente;
        int *p = vet;

        for (int i = 0; i < 2; i++) {
            // a nota��o de colchetes, aquela utilizada principalmente com arrays
            // tamb�m pode ser utilizada com ponteiros;
            // conforme o seguinte exemmplo;
            printf("%d\n", p[i]);
        }
    }

    // exemplo: acessando array utilizando aritm�tica de ponteiros:
    {
        int vet[2] = {1, 2};

        // como o nome do array j� � um ponteiro, basta atribu�-lo a um ponteiro
        // de tipo correspondente;
        int *p = vet;

        for (int i = 0; i < 2; i++) {
            // usando aritm�tica de ponteiros para percorrer um array;

            // para calcular o endere�o no qual o operador de desrefer�nciamento
            // ser� aplicado, � realizada a seguinte l�gica:
            // para o valor de 'i' igual a 0: multipla o valor de 'i' pelo
            // tamanho do tipo que o ponteiro aponta; neste caso, � um 'int', que
            // geralmente possui 4 bytes; portanto, 0 * 4 = 0;
            // o resultado � somado ao endere�o armazenado na
            // vari�vel ponteiro 'p';

            // para o valor de 'i' igual a 1: multiplica o valor de 'i' pelo
            // tamanho do tipo que o ponteiro aponta; neste caso, � um 'int', que
            // geralmente possui 4 bytes; portanto, 1 * 4 = 4;
            // o resultado, que neste caso, � o valor 4, � somado ao endere�o
            // armazenado na vari�vel ponteiro 'p';
            // desta forma, o valor armazenado em 'p', ser� incrementado
            // em 4 bytes;
            // e assim, acontece sucessivamente para cada novo valor da
            // vari�vel 'i';
            printf("%d\n", *(p + i));
        }
    }

    // quanto � atribui��o do endere�o do array para o ponteiro, podemos
    // faz�-la de duas formas:
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
    // de opera��es aritm�ticas e de acesso ao conte�do (operador �*�) no
    // acesso ao conte�do de uma posi��o de um array;

    // exemplo: equival�ncia entre arrays e ponteiros:
    {
        int vet[5] = {1, 2, 3, 4, 5};
        int *p, indice = 2;

        p = vet;

        // essas s�o duas formas de realizar a mesma opera��o; que � acessar o
        // elemento no �ndice 0, o primeiro elemento do array;
        printf("%d\n", *p);
        printf("%d\n", vet[0]);

        // duas formas de realizar a mesma opera��o; que � acessar o elemento
        // no �ndice correspondente ao valor da vari�vel 'indice';
        printf("%d\n", vet[indice]);    // utiliza o operador colchetes;
        printf("%d\n", *(p + indice));  // utiliza aritm�tica de ponteiros;

        // o primeiro � equivalente ao segundo printf;
        printf("%d\n", vet);        // endere�o de vet;
        printf("%d\n", &vet[0]);    // endere�o de vet, mas usando uma nota��o expl�cita;

        // endere�o do elemento no �ndice correspondente ao valor da vari�vel
        // 'indice'; ambas as formas s�o equivalentes;
        printf("%d\n", &vet[indice]);
        printf("%d\n", (vet + indice));
    }

    printf("-------------------------\n");

    // se��o - ponteiros e arrays multidimensionais:
    // os dados dos arrays multidimensionais s�o armazenados linearmente na mem�ria;
    // � o uso dos colchetes que cria a impress�o de estarmos trabalhando com mais de uma
    // dimens�o;
    {
        int mat[5][5];

        // apesar de ser bidimensional, � armazenada como um simples array na mem�ria;
        // podemos acessar os elementos de um array multidimensional usando a nota��o
        // tradicional de colchetes, como por exemplo, 'mat[linha][coluna]', ou a
        // nota��o de ponteiros, conforme a express�o: *(*(mat + linha) + colua);
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

    // se��o - ponteiros e arrays multidimensionais:
    // a linguagem C tamb�m permite que declaremos arrays de ponteiros como fazemos com
    // qualquer outro tipo de dado;
    // a declara��o de um array de ponteiros segue a esta forma geral:
    // tipo_dado *nome_array[tamanho];

    // assim a declara��o de um array de ponteiros para inteiros de tamanho 10 seria;
    int *p[10];

    // quanto ao seu uso, n�o existem diferen�as entre um array de ponteiros e um
    // ponteiro; basta lembrar que um array � sempre indexado; assim, para atribuir
    // o endere�o de uma vari�vel x a uma posi��o do array de ponteiros, podemos
    // utilizar o seguinte c�digo;
    {
        int x = 42;
        int indice = 0;
        p[indice] = &x;

        // e para retornar o conte�do guardado nessa posi��o de mem�ria:
        printf("%d\n", *p[indice]);
    }

    // cada posi��o de um array de ponteiros pode armazenar o endere�o de uma
    // vari�vel ou o endere�o da posi��o inicial de um outro array.
    {
        // declara um array de ponteiros para int, com tamanho 2;
        int *ptr_vet[2];

        // declara, e inicializa a vari�vel 'x', do tipo 'int', para o valor '10';
        // nesta mesma instru��o de declara��o, define um array de inteiros, com tamanho
        // 2, e inicializa os elementos deste array, para os valores '20', e '30';
        int x = 10, y[2] = { 20, 30 };

        // armazena no array de ponteiros do tipo 'int', na primeira posi��o deste array,
        // o endere�o da vari�vel 'x';
        ptr_vet[0] = &x;

        // 'y' � um array de inteiros, logo, seu identificador, � o endere�o do
        // primeiro elemento do array;
        ptr_vet[1] = y;

        // imprime o endere�o das vari�veis;
        // neste caso, o endere�o de 'x', que foi armazenado na primeira posi��o do array 'ptr_vet';
        // assim como, o endere�o de 'y', que foi armazenado na segunda posi��o do array 'ptr_vet';
        printf("O endereco em 'ptr_vet[0]': %p.\n", ptr_vet[0]);
        printf("O endereco em 'ptr_vet[1]': %p.\n", ptr_vet[1]);

        printf("O conteudo em 'ptr_vet[0]': %d.\n", *ptr_vet[0]);
        printf("O conteudo em 'ptr_vet[1][1]': %d.\n", ptr_vet[1][1]);
    }

    printf("-------------------------\n");

    // se��o - ponteiro para ponteiro:
    // aprendemos, ao longo deste cap�tulo que, toda informa��o que manipulamos est�
    // armazenada na mem�ria do computador, e portanto, possui um endere�o de mem�ria
    // associado a ela;
    // ponteiros, assim como qualquer vari�vel, tamb�m ocupa um espa�o na mem�ria do
    // computador, e possuem um endere�o de mem�ria associado ao seu nome;
    // como n�o existem diferen�as entre a maneira como uma vari�vel e um ponteiro s�o
    // guardadas na mem�ria, � poss�vel criar um ponteiro que aponte para o endere�o
    // de outro ponteiro;

    // a linguagem C permite criar ponteiros com diferentes n�veis de apontamento, isto
    // �, ponteiros que apontam para outros ponteiros;

    // a declara��o de um ponteiro para ponteiro criado pelo programador segue esta
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
