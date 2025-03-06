#include <stdio.h>

int global_var; // Глобальна змінна

void large_stack_function() {
    int large_array[10000]; // Великий локальний масив
    printf("Address of large array in stack: %p\n", (void*)&large_array);
}

int main() {
    int i;
    int local_var; // Локальна змінна

    printf("The stack top is near %p\n", (void*)&i);
    printf("Address of global variable: %p\n", (void*)&global_var);
    printf("Address of local variable: %p\n", (void*)&local_var);
    
    large_stack_function(); // Виклик функції з великим масивом

    return 0;
}