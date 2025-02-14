#include <stdio.h>

/**
    seção: recursão;
*/

// recursividade é o processo de repetir alguma coisa de maneira similar;
// uma função que tem essa característica é chamada de função recursiva;
int _08main() {
    return 0;
}

// função de cálculo de fatorial com uma implementação recursiva;
int fatorial_recursiva(int n) {
    // critério de parada;
    if (n == 0) {
        return 1;
    }

    // parâmetro do fatorial sempre muda;
    return n * fatorial_recursiva(n - 1);
}

// função de cálculo de fatorial com uma implementação não recursiva (iterativa);
int fatorial_iterativa(int n) {
    if (n == 0) {
        return 1;
    }

    int i, f = 1;
    for (i = 2; i <= n; i++) {
        f = f * i;
    }

    return f;
}

// função de cálculo da sequência de Fibonacci com uma implementação recursiva;
int fibonacci_recursiva(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacci_recursiva(n - 1) + fibonacci_recursiva(n - 2);
}

// função de cálculo da sequência de Fibonacci com uma implementação não recursiva (iterativa);
int fibonacci_iterativa(int n) {
    int i, c, a = 0, b = 1;
    for (i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}
