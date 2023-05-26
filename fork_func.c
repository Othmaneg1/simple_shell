#include "shell.h"

/**
 * fork_func - function that creates a fork
 * @arg: array of char
 * @av: program name
 * @envi: environment vars
 * @ptr_line: uset command line
 * @pidd: Process ID
 * @checker: Checker
 *
 * Return: 0 always success
 */
int fork_func(char *arg[], char *av[], char *envi[], char *ptr_line,
		int pidd, int checker)
{
	pid_t child;
	int st;
	char *fmt = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(arg[0], arg, envi) == -1)
		{
			fprintf(stderr, fmt, av[0], pidd, arg[0]);
			if (!checker)
				free(arg[0]);
			free(arg);
			free(ptr_line);
			exit(errno);
		}
	}
	else
	{
		wait(&st);

		if (WIFEXITED(st) && WEXITSTATUS(st) != 0)
			return (WEXITSTATUS(st));
	}

	return (0);
}
