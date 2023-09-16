#include "main.h"

/**
 * print_b - prints a unsigned int number in binary notation.
 * @arg: number to print.
 * Return: number of digits printed.
 */
int print_b(va_list arg)
{
	int cont = 1, i = 0, tab[33];
	unsigned int num = va_arg(arg, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		return (cont);
	}
	while (num != 0)
	{
		tab[i] = (num % 2);
		num = num / 2;
		i++;
	}
	cont = i;
	i--;
	for (; i >= 0; i--)
		_putchar(tab[i] + '0');

	return (cont);
}

/**
 * print_o - prints a unsigned int number in octal notation.
 * @arg: number to print.
 * Return: number of digits printed.
 */
int print_o(va_list arg)
{
	int cont = 1, i = 0, tab[13];
	unsigned int num = va_arg(arg, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		return (cont);
	}
	while (num != 0)
	{
		tab[i] = (num % 8);
		num = num / 8;
		i++;
	}
	cont = i;
	i--;
	for (; i >= 0; i--)
		_putchar(tab[i] + '0');

	return (cont);
}

/**
 * converter_x - converts a unsigned int number
 * into hexadecimal (lowercase) notation.
 * @i: number to convert.
 */
void converter_x(int i)
{
	if (i < 10)
		_putchar(i + '0');
	if (i == 10)
		_putchar('a');
	if (i == 11)
		_putchar('b');
	if (i == 12)
		_putchar('c');
	if (i == 13)
		_putchar('d');
	if (i == 14)
		_putchar('e');
	if (i == 15)
		_putchar('f');
}

/**
 * print_x - prints a unsigned int number in hexadecimal (lowercase) notation.
 * @arg: number to print.
 * Return: number of digits printed.
 */
int print_x(va_list arg)
{
	int cont = 1, i = 0, tab[8];
	unsigned int num = va_arg(arg, unsigned int);

	if (num == 0)
	{
		_putchar('0');
		return (cont);
	}

	while (num != 0)
	{
		tab[i] = (num % 16);
		num = num / 16;
		i++;
	}
	cont = i;
	i--;

	for (; i >= 0; i--)
		converter_x(tab[i]);

	return (cont);
}
