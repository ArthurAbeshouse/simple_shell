#include "shell.h"

char **token(char *buff)
{
        char *delim = "\n ";
        char **token = NULL;
        size_t i = 0, j, num_o_words = 0;

	for (j = 0; buff[j] != '\0'; ++j)
	{
		if (buff[j] != ' ' && buff[j] != '\n')
		{
			++num_o_words;
			while (buff[j] != ' ' && buff[j] != '\n')
				++j;
		}
	}
	/*printf("%zu\n", num_o_words);*/
	if (buff == NULL)
		return (0);
	token = malloc(sizeof(char *) * (num_o_words + 1));
	if (token == NULL)
                return (0);
	token[i] = strtok(buff, delim);
	while (token[i] != NULL)
        {
		++i;
		token[i] = strtok(NULL, delim);
	}
	return (token);
}
