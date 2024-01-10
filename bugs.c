#include "shell.h"

/**
 *_puts_err - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts_err(char *str)
{
	int kk = 0;

	if (!str)
		return;
	while (str[kk] != '\0')
	{
		_putchar_err(str[kk]);
		kk++;
	}
}

/**
 * _putchar_err - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_err(char c)
{
	static int kk;
	static char cushion[APHA4];

	if (c == APHA5 || kk >= APHA4)
	{
		write(2, cushion, kk);
		kk = 0;
	}
	if (c != APHA5)
		cushion[kk++] = c;
	return (1);
}

/**
 * fd_put - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int fd_put(char c, int fd)
{
	static int kk;
	static char cushion[APHA4];

	if (c == APHA5 || kk >= APHA4)
	{
		write(fd, cushion, kk);
		kk = 0;
	}
	if (c != APHA5)
		cushion[kk++] = c;
	return (1);
}

/**
 *fd_puts - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int fd_puts(char *str, int fd)
{
	int kk = 0;

	if (!str)
		return (0);
	while (*str)
	{
		kk += fd_put(*str++, fd);
	}
	return (kk);
}
