#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void handler(int signal_number){}

int main(void){
    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);
    pause();
    if(fork() == 0)
        exit(0);
    pause();
    wait(0);
    pause();
}