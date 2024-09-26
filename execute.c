#include "shell.h"

void execute(const char *command)
{
	pid_t ch_pid = fork();

	if (ch_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (ch_pid == 0)
	{
		execlp(command, command,(char *) NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
	
}
