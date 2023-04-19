#include <stdio.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success, 1 if argc is not 2, or 2 if atoi(argv[1]) is negative
 */
int main(int argc, char **argv)
{
int i, bytes;

if (argc != 2)
{
printf("Error\n");
return (1);
}

bytes = atoi(argv[1]);

if (bytes < 0)
{
printf("Error\n");
return (2);
}

for (i = 0; i < bytes; i++)
printf("%02x ", ((unsigned char *)main)[i]);

printf("\n");

return (0);
}
