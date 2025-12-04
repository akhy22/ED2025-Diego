#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
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

    fgets(linea, sizeof(linea), stdin);

    char *token = strtok(linea, " ");
    while (token != NULL) {
        arr[n] = atoi(token);
        n++;
        token = strtok(NULL, " ");
    }

    printf("\nArreglo original:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("\nArreglo ordenado con Merge Sort:\n");
    printArray(arr, n);

    return 0;
}
