#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * strrev - A function that adds a string in reverse to another string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 * @length : The printed length in the function if needed
 *
 * Return: A pointer to the modified string
*/

char *strrev(char *format, unsigned int *pos, unsigned int *length,
		va_list args)
{
	char *format_copy, *str = va_arg(args, char *);
	unsigned int i, format_len = _strlen(format), str_len, totlen;
	int j;

	*length = 0;
	if (str == NULL)
		str = ")llun(";
	str_len = _strlen(str);
	totlen = format_len + str_len - 2;
	format_copy = malloc((format_len + 1) * sizeof(char));
	if (format_copy == NULL)
		return (NULL);

	format_copy = _strcpy(format_copy, format);
	format = realloc(format, (totlen + 1) * sizeof(char));
	if (format == NULL)
		return (NULL);

	format[totlen] = '\0';
	for (j = totlen - 1, i = format_len - 1; i > (*pos) + 1; i--, j--)
		format[j] = format_copy[i];
	free(format_copy);
	for (i = (*pos), j = str_len - 1; j >= 0; i++, j--)
		format[i] = str[j];
	*pos = (*pos) + str_len - 1;

	return (format);
}

/**
 * binary_conv - A function that converts an unsigned integer to binary
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 * @length : The printed length in the function if needed
 *
 * Return: A pointer to the modified string
*/

char *binary_conv(char *format, unsigned int *pos, unsigned int *length,
		va_list args)
{
	char *format_copy;
	unsigned int bin[32];
	unsigned int i, j, bin_len = 0, format_len = _strlen(format),
		     totlen, num = va_arg(args, unsigned int);

	*length = 0;
	if (num == 0)
	{
		bin[0] = 0;
		bin_len = 1;
	}
	else
	{
		for (i = 0; num != 0; i++)
		{
			bin[i] = num % 2;
			num = num / 2;
		}
		bin_len = i;
	}
	totlen = format_len + bin_len - 2;
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
	for (i = (*pos), j = bin_len - 1; j != 0; i++, j--)
		format[i] = bin[j] + 48;
	format[i] = bin[j] + 48;
	*pos = (*pos) + bin_len - 1;

	return (format);
}

/**
 * unsigned_int_arg - A function that adds an unsigned integer to a string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 * @length : The printed length in the function if needed
 *
 * Return: A pointer to the modified string
*/

char *unsigned_int_arg(char *format, unsigned int *pos, unsigned int *length,
		va_list args)
{
	char *format_copy;
	unsigned int num = va_arg(args, unsigned int);
	unsigned int i, j, digit, denom = 1, format_len = _strlen(format),
			num_len, totlen;

	*length = 0;
	num_len = num_length(num);
	totlen = format_len + num_len - 2;
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
	for (i = num_length(num) - 1; i > 0; i--)
		denom *= 10;
	for (i = (*pos); denom != 0; i++)
	{
		digit = num / denom;
		num %= denom;
		format[i] = digit + '0';
		denom /= 10;
		if (num_length(num) != num_length(denom))
		{
			i++;
			format[i] = '0';
			denom /= 10;    }       }
	*pos = (*pos) + num_len - 1;
	return (format);
}
