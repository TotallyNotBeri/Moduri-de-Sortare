#include <stdio.h>

//Structura alergator
typedef struct {
    char nume[50];
    double timp;
} Alergator;

int main() {
    // Initializam lista formata
    Alergator lista[10] = {
        {"George", 10.22},
        {"Ana", 8.75},
        {"Mihai", 9.15},
        {"Elena", 11.02},
        {"Radu", 8.90},
        {"Ioana", 9.45},
        {"Alex", 10.05},
        {"Maria", 9.80},
        {"Vlad", 8.60},
        {"Cristi", 10.50}
    };
    int n = 10;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j].timp > lista[j + 1].timp) {

                Alergator temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }


    printf("=== CLASAMENT FINALA ===\n");
    for (int i = 0; i < n; i++) {
        printf("Locul %d: %s\n", i + 1, lista[i].nume);
    }

    return 0;
}