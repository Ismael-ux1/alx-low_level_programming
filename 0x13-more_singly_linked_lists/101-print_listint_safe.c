#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow = head, *fast = head;
size_t count = 0;

if (head == NULL)
exit(98);

while (slow != NULL && fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
printf("[%p] %d\n", (void *)slow, slow->n);
break;
}

printf("[%p] %d\n", (void *)slow, slow->n);
count++;
}

if (slow == NULL || fast == NULL || fast->next == NULL)
{
while (head != NULL)
{
printf("[%p] %d\n", (void *)head, head->n);
count++;
head = head->next;
}
}

printf("-> [%p] %d\n", (void *)slow, slow->n);

return (count);
}

