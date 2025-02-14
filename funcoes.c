#include <stdio.h>

/**
* capítulo: funções
*/

// declaração do protótipo de função;
int square(int n);

// declaração do protótipo de função, que omite o nome dos parâmetros;
int square2(int);

// as declarações de protótipos de função abaixo, são consideradas as mesmas;
// apenas existe essa variação, podendo colocar ou não a palavra-chave void
// dentro dos delimitadores de parâmetro, quando a função não declara
// nenhum parâmetro; ou seja, essa função não recebe nenhum argumento;
void imprimir();
void imprimir(void);

int _06main() {

    {
        void imprimir() {
            printf("function that do not have 'void' declared in the parameter list.\n");
        };

        // o compilador não irá verificar se no momento da invocação da
        // função imprimir, foi passado argumentos para a função; pois neste
        // caso, não foi fornecido a palavra-chave void, dentro do delimitador
        // da lista de parâmetros;
        imprimir(14);
    }

    {
        void imprimir(void) {
            printf("function that have 'void' declared in the parameter list.\n");
        };

        // neste outro caso de declaração da função imprimir, o compilador
        // irá verificar se no momento da invocação da função imprimir, foi
        // passado algum argumento para a função; pois neste caso, foi fornecido
        // a palavra-chave 'void', na declaração da lista de parâmetros;
        // desta forma, caso seja passado algum argumento para a invocação da
        // função imprimir(void), irá ser apresentado pelo compilador uma mensagem
        // de erro de compilação;
        // a linha abaixo não compila, por isso está comentada;
        //imprimir(14);
        imprimir();
    }

    return 0;
}

// definição da implementação do protótipo de função declarado acima;
int square(int n) {
    return n * n;
}

int square2(int n) {
    return n * n;
}

// a declaração de parâmetros de função deve ocorrer dentro dos limites
// definidos pelos parênteses; cada parâmetro deve ter um tipo e nome;
// cada declaração de parâmetro deve ser separada por uma virgula;
int somar(int x, int y) {
    return x + y;
}
