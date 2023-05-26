#include "shell.h"

/**
 * get_token - Get tokens from a string by splitting it.
 * @ptr_line: User command line
 * Return: Pointer to an array of tokens.
 */
char **get_token(char *ptr_line)
{
	char **user_cmd = NULL;
	char *token = NULL;
	size_t cnt = 0;
	size_t sz = 0;

	if (ptr_line == NULL)
		return (NULL);

	for (cnt = 0; ptr_line[cnt]; cnt++)
	{
		if (ptr_line[cnt] == ' ')
			sz++;
	}
	if ((sz + 1) == strlen(ptr_line))
		return (NULL);

	user_cmd = malloc(sizeof(char *) * (sz + 2));
	if (user_cmd == NULL)
		return (NULL);

	token = strtok(ptr_line, " \n\t\r");
	for (cnt = 0; token != NULL; cnt++)
	{
		user_cmd[cnt] = token;
		token = strtok(NULL, " \n\t\r");
	}
	user_cmd[cnt] = NULL;
	return (user_cmd);
}
