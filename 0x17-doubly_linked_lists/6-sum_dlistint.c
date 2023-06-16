#include "lists.h"
/**
 * sum_dlisint - returns the sum of all the data (n) of a dlsint_t linked list
 * @head: pointer to head of list
 * Return: sum of all the data (n) of the list, ot 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head)
{
int sum = 0;
dlistint_t *current = head;

while (head != NULL)
{
sum += head->n;
head = head->next;
}
return (sum);
}
