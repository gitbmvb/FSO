#include <signal.h>
#include <stdio.h>

int contador = 0;

void handler(int signal_number){
    contador++;
}

int main(){
    struct sigaction sa = {};
    sa.sa_handler = &handler;
    sigaction(SIGUSR1, &sa, NULL);
    printf("Pressione E para terminar a execução:\n");
    while(getchar() != 'E');
    printf("SIGUSR1 recebido %d vezes\n", contador);
    return 0;
}