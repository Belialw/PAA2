#include <stdio.h>
#include <time.h>

#define MAX 100

unsigned long long fatorial(int n) {
    if (n <= 1) return 1;
    return (unsigned long long) n * fatorial(n - 1);
}

unsigned long long memo[MAX];

unsigned long long fatorialMemo(int n) {
    if (n <= 1) return 1;
    if (memo[n] != 0) return memo[n];

    memo[n] = (unsigned long long) n * fatorialMemo(n-1);

    return memo[n];
}

int main() {
    int n = 30;
    clock_t start, end;
    double tempo;

    start = clock();
    unsigned long long resultado = fatorial(n);
    printf("%d! = %llu\n", n, resultado);
    resultado = fatorial(n-1);
    printf("%d! = %llu\n", n-1, resultado);
    resultado = fatorial(n-2);
    printf("%d! = %llu\n", n-2, resultado);
    resultado = fatorial(n-3);
    printf("%d! = %llu\n", n-3, resultado);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %.6f segundos\n", tempo);

    for(int i=0; i<MAX; i++) memo[i] = 0;

    start = clock();
    unsigned long long resultadoMemo = fatorialMemo(n);
    printf("%d! = %llu\n", n, resultadoMemo);
    resultadoMemo = fatorialMemo(n-1);
    printf("%d! = %llu\n", n-1, resultadoMemo);
    resultadoMemo = fatorialMemo(n-2);
    printf("%d! = %llu\n", n-2, resultadoMemo);
    resultadoMemo = fatorialMemo(n-3);
    printf("%d! = %llu\n", n-3, resultadoMemo);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Tempo de execução: %.6f segundos\n", tempo);

    return 0;
}
