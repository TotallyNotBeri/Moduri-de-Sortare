#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 1. Bubble Sort

void bubbleSort_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


// 2 Selection Sort

void selectionSort_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


// 3 Insertion Sort

void insertionSort_int(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


// 4. Merge Sort

void merge_int(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;


    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));


    if (L == NULL || R == NULL) {
        printf("Eroare memorie...\n");
        return;
    }

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }

    // Eliberam memoria locala
    free(L);
    free(R);
}

void mergeSort_int(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort_int(arr, l, m);
        mergeSort_int(arr, m + 1, r);
        merge_int(arr, l, m, r);
    }
}


// 5 Quick Sort

int partition_int(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1; // Assignment unit

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort_int(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_int(arr, low, high);
        quickSort_int(arr, low, pi - 1);
        quickSort_int(arr, pi + 1, high);
    }
}


void copiazaVector(int sursa[], int destinatie[], int n) {
    for(int i = 0; i < n; i++) {
        destinatie[i] = sursa[i];
    }
}


int main() {
    int n = 30000;

    int *arr = (int*)malloc(n * sizeof(int));
    int *testArr = (int*)malloc(n * sizeof(int));

    // 1. REZOLVARE EROARE POINTER NULL IN MAIN
    if (arr == NULL || testArr == NULL) {
        printf("Eroare critica: Nu s-a putut aloca memoria!\n");
        return 1; // Oprim programul cu cod de eroare
    }

    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
    }

    printf("Generam un vector cu %d de numere aleatoare...\n", n);
    printf("Incepem testarea...\n\n");


    clock_t start = clock();
    copiazaVector(arr, testArr, n);
    bubbleSort_int(testArr, n);
    clock_t end = clock();
    double timp_executie = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("1. Bubble Sort:    %f secunde\n", timp_executie);

    copiazaVector(arr, testArr, n);
    start = clock();
    selectionSort_int(testArr, n);
    end = clock();
    timp_executie = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("2. Selection Sort: %f secunde\n", timp_executie);

    copiazaVector(arr, testArr, n);
    start = clock();
    insertionSort_int(testArr, n);
    end = clock();
    timp_executie = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("3. Insertion Sort: %f secunde\n", timp_executie);

    copiazaVector(arr, testArr, n);
    start = clock();
    mergeSort_int(testArr, 0, n - 1);
    end = clock();
    timp_executie = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("4. Merge Sort:     %f secunde\n", timp_executie);

    copiazaVector(arr, testArr, n);
    start = clock();
    quickSort_int(testArr, 0, n - 1);
    end = clock();
    timp_executie = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("5. Quick Sort:     %f secunde\n", timp_executie);

    free(arr);
    free(testArr);

    printf("\nTest incheiat cu succes!\n");
    return 0;
}