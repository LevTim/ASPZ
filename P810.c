#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 100000  // розмір масиву

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void fill_array(int *arr, int n, int type) {
    if (type == 0) { // Впорядкований за зростанням
        for (int i = 0; i < n; i++) arr[i] = i;
    } else if (type == 1) { // Впорядкований за спаданням
        for (int i = 0; i < n; i++) arr[i] = n - i;
    } else if (type == 2) { // Всі однакові елементи
        for (int i = 0; i < n; i++) arr[i] = 42;
    } else if (type == 3) { // Випадкові дані
        for (int i = 0; i < n; i++) arr[i] = rand() % 100000;
    }
}

double measure_qsort_time(int *arr, int n) {
    clock_t start, end;
    start = clock();
    qsort(arr, n, sizeof(int), compare);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    const char *cases[] = {
        "Впорядкований за зростанням",
        "Впорядкований за спаданням",
        "Всі елементи однакові",
        "Випадкові дані"
    };

    printf("| %-30s | %-20s |\n", "Тип масиву", "Час виконання (сек)");
    printf("|%s|%s|\n", "--------------------------------|----------------------");

    for (int i = 0; i < 4; i++) {
        int *arr = malloc(SIZE * sizeof(int));
        if (!arr) {
            perror("malloc");
            return 1;
        }
        fill_array(arr, SIZE, i);

        double time_taken = measure_qsort_time(arr, SIZE);
        printf("| %-30s | %-20.6f |\n", cases[i], time_taken);

        free(arr);
    }

    return 0;
}
