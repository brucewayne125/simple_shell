/**
 * shprint - Prints a string to standard output.
 *
 * @inputs: the string to be printed.
 *
 * Description: This function writes the given string to the (STDOUT).
 *
 * Return: Nothing.
 */

#include "shell.h"

void shprint(const char *inputs)
{
	write(STDOUT_FILENO, inputs, strlen(inputs));
}
