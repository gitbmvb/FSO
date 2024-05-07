#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define N 2
#define loops 1000 * 1000

static int count = 0 ;
static pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

void * thread_func(void * arg){
    for(int i =0 ; i < loops; i++){
        pthread_mutex_lock(&my_mutex);
        count++;
        pthread_mutex_unlock(&my_mutex);
    }
    return NULL;
}

int main(void){
    pthread_t threads[N];
    for(int i = 0; i < N; i++){
        int ret = pthread_create(&threads[i], NULL, &thread_func, NULL);
        if(ret){
            printf("Error %d on thread %d\n", ret, i);
            perror("pthread_create");
            exit(-1);
        }
    }
    while(count < N * loops)
        printf("count %d/%d\n", count, N * loops);
    return 0;
}