#include "shell.h"

/**
 * screen_comot - initializes kingeso_t struct
 * @info: struct address
 */
void screen_comot(kingeso_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * _reset - initializes kingeso_t struct
 * @info: struct address
 * @av: argument vector
 */
void _reset(kingeso_t *info, char **av)
{
	int kk = 0;

	info->name_file = av[0];
	if (info->arg)
	{
		info->argv = strt(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (kk = 0; info->argv && info->argv[kk]; kk++)
			;
		info->argc = kk;

		ref_al(info);
		ref_v(info);
	}
}

/**
 * _i_free - frees kingeso_t struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void _i_free(kingeso_t *info, int all)
{
	free_mem(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->buffer_command)
			free(info->arg);
		if (info->alt)
			freel(&(info->env));
		if (info->backup)
			freel(&(info->backup));
		if (info->alias)
			freel(&(info->alias));
		free_mem(info->environ);
			info->environ = NULL;
		free_memory((void **)info->buffer_command);
		if (info->rfd > 2)
			close(info->rfd);
		_putchar(APHA5);
	}
}
