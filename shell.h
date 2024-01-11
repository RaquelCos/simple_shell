#ifndef _SHELL_H_
#define _SHELL_H_

#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>


#define ZEROS	0
#define ORS		1
#define ANDS	2
#define ESOS	3
#define APHA1 1
#define APHA2	2
#define APHA3 1024
#define APHA4 1024
#define APHA5 -1
#define APHA6 0
#define APHA7 0
#define APHA8	".simple_shell_history"
#define APHA9	4096

extern char **environ;


/**
 * struct liststr - singly
 * @num: the
 * @str: a
 * @next: points
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct loop_parse - contains
 *@arg: a
 *@argv: an
 *@path: a string
 *@argc: the
 *@num_line: the
 *@count_err: the
 *@count_line: put
 *@name_file: the rogram
 *@env: linked
 *@environ: cust
 *@backup: the
 *@alias: node
 *@alt: on
 *@curr_pos:command
 *@buffer_command: buf
 *@buffer_command_type: type
 *@rfd: line input
 *@hnum: the
 */
typedef struct loop_parse
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int num_line;
	int count_err;
	int count_line;
	char *name_file;
	list_t *env;
	list_t *backup;
	list_t *alias;
	char **environ;
	int alt;
	int curr_pos;

	char **buffer_command;
	int buffer_command_type;
	int rfd;
	int hnum;
} raqking_size_t;

#define ESO_KING \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin_functions - caron
 *@comm_type: the
 *@functions: the
 */
typedef struct builtin_functions
{
	char *comm_type;
	int (*functions)(raqking_size_t *);
} built_tab;


int ssh(raqking_size_t *, char **);
int built_search(raqking_size_t *);
void command_search(raqking_size_t *);
void rephrase(raqking_size_t *);

int _command(raqking_size_t *, char *);
char *ch_dup(char *, int, int);
char *path_file(raqking_size_t *, char *, char *);

int ssh_loop(char **);

void _puts_err(char *);
int _putchar_err(char);
int fd_put(char c, int fd);
int fd_puts(char *str, int fd);

int _strlen(char *);
int _strcmp(char *, char *);
char *com(const char *, const char *);
char *_strcat(char *, char *);

char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

char *_strncpy(char *, char *, int);
char *_strncat(char *, char *, int);
char *_strchr(char *, char);

char **strt(char *, char *);
char **strt2(char *, char);

char *_memset(char *, char, unsigned int);
void free_mem(char **);
void *_realloc(void *, unsigned int, unsigned int);

int free_memory(void **);

int itty(raqking_size_t *);
int _delim(char, char *);
int _begin(int);
int _attawa(char *);

int _attawa_err(char *);
void _err_print(raqking_size_t *, char *);
int print_e(int, int);
char *conv(long int, int, int);
void rem(char *);

int raqking_exit(raqking_size_t *);
int _cd(raqking_size_t *);
int _help(raqking_size_t *);

int _lace(raqking_size_t *, char *, size_t *);
void lace_s(raqking_size_t *, char *, size_t *, size_t, size_t);
int ref_al(raqking_size_t *);
int ref_v(raqking_size_t *);
int ref_str(char **, char *);
int _moi_backup(raqking_size_t *);
int _alias_moi(raqking_size_t *);

ssize_t _get_usr_inp(raqking_size_t *);
int _getline(raqking_size_t *, char **, size_t *);
void kkb(int);

void screen_comot(raqking_size_t *);
void _i_free(raqking_size_t *, int);
void _reset(raqking_size_t *, char **);

char *_getenv(raqking_size_t *, const char *);
int _env(raqking_size_t *);
int _set_env(raqking_size_t *);
int _unset_env(raqking_size_t *);
int gen128(raqking_size_t *);

char **get_environ(raqking_size_t *);
int _unsetenv_moi(raqking_size_t *, char *);
int _setenv_moi(raqking_size_t *, char *, char *);

char *ret_backup(raqking_size_t *info);
int w_b(raqking_size_t *info);
int r_b(raqking_size_t *info);
int b_b_l(raqking_size_t *info, char *buf, int linecount);
int re_b(raqking_size_t *info);

list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t p_l_s(const list_t *);
int del_node(list_t **, unsigned int);
void freel(list_t **);
size_t lc(const list_t *);
char **l_s(list_t *);
size_t pri_l(const list_t *);
list_t *alpha_n(list_t *, char *, char);
ssize_t g_i(list_t *, list_t *);

#endif
