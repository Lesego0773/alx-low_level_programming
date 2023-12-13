#include "main.h"

/**
 * binary_to_uint - Convert binary to decimal.
 * @b: The binary number in string format.
 *
 * Description: Converts a binary string to a decimal number.
 * Section header: The header of this function is header.h.
 * Return: The converted decimal number, or 0 if @b is NULL or contains
 *         characters other than '0' and '1'.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result, base;
	int i;

	result = 0;
	i = 0;
	base = 1;

	if (!b)
		return (0);

	while (*(b + i))
	{
		if (*(b + i) != '0' && *(b + i) != '1')
			return (0);
		i++;
	}

	for (i--; i >= 0; i--)
	{
		if (*(b + i) == '1')
			result = result + base;
		base = base * 2;
	}

	return (result);
}

