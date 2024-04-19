#include <stdio.h>
#include <pthread.h>
#define Thread pthread_t

void * computation(void * add){
    long * add_num = (long *) (add);
    long sum = 0;
    for(long i = 0; i < 1000000000; i++)
        sum += *add_num;
    printf("Add is %ld!\n", *add_num);
    return NULL;
}

int main(void){
    Thread thread1, thread2;
    long value1 = 1, value2 = 2;
    // computation((void*) &value1);
    // computation((void*) &value2);
    pthread_create(&thread1, NULL, computation, (void*) &value1);
    pthread_create(&thread2, NULL, computation, (void*) &value2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}