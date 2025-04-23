#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_FD 1024

int main() {
    printf("Відкриті файлові дескриптори цього процесу:\n");
    printf("%-5s %-10s %-s\n", "FD", "Тип", "Опис");

    for (int fd = 0; fd < MAX_FD; ++fd) {
        struct stat st;
        if (fstat(fd, &st) == 0) {
            char type[32] = "Невідомо";
            if (S_ISREG(st.st_mode)) strcpy(type, "Звич. файл");
            else if (S_ISDIR(st.st_mode)) strcpy(type, "Каталог");
            else if (S_ISCHR(st.st_mode)) strcpy(type, "Символ. пристрій");
            else if (S_ISBLK(st.st_mode)) strcpy(type, "Блоч. пристрій");
            else if (S_ISFIFO(st.st_mode)) strcpy(type, "FIFO");
            else if (S_ISSOCK(st.st_mode)) strcpy(type, "Сокет");

            char path[1024];
            snprintf(path, sizeof(path), "/dev/fd/%d", fd);
            char real_path[1024];
            ssize_t len = readlink(path, real_path, sizeof(real_path)-1);
            if (len != -1) {
                real_path[len] = '\0';
            } else {
                strcpy(real_path, "невідомо");
            }

            printf("%-5d %-10s %-s\n", fd, type, real_path);
        }
    }
    return 0;
}
