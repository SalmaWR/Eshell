#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "shell.h"
#define MAX_ARGS 10

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *prompt = "(Eshell) $";
	char *commandptr = NULL;
	char *commandcpy = NULL;
	size_t n = 0;
	ssize_t char_num = 0;
	int token_num = 0;
	char *token = NULL;
	char *delim = " ";
	char *args[MAX_ARGS + 1];
	int i = 0, j = 0;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, prompt, 11);
		char_num = getline(&commandptr, &n, stdin);

		if (char_num == -1)
			return (-1);

		commandcpy = malloc(sizeof(char) * char_num);

		if (!commandcpy)
		{
			perror("shell: Allocation error");
			return (-1);
		}

		strcpy(commandcpy, commandptr);

		token = strtok(commandptr, delim);

		while (token != NULL)
		{
			args[token_num++] = strdup(token);

			if (token_num >= MAX_ARGS)
			{
				printf("Too many arguments. Maximum is %d.\n", MAX_ARGS);
				break;
			}

			token = strtok(NULL, delim);
		}

		args[token_num] = NULL;

			if (token_num > 0)
			{
				pid_t pid = fork();

				if (pid < 0)
				{
					perror("shell: Fork error");
				}
				else if (pid == 0)
				{
					execvp(args[0], args);
					perror("shell: Execution error");
					_exit(EXIT_FAILURE);
				}
				else
				{
					wait(&status);
				}
			}

			free(commandcpy);
			for (i = 0; i < token_num; i++)
				free(args[i]);

			token_num = 0;
	}

/*av = malloc(sizeof(char *) * token_num);

token = strtok(commandptr, delim);

for (i = 0; token != NULL; i++)
{
	av[i] = malloc(sizeof(char) * strlen(token));
	strcpy(av[i], token);
	printf("%s", token);
	token = strtok(NULL, delim);
	printf("%s", token);
}

av[i] = NULL;
}*/

return (0);
}
