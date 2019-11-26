#include "shell.h"

int cy(char *toCheck)
{
	if (toCheck[0] == 'P' && toCheck[1] == 'A')
	{
		if (toCheck[2] == 'T' && toCheck[3] == 'H')
		{
			if (toCheck[4] == '=')
			{
				return (0);
			}
		}
	}
	return (-1);
}
char **checkPaths(char **cmd)
{
	int eI = 0, pS = 0, i = 0, found = 0, cL = 0;
	char **envBuff = NULL;
	char *path = NULL;

	cL = _strlen(cmd[0]);
	while (environ[eI] != NULL && found == 0)
	{
		if (cy(environ[eI]) == 0)
		{
			found = 1;
			envBuff = token(&environ[eI][5], ":");
			i = 0;
			while (envBuff[i] != NULL)
			{
				pS = 0;
				pS = _strlen(envBuff[i]);
				path = malloc(sizeof(char *) * (pS + cL + 2));
				if (path == NULL)
					return (0);
				_strcpy(path, envBuff[i]);
				path = _strcat(path, "/");
				path = _strcat(path, cmd[0]);
				if (access(path, R_OK) != -1)
				{
					if (access(path, X_OK) != -1)
					{
						cmd[0] = path;
						free(envBuff);
						eI = 0;
						return (cmd);
					}

				}
				else
				{
					i++;
					free(path);
				}
			}
		}
		eI++;
	}
	return (NULL);
}

int commandChecker(char **cmd)
{
	if (cmd[0] != NULL)
	{
		if (checkPaths(cmd) != NULL)
		{
			_execute(cmd);
		}
		else
		{
			_puts("\nCannot find command ");
			_puts(cmd[0]);
			return (-1);
		}
	}
	return (-1);
}
