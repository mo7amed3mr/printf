#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned
 *
 * @plus_flag: on if plus_flag
 * @space_flag: on if space_flag
 * @hashtag_flag: on if hashtag_flag
 * @zero_flag: on if zero_flag
 * @minus_flag: on if minus_flag
 * @width: on if width
 * @precision: on if precision
 * @h_modifier: on if h_modifier
 * @l_modifier: on if l_modifier
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
	unsigned int width		: 1;
	unsigned int precision		: 1;
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: The format.
 * @f: The function associated.
*/

typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* print puts */
int _puts(char *str);
int _putchar(int c);

/* print fun */
int print_char(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_percent(va_list pa, params_t *params);
int print_S(va_list ap, params_t *params);

/* print functions */
char *convert(long int num, int base, int flags, params_t);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* print string */
int (*get_specifier(char *s)) (va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* print number */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* print numbers */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print digit */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_numver_left_shift(char *str, params_t *params);

/* print param */
void init_params(params_t *params, va_list ap);

/* print precision*/
char *get_precision(char *p, params_t *params, va_list ap);

/* print pritf.c */
int _printf(const char *format, ...);

#endif
