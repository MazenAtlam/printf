#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _strlen - A function that gets the length of a string
 * @str: The string
 *
 * Return: The length of the string
*/

unsigned int _strlen(const char *str)
{
	unsigned int i = 0;

	while (str[i] != '\0' && str != NULL)
		i++;

	return (i);
}

/**
 * _strcpy - A function that copies a string pointed to
 * @dest: The returned string
 * @src: The sring to be copied
 *
 * Return: The pointer to dest
*/

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * num_length - A function that computes the length of an integer
 * @num: The integer
 *
 * Return: The length
*/

unsigned int num_length(int num)
{
	unsigned int length = 0;

	if (num < 0)
		num = num * -1;
	if (num >= 0 && num <= 9)
		return (1);

	while (num != 0)
	{
		num = num / 10;
		length++;
	}

	return (length);
}

/**
 * _printf - A function prints a string includes n of arguments of any type
 * @format: The customed string to be printed
 *
 * Return: The number of printed characters
*/

int _printf(const char *format, ...)
{	unsigned int i, j, length = 0;
	char *str;
	va_list args;
	fr_t type[] = { {"c", char_arg}, {"%", char_arg}, {"r", strrev},
	{"s", string_arg}, {"d", int_arg}, {"i", int_arg}, {"b", binary_conv},
	{"u", unsigned_int_arg}, {"R", rot13_conv}, {"o", oct},
	{"x", hex}, {"X", hex}, {NULL, NULL} };

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && format[2] == '\0')
		return (-1);
	va_start(args, format);
	str = malloc((_strlen(format) + 1) * sizeof(unsigned char));
	if (str == NULL)
		return (-1);
	str = _strcpy(str, format);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%' && format[i + 1] != '\0')
		{
			for (j = 0; type[j].ch != NULL; j++)
			{
				if (str[i + 1] == type[j].ch[0])
				{
					str = type[j].func(str, &i, &length, args);
					if (str == NULL)
						return (-1);
					break;	}	}	}	}
	va_end(args);
	length = length + _strlen(str);
	write(1, str, _strlen(str));
	free(str);
	return (length);	}
