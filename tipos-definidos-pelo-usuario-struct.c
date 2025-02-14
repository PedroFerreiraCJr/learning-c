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

    // a forma utilizada para fazer a inicialização de uma struct no momento da declaração
    // é através do operador chaves ({});
    // semelhante a inicialização de arrays, que também faz uso deste operador, a
    // inicialização de uma struct se faz como a seguir;
    {
        struct cadastro n = { "Pedro Junior", 32, "Av. Oeste", 551 };
        printf("nome: %s, idade: %d, rua: %s, numero: %d", n.nome, n.idade, n.rua, n.numero);
    }

    // também é possível utilizar declarar e usar um array de structs;
    {
        struct cadastro pessoas[2];

        // com o auxílio de um comando de repetição, é feita a leitura de cada valor
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

    // atribuição de estruturas (struct);
    // as únicas operações que são possíveis com uma struct, são o acesso aos membros
    // da struct, com o operador ponto (.); assim como, a operação de atribuição ou cópia;
    // na atribuição de uma variável do tipo struct para outra variável do mesmo tipo struct
    // é a cópia de capa componente da struct de origem, neste caso, o operando do lado direito
    // é copiado para o operando do lado esquerdo; campo a campo;
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

        // essa operação é realizada com sucesso; porque ambas as variáveis ou operandos são
        // do mesmo tipo de struct;
        p1 = p2;

        printf("\n");
        printf("before - x: %d, y: %d\n", p1.x, p1.y);
        printf("before - x: %d, y: %d\n", p2.x, p2.y);

        p1 = p2;

        // mesmo alterando os valores do operando de origem da atribuição, a alteração
        // não é refletida na variável de destino da atribuição, que é a variável p1;
        p2.x = 10;
        p2.y = 20;

        printf("\n");
        printf("after - x: %d, y: %d\n", p1.x, p1.y);
        printf("after - x: %d, y: %d\n", p2.x, p2.y);
    }

    // a seguir um exemplo sobre atribuição de uma struct contida em um array;
    {
        struct ponto {
            int x;
            int y;
        };

        // essa é uma forma válida de inicializar struct dentro de um array;
        struct ponto pontos[2] = {
            { 10, 20 },
            { 30, 40 }
        };

        printf("\n");
        printf("before - x: %d, y: %d\n", pontos[0].x, pontos[0].y);
        printf("before - x: %d, y: %d\n", pontos[1].x, pontos[1].y);

        // essa operação de atribuição entre duas posições (elementos), de um array
        // também é uma operação considerada válida porque os elementos possuem o
        // mesmo tipo;
        pontos[0] = pontos[1];

        printf("\n");
        printf("after - x: %d, y: %d\n", pontos[0].x, pontos[0].y);
        printf("after - x: %d, y: %d\n", pontos[1].x, pontos[1].y);
    }

    // estruturas aninhadas;
    // é permitido aninhar uma struct previamente definida dentro de outra struct;
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
