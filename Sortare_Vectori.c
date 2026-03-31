#include <stdio.h>

// Bubble Sort
void bubbleSort_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) { int temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp; }
}

void bubbleSort_double(double arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) { double temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp; }
}

void bubbleSort_char(char arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) { char temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp; }
}

// Selection Sort

void selectionSort_int(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) if (arr[j] < arr[min_idx]) min_idx = j;
        int temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
}

void selectionSort_double(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) if (arr[j] < arr[min_idx]) min_idx = j;
        double temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
}

void selectionSort_char(char arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) if (arr[j] < arr[min_idx]) min_idx = j;
        char temp = arr[min_idx]; arr[min_idx] = arr[i]; arr[i] = temp;
    }
}

// Insertion Sort
void insertionSort_int(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; int j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
        arr[j + 1] = key;
    }
}

void insertionSort_double(double arr[], int n) {
    for (int i = 1; i < n; i++) {
        double key = arr[i]; int j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
        arr[j + 1] = key;
    }
}

void insertionSort_char(char arr[], int n) {
    for (int i = 1; i < n; i++) {
        char key = arr[i]; int j = i - 1;
        while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
        arr[j + 1] = key;
    }
}

// Merge Sort
void merge_int(int arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) { if (L[i] <= R[j]) { arr[k] = L[i]; i++; } else { arr[k] = R[j]; j++; } k++; }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void mergeSort_int(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort_int(arr, l, m);
        mergeSort_int(arr, m + 1, r);
        merge_int(arr, l, m, r);
    }
}

// Quick Sort
int partition_int(int arr[], int low, int high) {
    int pivot = arr[high]; int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) { i++; int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
    return (i + 1);
}

void quickSort_int(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition_int(arr, low, high);
        quickSort_int(arr, low, pi - 1);
        quickSort_int(arr, pi + 1, high);
    }
}

//Functia de afisare
void printArray_int(int arr[], int n) {
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void printArray_double(double arr[], int n) {
    for(int i = 0; i < n; i++) printf("%.4f ", arr[i]);
    printf("\n");
}

void printArray_char(char arr[], int n) {
    for(int i = 0; i < n; i++) printf("'%c' ", arr[i]);
    printf("\n");
}

// Functii de a reseta codul la starea initiala.
void reset_a(int a[]) { int temp[] = {-47, 46, -91, -64, 100, 92, -20, 83, -12, 10}; for(int i=0; i<10; i++) a[i] = temp[i]; }
void reset_b(double b[]) { double temp[] = {90.675, -60.980, 86.10, 4.99, 30.2682854, -29.178584028, -86.58683, -51.1535, -76.40793, 32.169}; for(int i=0; i<10; i++) b[i] = temp[i]; }
void reset_c(char c[]) { char temp[] = {'C', 'Y', 'E', 'B', 'D', 'W', 'a', 'O', 's', 'Y'}; for(int i=0; i<10; i++) c[i] = temp[i]; }

int main() {
    int a[10]; double b[10]; char c[10];
    int n = 10;

    printf("=== Sortare Vector A (int) ===\n");
    reset_a(a); printf("Initial: "); printArray_int(a, n);
    bubbleSort_int(a, n); printf("Bubble:  "); printArray_int(a, n);

    reset_a(a); selectionSort_int(a, n); printf("Select:  "); printArray_int(a, n);
    reset_a(a); insertionSort_int(a, n); printf("Insert:  "); printArray_int(a, n);
    reset_a(a); mergeSort_int(a, 0, n - 1); printf("Merge:   "); printArray_int(a, n);
    reset_a(a); quickSort_int(a, 0, n - 1); printf("Quick:   "); printArray_int(a, n);

    printf("\n=== Sortare Vector B (double) ===\n");
    reset_b(b); printf("Initial: "); printArray_double(b, n);
    bubbleSort_double(b, n); printf("Bubble:  "); printArray_double(b, n);

    reset_b(b); selectionSort_double(b, n); printf("Select:  "); printArray_double(b, n);
    reset_b(b); insertionSort_double(b, n); printf("Insert:  "); printArray_double(b, n);
    // Pentru a rula Merge si Quick pe double, funcțiile se declară la fel ca cele de int, înlocuind 'int' cu 'double'

    printf("\n=== Sortare Vector C (char) ===\n");
    reset_c(c); printf("Initial: "); printArray_char(c, n);
    bubbleSort_char(c, n); printf("Bubble:  "); printArray_char(c, n);

    reset_c(c); selectionSort_char(c, n); printf("Select:  "); printArray_char(c, n);
    reset_c(c); insertionSort_char(c, n); printf("Insert:  "); printArray_char(c, n);

    return 0;
}