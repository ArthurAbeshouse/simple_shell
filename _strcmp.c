#include "shell.h"
/**
 * _strcmp - compares two strings, ending at the first byte that is different
 * @s1: string to be compared
 * @s2: string to be compared by
 * Return: the difference between the first character that are not the same
 */

int _strcmp(char *s1, char *s2)
{
        int a;

        if (s1 == NULL && s2 == NULL)
	        return (0);
        else if (s1 != NULL && s2 == NULL)
	        return (1);
        else if (s1 == NULL && s2 != NULL)
	        return (1);

        for (a = 0; s1[a] != '\0' && s2[a] != '\0'; ++a)
        {
                if (s1[a] != s2[a])
                        return (1);

        }
        return (0);
}
