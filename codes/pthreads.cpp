#include <pthread.h>
#include <iostream>
using namespace std;
using Thread = pthread_t;

void * hello(void * tid){
    cout << "Greetings from thread " << tid << endl;
    pthread_exit(NULL);
}

int main(){
    Thread threads[10];
    for(int i = 0; i < 10; i++){
        cout << "Creating thread " << i << endl;
        int status = pthread_create(&threads[i], NULL, &hello, (void *) &i);
        if(status){
            cout << "Ops. pthread_create return error code " << status << endl;
            return -1;
        }
    }
    return 0;
}