/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0
 */

#include "shell.h"

int main(void)
{
	char command[200];

	for (;;)
	{
		display();
		read_input(command, sizeof(command));
		execute(command);
	}

	return (0);
}
