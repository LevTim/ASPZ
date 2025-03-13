#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/resource.h>
#include <signal.h>

#define COUNT_49 7 
#define COUNT_36 6 
#define CPU_LIMIT 2 // Ліміт часу ЦП в секундах

void handle_cpu_limit(int sig) {
    printf("\nЛіміт часу ЦП перевищено! Завершення програми.\n");
    exit(EXIT_FAILURE);
}

void set_cpu_limit() {
    struct rlimit rl;
    rl.rlim_cur = CPU_LIMIT;
    rl.rlim_max = CPU_LIMIT;
    if (setrlimit(RLIMIT_CPU, &rl) != 0) {
        perror("Не вдалося встановити обмеження часу ЦП");
        exit(EXIT_FAILURE);
    }
    signal(SIGXCPU, handle_cpu_limit);  // Обробка сигналу перевищення часу ЦП
}

int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int is_unique(int *numbers, int count, int num) {
    for (int i = 0; i < count; i++) {
        if (numbers[i] == num) {
            return 0;
        }
    }
    return 1;
}

void generate_numbers(int *numbers, int count, int max_value) {
    int generated = 0;
    while (generated < count) {
        int num = get_random_number(1, max_value);
        if (is_unique(numbers, generated, num)) {
            numbers[generated++] = num;
        }
    }
}

void print_numbers(int *numbers, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    // Встановлюємо обмеження на час ЦП
    set_cpu_limit();

    int numbers_49[COUNT_49];
    int numbers_36[COUNT_36];

    printf("Лотерея: 7 із 49 та 6 із 36\n");

    printf("Числа (7 із 49): ");
    generate_numbers(numbers_49, COUNT_49, 49);
    print_numbers(numbers_49, COUNT_49);

    printf("Числа (6 із 36): ");
    generate_numbers(numbers_36, COUNT_36, 36);
    print_numbers(numbers_36, COUNT_36);

    return 0;
}
