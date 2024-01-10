#include "shell.h"

/**
 * _attawa_err - con
 * @s: the
 * Return: 0 if
 *       -1
 */
int _attawa_err(char *s)
{
	int kk = 0;
	unsigned long int outcome = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (kk = 0;  s[kk] != '\0'; kk++)
	{
		if (s[kk] >= '0' && s[kk] <= '9')
		{
			outcome *= 10;
			outcome += (s[kk] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (outcome);
}

/**
 * _err_print - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void _err_print(kingeso_t *info, char *estr)
{
	_puts_err(info->name_file);
	_puts_err(": ");
	print_e(info->num_line, STDERR_FILENO);
	_puts_err(": ");
	_puts_err(info->argv[0]);
	_puts_err(": ");
	_puts_err(estr);
}

/**
 * print_e - function prints a decimal (integer) number (base 10)
 * @inp: the inp
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_e(int inp, int fd)
{
	int (*__putchar)(char) = _putchar;
	int kk, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _putchar_err;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		count++;
	}
	else
		_abs_ = inp;
	current = _abs_;
	for (kk = 1000000000; kk > 1; kk /= 10)
	{
		if (_abs_ / kk)
		{
			__putchar('0' + current / kk);
			count++;
		}
		current %= kk;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * conv - converter
 * @num: number
 * @base: base
 * @signal_dirs: argumen
 *
 * Return: string
 */
char *conv(long int num, int base, int signal_dirs)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(signal_dirs & APHA2) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = signal_dirs & APHA1 ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * rem - function
 * @cushion: address
 *
 * Return: 0
 */
void rem(char *cushion)
{
	int kk;

	for (kk = 0; cushion[kk] != '\0'; kk++)
		if (cushion[kk] == '#' && (!kk || cushion[kk - 1] == ' '))
		{
			cushion[kk] = '\0';
			break;
		}
}
