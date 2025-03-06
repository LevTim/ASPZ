#include <stdio.h>

void hello(); // Декларація функції з динамічної бібліотеки

int main() {
    printf("Calling the dynamic library function...\n");
    hello(); // Виклик функції з бібліотеки
    return 0;
}