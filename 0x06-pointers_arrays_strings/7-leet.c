#include "main.h"
/**
 * leet - Encodes a string into 1337.
 * @str: The string to be encoded.
 *
 * Return: The encoded string.
 */

char *leet(char *str)
{
char *ptr = str;
char *leet_chars = "AaEeOoTtLl";
char *leet_nums = "4433007711";
int i, j;

while (*ptr != '\0')
{
i = 0;
j = 0;

while (leet_chars[i] != '\0')
		{
if (*ptr == leet_chars[i])
{
*ptr = leet_nums[j];
break;
}

i++;
j++;
}

ptr++;
}

return (str);
}
