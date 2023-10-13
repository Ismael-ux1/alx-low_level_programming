#include <stdio.h>
#include "search_algos.h"

/**
 * print_subarray - Prints a subarray from start to end
 *
 * @array: The array to print the subarray from.
 * @start: The start index of the subarray.
 * @end: The end index of the subarray.
*/
void print_subarray(int *array, size_t start, size_t end)
{
size_t i;
printf("Searching in array: %d", array[start]);
for (i = start + 1; i <= end; i++)
{
printf(", %d", array[i]);
}
printf("\n");
}


/**
 * exponential_search - Searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 *
 * Return: first index where value is located,
 * or -1 if not found or array is NULL
 */

int exponential_search(int *array, size_t size, int value)
{
size_t i = 1;
size_t start, end;

if (array == NULL || size == 0)
return (-1);

for (start = 0; i < size && array[i] < value; start = i, i *= 2)
{
printf("Value checked array[%lu] = [%d]\n", i, array[i]);
}

end = (i < size) ? i : size - 1;

printf("Value found between indexes [%lu] and [%lu]\n", start, end);
print_subarray(array, start, end);

while (start <= end)
{
size_t mid = (start + end) / 2;
printf("Value checked array[%lu] = [%d]\n", mid, array[mid]);

if (array[mid] == value)
return (mid);

if (array[mid] < value)
start = mid + 1;
else
end = mid - 1;

printf("Searching in array: ");
print_subarray(array, start, end);
}

return (-1);
}
