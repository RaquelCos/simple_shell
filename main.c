#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
	kingeso_t info[] = { ESO_KING };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_puts_err(av[0]);
				_puts_err(": 0: Can't open ");
				_puts_err(av[1]);
				_putchar_err('\n');
				_putchar_err(APHA5);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->rfd = fd;
	}
	gen128(info);
	r_b(info);
	ssh(info, av);
	return (EXIT_SUCCESS);
}
