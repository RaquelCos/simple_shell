#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @cushion: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
ssize_t input_buf(kingeso_t *info, char **cushion, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*free_memory((void **)info->buffer_command);*/
		free(*cushion);
		*cushion = NULL;
		signal(SIGINT, kkb);
#if APHA6
		r = getline(cushion, &len_p, stdin);
#else
		r = _getline(info, cushion, &len_p);
#endif
		if (r > 0)
		{
			if ((*cushion)[r - 1] == '\n')
			{
				(*cushion)[r - 1] = '\0'; /* remove trailing newline */
				r--;
			}
			info->count_line = 1;
			rem(*cushion);
			b_b_l(info, *cushion, info->hnum++);
			/* if (_strchr(*cushion, ';')) is this a command chain? */
			{
				*len = r;
				info->buffer_command = cushion;
			}
		}
	}
	return (r);
}

/**
 * _get_usr_inp - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t _get_usr_inp(kingeso_t *info)
{
	static char *cushion; /* the ';' command chain buffer */
	static size_t kk, z, len;
	ssize_t r = 0;
	char **cushion_p = &(info->arg), *p;

	_putchar(APHA5);
	r = input_buf(info, &cushion, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len)	/* we have commands left in the chain buffer */
	{
		z = kk; /* init new iterator to current cushion position */
		p = cushion + kk; /* get pointer for return */

		lace_s(info, cushion, &z, kk, len);
		while (z < len) /* iterate to semicolon or end */
		{
			if (_lace(info, cushion, &z))
				break;
			z++;
		}

		kk = z + 1; /* increment past nulled ';'' */
		if (kk >= len) /* reached end of buffer? */
		{
			kk = len = 0; /* reset position and length */
			info->buffer_command_type = ZEROS;
		}

		*cushion_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*cushion_p = cushion; /* else not a chain, pass back buffer from _getline() */
	return (r);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @cushion: buffer
 * @kk: size
 *
 * Return: r
 */
ssize_t read_buf(kingeso_t *info, char *cushion, size_t *kk)
{
	ssize_t r = 0;

	if (*kk)
		return (0);
	r = read(info->rfd, cushion, APHA3);
	if (r >= 0)
		*kk = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(kingeso_t *info, char **ptr, size_t *length)
{
	static char cushion[APHA3];
	static size_t kk, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (kk == len)
		kk = len = 0;

	r = read_buf(info, cushion, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(cushion + kk, '\n');
	k = c ? 1 + (unsigned int)(c - cushion) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, cushion + kk, k - kk);
	else
		_strncpy(new_p, cushion + kk, k - kk + 1);

	s += k - kk;
	kk = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * kkb - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void kkb(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(APHA5);
}
