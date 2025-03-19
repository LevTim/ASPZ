#include <stdio.h>
#include <stdlib.h>

struct sbar {
    int a;
    int b;
};

int main() {
    struct sbar *ptr, *newptr;

    // Використовуємо reallocarray для перевиділення пам'яті
    ptr = calloc(1000, sizeof(struct sbar));  // Виділення пам'яті
    if (ptr == NULL) {
        perror("calloc failed");
        return EXIT_FAILURE;
    }

    // Перевиділення пам'яті з використанням reallocarray
    newptr = reallocarray(ptr, 500, sizeof(struct sbar));  // Використання reallocarray
    if (newptr == NULL) {
        perror("reallocarray failed");
        free(ptr);
        return EXIT_FAILURE;
    }

    // Звільняємо пам'ять після використання
    free(newptr);

    return 0;
}
