#include "shell.h"
/**
 *
 */

int loop(void)
{
	char *buff;
	size_t buff_size = 1024, read_count;
	char *delim = " ";
	char *token = NULL;

	while(1)
	{
		buff = malloc(sizeof(char) * buff_size);
		if (buff == NULL)
			return (0);
		write(STDOUT_FILENO, "$ ", 2);
		read_count = getline(&buff, &buff_size, stdin);
		/*printf("%s", buff);*/
/*		token = malloc(sizeof(char *) * buff_size);
                if (token == NULL)
		return (0);*/
		token = strtok(buff, delim);
		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, delim);
		}
		spec(buff);
		/* spec(token); */
	}
	return (0);
}

/**
 *
 */

int main(void)
{
	loop();

	return (0);
}
