#include <stdio.h>

// arquivo de cabe�alho contendo fun��es de manipula��o de strings;
#include <string.h>

/**
* se��o: arrays de caractere - strings em linguagem C;
*/
int _1main() {
    // essa � uma declara��o de um array de caracteres;
    // e logo na declara��o desta vari�vel, foi feita a inicializa��o da mesma;
    // vale notar que, mesmo tendo sido declarado um tamanho de 6 posi��es,
    // neste caso, apenas duas posi��es cont�m caracteres da string final, e tamb�m
    // um delimitador do fim da string em C;
    // essa n�o � uma forma muito adequada de se inicializar vari�veis do tipo string,
    // e portanto, existe outra maneira mais pr�tica;
    char source[6] = { 'O', 'i', '\0' };
    printf("%s\n", source);

    // neste caso, est� sendo feita a declara��o e inicializa��o da vari�vel nome, que
    // corresponde a um array de caracteres; isto define uma string em C; que nada mais �
    // que um array de char; essa � uma outra forma mais f�cil de inicializar um array
    // de caracteres, que deve ser feita atrav�s do delimitador 'aspas duplas';
    // uma outra facilidade desta forma de inicializar um array de caracteres � que o
    // compilador adicionar automaticamente o delimitar de fim da string, que � definido
    // com um caractere de barra-invertida zero ('\0');
    char nome[10] = "Pedro";
    printf("%s\n", nome);
    // como est� sendo feita a inicializa��o da vari�vel 'palavra' com a forma mais pr�tica
    // de inicializar um array de caracteres, que � atrav�s de aspas duplas, o compilador
    // adiciona automaticamente o caractere de delimitador do fim da string;
    char palavra[6] = "Teste";
    printf("%s\n", palavra);

    // � poss�vel acessar cada caractere individual da string, que nada mais � que uma
    // array de caracteres; portanto, o acesso � feito atrav�s do operador de indexa��o;
    // que � definido pelo operador colchetes ([]);

    // para alterar o caractere na primeira posi��o em um array de caracteres, apenas �
    // preciso usar o operador de indexa��o, juntamente com o operador de atribui��o, conforme
    // o seguinte exemplo;
    palavra[0] = 'L';

    char frase[10] = "Ol� mundo";
    char copiaFrase[10];

    // essa atribui��o n�o funciona, porque na linguagem C n�o � permitido fazer atribui��o
    // de um array para outro; o correto � fazer a c�pia de cada elemento de um array para o
    // outro array;
    //copiaFrase = frase;

    // para ler uma string do teclado a alternativa mais eficiente � a fun��o 'gets';
    // ela l� do teclado todos os caracteres informados mesmo com espa�os em branco;
    // j� a fun��o 'scanf', apenas l� uma string do teclado at� o ponto onde ela encontrar
    // o primeiro caractere de espa�o;
    char teclado[10];

    // essa fun��o l� at� encontrar um caractere de barra-invertida n ('\n'), que � o caractere
    // representado pela tecla 'Enter';
    gets(teclado);
    printf("%s\n", teclado);

    // outra alternativa para leitura de valores do teclado;
    // o terceiro argumento desta fun��o � um ponteiro para o tipo FILE;
    // desta forma, � poss�vel notar que tamb�m d� certo a leitura de valores de outras 'fontes',
    // como, por exemplo, de um arquivo;
    char texto[10];
    // o primeiro argumento � um ponteiro para o primeiro byte que foi alocado para armazenar o
    // resultado lido do terceiro argumento, tendo, no m�ximo, at�: TAM - 1; caracteres;
    // essa fun��o est� fazendo a leitura de valores do teclado, at� encontrar o caractere
    // representado pela tecla Enter, que � o caractere de barra-invertida n ('\n'), ou at�
    // chegar ao limite informado no segundo argumento, que � o tamanho m�ximo;
    char *result = fgets(texto, 10, stdin);

    // o resultado da fun��o fgets(), � um ponteiro para char, que tem a possibiliadde de ser NULL;
    if (result) {
        printf("%s\n", result);
    }

    // para imprimir na tela, sa�da padr�o, uma string (array de caracteres), basta usar a fun��o
    // printf(), com o especificador de formato "%s" (porcentagem 's');
    char output[15] = "Pedro Junior";
    printf("%s\n", output);

    // uma maneira alternativa � usar a fun��o fputs();
    // a fun��o fputs recebe como primeiro argumento, a string que deve ser impressa na tela;
    // como segundo argumento, a fun��o fputs(), recebe um FILE *fp - um ponteiro para um arquivo;
    // segue um exemplo de uso;
    // a fun��o retorna EOF (-1) para indicar que houver um erro na escrita;
    int success = fputs(output, stdout);
    puts("\n");

    // obtendo o tamanho de uma string (array de caracteres, terminado com um delimitador barra-invertidao zero);
    int size_of_output = strlen(output);
    printf("o comprimento de output eh: %d\n", size_of_output);

    // n�o � poss�vel fazer a atribui��o de um array para outro array;
    // para obter um resultado semelhante, � preciso copiar os elementos de um array para o outro;
    // e para isso, existe a fun��o 'strcpy(dest, orig)';
    char origem[20] = "string de origem";
    char destino[20];
    strcpy(destino, origem);
    printf("%s\n", destino);

    // outra fun��o de manipula��o de string muito conhecida � a fun��o 'strcat(dest, orig)';
    // com essa fun��o � poss�vel concatenar ao final de uma string o conte�do de outra string;
    {
        char str_a[20] = "hello ";
        char str_b[20] = "world";
        strcat(str_a, str_b);
        printf("%s\n", str_a);
    }

    // � preciso saber que n�o � poss�vel usar o operador de atribui��o com strings em C;
    // � preciso saber que n�o � poss�vel usar operadores relacionais com strings em C;
    // para comparar o conte�do de duas string, existe a fun��o da biblioteca padr�o 'strcmp(s1, s2)';
    {
        char str_a[30] = "Aprendendo a linguagem C";
        char str_b[30] = "Aprendendo a linguagem C";
        // � preciso mencionar que esta fun��o � case-sensitive; portanto, strings com
        // o mesmo conte�do mais variando em mai�scula e men�scula, s�o consideradas strings diferentes;
        int resultado = strcmp(str_a, str_b);
        if (resultado == 0) {
            printf("as strings comparadas sao iguais\n");
        }
    }

    // para transformar uma letra mai�scula em min�scula, basta adicionar 32 ao valor do char;
    int letra = 'A' + 32;
    printf("a = %c\n", letra);

    return 0;
}
