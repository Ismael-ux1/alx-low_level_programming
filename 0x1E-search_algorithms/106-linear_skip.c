#include "search_algos.h"
#include <stdio.h>
#include <math.h>
#include <stddef.h>

/**
 * linear_skip - Search for a value in a sorted skip list of integers.
 * @list: A pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: A pointer to the first node where value is located or NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *current = list;
skiplist_t *express = list;

if (list == NULL)
return (NULL);

while (express && express->n < value)
{
current = express;
if (express->express == NULL)
{
while (express->next)
express = express->next;
break;
}
express = express->express;
printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
}

printf("Value found between indexes [%lu] and [%lu]\n",
current->index, express->index);

while (current && current->n <= value)
{
printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
if (current->n == value)
return (current);
current = current->next;
}

return (NULL);
}
