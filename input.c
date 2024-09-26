#include "shell.h"

void read_input(char *command, size_t size)
{
	if(fgets(command, size, stdin) == NULL)
	{
		if(feof(stdin))
		{
			shprint("\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			shprint("Reading error.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
}

