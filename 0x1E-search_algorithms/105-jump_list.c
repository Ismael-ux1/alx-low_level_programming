#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
 * jump_list - Searches for a value in a sorted list of integers using
 *             the Jump search algorithm.
 * @list: A pointer to the head of the list to search in.
 * @size: The number of nodes in list.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the head of the list is NULL, NULL.
 *         Otherwise, a pointer to the first node where value is located.
 *
 * Description: Uses the square root of the size of the list as the jump step.
 */

listint_t *jump_list(listint_t *list, size_t size, int value)
{
size_t jump;
listint_t *left, *right;
size_t i;

if (list == NULL)
return (NULL);

jump = sqrt(size);
left = list;
right = list;

/* Move the right pointer ahead by 'jump' nodes. */
while (right->next != NULL && right->index < size - 1)
{
left = right;
for (i = 0; i < jump && right->next != NULL; i++)
right = right->next;

printf("Value checked at index [%lu] = [%d]\n", right->index, right->n);
if (right->n >= value)
{
printf("Value found between indexes [%lu] and [%lu]\n",
left->index, right->index);
break;
}
}

/* Perform linear search between left and right pointers. */
while (left != NULL && left->index <= right->index)
{
printf("Value checked at index [%lu] = [%d]\n", left->index, left->n);
if (left->n == value)
return (left);
left = left->next;
}
return (NULL);
}
