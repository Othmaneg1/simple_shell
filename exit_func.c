#include "shell.h"

/**
 * ext_func - function that exit from shell
 * @argv: array of char
 * @ptr_line: pointer
 * @ext: exit status
 *
 * Return: void
 */
void ext_func(char **argv, char *ptr_line, int ext)
{
	int ext_stat = 0;

	if (argv[1] == NULL)
	{
		free(ptr_line);
		free(argv);
		exit(ext);
	}

	ext_stat = atoi(argv[1]);
	free(ptr_line);
	free(argv);
	exit(ext_stat);
}

/**
 * get_envi - function that get an enviroment
 * @env: array of char
 *
 * Return: void
 */
void get_envi(char **env)
{
	size_t index = 0;

	while (env[index] != NULL)
	{
		write(STDOUT_FILENO, env[index], strlen(env[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}
