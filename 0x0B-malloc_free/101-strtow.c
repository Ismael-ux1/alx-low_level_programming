#include <stdlib.h>
#include "main.h"

/**
 * count_words - count number of words in string
 * @str: string to count
 *
 * Return: number of words
 */
int count_words(char *str)
{
int i, words = 0;

for (i = 0; str[i]; i++)
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
words++;

return (words);
}

/**
 * strtow - split string into words
 * @str: string to split
 *
 * Return: pointer to array of words
 */
char **strtow(char *str)
{
char **words;
int i, j, k, len, wc = 0;

if (str == NULL || str[0] == '\0')
return (NULL);

wc = count_words(str);
if (wc == 0)
return (NULL);

words = malloc(sizeof(char *) * (wc + 1));
if (words == NULL)
return (NULL);

for (i = 0; i < wc; i++)
{
while (*str == ' ')
str++;

len = 0;
while (*(str + len) != ' ' && *(str + len) != '\0')
len++;

words[i] = malloc(sizeof(char) * (len + 1));
if (words[i] == NULL)
{
for (j = 0; j < i; j++)
free(words[j]);
free(words);
return (NULL);
}

for (k = 0; k < len; k++)
words[i][k] = *(str++);
words[i][k] = '\0';
}
words[i] = NULL;

return (words);
}
