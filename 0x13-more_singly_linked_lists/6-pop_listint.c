#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t linked list.
 * @head: A pointer to a pointer to the first node of the list.
 *
 * Return: The integer value stored in the head node,
 *  or 0 if the list is empty.
 */
int pop_listint(listint_t **head)
{
listint_t *temp;
int n;

if (*head == NULL)
return (0);

temp = *head;
n = temp->n;
*head = temp->next;
free(temp);

return (n);
}
