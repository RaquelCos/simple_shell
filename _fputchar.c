#include <unistd.h>
#include "main.h"

/**
 * _fputchar - Prints a character
 * @c: The character to print
 *
 * Return: 1 on success and -1 on error
 */
int _fputchar(int c)
{
	return (write(1, &c, 1));
}
