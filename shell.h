#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

void read_input(char *command, size_t size);
void execute(const char *command);
void shprint(const char *inputs);
void display(void);

#endif
