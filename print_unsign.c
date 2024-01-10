#include "main.h"

/**
 * unsigned_spec - Handles the %u specifier
 * @king: Arguments
 *
 * Return: Integer
 */
int unsigned_spec(va_list king)
{
	unsigned int w = va_arg(king, unsigned int);

	return (print_unsign(w));
}

/**
 * print_unsign - Prints an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_unsign(unsigned int n)
{
	int length1 = 0;
	char c_array[32];
	int x = 0, y;

	if (n == 0)
	{
		length1 += print_character('0');
	}
	while (n > 0)
	{
		c_array[x] = (n % 10) + '0';
		n /= 10;
		x++;
	}
	y = x - 1;
	while (y >= 0)
	{
		length1 += print_character(c_array[y]);
		y--;
	}
	return (length1);
}
