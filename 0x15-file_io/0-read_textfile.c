#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
if (filename == NULL)
{
return (0);
}
file = fopen(filename, "r");
if (file == NULL)
{
return (0);
}
char *buffer = (char *)malloc(letters + 1);
if (buffer == NULL)
{
close(file);
return (0);
}
ssize_t bytes_read = pread(buffer, sizeof(char), letters, file);
if (bytes_read <= 0)
{
free(buffer);
close(file);
return (0);
}
buffer[bytes_read] = '\0';
ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
free(buffer);
close(file);
if (bytes_written != bytes_read)
{
return (0);
}
return (bytes_read)
}
