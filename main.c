#include "shell.h"


static char **savedEnvironment;

/**
 * loop - Main shell loop
 *
 * Return: 0 (successful)
 */
int loop(void)
{
	char *buff = NULL, **args = NULL; /* buff = user command*/
	size_t buff_size = 1024, read_count = 0;

	while (1)
	{
		signal(SIGINT, ctrl_c); /* Ctrl C sends a SIGINT */
		buff = malloc(sizeof(char *) * buff_size);
		if (buff == NULL)
			return (0);
		write(STDOUT_FILENO, "$ ", 2);
		read_count = getline(&buff, &buff_size, stdin);
		if (read_count == '\0')
			return (0);

		args = token(buff, "\n ");

		if (spec(args) == -1)
			commandChecker(args);

		free(buff);
		free(args);
	}
	return (0);
}

/**
 * main - Starter function
 * @argc: Unused
 * @argv: Unused
 * @env: Shell environment
 *
 * Return: 0 (successful)
 */

int main(int argc, char **argv, char **env)
{
	int i, j;

	(void)argc;
	(void)argv;
	for (j = 0; env[j] != NULL; j++)
		;

	savedEnvironment = malloc(sizeof(char *) * (j + 1));
	if (savedEnvironment == NULL)
		return (0);

	for (i = 0; env[i] != NULL; i++)
		savedEnvironment[i] = env[i];
	savedEnvironment[i] = NULL;

	loop();

	return (0);
}

/**
 * _env - Print environment of the Shell
 *
 * Return: 0 (successful)
 */

int _env(void)
{
	int i;

	for (i = 0; savedEnvironment[i] != NULL; i++)
		_puts(savedEnvironment[i]);
	return (0);
}
