#include "main.h"
/**
* _strlen - determine strength length
* @s: character parameter pointer
* Return: c
*/
int _strlen(char *s)
{
int c = 0;

while (s[c] != '\0')
c++;

return (c);
}
