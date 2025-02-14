#include <stdio.h>

// arquivo de cabeçalho contendo funções de manipulação de strings;
#include <string.h>

/**
* seção: arrays de caractere - strings em linguagem C;
*/
int _1main() {
    // essa é uma declaração de um array de caracteres;
    // e logo na declaração desta variável, foi feita a inicialização da mesma;
    // vale notar que, mesmo tendo sido declarado um tamanho de 6 posições,
    // neste caso, apenas duas posições contém caracteres da string final, e também
    // um delimitador do fim da string em C;
    // essa não é uma forma muito adequada de se inicializar variáveis do tipo string,
    // e portanto, existe outra maneira mais prática;
    char source[6] = { 'O', 'i', '\0' };
    printf("%s\n", source);

    // neste caso, está sendo feita a declaração e inicialização da variável nome, que
    // corresponde a um array de caracteres; isto define uma string em C; que nada mais é
    // que um array de char; essa é uma outra forma mais fácil de inicializar um array
    // de caracteres, que deve ser feita através do delimitador 'aspas duplas';
    // uma outra facilidade desta forma de inicializar um array de caracteres é que o
    // compilador adicionar automaticamente o delimitar de fim da string, que é definido
    // com um caractere de barra-invertida zero ('\0');
    char nome[10] = "Pedro";
    printf("%s\n", nome);
    // como está sendo feita a inicialização da variável 'palavra' com a forma mais prática
    // de inicializar um array de caracteres, que é através de aspas duplas, o compilador
    // adiciona automaticamente o caractere de delimitador do fim da string;
    char palavra[6] = "Teste";
    printf("%s\n", palavra);

    // é possível acessar cada caractere individual da string, que nada mais é que uma
    // array de caracteres; portanto, o acesso é feito através do operador de indexação;
    // que é definido pelo operador colchetes ([]);

    // para alterar o caractere na primeira posição em um array de caracteres, apenas é
    // preciso usar o operador de indexação, juntamente com o operador de atribuição, conforme
    // o seguinte exemplo;
    palavra[0] = 'L';

    char frase[10] = "Olá mundo";
    char copiaFrase[10];

    // essa atribuição não funciona, porque na linguagem C não é permitido fazer atribuição
    // de um array para outro; o correto é fazer a cópia de cada elemento de um array para o
    // outro array;
    //copiaFrase = frase;

    // para ler uma string do teclado a alternativa mais eficiente é a função 'gets';
    // ela lê do teclado todos os caracteres informados mesmo com espaços em branco;
    // já a função 'scanf', apenas lê uma string do teclado até o ponto onde ela encontrar
    // o primeiro caractere de espaço;
    char teclado[10];

    // essa função lê até encontrar um caractere de barra-invertida n ('\n'), que é o caractere
    // representado pela tecla 'Enter';
    gets(teclado);
    printf("%s\n", teclado);

    // outra alternativa para leitura de valores do teclado;
    // o terceiro argumento desta função é um ponteiro para o tipo FILE;
    // desta forma, é possível notar que também dá certo a leitura de valores de outras 'fontes',
    // como, por exemplo, de um arquivo;
    char texto[10];
    // o primeiro argumento é um ponteiro para o primeiro byte que foi alocado para armazenar o
    // resultado lido do terceiro argumento, tendo, no máximo, até: TAM - 1; caracteres;
    // essa função está fazendo a leitura de valores do teclado, até encontrar o caractere
    // representado pela tecla Enter, que é o caractere de barra-invertida n ('\n'), ou até
    // chegar ao limite informado no segundo argumento, que é o tamanho máximo;
    char *result = fgets(texto, 10, stdin);

    // o resultado da função fgets(), é um ponteiro para char, que tem a possibiliadde de ser NULL;
    if (result) {
        printf("%s\n", result);
    }

    // para imprimir na tela, saída padrão, uma string (array de caracteres), basta usar a função
    // printf(), com o especificador de formato "%s" (porcentagem 's');
    char output[15] = "Pedro Junior";
    printf("%s\n", output);

    // uma maneira alternativa é usar a função fputs();
    // a função fputs recebe como primeiro argumento, a string que deve ser impressa na tela;
    // como segundo argumento, a função fputs(), recebe um FILE *fp - um ponteiro para um arquivo;
    // segue um exemplo de uso;
    // a função retorna EOF (-1) para indicar que houver um erro na escrita;
    int success = fputs(output, stdout);
    puts("\n");

    // obtendo o tamanho de uma string (array de caracteres, terminado com um delimitador barra-invertidao zero);
    int size_of_output = strlen(output);
    printf("o comprimento de output eh: %d\n", size_of_output);

    // não é possível fazer a atribuição de um array para outro array;
    // para obter um resultado semelhante, é preciso copiar os elementos de um array para o outro;
    // e para isso, existe a função 'strcpy(dest, orig)';
    char origem[20] = "string de origem";
    char destino[20];
    strcpy(destino, origem);
    printf("%s\n", destino);

    // outra função de manipulação de string muito conhecida é a função 'strcat(dest, orig)';
    // com essa função é possível concatenar ao final de uma string o conteúdo de outra string;
    {
        char str_a[20] = "hello ";
        char str_b[20] = "world";
        strcat(str_a, str_b);
        printf("%s\n", str_a);
    }

    // é preciso saber que não é possível usar o operador de atribuição com strings em C;
    // é preciso saber que não é possível usar operadores relacionais com strings em C;
    // para comparar o conteúdo de duas string, existe a função da biblioteca padrão 'strcmp(s1, s2)';
    {
        char str_a[30] = "Aprendendo a linguagem C";
        char str_b[30] = "Aprendendo a linguagem C";
        // é preciso mencionar que esta função é case-sensitive; portanto, strings com
        // o mesmo conteúdo mais variando em maiúscula e menúscula, são consideradas strings diferentes;
        int resultado = strcmp(str_a, str_b);
        if (resultado == 0) {
            printf("as strings comparadas sao iguais\n");
        }
    }

    // para transformar uma letra maiúscula em minúscula, basta adicionar 32 ao valor do char;
    int letra = 'A' + 32;
    printf("a = %c\n", letra);

    return 0;
}
