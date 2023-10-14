#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary_recursive - Recursively searches for a value in,
 *                             a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @left: The leftmost index of the subarray to search in
 * @right: The rightmost index of the subarray to search in
 * @value: The value to search for
 *
 * Return: The index where the first occurrence of value is located,
 *         or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
size_t i;
size_t mid;

if (left <= right)
{
printf("Searching in array: ");
for (i = left; i < right; i++)
printf("%d, ", array[i]);
printf("%d\n", array[i]);

mid = left + (right - left) / 2;

if (array[mid] == value)
{
if (mid == left || array[mid - 1] != value)
return (mid);
return (advanced_binary_recursive(array, left, mid, value));
}
if (array[mid] < value)
return (advanced_binary_recursive(array, mid + 1, right, value));

return (advanced_binary_recursive(array, left, mid, value));
}
return (-1);
}

/**
 * advanced_binary - Searches for a value in a sorted array of,
 *                   integers using recursion
 * @array: Pointer to the first element of the array to search in
 * @size: The number of elements in array
 * @value: The value to search for
 *
 * Return: The index where the first occurrence of value is located,
 *         or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
if (array == NULL)
return (-1);
return (advanced_binary_recursive(array, 0, size - 1, value));
}
