#include <stdio.h>
#include <limits.h>

#define MAX 100000

void coinChange(int amount) {
    
    int values[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    int size = 12;
    int cents = (int)(amount * 100 + 0.5);

    int dp[MAX];
    int last[MAX];

    for (int i = 1; i < cents; i++) {
        dp[i] = INT_MAX;
        for (int j = 0; j < size; j++) {
            if (values[j] <= i && dp[i - values[j]] + 1 < dp[i]) {
                dp[i] = dp[i - values[j]] + 1;
                last[i] = j;
            }
        }
    }

    int qtd[12] = {0};
    int current = cents;

    while (current > 0) {
        int lastUsed = last[current];
        qtd[lastUsed]++;
        current -= values[lastUsed];
    }

    printf("Notas:\n");
    for (int i = 0; i < 6; i++)
        printf("%d nota(s) de R$ %.2f\n", qtd[i], values[i] / 100.0);
    
    for (int i = 6; i < 12; i++) {
        printf("%d moeda(s) de R$ %.2f\n", qtd[i], values[i] / 100.0);
    }
}
