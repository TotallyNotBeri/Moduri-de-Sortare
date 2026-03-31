#include <stdio.h>

void cautaPereche(int arr[], int n, int suma_cautata) {
    int gasit = 0;

    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == suma_cautata) {
                printf("-> Am gasit perechea: %d + %d = %d\n", arr[i], arr[j], suma_cautata);
                gasit = 1;
            }
        }
    }

    
    if(gasit == 0) {
        printf("-> Nu exista nicio pereche in vector care sa dea suma %d.\n", suma_cautata);
    }
}

int main() {
    int vector[] = {10, 25, -4, 8, 14, 3, 7, 20};
    int n = 8;
    int suma;
    int continuare;

    printf("Vectorul nostru este: ");
    for(int i = 0; i < n; i++) printf("%d ", vector[i]);
    printf("\n\n");

    do {
        printf("Introdu o suma pe care vrei sa o cauti: ");
        scanf("%d", &suma);

        cautaPereche(vector, n, suma);

        printf("\nVrei sa cauti alta suma? (1 pentru DA, 0 pentru NU): ");
        scanf("%d", &continuare);
        printf("\n");

    } while (continuare == 1);

    printf("Program incheiat.\n");
    return 0;
}
