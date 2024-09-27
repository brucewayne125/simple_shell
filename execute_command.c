#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

void execute_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[BUFFER_SIZE];
        char *token;
        int index = 0;

        
        token = strtok(command, " ");
        while (token != NULL) {
            args[index++] = token;
            token = strtok(NULL, " ");
        }
        args[index] = NULL;

        if (execve(args[0], args, NULL) == -1) {
            char error_msg[BUFFER_SIZE];
            snprintf(error_msg, sizeof(error_msg), "./hsh: 1: %s: not found\n", args[0]);
            write(STDERR_FILENO, error_msg, strlen(error_msg));
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        const char *fork_error = "fork failed\n";
        write(STDERR_FILENO, fork_error, strlen(fork_error));
    } else {
        wait(NULL);
    }
}
