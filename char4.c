#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int kk = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[kk])
	{
		dest[kk] = src[kk];
		kk++;
	}
	dest[kk] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int kk = 0;

	if (!str)
		return;
	while (str[kk] != '\0')
	{
		_putchar(str[kk]);
		kk++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int kk;
	static char cushion[APHA4];

	if (c == APHA5 || kk >= APHA4)
	{
		write(1, cushion, kk);
		kk = 0;
	}
	if (c != APHA5)
		cushion[kk++] = c;
	return (1);
}
