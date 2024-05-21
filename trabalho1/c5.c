#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <sys/shm.h>

double get_time_in_seconds(struct timeval start, struct timeval end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
}

int main(void) {
    char command[256], args[256];
    pid_t pid = 1;
    struct timeval command_begin, command_end, prog_begin, prog_end;
    double total = 0;
    int erro;
    gettimeofday(&prog_begin, NULL);
    while(scanf("%s %s", command, args) != EOF) {
        fflush(stdout);
        pid = fork();
        gettimeofday(&command_begin, NULL);
        if (!pid) {
            execl(command, command, args, NULL);
            if (strerror(errno) != "Success") printf("> Erro: %s\n", strerror(errno));
            fflush(stdout);
            erro = errno;
            fclose(stdin);
            exit(errno);
        } else {
            wait(NULL);
            gettimeofday(&command_end, NULL);
            double time = (command_end.tv_sec - command_begin.tv_sec) + 1e-6 * (command_end.tv_usec - command_begin.tv_usec);
            printf("> Demorou %0.1lf segundos, retornou %i\n", time, WEXITSTATUS(erro));
            fflush(stdout);
            total += time;
        }
    }
    gettimeofday(&prog_end, NULL);
    if (pid) printf(">> O tempo total foi de %0.1lf segundos\n", total);
}