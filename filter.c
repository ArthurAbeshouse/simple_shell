#include "shell.h"

int spec(char *argv)
{

	if (_strcmp("exit", argv))
		exit(0);

	return (0);

	/*int i;

	filter_t type[] = {
		{"exit", shell_exit},
		{NULL, NULL}
	};

	for (i = 0; type[i].op != NULL; i++)
	{
		if (spec == *type[i].op)
			return (type[i].f);
	}
	return (NULL); */
}
