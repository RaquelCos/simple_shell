#include "main.h"

/**
 * hex_spec - For the hexadec specifier
 * @king: Arguments
 * @spec: x or X
 *
 * Return: Integer
 */
int hex_spec(va_list king, char spec)
{
	unsigned int num = va_arg(king, unsigned int);
	int up_case = 0;

	if (spec == 'X')
	{
		up_case = 1;
	}

	return (print_hexadecimal(num, up_case));
}

/**
 * print_hexadecimal - Converts an decimal integer to hexadecimal
 * @decim: Integer to convert
 * @up_case: Either x or X
 *
 * Return: leng
 */
int print_hexadecimal(unsigned int decim, int up_case)
{
	char hex_king[32];
	int length = 0, a = 0, b;

	if (decim == 0)
	{
		length += (print_character(decim));
		return (length);
	}
	while (decim > 0)
	{
		int temporal = decim % 16;

		if (temporal < 10)
		{
			hex_king[a] = temporal + '0';
		}
		else
		{
			if (up_case)
				hex_king[a] = temporal - 10 + 'A';
			else
				hex_king[a] = temporal - 10 + 'a';
		}
			decim /= 16;
			a++;
	}
	b = a - 1;
	while (b >= 0)
	{
		length += print_character(hex_king[b]);
		b--;
	}
	return (length);
}
