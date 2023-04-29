#include "lists.h"

/**
 * get_nodeint_at_index - Returns the nth node of a listint_t linked list.
 * @head: A pointer to the head node of the list.
 * @index: The index of the node to return, starting at 0.
 *
 * Return: If the node does not exist, return NULL. Otherwise, return the nth
 *         node of the list.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
listint_t *current = head;
unsigned int i = 0;

while (current != NULL && i < index)
{
current = current->next;
i++;
}

if (i == index)
{
return (current);
}

return (NULL);
}

