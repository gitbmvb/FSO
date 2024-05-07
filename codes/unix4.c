#include <stdio.h>
#include <unistd.h>

int main(){
    char * arg[] = {"ls", "-la", NULL};
    __pid_t idfilho = fork();
    if(idfilho != 0)
        printf("Este é o processo pai e criou o processo filho: %d\n", idfilho);
    else{
        execvp("ls", arg);
        printf("Erro\n");
        return 1;
    }
    return 0;
}