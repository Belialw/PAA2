/*
    1) Leia um valor de ponto flutuante com duas casas decimais. Este valor representa
    um valor monetário. A seguir, calcule o menor número de notas e moedas
    possíveis no qual o valor pode ser decomposto. As notas consideradas são de
    100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10,
    0.05 e 0.01. O seu programa deve a relação de notas necessárias, por
    exemplo para o valor 576.73 teríamos:
    NOTAS:                         
    5 nota(s) de R$ 100.00
    1 nota(s) de R$ 50.00
    1 nota(s) de R$ 20.00
    0 nota(s) de R$ 10.00
    1 nota(s) de R$ 5.00
    0 nota(s) de R$ 2.00
    
    MOEDAS:
    1 moeda(s) de R$ 1.00
    1 moeda(s) de R$ 0.50
    0 moeda(s) de R$ 0.25
    2 moeda(s) de R$ 0.10
    0 moeda(s) de R$ 0.05
    3 moeda(s) de R$ 0.01
*/

#include <stdio.h>

#define MAX 100000
#define INF 999999

int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
int nCoins = 12;

int coinChange(double amount) {
    int cents = (int)(amount * 100 + 0.5);

    int dp[MAX], ultima[MAX];
    int usado[12] = {0};

    dp[0] = 0;
    for (int i = 1; i <= cents; i++) {
        dp[i] = INF;
        ultima[i] = -1;
    }

    for (int i = 1; i <= cents; i++) {
        for (int j = 0; j < nCoins; j++) {
            if (i >= coins[j] && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1;
                ultima[i] = coins[j];
            }
        }
    }

    int change = cents;
    while (change > 0) {
        int m = ultima[change];
        for (int i = 0; i < nCoins; i++) {
            if (coins[i] == m) {
                usado[i]++;
                break;
            }
        }

        change -= m;
    }

    // Imprime resultado
    printf("NOTAS:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d nota(s) de R$ %.2f\n", usado[i], coins[i] / 100.0);
    }

    printf("MOEDAS:\n");
    for (int i = 6; i < 12; i++) {
        printf("%d moeda(s) de R$ %.2f\n", usado[i], coins[i] / 100.0);
    }
}

int main() {
    double amount = 576.73;

    coinChange(amount);

    return 0;
}
