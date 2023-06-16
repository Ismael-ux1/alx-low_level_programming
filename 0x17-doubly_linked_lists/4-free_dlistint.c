#include "lists.h"
#include <stdlib.h>

/**
 * free_dlistint - frees a dlistint_t_list
 * @head: pointer to head of list
 */
void free_dlistint(dlistint_t *head)
{
dlistint_t *temp;
while (head != NULL)
{
temp = head;
head = head->next;
free(temp);
}
}
