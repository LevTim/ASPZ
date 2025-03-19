#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = NULL;

    // realloc з NULL (еквівалент malloc)
    ptr = realloc(NULL, 100);  // Виділяється новий блок пам'яті
    if (ptr != NULL) {
        printf("realloc(NULL, 100) succeeded: %p\n", ptr);
        free(ptr);
    } else {
        printf("realloc(NULL, 100) failed\n");
    }

    // realloc з розміром 0 (звільнення пам'яті)
    ptr = malloc(50);  // Спершу виділимо пам'ять
    if (ptr == NULL) {
        perror("Initial malloc failed");
        return EXIT_FAILURE;
    }

    printf("Initial malloc succeeded: %p\n", ptr);

    // Виклик realloc з розміром 0
    void *new_ptr = realloc(ptr, 0);  // Має повернути NULL або валідний вказівник
    if (new_ptr == NULL) {
        printf("realloc(ptr, 0) returned NULL (memory freed)\n");
    } else {
        printf("realloc(ptr, 0) returned a valid pointer: %p (memory possibly freed)\n", new_ptr);
        free(new_ptr);
    }

    return EXIT_SUCCESS;
}
