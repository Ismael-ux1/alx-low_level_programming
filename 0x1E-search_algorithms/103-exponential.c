#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array of integers
 * using the Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @left: The leftmost index of the subarray to search in
 * @right: The rightmost index of the subarray to search in
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
size_t mid;

if (array == NULL || left > right)
return (-1);

while (left <= right)
{
printf("Searching in array: ");
for (mid = left; mid < right; mid++)
printf("%d, ", array[mid]);
printf("%d\n", array[mid]);

mid = (left + right) / 2;
if (array[mid] == value)
return (mid);
else if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}
return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The first index where value is located, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
size_t bound = 1;

if (array == NULL || size == 0)
return (-1);

while (bound < size && array[bound] < value)
{
printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
bound *= 2;
}
bound = bound < size - 1 ? bound : size - 1;
printf("Value found between indexes [%lu] and [%lu]\n", bound / 2, bound);
return (binary_search(array, bound / 2, bound, value));
}
