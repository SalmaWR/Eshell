#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point.
 *
 * @ac: arguments count.
 * @av: array of arguments passed to program.
 *
 * Return: 0 on success.
 */

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *line = NULL;
	char **tokens = NULL;
	int line_len;
	int terminal_active = isatty(STDIN_FILENO);

	while (terminal_active == 1)
	{
		write(STDOUT_FILENO, "($)", 3);

		line = shell_read_line();

		line_len = strlen(line);

		tokens = shell_split_line(line, line_len);

		if (tokens[0] != NULL)
		{
			shell_exec(tokens);
		}

		free(tokens);
		free(line);
	}

	return (0);
}
