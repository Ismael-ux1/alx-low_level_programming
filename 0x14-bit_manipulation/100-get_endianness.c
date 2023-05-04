#include "main.h"

/**
 * get_endianness - checks the endianness of the machine
 *
 * Return: 0 if big endian, 1 if little endian
 */
int get_endianness(void)
{
unsigned int x = 1;
char *c = (char *) &x;

if (*c)
return (1); /* little endian */
else
return (0); /* big endian */
}

