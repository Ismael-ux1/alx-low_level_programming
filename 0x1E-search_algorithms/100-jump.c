#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 *               using the Jump search algorithm.
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in array.
 * @value: The value to search for.
 *
 * Return: If value is not present in array or if array is NULL, -1.
 *         Otherwise, the first index where value is located.
 *
 * Description: Uses the square root of the size of the array as the jump step.
 *              Every time you compare a value in the array to the value you
 *              are searching, you have to print this value.
 */
int jump_search(int *array, size_t size, int value)
{
size_t i, jump;
int tmp;

if (array == NULL)
return (-1);

jump = sqrt(size);
for (i = 0; i < size; i += jump)
{
tmp = array[i];
printf("Value checked array[%lu] = [%d]\n", i, tmp);
if (tmp >= value)
{
printf("Value found between indexes [%lu] and [%lu]\n",
i < jump ? 0 : i - jump, i);
break;
}
}
if (i >= size)
return (-1);
for (i -= jump; i < size; ++i)
{
tmp = array[i];
printf("Value checked array[%lu] = [%d]\n", i, tmp);
if (tmp == value)
return (i);
}
return (-1);
}
