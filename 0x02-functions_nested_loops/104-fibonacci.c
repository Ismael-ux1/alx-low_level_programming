#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int i;
unsigned long long a = 1, b = 2, c;

printf("%llu, %llu", a, b);

for (i = 3; i <= 98; i++)
{
c = a + b;
printf(", %llu", c);
a = b;
b = c;
}

printf("\n");

return (0);
}

