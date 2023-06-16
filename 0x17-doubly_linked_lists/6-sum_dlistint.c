#include "lists.h"
/**
 * sum_dlistint - Returns the sum of all the elements.
 * in a doubly linked list.
 * @head: Pointer to the head (start) of the list.
 *
 * Return: The sum of all the elements in the list.
 *  If the list is empty, returns 0.
 */

int sum_dlistint(dlistint_t *head)
{
int sum = 0;

while (head != NULL)
{
sum += head->n;
head = head->next;
}
return (sum);
}
