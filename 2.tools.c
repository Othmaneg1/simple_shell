#include "shell.h"

/**
 * _ita - convert integer to array
 * @n: a given number
 *
 * Return: a pointer to the null terminated string
 */
char *_ita(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	len = intlen(n);
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	*s = '\0';
	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	array_rev(s, len);
	s[i + 1] = '\0';
	return (s);
}
/**
 * _atoi - converts character to integer
 * @c: a given character
 *
 * Return: an integer
 */
int _atoi(char *c)
{
	unsigned int val = 0;
	int sign = 1;

	if (c == NULL)
		return (0);
	while (*c)
	{
		if (*c == '-')
			sign *= (-1);
		else
			val = (val * 10) + (*c - '0');
		c++;
	}
	return (sign * val);
}

/**
 * lens - Determine the number of digit int integer
 * @num: the given number
 *
 * Return: the length of the integer
 */
int lens(int num)
{
	int len = 0;

	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}
/**
 * print_error -  error printer
 * @data: a data structure pointer
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int print_error(sh_t *data)
{
	char *idx = _itoa(data->index);

	PRINT("hsh: ");
	PRINT(idx);
	PRINT(": ");
	PRINT(data->args[0]);
	PRINT(": ");
	PRINT(data->error_msg);
	free(idx);
	return (0);
}

/**
 * write_his - prints error
 * @data: a data structure pointer
 *
 * Return: (Success) a positive number
 * ------- (Fail) a negative number
 */
int write_his(sh_t *data __attribute__((unused)))
{
	char *filename = "history";
	char *line_of_history = "this is a line of history";
	ssize_t fd, w;
	int len;

	if (!filename)
		return (-1);
	fd = open(filename, O_RDWR | O_APPEND);
	if (fd < 0)
		return (-1);
	if (line_of_history)
	{
		while (line_of_history[len])
			len++;
		w = write(fd, line_of_history, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
