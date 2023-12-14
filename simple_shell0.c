/**
 * main - writes a string to a file
 * str - the string to be written into a file
 * sizeof(str) - 1 is used to calculate the size of the string
 * Return: it returns the value 0, which indicates
 *  successful termination of the program
 */

#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	char str[] = "Hello, world!\n";
	int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fd != -1)
	{
		write(fd, str, sizeof(str) - 1);
		close(fd);
	}
	return (0);
}

