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

void change(double amount) {
    int cents = (int) round(amount*100);

    printf("Notas: \n");

    int notes[] = {10000, 5000, 2000, 1000, 500, 200};
    for (int i=0; i<6; i++) {
        int count = cents / notes[i];
        printf("%d nota(s) de R$ %.2f\n", count, notes[i] / 100.0);
        cents %= notes[i];
    }

    printf("Centavos: \n");
    int coins[] = {100, 50, 25, 10, 5, 1};
    for (int i=0; i<6; i++) {
        int count = cents / coins[i];
        printf("%d moeda(s) de R$ %.2f\n", count, coins[i] / 100.0);
        cents %= coins[i];
    }
}

int main() {
    double value = 576.73;
    change(value);
    return 0;
}
