#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double weight;
    double value;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    double r1 = ((Item *)a)->ratio;
    double r2 = ((Item *)b)->ratio;

    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

int knapsack(double value[], double weight[], int capacity, int n) {
    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].value = value[i];
        items[i].weight = weight[i];
        items[i].ratio = value[i] / weight[i];
    }
    
    qsort(items, n, sizeof(Item), compare);

    double totalValue = 0.0;

    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    return totalValue;
}

int main() {
    double val[] = {60.0, 100.0, 120.0};
    double wt[] = {10.0, 20.0, 30.0};
    double capacity = 50.0;
    int n = sizeof(val) / sizeof(val[0]);

    double maxValue = knapsack(val, wt, capacity, n);
    printf("%.2f", maxValue);
}
