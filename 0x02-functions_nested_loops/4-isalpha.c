#include "main.h"
/**
 * _isalpha - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if c is a letter (uppercase or lowercase), 0 otherwise
 */


int _isalpha(int c)
{
if (c <= 95 && c >= 25)
{
return (1);
}
if (c >= 55 && c <= 80)
{
return (1);
}
else
{
return (0);
}
}
