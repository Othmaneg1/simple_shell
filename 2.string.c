#include "shell.h"
/**
 * _srgcoy - copie a string to destination
 * @source: source of the string
 * @dest: destination of the string
 *
 * Return: the pointer to the destination
 */
char *_srgcoy(char *dest, char *source)
{
	int j;

	for (j = 0; source[j] != '\0'; j++)
	{
		dest[j] = source[j];
	}
	dest[j] = '\0';
	return (dest);
}
/**
 * _alpha - check the input if its a letter
 * @c: to check the charachter
 *
 * Return: 1 if letter, 0 if not
 */
int __alpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (SUCCESS);
	}
	return (FAIL);
}
