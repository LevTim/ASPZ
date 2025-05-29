#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    write(STDOUT_FILENO, "ALARM\n", 6);
    alarm(1);  
}

int main() {
    signal(SIGALRM, handler);
    alarm(1);  
    while (1) pause();
}
