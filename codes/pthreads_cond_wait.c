#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define numthreads 4
#define threadcount 200

pthread_mutex_t count_mutex =  PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t count_cond = PTHREAD_COND_INITIALIZER;

int count = numthreads * threadcount;

void * thread_func(void * arg){
    for(int i = 0; i < threadcount; i++){
        pthread_mutex_lock(&count_mutex);
        count--;
        pthread_cond_signal(&count_cond);
        pthread_mutex_unlock(&count_mutex);
    }
    return NULL;
}

int main(void){
        pthread_t threads[numthreads];
        for(int i = 0; i < numthreads; i++){
            int ret = pthread_create(&threads[i], NULL, &thread_func, NULL);
            printf("Creating thread %d\n", i);
            if(ret){
                printf("Error %d on thread %d\n", ret, i);
                perror("pthread_create");
                exit(-1);
            }
        }
        pthread_mutex_lock(&count_mutex);
        printf("main: beginning %d\n", count);
        while(count > 0){
            pthread_cond_wait(&count_cond, &count_mutex);
            printf("main: count is %d\n", count);
        }
        printf("bye %d\n", count);
        pthread_mutex_unlock(&count_mutex);
        pthread_exit(NULL);
}

/* 
     * pthread_cond_wait bloqueia aguardando uma condição
     * É necessário obter o mutex antes de bloquear.
     * A thread libera o mutex e aguarda a condição atomicamente.
     * Comportamento indefinido se não tiver o lock do mutex
     * Utilizar apenas um mutex por condição
*/