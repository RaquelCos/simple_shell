#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **get_environ(kingeso_t *info)
{
	if (!info->environ || info->alt)
	{
		info->environ = l_s(info->env);
		info->alt = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv_moi - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv_moi(kingeso_t *info, char *var)
{
	list_t *node = info->env;
	size_t kk = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = com(node->str, var);
		if (p && *p == '=')
		{
			info->alt = del_node(&(info->env), kk);
			kk = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		kk++;
	}
	return (info->alt);
}

/**
 * _setenv_moi - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv_moi(kingeso_t *info, char *var, char *value)
{
	char *cushion = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	cushion = malloc(_strlen(var) + _strlen(value) + 2);
	if (!cushion)
		return (1);
	_strcpy(cushion, var);
	_strcat(cushion, "=");
	_strcat(cushion, value);
	node = info->env;
	while (node)
	{
		p = com(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = cushion;
			info->alt = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), cushion, 0);
	free(cushion);
	info->alt = 1;
	return (0);
}
