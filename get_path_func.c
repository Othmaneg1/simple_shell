#include "shell.h"

/**
 * get_path - Get the value of the PATH environment variable.
 * @env: Local environment variables
 *
 * Return: Value of PATH on success, NULL otherwise.
 */
char *get_path(char **env)
{
	size_t index = 0;
	char *path = NULL;

	for (index = 0; env[index] != NULL; index++)
	{
		if (strncmp(env[index], "PATH=", 5) == 0)
		{
			path = strdup(env[index] + 5);
			break;
		}
	}

	return (path);
}
