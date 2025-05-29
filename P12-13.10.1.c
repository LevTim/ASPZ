#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void handler(int sig, siginfo_t *info, void *ctx) {
    printf(" Message received: signal=%d, from PID=%d, data=%d\n",
           sig, info->si_pid, info->si_value.sival_int);
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigaction(SIGRTMIN, &sa, NULL);

    printf("Receiver PID: %d\n", getpid());
    while (1) pause();
}
