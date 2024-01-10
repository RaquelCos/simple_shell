#include "main.h"

/**
 * str_spec - Handles the format %s
 * @king: Arguments
 *
 * Return: Integer
 */
int str_spec(va_list king)
{
	char *s = va_arg(king, char *);

	return (print_string(s));
}

/**
 * print_string - Prints a string
 * @str: The string to print
 *
 * Return: The length of characters printed
 */
int print_string(char *str)
{
	int length = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str != '\0' && str != NULL)
	{
		length += print_character(*str);
		str++;
	}

	return (length);
}
