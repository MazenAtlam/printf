#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * char_arg - A function that adds a character to a string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the character in
 *
 * Return: Nothing
*/

char *char_arg(char *format, unsigned int *pos, va_list args)
{
	unsigned int i = (*pos);

	if (format[i + 1] == 'c')
	{
		format[i] = va_arg(args, int);
		if (format[i] == '\0')
			format[i] = 0;
	}
	while (format[i + 2] != '\0')
	{
		format[i + 1] = format[i + 2];
		i++;
	}
	format[i + 1] = '\0';
	format = realloc(format, (_strlen(format)) * sizeof(char));

	return (format);
}

/**
 * string_arg - A function that adds a string to another string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 *
 * Return: Nothing
*/

char *string_arg(char *format, unsigned int *pos, va_list args)
{
	char *str = va_arg(args, char *);
	unsigned int i, j, format_len = _strlen(format),
		str_len = _strlen(str), totlen = format_len + str_len - 2;

	if (str == NULL)
		str = "(null)";
	format = realloc(format, (totlen + 1) * sizeof(char));
	if (format == NULL)
		return (NULL);

	format[totlen] = '\0';
	for (i = totlen - 1, j = format_len - 1; j > (*pos) + 1; i--, j--)
		format[i] = format[j];
	for (i = (*pos), j = 0; str[j] != '\0'; i++, j++)
		format[i] = str[j];
	*pos = (*pos) + str_len - 1;

	return (format);
}
