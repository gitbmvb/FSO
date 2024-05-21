#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <time.h> 
#include <unistd.h>

double get_time_in_seconds(struct timeval start, struct timeval end) {
    return (double)(end.tv_sec - start.tv_sec) + (double)(end.tv_usec - start.tv_usec) / 1000000.0;
}

int main(void) {
    char command[512], arg[512];
    struct timeval start, end;
    double total = 0, time;
    int ret;
    while(scanf("%s %s", command, arg) != EOF){
        gettimeofday(&start, NULL);
        if(!fork()){
            execl(command, command, arg, NULL);
            printf("> Erro: %s\n", strerror(errno));
            ret = errno;
            exit(errno);
        }
        wait(&ret);
        gettimeofday(&end, NULL);
        time += get_time_in_seconds(start, end);
        printf("> Demorou %.1f segundos, retornou %d\n", time, WEXITSTATUS(ret));
        total += time;
    }
    printf(">> O tempo total foi de %.1f segundos\n", total);
}
