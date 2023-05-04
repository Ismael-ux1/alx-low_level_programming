#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: A string containing a binary number
 *
 * Return: The converted number,
 * or 0 if there is one or more chars
 * in the string b that is not 0 or 1, or b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0;

if (b == NULL)
return (0);

for (; *b; b++)
{
if (*b != '0' && *b != '1')
return (0);

result <<= 1;
result += (*b - '0');
}

return (result);
}

