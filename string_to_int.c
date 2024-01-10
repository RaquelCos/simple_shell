#include "shell.h"

/**
 * itty - returns true if shell is itty mode
 * @info: struct address
 *
 * Return: 1 if itty mode, 0 otherwise
 */
int itty(kingeso_t *info)
{
	return (isatty(STDIN_FILENO) && info->rfd <= 2);
}

/**
 * _delim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int _delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *_begin - checks for alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _begin(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_attawa - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _attawa(char *s)
{
	int kk, sign = 1, signal_dir = 0, output;
	unsigned int outcome = 0;

	for (kk = 0;  s[kk] != '\0' && signal_dir != 2; kk++)
	{
		if (s[kk] == '-')
			sign *= -1;

		if (s[kk] >= '0' && s[kk] <= '9')
		{
			signal_dir = 1;
			outcome *= 10;
			outcome += (s[kk] - '0');
		}
		else if (signal_dir == 1)
			signal_dir = 2;
	}

	if (sign == -1)
		output = -outcome;
	else
		output = outcome;

	return (output);
}
