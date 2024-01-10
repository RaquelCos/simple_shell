#include "shell.h"

/**
 * _lace - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @cushion: the char buffer
 * @p: address of current position in cushion
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int _lace(kingeso_t *info, char *cushion, size_t *p)
{
	size_t z = *p;

	if (cushion[z] == '|' && cushion[z + 1] == '|')
	{
		cushion[z] = 0;
		z++;
		info->buffer_command_type = ORS;
	}
	else if (cushion[z] == '&' && cushion[z + 1] == '&')
	{
		cushion[z] = 0;
		z++;
		info->buffer_command_type = ANDS;
	}
	else if (cushion[z] == ';') /* found end of this command */
	{
		cushion[z] = 0; /* replace semicolon with null */
		info->buffer_command_type = ESOS;
	}
	else
		return (0);
	*p = z;
	return (1);
}

/**
 * lace_s - checks we should continue chaining based on last curr_pos
 * @info: the parameter struct
 * @cushion: the char buffer
 * @p: address of current position in cushion
 * @kk: starting position in cushion
 * @len: length of cushion
 *
 * Return: Void
 */
void lace_s(kingeso_t *info, char *cushion, size_t *p, size_t kk, size_t len)
{
	size_t z = *p;

	if (info->buffer_command_type == ANDS)
	{
		if (info->curr_pos)
		{
			cushion[kk] = 0;
			z = len;
		}
	}
	if (info->buffer_command_type == ORS)
	{
		if (!info->curr_pos)
		{
			cushion[kk] = 0;
			z = len;
		}
	}

	*p = z;
}

/**
 * ref_al - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int ref_al(kingeso_t *info)
{
	int kk;
	list_t *node;
	char *p;

	for (kk = 0; kk < 10; kk++)
	{
		node = alpha_n(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * ref_v - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int ref_v(kingeso_t *info)
{
	int kk = 0;
	list_t *node;

	for (kk = 0; info->argv[kk]; kk++)
	{
		if (info->argv[kk][0] != '$' || !info->argv[kk][1])
			continue;

		if (!_strcmp(info->argv[kk], "$?"))
		{
			ref_str(&(info->argv[kk]),
				_strdup(conv(info->curr_pos, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[kk], "$$"))
		{
			ref_str(&(info->argv[kk]),
				_strdup(conv(getpid(), 10, 0)));
			continue;
		}
		node = alpha_n(info->env, &info->argv[kk][1], '=');
		if (node)
		{
			ref_str(&(info->argv[kk]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		ref_str(&info->argv[kk], _strdup(""));

	}
	return (0);
}

/**
 * ref_str - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int ref_str(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
