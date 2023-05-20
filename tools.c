#include "shell.h"
/**
 * _chpath - chose the path
 * @path_name: a pointer to the struct of data
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
char _chpath(char *path_name)
{
	char **environ_cursor, *env_ptr, *name_ptr;

	environ_cursor = environ;
	while (*environ_cursor)
	{
		env_ptr = *environ_cursor;
		name_ptr = path_name;
		while (*env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if ((*env_ptr == '=') && (*name_ptr == '\0'))
			return (env_ptr + 1);
		environ_cursor++;
	}
	return (NULL);
}
/**
 * signal_hlr - handle the process interrept signal
 * @signo: signal identity
 *
 * Return: void
 */
void signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		PRINT("\n");
		PRINT(PROMPT);
	}
}
/**
 * fill_array - fill array with elements
 * @a: the array
 * @el: the element
 * @len: length of an array
 *
 * Return: pointer to filled array
 */
void *fill_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}

/**
 * rev_array -  array reversed
 * @arr: the given array
 * @len: the array length
 *
 * Return: void
 */
void rev_array(char *arr, int len)
{
	int i;
	char tmp;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = arr[i];
		arr[i] = arr[(len - 1) - i];
		arr[(len - 1) - i] = tmp;
	}
}
/**
 * cmd_of_index - indexed command
 * @data: a pointer to the data structure
 *
 * Return: void
 */
void cmd_of_index(sh_t *data)
{
	data->index += 1;
}
