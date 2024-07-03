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

int main(void) {
    char command[256], args[256];
    pid_t pid = 1;
    struct timeval tick, tack, begin, end;
    double total = 0;
    int erro;
    gettimeofday(&begin, NULL);
    while (scanf("%s %s", command, args) != EOF) {
        fflush(stdout);
        pid = fork();
        gettimeofday(&tick, NULL);
        if (pid == 0) {
            execl(command, command, args, NULL);
            if (strerror(errno) != "Success") printf("> Erro: %s\n", strerror(errno));
            fflush(stdout);
            erro = errno;
            fclose(stdin);
            exit(errno);
        } else {
            waitpid(pid, &erro, WUNTRACED);
            gettimeofday(&tack, NULL);
            double elapsed_time = (tack.tv_sec - tick.tv_sec) + 1e-6 * (tack.tv_usec - tick.tv_usec);
            printf("> Demorou %0.1lf segundos, retornou %i\n", elapsed_time, WEXITSTATUS(erro));
            fflush(stdout);
            total += elapsed_time;
        }
    }
    gettimeofday(&end, NULL);
    if (pid != 0) printf(">> O tempo total foi de %0.1lf segundos\n", total);
}