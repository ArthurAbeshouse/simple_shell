#include "shell.h"
/**
 * _strcpy - copy the given string
 * @dest: location of where the string is copied
 * @src: pointer to source of string to be copied
 * Return: return the value of dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
