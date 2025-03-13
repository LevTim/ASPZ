#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define FILE_NAME "dice_results.txt"
#define MAX_FILE_SIZE 1024  // Максимальний розмір файлу в байтах

int roll_dice() {
    return rand() % 6 + 1;
}

long get_file_size(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);
    return size;
}

void write_result(int result) {
    FILE *file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Помилка відкриття файлу");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Кидок: %d\n", result);
    fclose(file);
}

int main() {
    srand(time(NULL));
    printf("Імітація кидання шестигранного кубика. Натисніть Ctrl+C для завершення.\n");

    while (1) {
        if (get_file_size(FILE_NAME) >= MAX_FILE_SIZE) {
            printf("Файл '%s' досяг максимального розміру (%d байтів).\n", FILE_NAME, MAX_FILE_SIZE);
            exit(EXIT_SUCCESS);
        }

        int result = roll_dice();
        printf("Випало: %d\n", result);
        write_result(result);
        usleep(100000);  // Затримка 100 мс для зменшення навантаження на систему
    }

    return 0;
}
