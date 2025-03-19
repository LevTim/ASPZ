#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa = 100000;
    int xb = 100000;
    int num = xa * xb;  

    printf("xa = %d, xb = %d\n", xa, xb);
    printf("num = %d\n", num);

    void *ptr = malloc(num);
    if (ptr == NULL) {
        perror("Malloc failed");
    } else {
        printf("Malloc succeeded\n");
        free(ptr);
    }

    return 0;
}
