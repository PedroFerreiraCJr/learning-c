#include <stdio.h>

/**
* cap�tulo: fun��es
*/

// declara��o do prot�tipo de fun��o;
int square(int n);

// declara��o do prot�tipo de fun��o, que omite o nome dos par�metros;
int square2(int);

// as declara��es de prot�tipos de fun��o abaixo, s�o consideradas as mesmas;
// apenas existe essa varia��o, podendo colocar ou n�o a palavra-chave void
// dentro dos delimitadores de par�metro, quando a fun��o n�o declara
// nenhum par�metro; ou seja, essa fun��o n�o recebe nenhum argumento;
void imprimir();
void imprimir(void);

int _06main() {

    {
        void imprimir() {
            printf("function that do not have 'void' declared in the parameter list.\n");
        };

        // o compilador n�o ir� verificar se no momento da invoca��o da
        // fun��o imprimir, foi passado argumentos para a fun��o; pois neste
        // caso, n�o foi fornecido a palavra-chave void, dentro do delimitador
        // da lista de par�metros;
        imprimir(14);
    }

    {
        void imprimir(void) {
            printf("function that have 'void' declared in the parameter list.\n");
        };

        // neste outro caso de declara��o da fun��o imprimir, o compilador
        // ir� verificar se no momento da invoca��o da fun��o imprimir, foi
        // passado algum argumento para a fun��o; pois neste caso, foi fornecido
        // a palavra-chave 'void', na declara��o da lista de par�metros;
        // desta forma, caso seja passado algum argumento para a invoca��o da
        // fun��o imprimir(void), ir� ser apresentado pelo compilador uma mensagem
        // de erro de compila��o;
        // a linha abaixo n�o compila, por isso est� comentada;
        //imprimir(14);
        imprimir();
    }

    return 0;
}

// defini��o da implementa��o do prot�tipo de fun��o declarado acima;
int square(int n) {
    return n * n;
}

int square2(int n) {
    return n * n;
}

// a declara��o de par�metros de fun��o deve ocorrer dentro dos limites
// definidos pelos par�nteses; cada par�metro deve ter um tipo e nome;
// cada declara��o de par�metro deve ser separada por uma virgula;
int somar(int x, int y) {
    return x + y;
}
