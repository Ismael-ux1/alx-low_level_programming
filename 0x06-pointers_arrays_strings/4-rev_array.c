#include "main.h"
/**
 * reverse_array - reversse the content of an array of integers
 * @a: pointer to the array of integeres to reverese
 * @n: number of elemnet in array
 *
 * ReturnL void
 */
void reverse_array(int *a, int n)
{
int i, tmp;

for (i = 0; i < n / 2; i++)
{
tmp = a[i];
a[i] = a[n - i - 1];
a[n - i - 1] = tmp;
}
}
