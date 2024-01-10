#include "main.h"


/**
 * oct_spec - Handles the %o specifier
 * @akk: Arguments
 *
 * Return: Integer
 */
int oct_spec(va_list akk)
{
	unsigned int octa_akk = va_arg(akk, unsigned int);

	return (print_oct(octa_akk));
}

/**
 * print_oct - Prints octal numbers
 * @v: The number to convert
 *
 * Return: len
 */
int print_oct(unsigned int v)
{
	int len = 0, x = 0, y;
	char akk_oct[32];

	if (v == 0)
	{
		len += print_character('0');
	}

	while (v > 0)
	{
		akk_oct[x] = (v % 8) + '0';
		v /= 8;
		x++;
	}

	y = x - 1;
	while (y >= 0)
	{
		len += print_character(akk_oct[y]);
		y--;
	}
	return (len);
}
