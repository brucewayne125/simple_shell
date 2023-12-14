#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("Failed to fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if(execlp(command, command, NULL) == -1)
		{
			perror("Failed to execute the command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

int main()
{
	char command[100];
	char *line = NULL;
	size_t line_length = 0;
	ssize_t read_length;

	while(1)
	{
		write(STDOUT_FILENO, "($)", 4 );
		fflush(stdout);

		read_length = getline(&line, &line_length, stdin);
		if(read_length == -1)
		{
			if(feof(stdin))
			{
				break;
			}
			else
			{
				perror("Can't read the input");
				exit(EXIT_FAILURE);
			}
		}

		line[strcspn(line, "\n")] = '\0';
		strcpy(command, line);
		execute_command(line);
	}
	free(line);
	return 0;
}
