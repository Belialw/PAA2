#include <stdio.h>

int cutRodRecursive(int price[], int n) {
    if (n == 0) return 0;

    int max = -1;
    for (int i = 1; i <= n; i++) {
        int revenue = price[i - 1] + cutRodRecursive(price, n - i);
        if (revenue > max) max = revenue;
    }
    return max;
}

int memo[100];

int cutRodeTopDown(int price[], int n) {
    if (n == 0) return 0;

    if (memo[n] >= 0) return memo[n];

    int max = -1;
    for (int i = 1; i <= n; i++) {
        int revenue = price[i - 1] + cutRodeTopDown(price, n - i);
        if (revenue > max) max = revenue;
    }

    memo[n] = max;
    return max;
}

int cutRodBottomUp(int price[], int n) {
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int max = -1;
        for (int j = 1; j <= i; j++) {
            int revenue = price[j - 1] + dp[i - j];
            if (revenue > max) max = revenue;
        }
        dp[i] = max;
    }

    return dp[n];
}