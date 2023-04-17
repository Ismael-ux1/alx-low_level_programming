#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 *
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
dog_t *new_dog;
char *name_copy;
char *owner_copy;

new_dog = malloc(sizeof(dog_t));
if (new_dog == NULL)
return (NULL);

name_copy = malloc(sizeof(char) * (_strlen(name) + 1));
if (name_copy == NULL)
{
free(new_dog);
return (NULL);
}

owner_copy = malloc(sizeof(char) * (_strlen(owner) + 1));
if (owner_copy == NULL)
{
free(name_copy);
free(new_dog);
return (NULL);
}

name_copy = _strcpy(name_copy, name);
owner_copy = _strcpy(owner_copy, owner);

new_dog->name = name_copy;
new_dog->age = age;
new_dog->owner = owner_copy;

return (new_dog);
}

/**
 * _strlen - returns length of string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
int i;

for (i = 0; s[i]; i++)
continue;

return (i);
}

/**
 * _strcpy - copies string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to destination string
 */
char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i]; i++)
dest[i] = src[i];

dest[i] = '\0';

return (dest);
}
