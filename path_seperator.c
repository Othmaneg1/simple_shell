#include "shell.h"

/**
 * path_sepetator - separate the path into new strings.
 * @arg: command input from the user.
 * @env: environment variables.
 * Return: pointer to strings.
 */
int path_sepetator(char **arg, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);

	path_rela = get_path(env);
	if (!path_rela)
		return (-1);
	token = strtok(path_rela, ":");
	command = strlen(*arg);
	while (token)
	{
		value_path = strlen(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}

		path_absol = strcpy(path_absol, token);
		strcat(path_absol, "/");
		strcat(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}

		free(path_absol);
		token = strtok(NULL, ":");
	}

	free(path_rela);
	return (-1);
}
