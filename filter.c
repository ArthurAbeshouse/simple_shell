#include "shell.h"

/**
 * ctrl_c - handles ctrl + c and prints a new line
 * @n: recieves int from signal
 */

void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3); /*takes int from signal*/
}

/**
 * spec - determines what built-in function to run
 * @argv: Array of input
 * Return: returns 0 if successful, -1 if not
 */

int spec(char **argv)
{

	if (_strcmp("exit", argv[0]) == 0)
	{
		free(argv);
		exit(0);
	}
	else if (_strcmp("env", argv[0]) == 0)
		_env();
	else
		return (-1);
	return (0);
}
