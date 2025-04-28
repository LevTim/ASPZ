#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("datafile.bin", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    unsigned char buffer[4];
    lseek(fd, 3, SEEK_SET);
    read(fd, buffer, 4);

    printf("Прочитані байти: %d %d %d %d\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    close(fd);
    return 0;
}
