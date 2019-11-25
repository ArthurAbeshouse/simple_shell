#include "shell.h"
/**
 * _strcat - function that concatenates strings
 * @dest: destination for concatnation
 * @src: source of string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	for (j = 0; dest[j] != '\0'; ++j)
	  ;

	while (src[i] != '\0')
	{
		dest[j + i] = src[i];
		++i;
	}
	return (dest);
}
