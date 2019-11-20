#include "shell.h"
/**
 *
 */

int loop(void)
{
	char *buff;
	size_t buff_size = 1024, read_count;
	char **args = NULL;

	while(1)
	{
		buff = malloc(sizeof(char) * buff_size);
		if (buff == NULL)
			return (0);
		write(STDOUT_FILENO, "$ ", 2);
		read_count = getline(&buff, &buff_size, stdin);
		/*printf("%s", buff);*/

		args = token(buff);
		free(args);

		spec(buff);

		free(buff);
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
