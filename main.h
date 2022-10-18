#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_type;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_type *f);
} ph;

/* _printf */
int _printf(const char *format, ...);

/* what_to_print */
int (*what_to_print(char s))(va_list, flags_type *f);

/* check_flag */
int check_flag(char s, flags_type *f);

/* print_char_or_string */
int print_string(va_list l, flags_type *f);
int print_char(va_list l, flags_type *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_percent */
int print_percent(va_list l, flags_type *f);

#endif