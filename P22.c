#include <stdio.h>

void my_function() {
    int local_array[1000]; // Локальний масив
    int initialized_local_array[1000] = {0}; // Локальний масив з ініціалізатором
}

int main() {
    printf("Hello, World!\n");
    my_function();
    return 0;
}