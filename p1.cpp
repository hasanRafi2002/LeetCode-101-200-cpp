#include <stdio.h>
void bubbleSortAscending(char arr[], int n) {
    int i, j;
    char temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void printArray(char arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main() {
    char arr[] = {'g', 'd', 'f', 'e', 'c', 'b', 'a'};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSortAscending(arr, n);
    printf("Sorted characters in ascending order:\n");
    printArray(arr, n);

    return 0;
}
