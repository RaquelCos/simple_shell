#include "main.h"
#include <unistd.h>

/**
 * flags_kyei - Handles flags
 * @f: Pointer
 * @pos: Pointer
 * @spc: Pointer
 * @sh: Pointer
 *
 * Return: Nothing
 */
void flags_kyei(const char *f, int pos, int spc, int sh)
{
	while (*f == '+' || *f == ' ' || *f == '#')
	{
		if (*f == ' ')
		{
			UNUSED(spc = 1);
		}
		else if (*f == '#')
		{
			UNUSED(sh = 1);
		}
		else if (*f == '+')
		{
			UNUSED(pos == 1);
		}
		f++;
	}
}

/**
 * format_spec - Handles a format specifier
 * @format: Pointer to the current position in the format string
 * @king: Argument list
 *
 * Return: The number of characters printed
 */
int format_spec(const char **format, va_list king)
{
	if (**format == '%')
		return (print_character(**format));
	else if (**format == 'S')
		return (cust_strpec(king));
	else if (**format == 'c')
		return (ch_spec(king));
	else if (**format == 'p')
	{
		return (p_spec(king));
	}
		else if (**format == 's')
	{
		return (str_spec(king));
	}
	else if (**format == 'd' || **format == 'i')
	{
		return (int_spec(king));
	}
	else if (**format == 'b')
	{
		return (bin_spec(king));
	}
	else if (**format == 'u')
	{
		return (unsigned_spec(king));
	}
	else if (**format == 'o')
	{
		return (oct_spec(king));
	}
	else if (**format == 'x' || **format == 'X')
	{
		return (hex_spec(king, **format));
	}
	else
	{
		print_character('%');
		print_character(**format);
		return (2);
	}
}

/**
 * _printf - Produces output according to a format
 * @format: Character string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list king;
	int length2 = 0;

	if (format == NULL || *format == '\0')
	{
		return (-1);
	}
	va_start(king, format);
	while (*format != '\0' && format)
	{
		if (*format == '%')
		{
			int pos = 0, spc = 0, sh = 0;

			format++;
			if (format == NULL || *format == '\0')
			{
				return (-1);
			}
			UNUSED(flags_kyei(format, pos, spc, sh));
			if (format == NULL || *format == '\0')
			{
				return (-1);
			}

			length2 += format_spec(&format, king);
		}
		else
		{
			length2 += print_character(*format);
		}
		format++;
	}
	va_end(king);
	return (length2);
}
