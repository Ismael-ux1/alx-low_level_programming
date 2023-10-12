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
size_t step;
size_t prev = 0;
size_t min_val;

if (array == NULL)
return (-1);

step = sqrt(size);

while ((min_val = (step < size ? step : size), array[min_val]) < value)
{
printf("Value checked array[%lu] = [%d]\n", min_val, array[min_val]);
prev = min_val;
step += sqrt(size);
if (prev >= size)
return (-1);
}

printf("Value found between indexes [%lu] and [%lu]\n", prev, min_val);

while (array[prev] < value)
{
printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
prev++;
if (prev == min_val + 1 || prev == size)
return (-1);
}

if (array[prev] == value)
{
printf("Found %d at index: %lu\n", value, prev);
return (prev);
}

return (-1);
}
