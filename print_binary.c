#include "main.h"

/**
 * bin_spec - Handles the format %b
 * @king: Arguments
 *
 * Return: Integer
 */
int bin_spec(va_list king)
{
	unsigned int z = va_arg(king, unsigned int);

	return (print_binary(z));
}

/**
 * print_binary - Print the binary representation of an unsigned integer
 * @z: The unsigned integer to print in binary
 *
 * Return: The number of characters printed
 */
int print_binary(unsigned int z)
{
	int num = 0, x = 0, y;
	char array_king[32];

	if (z == 0)
	{
		print_character('0');
		return (1);
	}

	while (z > 0)
	{
		array_king[x] = (z & 1) + '0';
		z >>= 1;
		x++;
	}

	y = x - 1;
	while (y >= 0)
	{
		print_character(array_king[y]);
		num++;
		y--;
	}

	return (num);
}
