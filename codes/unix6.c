#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    pid_t idfilho;
    int status;
    printf("Processo inicial possui pid: %d\n", getpid());
    idfilho = fork();
    if(idfilho == 0){
        printf("Este é o processo (%d) filho de (%d)\n", getpid(), getppid());
        exit(0);
    }
    wait(NULL);
    printf("Este é o processo pai e o processo filho terminou\n");
    return 0;
}