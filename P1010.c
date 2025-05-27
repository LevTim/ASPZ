#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 0; i < 5; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            exit(1);
        } else if (pid == 0) {
            printf("Child %d with PID %d started\n", i, getpid());
            sleep(1);  // симуляція роботи
            printf("Child %d with PID %d finished\n", i, getpid());
            exit(0);
        } else {
            wait(NULL);
        }
    }

    printf("Parent process finished\n");
    return 0;
}
