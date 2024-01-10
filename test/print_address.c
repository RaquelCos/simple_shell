#include "main.h"
#include <unistd.h>

/**
 * print_address - Prints memory address
 * @addr_king: Pointer to print
 *
 * Return:len_king
 */
int print_address(unsigned long addr_king)
{
	char buff_addr[16];
	int len_king = 0;
	int c = 0;

	while (c < 16)
	{
		int piece = (addr_king >> ((15 - c) * 4)) & 0xF;

		if (piece < 10)
		{
			buff_addr[c] = '0' + piece;
		}
		else
		{
			buff_addr[c] = 'a' + (piece - 10);
		}
		c++;
	}

	len_king += write(1, buff_addr, 16);

	return (len_king);
}

/**
 * p_spec - %p Specifier
 * @king: Arguments
 *
 * Return: len_add2
 */
int p_spec(va_list king)
{
	void *p_addr = va_arg(king, void *);
	int len_king1 = 0;

	len_king1 += write(1, "0x", 2);
	len_king1 += print_address((unsigned long)p_addr);
	return (len_king1);
}
