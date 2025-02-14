#include <stdio.h>

/**
    se��o: recurs�o;
*/

// recursividade � o processo de repetir alguma coisa de maneira similar;
// uma fun��o que tem essa caracter�stica � chamada de fun��o recursiva;
int _08main() {
    return 0;
}

// fun��o de c�lculo de fatorial com uma implementa��o recursiva;
int fatorial_recursiva(int n) {
    // crit�rio de parada;
    if (n == 0) {
        return 1;
    }

    // par�metro do fatorial sempre muda;
    return n * fatorial_recursiva(n - 1);
}

// fun��o de c�lculo de fatorial com uma implementa��o n�o recursiva (iterativa);
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

// fun��o de c�lculo da sequ�ncia de Fibonacci com uma implementa��o recursiva;
int fibonacci_recursiva(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacci_recursiva(n - 1) + fibonacci_recursiva(n - 2);
}

// fun��o de c�lculo da sequ�ncia de Fibonacci com uma implementa��o n�o recursiva (iterativa);
int fibonacci_iterativa(int n) {
    int i, c, a = 0, b = 1;
    for (i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return a;
}
