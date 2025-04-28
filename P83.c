#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void fill_array(int *arr, int n, int type) {
    if (type == 0) { // Sorted
        for (int i = 0; i < n; i++) arr[i] = i;
    } else if (type == 1) { // Reversed
        for (int i = 0; i < n; i++) arr[i] = n - i;
    } else if (type == 2) { // All equal
        for (int i = 0; i < n; i++) arr[i] = 5;
    } else { // Random
        for (int i = 0; i < n; i++) arr[i] = rand() % 1000;
    }
}

void test_case(int type, const char *desc) {
    const int n = 100000;
    int *arr = malloc(n * sizeof(int));
    fill_array(arr, n, type);

    clock_t start = clock();
    qsort(arr, n, sizeof(int), compare);
    clock_t end = clock();

    printf("%s: %lf секунд\n", desc, (double)(end - start) / CLOCKS_PER_SEC);

    free(arr);
}

int main() {
    srand(time(NULL));
    test_case(0, "Впорядкований масив (зростання)");
    test_case(1, "Впорядкований масив (спадання)");
    test_case(2, "Масив з однаковими елементами");
    test_case(3, "Випадковий масив");
    return 0;
}
