#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <pid> <message>\n", argv[0]);
        return 1;
    }
    pid_t pid = atoi(argv[1]);
    int msg = atoi(argv[2]);

    union sigval val;
    val.sival_int = msg;

    if (sigqueue(pid, SIGRTMIN, val) == -1) {
        perror("sigqueue failed");
        return 1;
    }

    printf("Sent message %d to PID %d\n", msg, pid);
    return 0;
}
