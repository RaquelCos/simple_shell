#include "shell.h"

/**
 * lc - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t lc(const list_t *h)
{
	size_t kk = 0;

	while (h)
	{
		h = h->next;
		kk++;
	}
	return (kk);
}

/**
 * l_s - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **l_s(list_t *head)
{
	list_t *node = head;
	size_t kk = lc(head), z;
	char **strs;
	char *str;

	if (!head || !kk)
		return (NULL);
	strs = malloc(sizeof(char *) * (kk + 1));
	if (!strs)
		return (NULL);
	for (kk = 0; node; node = node->next, kk++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (z = 0; z < kk; z++)
				free(strs[z]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[kk] = str;
	}
	strs[kk] = NULL;
	return (strs);
}


/**
 * pri_l - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t pri_l(const list_t *h)
{
	size_t kk = 0;

	while (h)
	{
		_puts(conv(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		kk++;
	}
	return (kk);
}

/**
 * alpha_n - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *alpha_n(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = com(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * g_i - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t g_i(list_t *head, list_t *node)
{
	size_t kk = 0;

	while (head)
	{
		if (head == node)
			return (kk);
		head = head->next;
		kk++;
	}
	return (-1);
}
