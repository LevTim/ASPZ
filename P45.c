#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    // Виділяємо початкову пам’ять
    size_t size = 1024;
    void *ptr = malloc(size);

    if (ptr == NULL) {
        perror("Initial malloc failed");
        return EXIT_FAILURE;
    }

    printf("Initial allocation succeeded: %p\n", ptr);

    // Намагання виділити велику кількість пам'яті
    size_t new_size = (size_t)-1;  // Максимально можливий розмір
    void *new_ptr = realloc(ptr, new_size);

    if (new_ptr == NULL) {
        perror("realloc failed");
        printf("Original pointer is still valid: %p\n", ptr);
        // Звільняємо попередню пам’ять
        free(ptr);
    } else {
        printf("Reallocation succeeded: %p\n", new_ptr);
        // Звільняємо новий блок пам'яті
        free(new_ptr);
    }

    return EXIT_SUCCESS;
}
