#include "shell.h"

/**
 * _puts - Print a string
 * s: String to be printed
 *
 * Return: Nothing, function is void.
 */

void _puts(char *s)
{
	int i;

	for(i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}
