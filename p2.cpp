#include <stdio.h>
void bubbleSortDescending(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 30, 20, 50, 70, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSortDescending(arr, n);
    printf("Sorted array in descending order:\n");
    printArray(arr, n);
    return 0;
}
