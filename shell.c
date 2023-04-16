#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/*
 *
 *
 *@ac : arguments count
 *@av : array of arguments passed to program
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

		printf("spilt it baby:%s", tokens[2]);
		/*if (tokens[0] != NULL)
		{
			shell_exec(tokens);
		}

		free(tokens);
		free(line);*/
	}

	return (0);

}
