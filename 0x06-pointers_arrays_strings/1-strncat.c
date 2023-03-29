#include "main.h"

/**
 * _strncat - concatenates two strings up to n bytes
 * @dest: destinaton string to concatenate t0
 * @src : source string to concatenate
 * @n: maximum number of bytes to concatenate
 *
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
int dest_len = 0;
int i;
/* Get length of destination string */
while (dest[dest_len] != '\0')
{
dest_len++;
}
/* concatnate up to n bytes of source string */
for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[dest_len + i] = src[i];
}
/* Tenrminate the string with null character */
dest[dest_len + i] = '\0';

/* Return pointers to the resulting string dest */
return (dest);
}
