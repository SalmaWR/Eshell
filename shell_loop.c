#include "shell.h"

void shell_loop(void)
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

}
