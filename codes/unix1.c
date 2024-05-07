#include <stdio.h>
#include <unistd.h>

int main(){
    __pid_t mypid = getpid();
    printf("Pid of current process: %d\n", mypid);
    __pid_t parentpid = getppid();
    printf("Pid of parent process: %d\n", parentpid);
    return 0;
}