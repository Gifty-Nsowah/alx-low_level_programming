#include "main.h"

/**
 * binary_to_uint - convert binary number to unsigned int/decimal numbers
 * @b: string containing the binary number with a character pointer
 *
 * Return: the converted number/decimal
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int len, i, j, sum, pow;
	int base;
	base = 2;
	sum = 0;
	pow = 1;

	if (b ==NULL)
		return (0);

	for (i = 0; b[i]; len++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		dec_val = 2 * dec_val + (b[i] - '0');
	}

	return (dec_val);
}

