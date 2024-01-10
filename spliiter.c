#include "shell.h"

/**
 * **strt - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strt(char *str, char *d)
{
	int kk, z, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (kk = 0; str[kk] != '\0'; kk++)
		if (!_delim(str[kk], d) && (_delim(str[kk + 1], d) || !str[kk + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (kk = 0, z = 0; z < numwords; z++)
	{
		while (_delim(str[kk], d))
			kk++;
		k = 0;
		while (!_delim(str[kk + k], d) && str[kk + k])
			k++;
		s[z] = malloc((k + 1) * sizeof(char));
		if (!s[z])
		{
			for (k = 0; k < z; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[z][m] = str[kk++];
		s[z][m] = 0;
	}
	s[z] = NULL;
	return (s);
}

/**
 * **strt2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strt2(char *str, char d)
{
	int kk, z, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (kk = 0; str[kk] != '\0'; kk++)
		if ((str[kk] != d && str[kk + 1] == d) ||
		    (str[kk] != d && !str[kk + 1]) || str[kk + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (kk = 0, z = 0; z < numwords; z++)
	{
		while (str[kk] == d && str[kk] != d)
			kk++;
		k = 0;
		while (str[kk + k] != d && str[kk + k] && str[kk + k] != d)
			k++;
		s[z] = malloc((k + 1) * sizeof(char));
		if (!s[z])
		{
			for (k = 0; k < z; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[z][m] = str[kk++];
		s[z][m] = 0;
	}
	s[z] = NULL;
	return (s);
}
