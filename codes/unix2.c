#include <stdlib.h>

int main(){
    /*System irá criar um subprocesso de shell (bin/sh)
    que irá efetuar a execução do comando*/
    return system("ls -la");
}