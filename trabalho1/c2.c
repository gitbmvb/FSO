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
    char command[512], buffer[512];
    struct timeval start, end;
    double total_elapsed_time = 0, elapsed_time;
    int ret;
    while(fgets(command, 512, stdin)){
        snprintf(buffer, sizeof(buffer), "%s", command);
        gettimeofday(&start, NULL);
        ret = system(command);
        gettimeofday(&end, NULL);
        if(ret){
            printf("> Erro: %s\n", strerror(errno));
        }
        elapsed_time = get_time_in_seconds(start, end);
        total_elapsed_time += elapsed_time;
        printf("> Demorou %.1f segundos, retornou %d\n", elapsed_time, WEXITSTATUS(errno));
    }
    printf(">> O tempo total foi de %.1f segundos\n", total_elapsed_time);
}
