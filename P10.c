#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

void print_limit(const char *resource_name, int resource_type) {
    struct rlimit rl;
    if (getrlimit(resource_type, &rl) == 0) {
        printf("%s: Soft limit = %ld, Hard limit = %ld\n", resource_name, rl.rlim_cur, rl.rlim_max);
    } else {
        perror("getrlimit failed");
    }
}

void set_limit(int resource_type, rlim_t new_limit) {
    struct rlimit rl;
    if (getrlimit(resource_type, &rl) == 0) {
        rl.rlim_cur = new_limit;
        if (setrlimit(resource_type, &rl) == 0) {
            printf("Set new limit for resource %d to %ld\n", resource_type, new_limit);
        } else {
            perror("setrlimit failed");
        }
    }
}

int main() {
    // Тестуємо обмеження для кількості відкритих файлів
    print_limit("Open files", RLIMIT_NOFILE);
    
    // Тестуємо обмеження на розмір процесу (у байтах)
    print_limit("Process size", RLIMIT_AS);
    
    // Тестуємо обмеження на розмір стека
    print_limit("Stack size", RLIMIT_STACK);
    
    // Тестуємо обмеження на максимальний час процесора
    print_limit("CPU time", RLIMIT_CPU);
    
    // Тестуємо обмеження на кількість процесів
    print_limit("Number of processes", RLIMIT_NPROC);
    
    // Зміна ліміту для кількості відкритих файлів
    printf("\nЗмінюємо ліміт для відкритих файлів на 3000...\n");
    set_limit(RLIMIT_NOFILE, 3000);

    // Зміна ліміту для розміру стека
    printf("\nЗмінюємо ліміт для стека на 8192...\n");
    set_limit(RLIMIT_STACK, 8192);

    // Перевіряємо ліміти після змін
    print_limit("Open files", RLIMIT_NOFILE);
    print_limit("Stack size", RLIMIT_STACK);

    return 0;
}
