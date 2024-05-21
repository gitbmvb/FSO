#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMMAND_LEN 256
#define MAX_ERROR_LEN   256

int main() {
    char command[MAX_COMMAND_LEN];
    char error_message[MAX_ERROR_LEN] = "";
    
    printf("Enter a command to execute: ");
    
    if (fgets(command, sizeof(command), stdin) == NULL) {
        perror("Error reading command");
        return EXIT_FAILURE;
    }

    // Remove the newline character at the end of the command if it exists
    size_t len = strlen(command);
    if (len > 0 && command[len - 1] == '\n') {
        command[len - 1] = '\0';
    }

    // Start the clock
    clock_t start_time = clock();

    // Execute the command and capture its output
    FILE *cmd_output = popen(command, "r");
    int return_code = pclose(cmd_output);
    
    // End the clock
    clock_t end_time = clock();
    
    // Calculate the total execution time in seconds
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the execution time and return code
    printf("Execution time: %.6f seconds\n", total_time);
    printf("Return code: %d\n", return_code);

    // If the command failed, store the error message
    if (return_code != 0) {
        snprintf(error_message, sizeof(error_message), "Command failed with return code: %d", return_code);
    }

    // Print the error message if it's not empty
    if (strlen(error_message) > 0) {
        printf("Error message: %s\n", error_message);
    }

    return 0;
}
