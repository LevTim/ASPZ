#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <signal.h>

#define STACK_LIMIT 1024 * 1024  // Максимальний розмір стеку (1 МБ)

void handle_stack_overflow(int sig) {
    printf("\nПомилка: Переповнення стеку (SIGSEGV). Ліміт стеку перевищено!\n");
    exit(EXIT_FAILURE);
}

void set_stack_limit() {
    struct rlimit rl;
    rl.rlim_cur = STACK_LIMIT;
    rl.rlim_max = STACK_LIMIT;
    if (setrlimit(RLIMIT_STACK, &rl) != 0) {
        perror("Не вдалося встановити обмеження на розмір стеку");
        exit(EXIT_FAILURE);
    }
    signal(SIGSEGV, handle_stack_overflow);  
}

void recursive_function(int depth) {
    char buffer[1024];  
    printf("Глибина рекурсії: %d\n", depth);
    recursive_function(depth + 1);  
}

int main() {
    set_stack_limit();

    printf("Демонстрація обмеження розміру стеку.\n");
    printf("Ліміт розміру стеку встановлено на %d байтів.\n", STACK_LIMIT);

    recursive_function(1);

    return 0;
}
