#include "shell.h"

/**
 * _execute - execute the users command
 * @argv: user command
 * Return: pid
 */

int _execute(char **argv)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error");
			exit(-1);
		}
	}
	else if (pid < 0)
	{
		perror("Error");
		exit(-1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (pid);
}
