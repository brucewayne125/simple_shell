#include "shell.h"
#include <unistd.h>
#include <string.h>

void prompt(void) {
    const char *prompt_str = "($) ";
    write(STDOUT_FILENO, prompt_str, strlen(prompt_str));
}
