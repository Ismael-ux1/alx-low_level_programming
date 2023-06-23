#include <stdio.h>
#include "operands.h"

/**
 * add - Adds two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Result of addition
 */
int add(int a, int b)
{
return (a + b);
}

/**
 * subtract - Subtracts two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Result of subtraction
 */
int sub(int a, int b)
{
return (a - b);
}

/**
 * multiply - Multiplies two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Result of multiplication
 */
int mul(int a, int b)
{
return (a * b);
}

/**
 * divide - Divides two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Result of division
 */
int div(int a, int b)
{
return (a / b);
}

/**
 * mod - Computes the modulo of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Modulo result of @a divided by @b
 */
int mod(int a, int b)
{
return (a % b);
}
