#include "shell.h"

void ctrl_c()
{
  write(STDOUT_FILENO, "\n$ ", 3); /*takes int from signal*/
}

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
