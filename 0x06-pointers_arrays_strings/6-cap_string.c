#include "main.h"
/**
 * cap_string - Capitalizes all words of a string.
 * @str: The string to be modified.
 *
 * Return: The modified string.
 */
char *cap_string(char *str)
{
char *ptr = str;
int cap_next = 1;

while (*ptr != '\0')
{
if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' ||
*ptr == ',' || *ptr == ';' || *ptr == '.' ||
*ptr == '!' || *ptr == '?' || *ptr == '"' ||
*ptr == '(' || *ptr == ')' || *ptr == '{' ||
*ptr == '}')
cap_next = 1;
else if (cap_next && (*ptr >= 'a' && *ptr <= 'z'))
{
*ptr -= 32;
cap_next = 0;
}
else
cap_next = 0;

ptr++;
}

return (str);
}

