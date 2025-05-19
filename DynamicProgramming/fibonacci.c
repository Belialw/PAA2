#include <stdio.h>
#include <time.h>

#define MAX 1000
int memo[MAX];

int fibonacci(int n) {
    if (n == 0 || n == 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib(n - 1) + fib(n - 2);
    return memo[n];
}

int main() {
    int n = 50;  // Use 40 ou mais para perceber diferença real de tempo
    clock_t start, end;
    double tempo;

    // --- Recursiva pura ---
    start = clock();
    int resultado1 = fibonacci(n);
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Recursiva pura:\n");
    printf("Resultado = %d\n", resultado1);
    printf("Tempo = %.6f segundos\n\n", tempo);

    // Inicializa o memo com -1 para memoization
    for (int i = 0; i < MAX; i++) {
        memo[i] = -1;
    }

    // --- Recursiva com memoization ---
    start = clock();
    int resultado2 = fib(n);
    end = clock();
    tempo = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Recursiva com memoization:\n");
    printf("Resultado = %d\n", resultado2);
    printf("Tempo = %.6f segundos\n", tempo);

    return 0;
}
