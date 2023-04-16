#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *shell_read_line();
char **shell_split_line(char *line, int line_len);

#endif