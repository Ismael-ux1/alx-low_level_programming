#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers
 * @head: Pointer to the head node of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *current = head, *temp;
size_t count = 0;

while (current != NULL)
{
count++;
printf("[%p] %d\n", (void *) current, current->n);
temp = current->next;
if (temp >= current)
{
printf("-> [%p] %d\n", (void *) temp, temp->n);
break;
}
current = temp;
}

if (current == NULL)
return (count);
exit(98);
}

