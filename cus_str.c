#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * print_s2 - Prints a string
 * @cust_str: String to print
 *
 * Return: str_len
 */
int print_s2(char *cust_str)
{
	int str_len = 0;

	if (cust_str == NULL)
	{
		cust_str = "(null)";
	}
	while (*cust_str != '\0' && cust_str != NULL)
	{
		if ((*cust_str >= 0 && *cust_str < 32) || *cust_str >= 127)
		{
			print_string("\\x");
			if (*cust_str <= 15)
				print_character('0');
			print_hexadecimal(*cust_str, 1);
			str_len += 4;
		}
		else
		{
			print_character(*cust_str);
			str_len++;
		}
		cust_str++;
	}
	return (str_len);
}

/**
 * cust_strpec - Handles the format %S
 * @king: Arguments
 *
 * Return: Integer
 */
int cust_strpec(va_list king)
{
	char *s2 = va_arg(king, char *);

return (print_s2(s2));
}
