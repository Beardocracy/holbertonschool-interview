#include "palindrome.h"

/**
 * is_palindrome - checks if a number is palindromic
 * @n: the number to check
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long int temp = n;
	unsigned long int reverse = 0;

	while (temp > 0)
	{
		reverse = (temp % 10) + (reverse * 10);
		temp /= 10;
	}
	return (reverse == n);
}
