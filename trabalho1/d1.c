#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int count = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
struct thread_arg {
    int vezes;
};

void * thread_func(void *arg){
    struct thread_arg * ptr = arg;
    for(int i = 0 ; i < ptr->vezes; i++){
        pthread_mutex_lock(&mut);
        int id = count++;
        pthread_mutex_unlock(&mut);
        work(id);
    }
    pthread_exit(NULL);
    return NULL;
}