#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memo[1000][1000];

int lisTopDown(int seq[], int n, int prev_index, int current_index) {
    if (current_index == n) return 0;

    if (memo[prev_index + 1][current_index] != -1) 
        return memo[prev_index + 1][current_index];

    int exclude = lisTopDown(seq, n, prev_index, current_index + 1);

    int include = 0;
    if (prev_index == -1 || seq[current_index] > seq[prev_index]) 
        include = 1 + lisTopDown(seq, n, current_index, current_index + 1);

    memo[prev_index + 1][current_index] = (include > exclude) ? include : exclude;
    return memo[prev_index + 1][current_index];
}

int lisBottomUp(int seq[], int n) {
    int lis[n];
    for (int i = 0; i < n; i++)
        lis[i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (seq[i] > seq[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    
    int max = 0;
    for (int i = 0; i < n; i++)
        if (lis[i] > max) max = lis[i];

    return max;
}

int lisRecursive(int arr[], int n, int prev, int curr) {
    if (curr == n) return 0;

    int exclude = lisRecursive(arr, n, prev, curr + 1);
    int include = 0;
    if (prev == -1 || arr[curr] > arr[prev])
        include = 1 + lisRecursive(arr, n, curr, curr + 1);
    
    return (include > exclude) ? include : exclude;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(memo, -1, sizeof(memo));
    printf("LIS Top-Down = %d\n", lisTopDown(arr, n, -1, 0));
    printf("LIS Bottom-Up = %d\n", lisBottomUp(arr, n));
    printf("LIS Recursive = %d", lisRecursive(arr, n, -1, 0));
    return 0;
}