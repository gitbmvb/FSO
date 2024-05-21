// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>
// #include <errno.h>

// int main(void){
//     clock_t start, end;
//     double total = 0, cpu_time_used;
//     FILE * fp;
//     char command[512];
//     int ret;
//     while(fgets(command, 512, stdin)){

//         start = clock();
//         ret = system(command);
//         end = clock();
//         cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//         total += cpu_time_used;
//         if(ret == -1){
//             printf("> Erro: %s\n", strerror(3));
//         } else {
//             printf("> Demorou %f segundos, retornou %d\n", cpu_time_used, ret);
//         }
//     }
//     printf(">> O tempo total foi de %f segundos\n", total);
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main() {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    double real_time, user_time, sys_time;

    // Construct the command to be executed with 'time'
    snprintf(command, sizeof(command), "/usr/bin/time -f '%%e %%U %%S' your_command_here 2>&1", NULL);

    // Open the command for reading
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Error opening pipe");
        return -1;
    }

    // Read the output of the command
    printf("Command output:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Print the output
        printf("%s", buffer);

        // Parse the timing information from the 'time' command output
        if (sscanf(buffer, "%lf %lf %lf", &real_time, &user_time, &sys_time) == 3) {
            // Timing information found
            break;
        }
    }

    // Close the pipe and get the return status
    int ret = pclose(fp);
    if (ret == -1) {
        perror("Error closing pipe");
        return -1;
    }

    // Output the execution time
    printf("Real time: %f seconds\n", real_time);
    printf("User time: %f seconds\n", user_time);
    printf("System time: %f seconds\n", sys_time);

    // Return the command's return value
    return WEXITSTATUS(ret);
}

