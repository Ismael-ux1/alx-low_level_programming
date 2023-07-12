#include "hash_tables.h"

/**
 * key_index - Calculates the index of a key in a hash table array.
 * @key: The key to be hashed.
 * @size: The size of the array.
 *
 * Return: The calculated index.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash_value = hash_djb2(key);
unsigned long int index = hash_value % size;

return (index);
}
