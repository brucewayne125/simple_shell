#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

void execute_command(char *command) {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
		return;
	}

	if (pid == 0) {
		if (execlp(command, command, (char *)NULL) == -1) {
			perror(command);
			exit(EXIT_FAILURE);
		}
	} else {
		wait(NULL);
	}
}

int main() {
	char command[BUFFER_SIZE];

	while (1) {
		printf("#cisfun$ ");
		if (fgets(command, BUFFER_SIZE, stdin) == NULL) {
			printf("\n");
			break;
		}

		command[strcspn(command, "\n")] = 0;

		if (strlen(command) == 0) {
			continue;
		}

		execute_command(command);
	}

	return 0;
}

