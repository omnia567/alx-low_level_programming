#include "main.h"

/**
 * factorial - returns the factorial of a number
 * @n: number to return the factorial from
 *
 * Return: factorial of x
 */
int factorial(int x)
{
	if (x < 0)
		return (-1);
	if (x == 0)
		return (1);
	return (x * factorial(x - 1));
}
