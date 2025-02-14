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
        int vet[5] = {1, 2, 3, 4, 5};

        // como o nome do array j� � um ponteiro, basta atribu�-lo a um ponteiro
        // de tipo correspondente;
        int *p = vet;

        for (int i = 0; i < 5; i++) {
            // a nota��o de colchetes, aquela utilizada principalmente com arrays
            // tamb�m pode ser utilizada com ponteiros;
            // conforme o seguinte exemmplo;
            printf("%d\n", p[i]);
        }
    }

    // exemplo: acessando array utilizando aritm�tica de ponteiros:
    {
        int vet[5] = {1, 2, 3, 4, 5};

        // como o nome do array j� � um ponteiro, basta atribu�-lo a um ponteiro
        // de tipo correspondente;
        int *p = vet;

        for (int i = 0; i < 5; i++) {
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
    // ponteiros e arrays multidimensionais:
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

    return 0;
}
