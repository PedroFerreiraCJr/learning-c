#include <stdio.h>

/**
 seção: passagem de parâmetros para função;
*/

// na linguagem C, a passagem de argumentos para uma função são sempre
// passados por valor, ou seja, uma cópia dos dados informados é feita,
// e atribuída ao parâmetro da função; isso é realizado para todos os tipos
// de dados predefinidos na linguagem, assim como, para tipos de dados definidos
// pelo próprio programador, como uma struct, union, e enum;


// a seguinte função declara um parâmetro formal, que então deve ser
// fornecido pelo invocador dela, para que ela possa executar sua funcionalidade;
void somar_mais_um_pass_by_value(int n) {
    // nesta linha, está sendo feita a tentativa de alterar o valor da variavel
    // que foi fornecida para esta função; mas isso não é possível; neste caso,
    // o parâmetro 'n' terá seu valor alterado, mas o valor da variável que foi
    // fornecido para a invocação da função, não terá seu valor alterado;
    n = n + 1;
    printf("dentro da function[by_val], o valor do parametro[int n] eh %d.\n", n);
}

// a seguinte função declara um parâmetro formal, que então deve ser fornecido
// pelo invocador dela, para que ela possa realizar sua funcionalidade;
// a passagem de parâmetro é apenas um mecanismo para passar uma informação de um
// local no programa para outro local, que para poder realizar determinada tarefa
// precisa daquela informação que está localizada em outra parte do programa;
// a seguinte declaração de função, está sendo declarado um parâmetro ponteiro
// para um 'int';
// um ponteiro é apenas uma variável especial que tem o mesmo sentido de uma variável
// qualquer, mas ele é considerado especial porque o valor que ele armazena, na realidade
// é o endereço para uma outra posição de memória, geralmente uma outra localização na
// memóra que foi alocada, seja estaticamente ou dinamicamente, e que está disponível para
// o programa utilizar;
// para declarar um parâmetro como sendo um ponteiro, é preciso usar o operador asterísco '*';
void somar_mais_um_pass_by_reference(int *n) {
    // na seguinte instrução, está sendo feito o acesso através do ponteiro para 'int',
    // chamado 'n', utilizando o operador asterísco (*), para recuperar o valor da variável
    // ponteiro, e na mesma instrução está sendo feita a atualização do valor que está
    // armazenado no endereço que está contido no parâmetro 'n';
    // ou seja, estamos alterando o valor da variável que está contido no endereço apontado
    // pelo parâmetro 'n' que é um ponteiro para 'int';
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

// nessa declaração de função, o parâmetro que foi declarado nela está informando
// que o argumento que deve ser fornecido seja uma struct, do tipo 'ponto'; além disso,
// como é solicitado a passagem de parâmetro por referência, é preciso adicionar o
// operador asterísco (*) antes do nome do parâmetro da função;
void atribuir_valor_inicial(struct ponto *p) {
    // para acessar os campos da struct, é preciso, primeiro desreferencia o
    // ponteiro 'p', neste caso, utilizando o operador asterísco (*);
    // outro aspecto importante é que é preciso utilizar o operador parênteses '()',
    // para alterar a prescedencia de operadores, para que o operador asterísco (*)
    // seja interpretado primeiro, e somente depois, o operador ponto (.), é interpretado
    // para acessar o campo da struct;
    (*p).x = 100;
    (*p).y = 200;
}

// nessa declaração de função, o parâmetro que foi declarado nela está informando
// que o argumento que deve ser fornecido seja uma struct, do tipo 'ponto'; além disso,
// como é solicitado a passagem de parâmetro por referência, é preciso adicionar o
// operador asterísco (*) antes do nome do parâmetro da função;
void imprimir_campos(struct ponto *p) {
    printf("Ponto[x=%d, y=%d]\n", (*p).x, (*p).y);
}

// exemplo de utilização do operador '->' (seta) para facilitar o acesso aos campos
// da struct ponto que é passada por referência;
void acessar_campos_struct_com_operador_seta(struct ponto *p) {
    p->x = 500;
    p->y = 1000;
    printf("Ponto[x=%d, y=%d]\n", p->x, p->y);
}

int _07main() {
    // exemplo de invocação de função através da passagem de parâmetro por valor;
    int x = 5;
    somar_mais_um_pass_by_value(x);
    printf("dentro da function[main], ");
    printf("o valor da variavel passada como argumento para a function[by_val] ");
    printf("eh %d.\n", x);

    // exemplo de invocação de função através da passagem de parâmetro por referência;
    //int numero;
    // a função scanf é um exemplo de função que altera o valor original da variável que
    // é informada ou passada como argumento para a função; porque neste caso, está sendo
    // feita a passagem de parâmetro por referência;

    // na passagem de parâmetrso por referência não se passa para a função os valores das
    // variáveis, mas os endereços das variáveis na memória;
    //scanf("%d", &numero);

    // exemplo de invocação de função através da passagem de parâmetro por valor;
    int y = 5;
    somar_mais_um_pass_by_reference(&y);
    printf("dentro da function[main], ");
    printf("o valor da variavel passada como argumento para a function[by_ref] ");
    printf("eh %d.\n", y);

    // na passagem de parâmetro para funções, a passagem de um array é sempre feita
    // por referência; nestes casos, quando é necessário passar um array para dentro
    // de uma outra função, é preciso informar em outro parâmetro da função o tamanho
    // do array; outra coisa importante a saber, é que o próprio nome do array já é
    // suficiente para a passagem de parâmtro por referência; pois o nome do array é
    // um ponteiro constante para a primeira posição do array;

    // nos blocos de código anônimos a seguir, as 3 declarações de função
    // em cada bloco são equivalentes;
    {
        // recebe um array para int;
        // dentro da função não é preciso usar o operador asterísco
        // para acessar os valores do array;
        void imprimir(int *arr, int tamanho) {
            for (int i = 0; i < tamanho; i++) {
                // devido a compatibilidade entre ponteiros e arrays
                // é possível utilizar o operador colhete ([]) para
                // indexar um ponteiro ou array;
                printf("%d, ", arr[i]);
            }
            printf("\n");
        }
    }

    {
        // recebe um array para int;
        // dentro da função não é preciso usar o operador asterísco
        // para acessar os valores do array;
        void imprimir(int arr[], int tamanho) {
            for (int i = 0; i < tamanho; i++) {
                // devido a compatibilidade entre ponteiros e arrays
                // é possível utilizar o operador colhete ([]) para
                // indexar um ponteiro ou array;
                printf("%d, ", arr[i]);
            }
            printf("\n");
        }
    }

    {
        // recebe um array para int;
        // dentro da função não é preciso usar o operador asterísco
        // para acessar os valores do array;
        void imprimir(int arr[5], int tamanho) {
            for (int i = 0; i < tamanho; i++) {
                // devido a compatibilidade entre ponteiros e arrays
                // é possível utilizar o operador colhete ([]) para
                // indexar um ponteiro ou array;
                printf("%d, ", arr[i]);
            }
            printf("\n");
        }
    }

    // passagem de parâmetro para função, recebendo uma struct;
    {
        // declara e inicializa uma variável do tipo struct ponto;
        struct ponto p = { 10, 20 };
        imprimir(p);
    }

    // passagem de parâmetro para função, recebendo um campo da struct por valor;
    {
        // o argumento informado para esta função a partir da linha de código
        // abaixo precisa levar em consideração o tipo do parâmetro da função
        // assim como, o tipo do campo da struct; eles devem ser compatíveis;
        void imprimir(int x) {
            printf("O valor informado foi: %d.\n", x);
        }

        // declara e inicializa uma variável do tipo struct ponto;
        struct ponto p = { 10, 20 };
        imprimir(p.x);
        imprimir(p.y);
    }

    // passagem de parâmetro para função, recebendo um campo da struct por referência;
    {
        // o argumento informado para esta função a partir da linha de código
        // abaixo precisa levar em consideração o tipo do parâmetro da função,
        // assim como, o tipo do campo da struct; eles devem ser compatíveis;
        // como neste caso precisa ser feita a passagem de parâmetro por referência
        // basta adicionar o operador asteríscto (*), depois do tipo do campo;
        // nesse exemplo, o campo da struct tem o tipo 'int', e o parâmetro da
        // função tem um tipo ponteiro para 'int' (int*);
        void somar_e_imprimir(int* ptr_i) {
            *ptr_i = *ptr_i + 1;
            printf("Apos somar 1 ao valor informado, agora ele tem o valor: %d.\n", *ptr_i);
        }

        // declara e inicializa uma variável do tipo struct ponto;
        struct ponto p = { 10, 20 };

        // invoca a função 'somar_e_imprimir' passando como argumento o
        // endereço do campo 'x' de uma instância da struct ponto;
        somar_e_imprimir(&p.x);

        // faz a mesma coisa para o campo 'y';
        somar_e_imprimir(&p.y);
    }

    {
        // declara uma variável do tipo struct ponto chamada 'minha_struct';
        struct ponto minha_struct;

        // invoca a função 'atribuir_valor_inicial', passando como argumento o
        // endereço de uma instância da struct ponto chamada 'minha_struct';
        atribuir_valor_inicial(&minha_struct);

        // invoca a função 'imprimir_campos', passando como argumento o
        // endereço de uma instância da struct ponto, chamada 'minha_struct';
        imprimir_campos(&minha_struct);
    }

    // o operador '->' (seta) substitui o uso conjunto dos operadores '*' (asterísco),
    // e o operador '.' (ponto), no acesso ao campo de uma estrutura (struct) passada
    // por referência para uma função; ou seja, quando eu tenho um ponteiro para uma
    // estrutura, é possível usar o operador '->' (seta), para facilitar o acesso aos
    // campos da estrutura; conforme o seguinte exemplo;
    {
        struct ponto minha_struct;
        acessar_campos_struct_com_operador_seta(&minha_struct);
    }

    return 0;
}
