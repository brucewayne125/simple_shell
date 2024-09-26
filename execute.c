/**
 * execute - Executes a command in a child process.
 *
 * @command: The command to be executed
 */

#include "shell.h"

void execute(const char *command)
{
	pid_t ch_pid = fork();

	if (ch_pid == -1)
	{
		shprint("Forking error");
		exit(EXIT_FAILURE);
	}
	else if (ch_pid == 0)
	{
		char *args[200];
		int arg_count = 0;
		char *tocken = strtok((char *)command, " ");

		while (tocken != NULL)
		{
			args[arg_count++] = tocken;
			tocken = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execvp(args[0], args);

		shprint("Execution error.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
