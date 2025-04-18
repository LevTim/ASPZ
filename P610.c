#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *original = "This is a memory leak example.";
    
    char *leaked = strdup(original);

    if (leaked == NULL) {
        perror("strdup failed");
        return 1;
    }

    printf("Copied string: %s\n", leaked);

    // !!! Ми не викликаємо free(leaked), що створює витік пам’яті
    // free(leaked); // Закоментовано для симуляції витоку

    return 0;
}
