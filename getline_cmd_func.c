#include "shell.h"

/**
 * getline_cmd - Print the shell prompt and wait for user input.
 *
 * Return: User input as a line of string.
 */
char *getline_cmd(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#cisfun$ ", 10);

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
