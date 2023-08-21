#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * char_arg - A function that adds a character to a string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the character in
 *
 * Return: A pointer to the modified string
*/

char *char_arg(char *format, unsigned int *pos, va_list args)
{
	unsigned int i = (*pos);
	char ch;

	if (format[i + 1] == 'c')
	{
		ch = va_arg(args, int);
		if (ch >= 0 && ch <= 31)
			ch = 0;
		format[i] = ch;
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
 * Return: A pointer to the modified string
*/

char *string_arg(char *format, unsigned int *pos, va_list args)
{
	char *str = va_arg(args, char *), format_copy;
	unsigned int i, j, format_len = _strlen(format),
		str_len = _strlen(str), totlen = format_len + str_len - 2;

	if (str == NULL || str[0] == '\0')
		str = "(null)";
	format_copy = _strcpy(format_copy, format);
	format = realloc(format, (totlen + 1) * sizeof(char));
	if (format == NULL)
		return (NULL);

	format[totlen] = '\0';
	for (i = totlen - 1, j = format_len - 1; j > (*pos) + 1; i--, j--)
		format[i] = format_copy[j];
	for (i = (*pos), j = 0; str[j] != '\0'; i++, j++)
		format[i] = str[j];
	*pos = (*pos) + str_len - 1;

	return (format);
}

/**
 * int_arg - A function that adds an integer to a string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 *
 * Return: A pointer to the modified string
*/

char *int_arg(char *format, unsigned int *pos, va_list args)
{
	int num = va_arg(args, int);
	unsigned int i, j, sign = 0, digit, denom = 1, format_len = _strlen(format),
		num_len = num_length(num), totlen = format_len + num_len - 2;

	if (num < 0)
	{
		totlen++;
		num = num * -1;
		format[(*pos)] = '-';
		sign = 1;
	}
	format = realloc(format, (totlen + 1) * sizeof(char));
	if (format == NULL)
		return (NULL);

	format[totlen] = '\0';
	for (i = totlen - 1, j = format_len - 1; j > (*pos) + 1; i--, j--)
		format[i] = format[j];
	for (i = num_length(num) - 1; i > 0; i--)
		denom *= 10;
	for (i = (*pos) + sign; denom != 0; i++)
	{
		digit = num / denom;
		num %= denom;
		format[i] = digit + '0';
		denom /= 10;
		if (num_length(num) != num_length(denom))
		{
			i++;
			format[i] = '0';
			denom /= 10;
		}
	}
	*pos = (*pos) + sign + num_len - 1;

	return (format);
}
