#include"shell.h"
#include<string.h>

char** shell_split_line(char *line, int line_len) 
{	
	char **Array_of_tokens = NULL;
	char *token = NULL;
	char *delimiters = " \t\r\n";
	int tokens_len = 0;
	char *line_cpy = NULL;

	line_cpy = malloc(sizeof(char) * line_len);

	if (!line_cpy)
		{
			perror("shell: Allocation error");
			return (NULL);
		}

	strcpy(line_cpy, line);

	Array_of_tokens = malloc(line_len * sizeof(char*));
	token = strtok(line_cpy, delimiters);

	while (token != NULL) 
	{
		Array_of_tokens[tokens_len] = token;
		
		++tokens_len;
		token = strtok(NULL, delimiters);

        

	}
	
	Array_of_tokens[tokens_len] = NULL;
	
	return(Array_of_tokens);
}