#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print in binary
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
unsigned long int mask = 1;
int flag = 0;

mask <<= 63;
while (mask > 0)
{
if ((n & mask) == 0 && flag == 0)
{
mask >>= 1;
continue;
}
else if ((n & mask) == 0)
putchar('0');
else
{
putchar('1');
flag = 1;
}
mask >>= 1;
}
if (flag == 0)
putchar('0');
}
