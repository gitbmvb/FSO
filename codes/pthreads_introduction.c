#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10

struct thread_arg {
    int num;
};

void * thread_func(void *arg){
    struct thread_arg * ctx = arg;
    printf("Hello world from %d\n", ctx->num);
    pthread_exit(NULL);
}

int main(void){
    int ret, i;
    pthread_t threads[N];
    struct thread_arg args[N];
    for(int i = 0; i < N; i++) args[i].num = i;
    for(i = 0; i < N; i++){
        printf("Creating %d\n", i);
        // int pthread_create(
        //             pthread_t *restrict thread, 
        //             const pthread_attr_t *restrict attr,
        //             void *(*start_routine)(void *),
        //             void *restrict arg
        // );
        ret = pthread_create(&threads[i], NULL, &thread_func, &args[i]);
        if(ret){
            printf("Error %d on thread %d\n", ret, i);
            perror("pthread_create");
            exit(-1);
        }
    }
    for(i = 0; i < N; i++){
        // int pthread_join(pthread_t thread, void **retval);
        // Se retval != NULL, recebe o valor retornado pela thread
        ret = pthread_join(threads[i], NULL);
        if(ret){
            printf("Error waiting thread %d\n", i);
            perror("pthread_join");
            exit(-1);
        }
    }
    return 0;
    // pthread_exit(NULL);
}