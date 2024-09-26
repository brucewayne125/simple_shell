#include "shell.h"

void shprint(const char *inputs)
{
	write(STDOUT_FILENO, inputs, strlen(inputs));
}
