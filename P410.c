#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = malloc(100 * sizeof(int));  // Виділення пам'яті
    if (arr == NULL) {
        perror("malloc failed");
        return EXIT_FAILURE;
    }
    
    // Використовуємо пам'ять
    arr[0] = 42;

    // Перевиділяємо пам'ять
    arr = realloc(arr, 200 * sizeof(int));

    // Звільняємо пам'ять
    free(arr);
    return 0;
}
