#include "main.h"
/**
 * print_char - Prints a char
 * Return: number of characters printed
 * @args: argument
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	write(STDOUT_FILENO, &c, 1);
	return (1);
}
/**
 * print_str - prints a string
 * @args: argument
 * Return: number of character printed
 */
int print_str(va_list args)
{
	int len;
	char *s = va_arg(args, char*);

	if (!s)
		s = "(null)";
	len = _strlen(s);
	write(STDOUT_FILENO, s, len);
	return (len);
}
/**
 * print_int - prints an integer.
 * @args: argument
 * Return: number of chars printed
 */

int print_int(va_list args)
{
	long int n = va_arg(args, int);
	char buffer[BUFF_SIZE];
	int i = 0, count = 0;

	if (n == 0)
		buffer[i++] = '0';

	if (n < 0)
	{
		write(STDOUT_FILENO, &"-", 1);
		n = -n;
		count++;
	}
	for (; n > 0; i++)
	{
		buffer[i] = '0' + (n % 10);
		n /= 10;

	}
	buffer[i] = '\0';
	while (i > 0)
	{
		write(STDOUT_FILENO, &buffer[--i], 1);
		count++;
	}
	return (count);
}
/**
 * print_37 - Prints a percent sign
 * @list: ignored
 * Return: Number of chars printed
 */
int print_37(va_list list)
{
	(void)list;
	return (_putchar('%'));
}
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
	int _strlen(char *s)
{
	int cnt = 0;

	while (*s != '\0')
	{
		cnt++;
		s++;
	}
	return (cnt);
}
