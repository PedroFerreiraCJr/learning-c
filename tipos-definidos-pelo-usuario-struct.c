#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cadastro {
    char nome[50];
    int idade;
    char rua[50];
    int numero;
};

int _2main() {
    struct cadastro c;

    strcpy(c.nome, "Pedro Junior");
    c.idade = 32;
    strcpy(c.rua, "Av. Oeste");
    c.numero = 551;

    // a forma utilizada para fazer a inicializa��o de uma struct no momento da declara��o
    // � atrav�s do operador chaves ({});
    // semelhante a inicializa��o de arrays, que tamb�m faz uso deste operador, a
    // inicializa��o de uma struct se faz como a seguir;
    {
        struct cadastro n = { "Pedro Junior", 32, "Av. Oeste", 551 };
        printf("nome: %s, idade: %d, rua: %s, numero: %d", n.nome, n.idade, n.rua, n.numero);
    }

    // tamb�m � poss�vel utilizar declarar e usar um array de structs;
    {
        struct cadastro pessoas[2];

        // com o aux�lio de um comando de repeti��o, � feita a leitura de cada valor
        // para cada elemento do array de structs;
        /*
        for (int i = 0; i < 2; i++) {
            printf("\ninformacoes para o cadastro[%d]", i);
            fgets(pessoas[i].nome, 50, stdin);
            scanf("%d", &pessoas[i].idade);
            fgets(pessoas[i].rua, 50, stdin);
            scanf("%d", &pessoas[i].numero);
        }
        */
    }

    // atribui��o de estruturas (struct);
    // as �nicas opera��es que s�o poss�veis com uma struct, s�o o acesso aos membros
    // da struct, com o operador ponto (.); assim como, a opera��o de atribui��o ou c�pia;
    // na atribui��o de uma vari�vel do tipo struct para outra vari�vel do mesmo tipo struct
    // � a c�pia de capa componente da struct de origem, neste caso, o operando do lado direito
    // � copiado para o operando do lado esquerdo; campo a campo;
    {
        struct ponto {
            int x;
            int y;
        };

        struct novo_ponto {
            int x;
            int y;
        };

        struct ponto p1, p2 = {1, 2};
        struct novo_ponto p3 = {3, 4};

        // essa opera��o � realizada com sucesso; porque ambas as vari�veis ou operandos s�o
        // do mesmo tipo de struct;
        p1 = p2;

        printf("\n");
        printf("before - x: %d, y: %d\n", p1.x, p1.y);
        printf("before - x: %d, y: %d\n", p2.x, p2.y);

        p1 = p2;

        // mesmo alterando os valores do operando de origem da atribui��o, a altera��o
        // n�o � refletida na vari�vel de destino da atribui��o, que � a vari�vel p1;
        p2.x = 10;
        p2.y = 20;

        printf("\n");
        printf("after - x: %d, y: %d\n", p1.x, p1.y);
        printf("after - x: %d, y: %d\n", p2.x, p2.y);
    }

    // a seguir um exemplo sobre atribui��o de uma struct contida em um array;
    {
        struct ponto {
            int x;
            int y;
        };

        // essa � uma forma v�lida de inicializar struct dentro de um array;
        struct ponto pontos[2] = {
            { 10, 20 },
            { 30, 40 }
        };

        printf("\n");
        printf("before - x: %d, y: %d\n", pontos[0].x, pontos[0].y);
        printf("before - x: %d, y: %d\n", pontos[1].x, pontos[1].y);

        // essa opera��o de atribui��o entre duas posi��es (elementos), de um array
        // tamb�m � uma opera��o considerada v�lida porque os elementos possuem o
        // mesmo tipo;
        pontos[0] = pontos[1];

        printf("\n");
        printf("after - x: %d, y: %d\n", pontos[0].x, pontos[0].y);
        printf("after - x: %d, y: %d\n", pontos[1].x, pontos[1].y);
    }

    // estruturas aninhadas;
    // � permitido aninhar uma struct previamente definida dentro de outra struct;
    {
        struct endereco {
            char rua[50];
            int numero;
        };

        struct cadastro {
            char nome[50];
            int idade;
            struct endereco ender;
        };

        struct cadastro meu_cadastro;
    }

    return 0;
}
