#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * oct - A function that adds an integer in hexadecimal to a string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 * @length : The printed length in the function if needed
 *
 * Return: A pointer to the modified string
*/

char *oct(char *format, unsigned int *pos, unsigned int *length, va_list args)
{
	char *format_copy;
	int oct[11];
	unsigned int i, j, oct_len = 0, format_len = _strlen(format),
		totlen, num = va_arg(args, unsigned int);

	*length = 0;
	if (num == 0)
	{
		oct[0] = 0;
		oct_len = 1;    }
	else
	{
		for (i = 0; num != 0; i++)
		{
			oct[i] = num % 8;
			num = num / 8; }
		oct_len = i;    }
	totlen = format_len + oct_len - 2;
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
	for (i = (*pos), j = oct_len - 1; j != 0; i++, j--)
		format[i] = oct[j] + 48;
	format[i] = oct[j] + 48;
	*pos = (*pos) + oct_len - 1;
	return (format);
}
