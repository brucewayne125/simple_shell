#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void prompt() {
    const char *prompt_str = "($) ";
    write(STDOUT_FILENO, prompt_str, strlen(prompt_str));
}

void execute_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[2];
        args[0] = command;
        args[1] = NULL;
        if (execve(command, args, NULL) == -1) {
            const char *error_msg = "./shell: No such file or directory\n";
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

int main() {
    char *command = malloc(BUFFER_SIZE);
    if (!command) {
        const char *malloc_error = "malloc failed\n";
        write(STDERR_FILENO, malloc_error, strlen(malloc_error));
        exit(EXIT_FAILURE);
    }

    while (1) {
        prompt();
        if (fgets(command, BUFFER_SIZE, stdin) == NULL) {
            write(STDOUT_FILENO, "\n", 1);
            free(command);
            exit(EXIT_SUCCESS);
        }

        command[strcspn(command, "\n")] = 0;

        if (strlen(command) > 0) {
            execute_command(command);
        }
    }

    free(command);
    return 0;
}
