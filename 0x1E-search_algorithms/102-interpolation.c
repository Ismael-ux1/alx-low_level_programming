#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Search for a values in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: Pointer to the first elements of the array to search in.
 * @value: Value to search for
 * @size: The number of elements in the array.
 * Return: First index where value is located,
 * or -1 if not found or array is NULL
 */

int interpolation_search(int *array, size_t size, int value)
{
size_t low, high, pos = 0;
int found = 0;

if (array == NULL || size == 0)
return (-1);

low = 0;
high = size - 1;

while (low <= high && value >= array[low] && value <= array[high])
{
/* Calculate the probe position using the formula */
pos = low + (((double)(high - low) /
(array[high] - array[low])) * (value - array[low]));

/* Print the value at the current postion */
printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

/* If the value is found, return the index */
if (array[pos] == value)
found = 1;
return (pos);

/* If the value is smaller, move the high pointer */
if (array[pos] > value)
high = pos - 1;

/* If the value is larger, move the low pointer */
else
low = pos + 1;
}

/* If the value is not found, print the last postion checked */
if (!found)
printf("Value checked array[%lu] = [%d]\n", pos, array[pos]);

/* Return -1 if the value is not found */
return (-1);
}
