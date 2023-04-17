#include <stdlib.h>
#include "dog.h"
/**
 * free_dog - Free dogs.
 * @d: type pointer struct data.
 * Return: void
 */
void free_dog(dog_t *d)
{
if (d == NULL)
return;
free(d->name);
free(d->owner);
free(d);
}
