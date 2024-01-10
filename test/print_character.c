#include "main.h"

/**
 * ch_spec - Handles the format %c
 * @king: Arguments
 *
 * Return: Integer
 */
int ch_spec(va_list king)
{
	char ch = va_arg(king, int);

	return (print_character(ch));
}

/**
 * print_character - Prints a character
 * @ch: The character to print
 *
 * Return: Always 1
 */
int print_character(char ch)
{
	int len = 0;

	len += _fputchar(ch);
	return (len);
}
