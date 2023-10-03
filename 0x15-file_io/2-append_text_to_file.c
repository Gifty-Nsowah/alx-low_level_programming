#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file.
 * @text_content: The text to append to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
if (filename == NULL)
{
return (-1) ;  (Return -1 if filename is NULL)
}
if (text_content == NULL)
{
return (1); Do nothing if text_content is NULL and return 1 (success)
}
file;
int result;
file = fopen(filename, "a"); Open the file in append mode
if (file == NULL)
{
return (-1) ;  (Return -1 if unable to open the file)
}
result = fputs(text_content, file); Write the text content to the file
fclose(file);
if (result == EOF)
{
return (-1) ;  (Return -1 if there was an error writing to the file)
}
return (1);  (Return 1 to indicate success)
}

