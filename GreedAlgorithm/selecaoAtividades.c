#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} Activity;

int compare(const void *a, const void *b) {
    Activity *actA = (Activity *)a;
    Activity *actB = (Activity *)b;
    return actA->finish - actB->finish;
}

void selecionarAtividades(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), compare);

    printf("Atividades selecionadas: \n");
    int last_finish = activities[0].finish;
    printf("(%d,%d)\n", activities[0].start, activities[0].finish);
    
    for (int i=1; i<n; i++) {
        if (activities[i].start >= last_finish) {
            printf("(%d,%d)\n", activities[i].start, activities[i].finish);
            last_finish = activities[i].finish;
        }
    }
}

int main() {
    Activity activities[] = {{7,9},{5,6},{4,9},{1,2},{3,7},{6,8},{2,5},{1,3},{1,4}};

    int n = sizeof(activities) / sizeof(activities[0]);
    selecionarAtividades(activities, n);

    return 0;
}
