#include "shell.h"

/**
 * _strcat - append string src to dest string
 * @dest: string
 * @src: string
 *  Return: ponting to resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *result;

	result = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (result);
}

/**
 * _strlen - A function that returns the length of a string.
 * @s: An array od char
 * Return: the length of a string.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcmp - compare two strings
 * @s1: string
 * @s2: string
 * Return: 0 if equal
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}
