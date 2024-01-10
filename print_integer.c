#include "main.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * int_spec - Handles the format %i or %d
 * @king: Arguments
 *
 * Return: Integer
 */
int int_spec(va_list king)
{
	int num = va_arg(king, int);

	return (print_integer(num));
}

/**
 * print_integer - Prints an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(int n)
{
	int len5 = 0;
	int storage = n;
	int king_div = 1;

	if (n < 0)
	{
		len5 += print_character('-');
		n = -n;
	}

	while (storage / 10 != 0)
	{
		king_div *= 10;
		storage /= 10;
	}

	while (king_div != 0)
	{
		len5 += print_character('0' + n / king_div);
		n %= king_div;
		king_div /= 10;

	}
	return (len5);
}
