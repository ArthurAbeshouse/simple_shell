#include "shell.h"

int spec(char *argv)
{

	if (_strcmp("exit", argv) == 0)
	{
		free(argv);
		exit(0);
	}

	if (_strcmp("env", argv) == 0)
	{
		_env();
	}
	return (0);
}
