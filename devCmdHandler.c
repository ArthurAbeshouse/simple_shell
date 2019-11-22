#include "shell.h"

/**
 *
 *
 *
 *
 */

int checkBuiltIns(char *cmd)
{
	int found = 0, index = 0;
	char *commands[4];

	commands[0] = "exit";
	commands[1] = "help";
	commands[2] = "cd";
	commands[3] = "env";

	while (commands[index] != NULL)
	{
		if (_strcmp(cmd, commands[index]) == 1)
		{
			found = 1; /* Sudo bool to true */
			break;
		}
		index++;
	}

	if (found == 1)
	{
		switch (index)
		{
			case 0:
				/* Run exit */
				break;
			case 1:
				/* Run help */
				break;
			case 2:
				/* Run cd */
				break;
			case 3:
				/* Run env */
				break;
			default:
				return (0);
				break;
		}
		return (1);
	}
	return (0);
}

char checkPaths(char *cmd)
{
	int envIn = 0, pathSize = 0, i = 0;
	int cmdLen = 0;
	char **envBuffer;
	char *delim = ':';
	char *path;

	cmdLen = _strlen(cmd);

	while (environ[envIn] != NULL)
	{
		/* Find paths, add paths to buffer */
		if (environ[envIn][0] == 'P' && environ[envIn][1] == 'A' && environ[envIn][2] == 'T'
				&& environ[envIn][3] == 'H' && environ[envIn][4] == '=')
		{
			envBuffer = token(environ[envIn][5]);

			/* Paths copied, continue to checking */

			i = 0;
			pathSize = _strlen(envBuffer[0]);
			path = malloc(sizeof(char *) * (pathSize + cmdLen + 1));
			while (envBuffer[i] != NULL)
			{
				pathSize = 0;
				pathSize = _strlen(cmd);
				path = _realloc(path, , (sizeof(char *) * (pathSize + cmdLen + 1)));

			}
		}	

	}
}

int commandChecker(char *cmd)
{
	if (checkBuiltIns(cmd) == 1)
		return (1);
	if (checkPaths(cmd) != NULL)
		return (1);

	_puts("\nCannot find command ");
	_puts(cmd);
	_puts(".");
	return (-1);

}
