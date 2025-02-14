#include <stdio.h>

/**
 se��o: passagem de par�metros para fun��o;
*/

// na linguagem C, a passagem de argumentos para uma fun��o s�o sempre
// passados por valor, ou seja, uma c�pia dos dados informados � feita,
// e atribu�da ao par�metro da fun��o; isso � realizado para todos os tipos
// de dados predefinidos na linguagem, assim como, para tipos de dados definidos
// pelo pr�prio programador, como uma struct, union, e enum;


// a seguinte fun��o declara um par�metro formal, que ent�o deve ser
// fornecido pelo invocador dela, para que ela possa executar sua funcionalidade;
void somar_mais_um_pass_by_value(int n) {
    // nesta linha, est� sendo feita a tentativa de alterar o valor da variavel
    // que foi fornecida para esta fun��o; mas isso n�o � poss�vel; neste caso,
    // o par�metro 'n' ter� seu valor alterado, mas o valor da vari�vel que foi
    // fornecido para a invoca��o da fun��o, n�o ter� seu valor alterado;
    n = n + 1;
    printf("dentro da function[by_val], o valor do parametro[int n] eh %d.\n", n);
}

// a seguinte fun��o declara um par�metro formal, que ent�o deve ser fornecido
// pelo invocador dela, para que ela possa realizar sua funcionalidade;
// a passagem de par�metro � apenas um mecanismo para passar uma informa��o de um
// local no programa para outro local, que para poder realizar determinada tarefa
// precisa daquela informa��o que est� localizada em outra parte do programa;
// a seguinte declara��o de fun��o, est� sendo declarado um par�metro ponteiro
// para um 'int';
// um ponteiro � apenas uma vari�vel especial que tem o mesmo sentido de uma vari�vel
// qualquer, mas ele � considerado especial porque o valor que ele armazena, na realidade
// � o endere�o para uma outra posi��o de mem�ria, geralmente uma outra localiza��o na
// mem�ra que foi alocada, seja estaticamente ou dinamicamente, e que est� dispon�vel para
// o programa utilizar;
// para declarar um par�metro como sendo um ponteiro, � preciso usar o operador aster�sco '*';
void somar_mais_um_pass_by_reference(int *n) {
    // na seguinte instru��o, est� sendo feito o acesso atrav�s do ponteiro para 'int',
    // chamado 'n', utilizando o operador aster�sco (*), para recuperar o valor da vari�vel
    // ponteiro, e na mesma instru��o est� sendo feita a atualiza��o do valor que est�
    // armazenado no endere�o que est� contido no par�metro 'n';
    // ou seja, estamos alterando o valor da vari�vel que est� contido no endere�o apontado
    // pelo par�metro 'n' que � um ponteiro para 'int';
    *n = *n + 1;
    printf("dentro da function[by_ref], o valor do parametro[int *n] eh %d.\n", *n);
}

struct ponto {
    int x;
    int y;
};

void imprimir(struct ponto p) {
    printf("Ponto[x=%d, y=%d]\n", p.x, p.y);
}

// nessa declara��o de fun��o, o par�metro que foi declarado nela est� informando
// que o argumento que deve ser fornecido seja uma struct, do tipo 'ponto'; al�m disso,
// como � solicitado a passagem de par�metro por refer�ncia, � preciso adicionar o
// operador aster�sco (*) antes do nome do par�metro da fun��o;
void atribuir_valor_inicial(struct ponto *p) {
    // para acessar os campos da struct, � preciso, primeiro desreferencia o
    // ponteiro 'p', neste caso, utilizando o operador aster�sco (*);
    // outro aspecto importante � que � preciso utilizar o operador par�nteses '()',
    // para alterar a prescedencia de operadores, para que o operador aster�sco (*)
    // seja interpretado primeiro, e somente depois, o operador ponto (.), � interpretado
    // para acessar o campo da struct;
    (*p).x = 100;
    (*p).y = 200;
}

// nessa declara��o de fun��o, o par�metro que foi declarado nela est� informando
// que o argumento que deve ser fornecido seja uma struct, do tipo 'ponto'; al�m disso,
// como � solicitado a passagem de par�metro por refer�ncia, � preciso adicionar o
// operador aster�sco (*) antes do nome do par�metro da fun��o;
void imprimir_campos(struct ponto *p) {
    printf("Ponto[x=%d, y=%d]\n", (*p).x, (*p).y);
}

// exemplo de utiliza��o do operador '->' (seta) para facilitar o acesso aos campos
// da struct ponto que � passada por refer�ncia;
void acessar_campos_struct_com_operador_seta(struct ponto *p) {
    p->x = 500;
    p->y = 1000;
    printf("Ponto[x=%d, y=%d]\n", p->x, p->y);
}

int _07main() {
    // exemplo de invoca��o de fun��o atrav�s da passagem de par�metro por valor;
    int x = 5;
    somar_mais_um_pass_by_value(x);
    printf("dentro da function[main], ");
    printf("o valor da variavel passada como argumento para a function[by_val] ");
    printf("eh %d.\n", x);

    // exemplo de invoca��o de fun��o atrav�s da passagem de par�metro por refer�ncia;
    //int numero;
    // a fun��o scanf � um exemplo de fun��o que altera o valor original da vari�vel que
    // � informada ou passada como argumento para a fun��o; porque neste caso, est� sendo
    // feita a passagem de par�metro por refer�ncia;

    // na passagem de par�metrso por refer�ncia n�o se passa para a fun��o os valores das
    // vari�veis, mas os endere�os das vari�veis na mem�ria;
    //scanf("%d", &numero);

    // exemplo de invoca��o de fun��o atrav�s da passagem de par�metro por valor;
    int y = 5;
    somar_mais_um_pass_by_reference(&y);
    printf("dentro da function[main], ");
    printf("o valor da variavel passada como argumento para a function[by_ref] ");
    printf("eh %d.\n", y);

    // na passagem de par�metro para fun��es, a passagem de um array � sempre feita
    // por refer�ncia; nestes casos, quando � necess�rio passar um array para dentro
    // de uma outra fun��o, � preciso informar em outro par�metro da fun��o o tamanho
    // do array; outra coisa importante a saber, � que o pr�prio nome do array j� �
    // suficiente para a passagem de par�mtro por refer�ncia; pois o nome do array �
    // um ponteiro constante para a primeira posi��o do array;

    // nos blocos de c�digo an�nimos a seguir, as 3 declara��es de fun��o
    // em cada bloco s�o equivalentes;
    {
        // recebe um array para int;
        // dentro da fun��o n�o � preciso usar o operador aster�sco
        // para acessar os valores do array;
        void imprimir(int *arr, int tamanho) {
            for (int i = 0; i < tamanho; i++) {
                // devido a compatibilidade entre ponteiros e arrays
                // � poss�vel utilizar o operador colhete ([]) para
                // indexar um ponteiro ou array;
                printf("%d, ", arr[i]);
            }
            printf("\n");
        }
    }

    {
        // recebe um array para int;
        // dentro da fun��o n�o � preciso usar o operador aster�sco
        // para acessar os valores do array;
        void imprimir(int arr[], int tamanho) {
            for (int i = 0; i < tamanho; i++) {
                // devido a compatibilidade entre ponteiros e arrays
                // � poss�vel utilizar o operador colhete ([]) para
                // indexar um ponteiro ou array;
                printf("%d, ", arr[i]);
            }
            printf("\n");
        }
    }

    {
        // recebe um array para int;
        // dentro da fun��o n�o � preciso usar o operador aster�sco
        // para acessar os valores do array;
        void imprimir(int arr[5], int tamanho) {
            for (int i = 0; i < tamanho; i++) {
                // devido a compatibilidade entre ponteiros e arrays
                // � poss�vel utilizar o operador colhete ([]) para
                // indexar um ponteiro ou array;
                printf("%d, ", arr[i]);
            }
            printf("\n");
        }
    }

    // passagem de par�metro para fun��o, recebendo uma struct;
    {
        // declara e inicializa uma vari�vel do tipo struct ponto;
        struct ponto p = { 10, 20 };
        imprimir(p);
    }

    // passagem de par�metro para fun��o, recebendo um campo da struct por valor;
    {
        // o argumento informado para esta fun��o a partir da linha de c�digo
        // abaixo precisa levar em considera��o o tipo do par�metro da fun��o
        // assim como, o tipo do campo da struct; eles devem ser compat�veis;
        void imprimir(int x) {
            printf("O valor informado foi: %d.\n", x);
        }

        // declara e inicializa uma vari�vel do tipo struct ponto;
        struct ponto p = { 10, 20 };
        imprimir(p.x);
        imprimir(p.y);
    }

    // passagem de par�metro para fun��o, recebendo um campo da struct por refer�ncia;
    {
        // o argumento informado para esta fun��o a partir da linha de c�digo
        // abaixo precisa levar em considera��o o tipo do par�metro da fun��o,
        // assim como, o tipo do campo da struct; eles devem ser compat�veis;
        // como neste caso precisa ser feita a passagem de par�metro por refer�ncia
        // basta adicionar o operador aster�scto (*), depois do tipo do campo;
        // nesse exemplo, o campo da struct tem o tipo 'int', e o par�metro da
        // fun��o tem um tipo ponteiro para 'int' (int*);
        void somar_e_imprimir(int* ptr_i) {
            *ptr_i = *ptr_i + 1;
            printf("Apos somar 1 ao valor informado, agora ele tem o valor: %d.\n", *ptr_i);
        }

        // declara e inicializa uma vari�vel do tipo struct ponto;
        struct ponto p = { 10, 20 };

        // invoca a fun��o 'somar_e_imprimir' passando como argumento o
        // endere�o do campo 'x' de uma inst�ncia da struct ponto;
        somar_e_imprimir(&p.x);

        // faz a mesma coisa para o campo 'y';
        somar_e_imprimir(&p.y);
    }

    {
        // declara uma vari�vel do tipo struct ponto chamada 'minha_struct';
        struct ponto minha_struct;

        // invoca a fun��o 'atribuir_valor_inicial', passando como argumento o
        // endere�o de uma inst�ncia da struct ponto chamada 'minha_struct';
        atribuir_valor_inicial(&minha_struct);

        // invoca a fun��o 'imprimir_campos', passando como argumento o
        // endere�o de uma inst�ncia da struct ponto, chamada 'minha_struct';
        imprimir_campos(&minha_struct);
    }

    // o operador '->' (seta) substitui o uso conjunto dos operadores '*' (aster�sco),
    // e o operador '.' (ponto), no acesso ao campo de uma estrutura (struct) passada
    // por refer�ncia para uma fun��o; ou seja, quando eu tenho um ponteiro para uma
    // estrutura, � poss�vel usar o operador '->' (seta), para facilitar o acesso aos
    // campos da estrutura; conforme o seguinte exemplo;
    {
        struct ponto minha_struct;
        acessar_campos_struct_com_operador_seta(&minha_struct);
    }

    return 0;
}
