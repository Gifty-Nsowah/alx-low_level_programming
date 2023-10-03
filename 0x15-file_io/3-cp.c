#include "main.h"
#include <stdlib.h>
#define BUFFER_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 */

int main(int argc, char *argv[])
{
int fd_from, fd_to, bytes_read, bytes_written;
char buffer[BUFFER_SIZE];
struct stat st;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
return (97);
}
fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
return (98);
}
if (fstat(fd_from, &st) == -1)
{
perror("Error getting file information");
close(fd_from);
return (98);
}
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, st.st_mode & 0777);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
close(fd_from);
return (99);
}
while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
close(fd_from);
close(fd_to);
return (99);
}
}
if (bytes_read == -1)
{
perror("Error reading from file");
close(fd_from);
close(fd_to);
return (98);
}
if (close(fd_from) == -1 || close(fd_to) == -1)
{
error("Error closing file descriptor");
return (100);
}
return (0);
}


