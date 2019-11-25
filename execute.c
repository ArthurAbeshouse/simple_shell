#include "shell.h"

int _execute(char **argv)
{
  pid_t pid;
  int status;

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
      perror("chicken wing");
      exit(-1);
    }
  else
    {
      /*      printf("it don't work\n");*/
      wait(&status);
      /*      printf("why?\n");*/
    }
  return (pid);
}

