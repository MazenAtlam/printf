#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * hex - A function that adds an integer in hexadecimal to a string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 * @length : The printed length in the function if needed
 *
 * Return: A pointer to the modified string
*/

char *hex(char *format, unsigned int *pos, unsigned int *length, va_list args)
{
	char *format_copy;
	char hex[9];
	unsigned int i, j, remaind, hex_len = 0, format_len = _strlen(format),
		     totlen, num = va_arg(args, unsigned int);

	*length = 0;
	if (num == 0)
	{
		hex[0] = 48;
		hex_len = 1;    }
	else
	{
		for (i = 0; num != 0; i++)
		{
			remaind = num % 16;
			if (remaind < 10)
				hex[i] = remaind + 48;
			else
			{
				(format[(*pos) + 1] == 'x') ? (hex[i] = remaind + 87)
					: (hex[i] = remaind + 55);	}
			num = num / 16; }
		hex[i] = '\0';
		hex_len = i;    }
	totlen = format_len + hex_len - 2;
	format_copy = malloc((format_len + 1) * sizeof(char));
	if (format_copy == NULL)
		return (NULL);
	format_copy = _strcpy(format_copy, format);
	format = realloc(format, (totlen + 1) * sizeof(char));
	if (format == NULL)
		return (NULL);
	format[totlen] = '\0';
	for (i = totlen - 1, j = format_len - 1; j > (*pos) + 1; i--, j--)
		format[i] = format_copy[j];
	free(format_copy);
	for (i = (*pos), j = hex_len - 1; j != 0; i++, j--)
		format[i] = hex[j];
	format[i] = hex[j];
	*pos = (*pos) + hex_len - 1;
	return (format);	}
