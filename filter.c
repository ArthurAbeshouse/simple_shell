#include "shell.h"

int checkExists(char *argv)
{
	const char *builtins[] = {"ls", "cd", "exit"}
	int i = 0;

	while (bultins[i])
	{
		if(_strcmp(builtins[i], argv) == 0)
		{
			printf("Found match at %d", i);
			return (i);
		}
	}

	return (-1);
}

int systemfunc(char *argv)
{
	const char *buffer = "/bin/";
	int result;

	_strcat(argv, buffer);
	result = access(buffer, F_OK);
	if (result == 0)
		printf("%s exists!", argv);
	else
		printf("Error! %s does not exist!", argv);
}
