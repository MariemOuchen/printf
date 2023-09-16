#include "main.h"

/**
 * print_r - prints a reversed string.
 * @arg: string to print in reverse.
 * Return: number of chars printed.
 */
int print_r(va_list arg)
{

	char *s = va_arg(arg, char*);
	int i;
	int j = 0;

	if (s == NULL)
		s = "(null)";
	while (s[j] != '\0')
		j++;
	for (i = j - 1; i >= 0; i--)
		_putchar(s[i]);
	return (j);
}

/**
 * print_R - prints a string with rot13 encryption.
 * @arg: string to print.
 * Return: number of chars printed.
 */
int print_R(va_list arg)
{
	int i, j, cont = 0;
	char *str = va_arg(arg, char *);
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alpha[j])
			break;
		}
		if (str[i] == alpha[j])
		{
			_putchar(rot13[j]);
			cont++;
		}
		else
		{
			_putchar(str[i]);
			cont++;
		}
	}

	return (cont);
}

/**
 * print_u - prints a unsigned int number.
 * @arg: number to print.
 * Return: number of digits printed.
 */
int print_u(va_list arg)
{
	unsigned int num = va_arg(arg, int);
	int cont = 1;

	print_int_aux(num);
	if (num == 4294967295)
		return (10);

	while (num / 10 != 0)
	{
		cont++;
		num = num / 10;
	}

	return (cont);
}

/**
 * print_int_aux - auxiliar function for prints an unsigned int number.
 * @num: number to print.
 * Return: always 0 (success).
 */
int print_int_aux(unsigned int num)
{
	if (num / 10 != 0)
		print_int_aux(num / 10);
	_putchar('0' + (num % 10));

	return (0);
}
