#include <bits/stdc++.h>
using namespace std;
#include <stdlib.h>
#include <sys/types.h>


int main(){
    FILE *fp;
    int status;
    char command[519], path[PATH_MAX];
    strcpy(command, "time ");
    fgets(&command[5], 514, stdin);
    
    fp = popen(command, "r");
    // while (fgets(path, PATH_MAX, fp) != NULL)
        // printf("%s", path);

    status = pclose(fp);
    if (status == -1) {
    
    } else {
    
    }
    
}