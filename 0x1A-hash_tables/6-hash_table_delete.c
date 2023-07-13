#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
hash_node_t *node, *temp;
unsigned long int i;

if (ht == NULL)
return;

/* Free memory for each node and its elements */
for (i = 0; i < ht->size; i++)
{
node = ht->array[i];
while (node != NULL)
{
temp = node;
node = node->next;
free(temp->key);
free(temp->value);
free(temp);
}
}

/* Free memory for the array and the hash table structure */
free(ht->array);
free(ht);
}
