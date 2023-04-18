#include "shell.h"

/**
 * shell_exec - Execute a command with the given arguments.
 *
 * @args: An array of arguments, including the command.
 */

void shell_exec(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0) /* Child process */
	{
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "%s: %d: %s:command not found\n", args[0], errno, args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0) /* Error forking */
	{
		perror("shell");
	}
	else /* Parent process */
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
}