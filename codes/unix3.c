#include <stdio.h>
#include <unistd.h>

int main(){
    __pid_t idfilho;
    printf("Processo inicial possui pid: %d\n", getpid());
    idfilho = fork();
    if(idfilho == 0) printf("Este é o processo filho de pid: %d\n", getpid());
    else printf("Este é o processo pai e criou o processo filho: %d\n", idfilho);
    return 0;
    
}
