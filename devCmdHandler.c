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
	}
	return (1);
}

char checkPaths(char *cmd)
{
	int envIn = 0;
	char **envBuffer;

	while (environ[envIn] != NULL)
	{
		/* Ask about doing this junk correctly during PLH */

	}
}

int commandChecker(char *cmd)
{
	if (checkBuiltIns(cmd) == 1)
		return (1);
	if (checkPaths(cmd) != NULL)
		return (1);

	_puts("\n");
	_puts("Cannot find command ");
	_puts(cmd);
	_puts(".");
	return (-1);

}
