#include <stdlib.h>
#include "hash_tables.h"

/**
 * hash_table_create - Creates a hash table.
 * @size: The size of the array.
 *
 * Return: Pointer to the newly created hash table, or NULL if an error occurs.
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *hash_table = NULL;
unsigned long int i;

/* Allocate memory for the hash table */
hash_table = malloc(sizeof(hash_table_t));
if (hash_table == NULL)
return (NULL);

/* Allocate memory for the array of hash nodes */
hash_table->array = malloc(size * sizeof(hash_node_t *));
if (hash_table->array == NULL)
{
free(hash_table);
return (NULL);
}

/* Initialize each element of the array to NULL */
for (i = 0; i < size; i++)
hash_table->array[i] = NULL;

/* Set the size of the hash table */
hash_table->size = size;

return (hash_table);
}

