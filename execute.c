#include "shell.h"

char *checkPaths(char *cmd)
{
        int envIn = 0, pathSize = 0, i = 0;
        int cmdLen = 0;
        char **envBuffer;
        char *path;

        cmdLen = _strlen(cmd);

        while (environ[envIn] != NULL)
        {
                /* Find paths, add paths to buffer */
                if (environ[envIn][0] == 'P' && environ[envIn][1] == 'A' && environ[envIn][2] == 'T'
                                && environ[envIn][3] == 'H' && environ[envIn][4] == '=')
                {
                        envBuffer = token(&environ[envIn][5], ":");

                        /* Paths copied, continue to checking */

                        i = 0;
                        /*pathSize = _strlen(envBuffer[0]);*/
                        /*path = malloc(sizeof(char *) * (pathSize + cmdLen + 1));*/
                        while (envBuffer[i] != NULL)
                        {
                                pathSize = 0;
                                pathSize = _strlen(cmd);
                                path = _realloc(path, sizeof(char *) * _strlen(path), sizeof(char *) * (pathSize + cmdLen + 1));
                                _strcpy(path, envBuffer[i]);
                                path = _strcat(path, cmd);
				if (access(path, R_OK) != -1 && access(path, X_OK) != -1)
				    _puts_recursion(path);
                        }
                }

        }
	return (path);
}

int commandChecker(char *cmd)
{
        if (spec(cmd) == 1)
                return (1);
        if (checkPaths(cmd) != NULL)
                return (1);

        _puts_recursion("\nCannot find command ");
        _puts_recursion(cmd);
        _puts_recursion(".");
        return (-1);
}
