#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - entry point
 * @argc: number of arguments from command line
 * @argv: array of pointers to arguments
 * Return: 0 on success, or 98
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *product, *prod_end, *curr_prod, result;
	char *current1, *current2;
	int len1, len2, carry, temp, first;

	if (argc != 3)
	{
		str_print("Error");
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = str_length(num1);
	len2 = str_length(num2);
	product = malloc(sizeof(char) + len1 + len2 + 1);
	prod_end = product + len1 + len2;
	*prod_end = '\0';

	for (current2 = num2 + len2 - 1; current2 >= num2; current2--)
	{
		curr_prod = prod_end + (current2 - num2 - len2 + 1) - 1;
		carry = 0;
		for (current1 = num1 + len1 - 1; current1 >= num1; current1--)
		{
			result = char_product(*current1, *current2, &carry);
			temp = (result - '0') + (first ? 0 : *curr_prod - '0');
			carry += temp / 10;
			*curr_prod = (temp % 10) + '0';
			curr_prod--;
		}
		first = 0;
		*curr_prod = (char)(carry + '0');
	}
	str_print(curr_prod);
	free(product);
	return (0);
}

/**
 * char_product - Multiplies 2 chars
 * @x: char 1
 * @y: char 2
 * @carry: pointer to store the tens digit
 * Return: char representing the product
 */
char char_product(char x, char y, int *carry)
{
	int mul1, mul2, product;

	if (x < '0' || x > '9' || y < '0' || y > '9')
	{
		str_print("Error");
		exit(98);
	}

	mul1 = x - '0';
	mul2 = y - '0';

	product = *carry + (mul1 * mul2);
	*carry = product / 10;

	return ('0' + (product % 10));
}


/**
 * str_print - prints a string of chars, ignoring leading 0s
 * @s: pointer to the first char
 */
void str_print(char *s)
{
	while (*s == '0')
		s++;
	if (!*s)
		_putchar('0');
	while (*s)
		_putchar(*s++);
	_putchar('\n');
}

/**
 * str_length - returns the length of a string
 * @c: Pointer to first char in string
 * Return: length of string
 */
int str_length(char *c)
{
	int len;

	for (len = 0; *c; c++)
		len++;

	return (len);
}
