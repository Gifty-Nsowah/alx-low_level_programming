#include "main.h"
#include <unistd.h>
/**
 * _putchar - write a character c to stdout
 * @c: A character  printing
 *
 * Return: Success 1.
 * On error, -1 is returned, and errno is set properly.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

