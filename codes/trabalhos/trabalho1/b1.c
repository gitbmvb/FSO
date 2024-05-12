#include <signal.h>
#include <stdio.h>

int contador = 0;

void handler(int signal_number){
    contador++;
}

int main(){
    struct sigaction sa = {};
    sa.sa_handler = &handler;
    sigaction (SIGUSR1, &sa, NULL);
    printf("Press E to exit:\n");
    while(getchar() != 'E');
    printf("SIGUSR1 received %d times\n", contador);
    return 0;
}