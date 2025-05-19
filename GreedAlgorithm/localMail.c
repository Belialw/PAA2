/*
    2) No correio local há somente selos de 3 e de 5 centavos. A taxa mínima para
    correspondência é de 8 centavos. Faça um programa que determina o menor
    número de selos de 3 e de 5 centavos que completam o valor de uma taxa dada.
*/

#include <stdio.h>

void findStamps(int tax) {
    if (tax < 8) {
        printf("Taxa mínima de 8 centávos.\n");
        return;
    }

    for (int qtdStamps5 = tax / 5; qtdStamps5 >= 0; qtdStamps5--) {
        int remaining = tax - (qtdStamps5 * 5);

        if (remaining % 3 == 0) {
            int qtdStamps3 = remaining / 3;
            printf("%d selo(s) de 5 centavos e %d selo(s) de 3 centavos\n", qtdStamps5, qtdStamps3);
            return;
        }
    }

    printf("Impossível encontrar uma solução para essa taxa.\n");
}

int main() {
    findStamps(11);
    return 0;
}