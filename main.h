#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRUNG "(null)"

#define PARAMS_INIT (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

#define CONVERT_LOWERCASE
#define CONVERT_UNSIGNED

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsign value
 *
 * @plus_flag: on if plus_flag specified
 * @plus_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * #minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified 
 *
 * @h_modifier: on if h_modifier is specified
 * @i_modifier: on if i_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int i_modifier		; 1;
} params_t

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f) (va_list, params_t *);
} specifier_t

/* _put.c module */
int _puts(char *str);
int _putchar(int c);

/* print_function.c module */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_s(va_list ap, params_t *params);

/* number.c module */
char *convert(long int num, int base, int flage, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c module */
int(*get_specifier )
