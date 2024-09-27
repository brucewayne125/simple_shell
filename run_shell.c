#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void run_shell(void) {
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

        command[strcspn(command, "\n")] = 0;  /* Remove newline character */

        if (strlen(command) > 0) {
            execute_command(command);
        }
    }

    free(command);
}
