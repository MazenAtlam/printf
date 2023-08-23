#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * rot13_conv - A function that adds the rot13 of a string to another string
 * @args: The arguments list
 * @format: The string to be edited
 * @pos: A pointer to the position to be added the string in
 * @length : The printed length in the function if needed
 *
 * Return: A pointer to the modified string
*/

char *rot13_conv(char *format, unsigned int *pos, unsigned int *length,
		va_list args)
{
	char *format_copy;
	char *str = va_arg(args, char *);
	char s[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	unsigned int i, j, k = 1, format_len = _strlen(format), str_len, totlen;

	*length = 0;
	if (str == NULL)
	{
		str = "(null)";
		k = 0;	}
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
	for (i = totlen - 1, j = format_len - 1; j > (*pos) + 1; i--, j--)
		format[i] = format_copy[j];
	free(format_copy);
	if (k != 0)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			for (j = 0; s[j] != '\0'; j++)
			{
				if (str[i] == s[j])
				{
					str[i] = rot13[j];
					break;	}	}	}	}
	for (i = (*pos), j = 0; str[j] != '\0'; i++, j++)
		format[i] = str[j];
	*pos = (*pos) + str_len - 1;
	return (format);
}
