#include "palindrome.h"

/**
 * is_palindrome - checks if unsigned long int is a palindrome
 * @n: int to check
 * Return: 1 if yes, or 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long r = n, x = 0;

	while (r != 0)
	{
		x = x * 10;
		x += r % 10;
		r /= 10;
	}

	return (x == n);
}
