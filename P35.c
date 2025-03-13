#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_SIZE 1048576  // Максимальний розмір файлу (1 МБ)

void set_file_size_limit() {
    struct rlimit rl;
    rl.rlim_cur = MAX_FILE_SIZE;
    rl.rlim_max = MAX_FILE_SIZE;
    if (setrlimit(RLIMIT_FSIZE, &rl) != 0) {
        perror("Не вдалося встановити обмеження на розмір файлу");
        exit(EXIT_FAILURE);
    }
}

void copy_file(const char *src, const char *dst) {
    FILE *source, *destination;
    char buffer[BUFFER_SIZE];
    size_t bytes;

    source = fopen(src, "rb");
    if (source == NULL) {
        fprintf(stderr, "Cannot open file %s for reading: %s\n", src, strerror(errno));
        exit(EXIT_FAILURE);
    }

    destination = fopen(dst, "wb");
    if (destination == NULL) {
        fprintf(stderr, "Cannot open file %s for writing: %s\n", dst, strerror(errno));
        fclose(source);
        exit(EXIT_FAILURE);
    }

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, source)) > 0) {
        if (fwrite(buffer, 1, bytes, destination) != bytes) {
            fprintf(stderr, "Помилка запису у файл %s: %s\n", dst, strerror(errno));
            fclose(source);
            fclose(destination);
            exit(EXIT_FAILURE);
        }
    }

    fclose(source);
    fclose(destination);

    printf("Копіювання завершено успішно!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Program need two arguments\n");
        exit(EXIT_FAILURE);
    }

    set_file_size_limit();

    copy_file(argv[1], argv[2]);

    return 0;
}
