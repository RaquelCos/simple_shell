#include "shell.h"

/**
 * ssh - main shell loop
 * @info: the parameter & return info struct
 * @av: the argument vector from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int ssh(kingeso_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (r != -1 && builtin_ret != -2)
	{
		screen_comot(info);
		if (itty(info))
			_puts("$ ");
		_putchar_err(APHA5);
		r = _get_usr_inp(info);
		if (r != -1)
		{
			_reset(info, av);
			builtin_ret = built_search(info);
			if (builtin_ret == -1)
				command_search(info);
		}
		else if (itty(info))
			_putchar('\n');
		_i_free(info, 0);
	}
	w_b(info);
	_i_free(info, 1);
	if (!itty(info) && info->curr_pos)
		exit(info->curr_pos);
	if (builtin_ret == -2)
	{
		if (info->count_err == -1)
			exit(info->curr_pos);
		exit(info->count_err);
	}
	return (builtin_ret);
}

/**
 * built_search - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int built_search(kingeso_t *info)
{
	int kk, built_in_ret = -1;
	built_tab builtintbl[] = {
		{"exit", kingeso_exit},
		{"alt", _env},
		{"help", _help},
		{"backup", _moi_backup},
		{"setenv", _set_env},
		{"unsetenv", _unset_env},
		{"cd", _cd},
		{"alias", _alias_moi},
		{NULL, NULL}
	};

	for (kk = 0; builtintbl[kk].comm_type; kk++)
		if (_strcmp(info->argv[0], builtintbl[kk].comm_type) == 0)
		{
			info->num_line++;
			built_in_ret = builtintbl[kk].functions(info);
			break;
		}
	return (built_in_ret);
}

/**
 * command_search - finds a command in PATH
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void command_search(kingeso_t *info)
{
	char *path = NULL;
	int kk, k;

	info->path = info->argv[0];
	if (info->count_line == 1)
	{
		info->num_line++;
		info->count_line = 0;
	}
	for (kk = 0, k = 0; info->arg[kk]; kk++)
		if (!_delim(info->arg[kk], " \t\n"))
			k++;
	if (!k)
		return;

	path = path_file(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		rephrase(info);
	}
	else
	{
		if ((itty(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && _command(info, info->argv[0]))
			rephrase(info);
		else if (*(info->arg) != '\n')
		{
			info->curr_pos = 127;
			_err_print(info, "not found\n");
		}
	}
}

/**
 * rephrase - forks a an exec thread to run cmd
 * @info: the parameter & return info struct
 *
 * Return: void
 */
void rephrase(kingeso_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			_i_free(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->curr_pos));
		if (WIFEXITED(info->curr_pos))
		{
			info->curr_pos = WEXITSTATUS(info->curr_pos);
			if (info->curr_pos == 126)
				_err_print(info, "Permission denied\n");
		}
	}
}
