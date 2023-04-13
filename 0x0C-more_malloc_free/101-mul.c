#include <stdio.h>
#include <stdlib.h>

/**
 * multiply - multiplies two numbers
 * @num1: the first number
 * @num2: the second number
 *
 * Return: the result of multiplying num1 and num2
 */
int multiply(int num1, int num2)
{
return (num1 * num2);
}

/**
 * is_positive - checks if a number is positive
 * @num: the number to check
 *
 * Return: 1 if the number is positive, 0 otherwise
 */
int is_positive(char *num)
{
int i;
for (i = 0; num[i] != '\0'; i++)
{
if (num[i] < '0' || num[i] > '9')
{
return (0);
}
}
return (1);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
int num1, num2, result;

if (argc != 3)
{
printf("Error\n");
return (98);
}
if (!is_positive(argv[1]) || !is_positive(argv[2]))
{
printf("Error\n");
return (98);
}
num1 = atoi(argv[1]);
num2 = atoi(argv[2]);
result = multiply(num1, num2);
printf("%d\n", result);
return (0);
}

