#include "shell.h"

/**
 * _strcount - counts the number of words
 * @buf: input from token
 * Return: an integer
 */

int _strcount(char *buf)
{
	int j, i = 0;

	for (j = 0; buf[j] != '\0'; ++j)
	{
		if ((buf[j] != ' ' && buf[j + 1] != ' ') || buf[j + 1] != '\0')
			++i;
	}
	return (j);
}
