#include <stdio.h>
#include <time.h>

int fatorial(int n) {
    if (n <= 1) return 1.0;
    return n * fatorial(n - 1);
}

int main() {
    int n = 5;
    clock_t start, end;
    double tempo;

    start = clock();
    int resultado = fatorial(n);
    end = clock();

    tempo = (double)(end - start) / CLOCKS_PER_SEC;

    printf("%d! = %d\n", n, resultado);  // %.0Lf imprime sem casas decimais
    printf("Tempo de execução: %.6f segundos\n", tempo);

    return 0;
}
