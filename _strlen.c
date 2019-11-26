#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @s: String
 *
 * Return: Length of string
 */

int _strlen(char *s)
{
	int length = 0;

	while (s[length++] != '\0')
		;

	return (length - 1);
}
