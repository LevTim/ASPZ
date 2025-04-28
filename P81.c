#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd = open("testfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buffer[10000];
    memset(buffer, 'A', sizeof(buffer));

    ssize_t count = write(fd, buffer, sizeof(buffer));
    if (count != sizeof(buffer)) {
        printf("Записано тільки %zd байтів із %zu\n", count, sizeof(buffer));
    } else {
        printf("Записано всі байти\n");
    }

    close(fd);
    return 0;
}
