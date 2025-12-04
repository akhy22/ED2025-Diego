#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    char linea[500];
    int arr[200];
    int n = 0;

    printf("Ingresa los elementos a ordenar separados por espacio:\n");

    // Leer la línea completa
    fgets(linea, sizeof(linea), stdin);

    char *token = strtok(linea, " ");
    while (token != NULL) {
        arr[n] = atoi(token);
        n++;
        token = strtok(NULL, " ");
    }

    printf("\nArreglo original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("\nArreglo ordenado con QuickSort:\n");
    printArray(arr, n);

    return 0;
}
