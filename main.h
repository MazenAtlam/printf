#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
unsigned int _strlen(const char *str);
unsigned int num_length(int num);
char *_strcpy(char *dest, const char *src);
char *char_arg(char *format, unsigned int *pos, va_list args);
char *string_arg(char *format, unsigned int *pos, va_list args);
char *int_arg(char *format, unsigned int *pos, va_list args);
char *binary_conv(char *format, unsigned int *pos, va_list args);

/**
 * struct fr - A type printer selector
 * @ch: The char to determine the type
 * @func: A pointer to the selected type function
 *
 * Description: A function that selects the correct type depends on a character
*/

typedef struct fr
{
	char *ch;
	char *(*func)();
} fr_t;

#endif /*_main.h_*/
