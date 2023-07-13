#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: Pointer to the newly created sorted hash table, or NULL if an error occurs.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *ht = NULL;
unsigned long int i;

/* Allocate memory for the hash table */
ht = malloc(sizeof(shash_table_t));
if (ht == NULL)
return (NULL);

/* Allocate memory for the array of hash nodes */
ht->array = malloc(size * sizeof(shash_node_t *));
if (ht->array == NULL)
{
free(ht);
return (NULL);
}

/* Initialize each element of the array to NULL */
for (i = 0; i < size; i++)
ht->array[i] = NULL;

/* Set the size of the hash table */
ht->size = size;
ht->shead = NULL;
ht->stail = NULL;

return (ht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table.
 * @ht: The sorted hash table to add/update the key/value pair.
 * @key: The key to be added/updated.
 * @value: The value associated with the key.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *new_node = NULL, *node = NULL;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (0);

/* Calculate the index */
index = key_index((const unsigned char *)key, ht->size);

/* Check if the key already exists */
node = ht->array[index];
while (node != NULL)
{
if (strcmp(node->key, key) == 0)
{
/* Update value and return */
free(node->value);
node->value = strdup(value);
if (node->value == NULL)
return (0);
return (1);
}
node = node->next;
}

/* Create a new node */
new_node = malloc(sizeof(shash_node_t));
if (new_node == NULL)
return (0);
new_node->key = strdup(key);
new_node->value = strdup(value);
if (new_node->key == NULL || new_node->value == NULL)
{
free(new_node->key);
free(new_node->value);
free(new_node);
return (0);
}

/* Add the new node to the sorted linked list */
if (ht->shead == NULL || strcmp(new_node->key, ht->shead->key) < 0)
{
new_node->snext = ht->shead;
if (ht->shead != NULL)
ht->shead->sprev = new_node;
ht->shead = new_node;
}
else
{
node = ht->shead;
while (node->snext != NULL && strcmp(new_node->key, node->snext->key) > 0)
node = node->snext;

new_node->snext = node->snext;
new_node->sprev = node;
if (node->snext != NULL)
node->snext->sprev = new_node;
node->snext = new_node;
}

/* Add the new node to the array */
new_node->next = ht->array[index];
ht->array[index] = new_node;

/* Update the tail of the sorted linked list */
if (new_node->snext == NULL)
ht->stail = new_node;

return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key in a sorted hash table.
 * @ht: The sorted hash table to search.
 * @key: The key to search for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

/* Calculate the index */
index = key_index((const unsigned char *)key, ht->size);

/* Search for the key in the linked list at the calculated index */
node = ht->array[index];
while (node != NULL)
{
if (strcmp(node->key, key) == 0)
return (node->value);
node = node->next;
}

/* Key not found */
return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *node;

if (ht == NULL)
return;

printf("{");
for (node = ht->shead; node != NULL; node = node->snext)
{
printf("'%s': '%s'", node->key, node->value);
if (node->snext != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *node;

if (ht == NULL)
return;

printf("{");
for (node = ht->stail; node != NULL; node = node->sprev)
{
printf("'%s': '%s'", node->key, node->value);
if (node->sprev != NULL)
printf(", ");
}
printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *node, *temp;
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
