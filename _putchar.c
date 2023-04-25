#include "main.h"
/**
 * _putchar - prints to stdout
 * @c: char to print
 * Return: 1 if success -1 if fail
 */
int _putchar(char c)
{
	if (c)
	{
		write(STDOUT_FILENO, &c, 1);
		return (1);
	}
	else
		return (-1);
}
