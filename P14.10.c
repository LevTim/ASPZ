#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

void* alarm_thread(void* arg) {
    signal(SIGALRM, [](int sig) {
        write(STDOUT_FILENO, "[ALARM] tick\n", 13);
        alarm(1);
    });
    alarm(1);
    while (1) pause();
    return NULL;
}

void* setitimer_thread(void* arg) {
    signal(SIGVTALRM, [](int sig) {
        write(STDOUT_FILENO, "[ITIMER] tick\n", 14);
    });

    struct itimerval timer;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;
    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    while (1) pause();
    return NULL;
}

void* posix_timer_thread(void* arg) {
    struct sigaction sa = {0};
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = [](int sig, siginfo_t *si, void *uc) {
        write(STDOUT_FILENO, "[POSIX] tick\n", 13);
    };
    sigaction(SIGRTMIN, &sa, NULL);

    timer_t timerid;
    struct sigevent sev = {0};
    sev.sigev_notify = SIGEV_SIGNAL;
    sev.sigev_signo = SIGRTMIN;
    timer_create(CLOCK_REALTIME, &sev, &timerid);

    struct itimerspec its = {
        .it_value = {1, 0},
        .it_interval = {1, 0}
    };

    timer_settime(timerid, 0, &its, NULL);
    while (1) pause();
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, alarm_thread, NULL);
    sleep(1); 
    pthread_create(&t2, NULL, setitimer_thread, NULL);
    sleep(1);
    pthread_create(&t3, NULL, posix_timer_thread, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    return 0;
}
