#include <stdio.h>
#include <math.h>
#include  "search_algos.h"
/**
 * jump_search - searches for a value in a sorted array of integers
 * using the Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located, or -1 if value is not present
 * in array or if array is NULL
 */

int jump_search(int *array, size_t size, int value)
{
size_t step, prev, i;

if (array == NULL || size == 0)
return (-1);

step = sqrt(size);
prev = 0;

while (array[prev] < value)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
prev += step;
if (prev >= size)
break;
}

printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

for (i = prev - step; i < prev && i < size; i++)
{
printf("Value checked array[%lu] = [%d]\n", i, array[i]);
if (array[i] == value)
return (i);
}

return (-1);
}
