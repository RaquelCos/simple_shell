#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int kk, z;
	char *s = dest;

	kk = 0;
	while (src[kk] != '\0' && kk < n - 1)
	{
		dest[kk] = src[kk];
		kk++;
	}
	if (kk < n)
	{
		z = kk;
		while (z < n)
		{
			dest[z] = '\0';
			z++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int kk, z;
	char *s = dest;

	kk = 0;
	z = 0;
	while (dest[kk] != '\0')
		kk++;
	while (src[z] != '\0' && z < n)
	{
		dest[kk] = src[z];
		kk++;
		z++;
	}
	if (z < n)
		dest[kk] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
