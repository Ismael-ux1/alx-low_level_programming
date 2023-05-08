#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * read_textfile - reads a text file and prints it to POSIX stdout
 * @filename: pointer to name of the file to read
 * @letters: number of letters to read and print
 * Return: actual number of letters read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
int fd, num_read, num_written;
char *buf;

if (filename == NULL)
return (0);

fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);

buf = malloc(sizeof(char) * letters);
if (buf == NULL)
return (0);

num_read = read(fd, buf, letters);
if (num_read == -1)
{
free(buf);
close(fd);
return (0);
}

num_written = write(STDOUT_FILENO, buf, num_read);
if (num_written == -1 || num_written != num_read)
{
free(buf);
close(fd);
return (0);
}

free(buf);
close(fd);
return (num_written);
}
