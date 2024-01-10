#include "shell.h"

/**
 * _env - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _env(kingeso_t *info)
{
	p_l_s(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(kingeso_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = com(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _set_env - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _set_env(kingeso_t *info)
{
	if (info->argc != 3)
	{
		_puts_err("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv_moi(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unset_env - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _unset_env(kingeso_t *info)
{
	int kk;

	if (info->argc == 1)
	{
		_puts_err("Too few arguements.\n");
		return (1);
	}
	for (kk = 1; kk <= info->argc; kk++)
		_unsetenv_moi(info, info->argv[kk]);

	return (0);
}

/**
 * gen128 - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int gen128(kingeso_t *info)
{
	list_t *node = NULL;
	size_t kk;

	for (kk = 0; environ[kk]; kk++)
		add_node_end(&node, environ[kk], 0);
	info->env = node;
	return (0);
}
