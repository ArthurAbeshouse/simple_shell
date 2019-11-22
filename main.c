#include "shell.h"
/**
 *
 */

static char **savedEnvironment;

int loop(void)
{
  char *buff;
  size_t buff_size = 1024, read_count;
  char **args = NULL;
  /*int exec;*/

  while(1)
    {
      signal(SIGINT, ctrl_c); /* Ctrl C sends a SIGINT*/
      buff = malloc(sizeof(char) * buff_size);
      if (buff == NULL)
	      return (0);
      write(STDOUT_FILENO, "$ ", 2);
      read_count = getline(&buff, &buff_size, stdin);

      args = token(buff);

/*      spec(*args);*/
      

      free(buff);

      free(args);

      /*spec(buff);*/

    }
  return (0);
}

/**
 *
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)), char **env)
{
  int i, j;

  for (j = 0; env[j] != NULL; j++)
	  ;

  savedEnvironment = malloc(sizeof(char *) * (j + 1));
  if (savedEnvironment == NULL)
  {
	  perror("Malloc failed");
	  return (0);
  }

  for (i = 0; env[i] != NULL; i++)
	  savedEnvironment[i] = env[i];
  savedEnvironment[i] = NULL;

  loop();

  /*free(savedEnvironment);*/

  return (0);
}

int _env(void)
{
  int i;

  for (i = 0; savedEnvironment[i] != NULL; i++)
	  _puts_recursion(savedEnvironment[i]);
  return (0);
}
