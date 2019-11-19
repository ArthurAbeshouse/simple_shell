#include "shell.h"

char **token(char *buff)
{
        char *delim = "\n ";
        char **token = NULL;
        size_t i = 0, count = 20;

	if (buff == NULL)
		return (0);
	token = malloc(sizeof(char *) * count);
	if (token == NULL)
                return (0);
	token[i] = strtok(buff, delim);
	while (token[i] != NULL)
        {
                printf("%s\n", token[i]);
		++i;
		token[i] = strtok(NULL, delim);
	}
	return (token);
}
