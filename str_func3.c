#include "shell.h"

/**
 * _strtok - tokenize a string by breaking it into tokens.
 * @str: string to tokenize.
 * @delim: string with the delimiter characters.
 * Return: the first/next token if possible, a null-pointer otherwise.
 **/
char *_strtok(char *str, const char *delim)
{
	static char *p;

	if (str)
		p = str;
	else if (!p)
		return (NULL);

	str = p + strspn(p, delim);
	p = str + strcspn(str, delim);

	if (*p)
		*p++ = '\0';
	else
		p = NULL;

	return (str);
}

/**
 * _strcspn - compute the length of the maximum initial segment of the string
 * pointed to by s1 which consists entirely of characters not from the
 * string pointed to by s2.
 * @s1: string to check.
 * @s2: string to compare.
 * Return: the length of the segment.
 **/
size_t _strcspn(char *s1, char *s2)
{
	size_t ret = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
			break;
		s1++;
		ret++;
	}

	return (ret);
}
