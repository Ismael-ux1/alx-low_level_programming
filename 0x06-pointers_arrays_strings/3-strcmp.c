#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: pointer to first string to compare
 * @s2: pointer to second string to compare
 *
 * Return: integer less than, equal to, or greater than zero if s1 is less
 * than, matches, or is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
{
i++;
}

return (s1[i] - s2[i]);
}

