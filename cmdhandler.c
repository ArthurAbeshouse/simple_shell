#include "shell.h"

char **checkPaths(char **cmd)
{
  int envIn = 0, pathSize = 0, i = 0, found = 0;
  int cmdLen = 0;
  char **envBuffer = NULL;
  char *path = NULL;
  /*  char *wabu = NULL;*/

        cmdLen = _strlen(cmd[0]);

        while (environ[envIn] != NULL && found == 0)
        {
                /* Find paths, add paths to buffer */
	  /* strtok(environ) */
                if (environ[envIn][0] == 'P' && environ[envIn][1] == 'A' && environ[envIn][2] == 'T'
                                && environ[envIn][3] == 'H' && environ[envIn][4] == '=')
                {
		  
		  /*printf("env path -> [%s]\n", &environ[envIn][5]);*/
		  envBuffer = token(&environ[envIn][5], ":");
                        /* Paths copied, continue to checking */

                        i = 0;
                        while (envBuffer[i] != NULL)
                        {
			  pathSize = 0;
                          pathSize = _strlen(envBuffer[i]);
                          path = malloc(sizeof(char *) * (pathSize + cmdLen + 2));
			  if (path == NULL)
			    return (0);
			  /*			  wabu = malloc(sizeof(char *) * (pathSize + cmdLen + 2));
			  if (wabu == NULL)
			  return (0);*/
			  _strcpy(path, envBuffer[i]);
			  /*			  printf("%s Got here 1\n", path);*/
			  path = _strcat(path, "/");
			  /*		  printf("%s Got here 2\n", path);*/
			  path = _strcat(path, cmd[0]);
			  /*			  printf("path -> [%s]\n", path);*/
			  /*			  printf("%s Got here 3\n", path);*/
			  if (access(path, R_OK) != -1 && access(path, X_OK) != -1)
			    {
			      cmd[0] = path;
			      /*free(path);
			      free(wabu);*/
			      free(envBuffer);
			      envIn = 0;
			      /*			      printf("I got here\n");*/
			      return (cmd);
			    }
			  else
			    {
			      i++;
			      free(path);
			      /*			      printf("here I am envbuff for i=%d -> [%s]\n", i, envBuffer[i]);*/
			      /*   continue;*/
			    }
                        }
                }
		envIn++;
        }
	/*	free(path);*/
	/*	printf("it's broken\n");*/
	return (NULL);
}

int commandChecker(char **cmd)
{
  if (cmd[0] != NULL)
    {
      /*      if (spec(cmd) == 0)
	      return (1);*/
      if (checkPaths(cmd) != NULL)
	{
	  /*	  printf("found command\n");*/
	  _execute(cmd);
	}
      else
	{
	  _puts("\nCannot find command ");
	  _puts(cmd[0]);
	  _puts(".");
	  return (-1);
	}
    }
  return (-1);
}
