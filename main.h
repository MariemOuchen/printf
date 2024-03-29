#ifndef MAIN_H
#define MAIN_H

#define BUFF_SIZE 1024
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
* struct flags - struct containing pointers to functions
*
* @c: format
* @print: pointer to function assosciated
*/
struct flags
{
	char c;
	int (*print)(va_list);
};

/**
* typedef struct flags ff - struct definition
*
* @flags: format
* @ff: function assosciated
*/

typedef struct flags ff;

int _printf(const char *form, ...);
int _strlen(char *s);

/* Funtions to print chars and strings */
int handle_print(const char *format, int *i, va_list list);
int print_char(va_list list);
int print_str(va_list list);
int _putchar(char c);
int print_37(va_list list);
int print_r(va_list arg);
int print_R(va_list arg);
int print_p(va_list p);
int print_S(va_list val);
/* Functions to print numbers */
int print_int(va_list list);
int print_int_aux(unsigned int num);
int print_b(va_list arg);
int print_u(va_list arg);
int print_o(va_list arg);
int print_x(va_list arg);
int print_X(va_list arg);
#endif
