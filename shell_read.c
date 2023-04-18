#include"shell.h"
#include<stdio.h>

/**
 * shell_read_line - Read a line from stdin.
 *
 * Return: The line as a string.
 */

char* shell_read_line() 
{
    char *line = NULL;
    size_t buffer_len = 0;
	ssize_t characters_num = getline(&line, &buffer_len, stdin);
	
	while (characters_num == -1)
	{
		return (NULL);
	}
	
    return (line);
}