This is a readme for the project C - Hash tables

C Algorithm Data structure

Requirements
General
Allowd editors:  vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called hash_tables.h
Don’t forget to push your header file
All your header files should be include guarded


All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
You are allowed to use the C standard library
The prototypes of all your functions should be included in your header file called hash_tables.h
Don’t forget to push your header file
All your header files should be include guarded

Data Structures
Please use these data structures for this project:

/** 
* struct hash_node_s - Node of a hash table
* 
* @key: The key, string
* The key is unique in the HasgTable
* @value: The value corresponding to the a key
* @next: A pointer to the next node of the list
*/

typedef struct hash_node_s
{
   char *key;
   char *value;
   struct hash_node_s *next;
} hash_node_t;

/**
* struct hash_table_s = Hash table ata structure
*
*@size: The size of the  array 

