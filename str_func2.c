#include "shell.h"

/**
 * _strcpy - copy a string from source to destination.
 * @dest: pointer to the destination string.
 * @src: pointer to the source string.
 * Return: pointer to the destination string.
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return (dest);
}

/**
 * _strncmp - compare two strings up to a specified number of characters.
 * @s1: first string.
 * @s2: second string.
 * @n: number of characters to compare.
 * Return: the difference between the strings.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return ((int)(s1[i] - s2[i]));

		if (s1[i] == '\0')
			return (0);
	}

	return (0);
}
