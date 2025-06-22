#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int x;
    int max_y;
} XMaxY;

int compare(const void *a, const void *b) {
    return ((XMaxY *)b)->max_y - ((XMaxY *)a)->max_y;
}

int maxSumDistinctTriplet(int* x, int xSize, int* y, int ySize) {

    int max_x = 0;
    for (int i = 0; i < xSize; i++) {
        if (x[i] > max_x) {
            max_x = x[i];
        }
    }
    

    int *max_y_for_x = (int *)calloc(max_x + 1, sizeof(int));
    
    for (int i = 0; i < xSize; i++) {
        if (y[i] > max_y_for_x[x[i]]) {
            max_y_for_x[x[i]] = y[i];
        }
    }
    

    int distinct_count = 0;
    for (int i = 1; i <= max_x; i++) {
        if (max_y_for_x[i] > 0) {
            distinct_count++;
        }
    }
    
    if (distinct_count < 3) {
        free(max_y_for_x);
        return -1;
    }
    

    XMaxY *distincts = (XMaxY *)malloc(distinct_count * sizeof(XMaxY));
    int index = 0;
    for (int i = 1; i <= max_x; i++) {
        if (max_y_for_x[i] > 0) {
            distincts[index].x = i;
            distincts[index].max_y = max_y_for_x[i];
            index++;
        }
    }
    

    qsort(distincts, distinct_count, sizeof(XMaxY), compare);
    
    int sum = distincts[0].max_y + distincts[1].max_y + distincts[2].max_y;
    
    free(max_y_for_x);
    free(distincts);
    
    return sum;
}







int main() {
    int n;
    printf("Enter the size of arrays (n >= 3): ");
    scanf("%d", &n);
    
    if (n < 3) {
        printf("n must be at least 3\n");
        return 1;
    }
    
    int *x = (int *)malloc(n * sizeof(int));
    int *y = (int *)malloc(n * sizeof(int));
    
    printf("Enter %d elements for array x:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    
    printf("Enter %d elements for array y:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }
    
    int result = maxSumDistinctTriplet(x, n, y, n);
    printf("Output: %d\n", result);
    
    free(x);
    free(y);
    
    return 0;
}