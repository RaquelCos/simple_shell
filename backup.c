#include "shell.h"

/**
 * ret_backup - gets the backup file
 * @info: parameter struct
 *
 * Return: allocated string containg backup file
 */

char *ret_backup(kingeso_t *info)
{
	char *cushion, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	cushion = malloc(sizeof(char) * (_strlen(dir) + _strlen(APHA8) + 2));
	if (!cushion)
		return (NULL);
	cushion[0] = 0;
	_strcpy(cushion, dir);
	_strcat(cushion, "/");
	_strcat(cushion, APHA8);
	return (cushion);
}

/**
 * w_b - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int w_b(kingeso_t *info)
{
	ssize_t fd;
	char *filename = ret_backup(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->backup; node; node = node->next)
	{
		fd_puts(node->str, fd);
		fd_put('\n', fd);
	}
	fd_put(APHA5, fd);
	close(fd);
	return (1);
}

/**
 * r_b - reads backup from file
 * @info: the parameter struct
 *
 * Return: hnum on success, 0 otherwise
 */
int r_b(kingeso_t *info)
{
	int kk, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *cushion = NULL, *filename = ret_backup(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	cushion = malloc(sizeof(char) * (fsize + 1));
	if (!cushion)
		return (0);
	rdlen = read(fd, cushion, fsize);
	cushion[fsize] = 0;
	if (rdlen <= 0)
		return (free(cushion), 0);
	close(fd);
	for (kk = 0; kk < fsize; kk++)
		if (cushion[kk] == '\n')
		{
			cushion[kk] = 0;
			b_b_l(info, cushion + last, linecount++);
			last = kk + 1;
		}
	if (last != kk)
		b_b_l(info, cushion + last, linecount++);
	free(cushion);
	info->hnum = linecount;
	while (info->hnum-- >= APHA9)
		del_node(&(info->backup), 0);
	re_b(info);
	return (info->hnum);
}

/**
 * b_b_l - adds entry to a backup linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @cushion: buffer
 * @linecount: the backup linecount, hnum
 *
 * Return: Always 0
 */
int b_b_l(kingeso_t *info, char *cushion, int linecount)
{
	list_t *node = NULL;

	if (info->backup)
		node = info->backup;
	add_node_end(&node, cushion, linecount);

	if (!info->backup)
		info->backup = node;
	return (0);
}

/**
 * re_b - renumbers the backup linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new hnum
 */
int re_b(kingeso_t *info)
{
	list_t *node = info->backup;
	int kk = 0;

	while (node)
	{
		node->num = kk++;
		node = node->next;
	}
	return (info->hnum = kk);
}
