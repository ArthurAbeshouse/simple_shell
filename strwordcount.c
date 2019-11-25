#include "shell.h"

int _strcount(char *buff)
{
  int j, i = 0;
  for (j = 0; buff[j] != '\0'; ++j)
    {
      if ((buff[j] != ' ' && buff[j + 1] != ' ') || buff[j + 1] != '\0')
	  ++i;
    }
  return (j);
}
