#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at a given index
 * @n: number to modify
 * @index: index, starting from 0 of the bit you want to clear
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
return (-1);
*n &= ~(1ul << index);

return (1);
}

