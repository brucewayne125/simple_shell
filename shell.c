#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void prompt() {
    printf("($) ");
}

void execute_command(char *command) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[2];
	args[0] = command;
	args[1] = NULL;
        if (execve(command, args, NULL) == -1) {
            perror("./shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        wait(NULL);
    }
}

int main() {
    char *command = malloc(BUFFER_SIZE);
    if (!command) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    while (1) {
        prompt();
        if (fgets(command, BUFFER_SIZE, stdin) == NULL) {
            printf("\n");
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
