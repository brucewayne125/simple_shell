#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

void prompt(void);
void execute_command(char *command);
void run_shell(void);

#endif
