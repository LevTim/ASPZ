#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    size_t max_size = (size_t)-1;
    void *ptr;

    printf("Max value of size_t: %zu bytes\n", max_size);

    ptr = malloc(max_size);
    if (ptr == NULL) {
        perror("Malloc failed");
    } else {
        printf("Malloc succeeded\n");
        free(ptr);
    }

    return 0;
}
