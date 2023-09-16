#include "main.h"
/**
* _printf - prints out string and arguments
* @format: string to print
* Return: size of string -1 if fail
*/

int _printf(const char *format, ...)
{
	int i, pc = 0, p = 0;
	va_list list;


	if (!format)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			pc++;
		}
		else
		{
			i++;
			if (format[i])
				p = handle_print(format, &i, list);
			else
				p = -1;
			if (p == -1 && format[i])
			{
				print_37(list);
				pc++;
				i--;
			}
			else if (p == -1)
				return (-1);
			else if (p != -1)
				pc += p;
		}
	}
	va_end(list);
	return (pc);
}

/**
 * handle_print - takes care of printing
 * @format: pointer to format string
 * @i: index of char
 * @list: arguments
 * Return: size of print or -1 if fail
 */


int handle_print(const char *format, int *i, va_list list)
{
	ff function[] = {
		{'c', print_char}, {'s', print_str},
		{'%', print_37}, {'i', print_int},
		{'d', print_int}, {'b', print_b},
		{'u', print_u}, {'o', print_o},
		{'x', print_x}, {'X', print_X},
		{'r', print_r}, {'R', print_R},
		{'S', print_S}, {'p', print_p},
		{'\0', NULL}
	};
	int j;

	for (j = 0; j < 15; ++j)
	{
		if (function[j].c == format[*i])
			return (function[j].print(list));
	}
	return (-1);
}
