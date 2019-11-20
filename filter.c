#include "shell.h"

int spec(char *argv)
{

	if (_strcmp("exit", argv) == 0)
	{
		free(argv);
		exit(0);
	}

	return (0);
}
