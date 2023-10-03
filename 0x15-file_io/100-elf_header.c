#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * error_exit - Display an error message and exit with status code 98.
 * @msg: The error message to display.
 *
 * Description: This function prints an error message to stderr and exits
 * the program with a status code of 98.
 */
void error_exit(const char *msg) 
{
fprintf(stderr, "%s\n", msg);
exit(98);
}

/**
 * print_elf_header_info - Print information from the ELF header.
 * @header: Pointer to the ELF header structure.
 *
 * Description: This function prints various information from the ELF header,
 * such as Magic, Class, Data, Version, OS/ABI, ABI Version, Type, and
 * Entry point address.
 */
void print_elf_header_info(Elf64_Ehdr *header) 
{
printf("Magic:   ");
int i;
for (i = 0; i < EI_NIDENT; i++) 
{
printf("%02x ", header->e_ident[i]);
}
printf("\n");
printf("Class:                              %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
printf("Data:                               %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" : "2's complement, big-endian");
printf("Version:                            %d (current)\n", header->e_ident[EI_VERSION]);
printf("OS/ABI:                             %d\n", header->e_ident[EI_OSABI]);
printf("ABI Version:                        %d\n", header->e_ident[EI_ABIVERSION]);
printf("Type:                               ");
switch (header->e_type) 
{
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown>\n");
}
printf("Entry point address:                 0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line arguments.
 *
 * Return: 0 on success, or the corresponding error code on failure.
 *
 * Description: This function reads the ELF header of the specified ELF file,
 * checks its validity, and then prints the required information as specified
 * in the question. If there are any errors or if the file is not an ELF file,
 * it exits with a status code of 98 and displays an error message. Otherwise,
 * it displays the ELF header information.
 */
int main(int argc, char *argv[]) 
{
if (argc != 2) 
{
error_exit("Usage: elf_header elf_filename");
}
int fd = open(argv[1], O_RDONLY);
if (fd == -1) 
{
error_exit("Error: Cannot open ELF file");
}
Elf64_Ehdr header;
ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
if (bytes_read != sizeof(Elf64_Ehdr)) 
{
close(fd);
error_exit("Error: Unable to read ELF header");
}
if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 || header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3) 
{
close(fd);
error_exit("Error: Not an ELF file");
}
print_elf_header_info(&header);
close(fd);
return 0;
}


