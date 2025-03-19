#include <stdio.h>
#include <stdlib.h>

int main() {
    int i = 0;

    while (i < 5) {
        void *ptr = malloc(100);  // Виділяємо пам'ять на кожній ітерації
        if (ptr == NULL) {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }

        // Використання пам'яті
        printf("Iteration %d: Using pointer %p\n", i, ptr);

        // Звільнення пам'яті
        free(ptr);
        i++;
    }

    return 0;
}
