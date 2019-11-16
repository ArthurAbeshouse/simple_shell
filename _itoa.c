#include "shell.h"

/**
 *
 *
 *
 *
 *
 */

char *_revstr(char *s)
{
	int len = _strlen(s);
	char *buffer = malloc(sizeof(char *));
	int i, j;

	j = 0;
	for (i = len - 1; i >= 0; i--)
		buffer[j++] = s[i];

	return (buffer);
}


/**
 * _itoa - Convert int to string
 * @in: Num to convert
 * @out: Output
 * @base: Base to convert to
 *
 * Return: Num converted to string
 */

char *_itoa(long int in, char *out, int base)
{
	int n = in;
	int i = 0;
	int len, r;

	if (in == INT_MIN)
		n -= 1;

	if (in < 0)
		n = in * -1;

	if (base < 2 || base > 32)
		return (out);
	while (in)
	{
		r = n % base;
		if (r >= 10)
			out[i++] = 65 + (r - 10);
		else
			out[i++] = 48 + r;
		n = n / base;
	}
	if (i == 0)
		out[i++] = '0';

	if (in < 0 && base == 10)
		out[i++] = '-';

	out[i] = '\0';
	out = _revstr(out);
	if (in == INT_MIN)
	{
		len = _strlen(out);
		out[len - 1] = 8 + '0';
	}
	return (out);
}
