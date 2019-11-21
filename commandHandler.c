#include "shell.h"


/**
*
*
*
*
*
*
*
*/

char *reference(char *cmd)
{
	char *path;
	unsigned int len = 0;

	len =_strlen(cmd);
	path = malloc(sizeof(char *) * (len + 6));

	_strcpy(path, "/bin/");
	path = _strcat(path, cmd);

	return (path);
}

char *cmdHandler(char *cmd)
{
	int bITest = builtIn(cmd);
	if (bITest != -1)
	{
		builtIn(bITest);
		return(1);
	}

	/* Not found as a built-in, check PATH locations */

}

/**
*
*
* Return: -1 on error, 
* 1 if found in /bin/
* 2 if found in /usr/local/sbin/
*/

int sysCmd(char *cmd)
{
	char *path;
	unsigned int len = _strlen(cmd);

	path = malloc(sizeof(char *) * (len + 6));
	if (!path)
	{
		return (-1);
	}
	path = _strcpy(path, "/bin/");
	path = _strcat(path, cmd);

	if (access(path, F_OK))
	{
		if (access(path, X_OK));
			return (1);
		else
		{
			_puts("\n");
			_puts(cmd);
			_puts(" found in /bin/:: Permission denied.");
			return (-1);
		}
	}
}

int builtIn(char *cmd)
{
	char *prebuilts[] = {"exit", "env"};
	int i;

	while(i = 0; prebuilts[i] != NULL; i++)
	{
		if (_strcmp(prebuilts[i], cmd) == 0)
			return (i); /* Found match, return index */
	}

	return (-1); /* No match found, return -1 */
}

int execBI(int index)
{
	
}
