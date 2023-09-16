#include "main.h"

/**
 * converter_X - converts a unsigned int number
 * into hexadecimal (uppercase) notation.
 * @i: number to convert.
 */
void converter_X(int i)
{
	if (i < 10)
		_putchar(i + '0');
	if (i == 10)
		_putchar('A');
	if (i == 11)
		_putchar('B');
	if (i == 12)
		_putchar('C');
	if (i == 13)
		_putchar('D');
	if (i == 14)
		_putchar('E');
	if (i == 15)
		_putchar('F');
}

/**
 * print_X - prints a unsigned int number in hexadecimal (uppercase) notation.
 * @arg: number to print.
 * Return: number of digits printed.
 */
int print_X(va_list arg)
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
		converter_X(tab[i]);

	return (cont);
}

/**
 * printf_HEX_aux - prints a hexadecimal number.
 * @num: number to print.
 * Return: counter.
 */
int printf_HEX_aux(unsigned int num)
{
	int i;
	int *array;
	int counter = 0;
	unsigned int temp = num;

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));

	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	free(array);
	return (counter);
}

/**
 * print_S - print custom conversion specifier S..
 * @val: argument.
 * Return: the length of the string.
 */

int print_S(va_list val)
{
	char *s;
	int i, len = 0;
	int cast;

	s = va_arg(val, char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			cast = s[i];
			if (cast < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + printf_HEX_aux(cast);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}

/**
 * print_p - prints conversion specifier p.
 * @p: arguments.
 * Return: counter.
 */
int print_p(va_list p)
{
	int counter = 0;
	unsigned int a[16];
	unsigned int i = 0, sum = 0;
	unsigned long n, m = 1152921504606846976;
	char *str = "(nil)";

	n = va_arg(p, unsigned long);
	if (n == 0)
	{
		for (; str[i]; i++)
		{
			_putchar(str[i]);
			counter++;
		}
		return (counter);
	}
	_putchar('0');
	_putchar('x');
	counter = 2;

	a[0] = n / m;
	for (i = 1; i < 16; i++)
	{
		m /= 16;
		a[i] = (n / m) % 16;
	}
	for (i = 0; i < 16; i++)
	{
		sum += a[i];
		if (sum || i == 15)
		{
			if (a[i] < 10)
				_putchar('0' + a[i]);
			else
				_putchar('0' + ('a' - ':') + a[i]);
			counter++;
		}
	}
	return (counter);
}
