#include "shell.h"

/**
 * token - tokenizes a string and returns an array of tokens
 * @buff: user's command
 * @delim: char to split str with (e.g. "\n")
 * Return: an array of tokens (e.g. {"ls", "-l", "\0"})
 */

char **token(char *buff, char *delim)
{
	char **token = NULL;
	char *holdbuff = NULL;
	size_t i = 0, num_o_words = 0;

	num_o_words = _strcount(buff);

	if (buff == NULL)
		return (0);
	holdbuff = malloc(sizeof(char *) * (num_o_words + 1));
	if (holdbuff == NULL)
		return (0);
	_strcpy(holdbuff, buff);
	token = malloc(sizeof(char *) * (num_o_words + 1));
	if (token == NULL)
	{
		perror("Token malloc failed");
		return (0);
	}
	token[i] = strtok(holdbuff, delim);
	while (token[i] != NULL)
	{
		++i;
		token[i] = strtok(NULL, delim);
	}
	return (token);
}
