#include "holberton.h"
#include <stddef.h>


/**
 * wild_rec - recursive helper function for comparing two strings
 * @s1: Pointer to first char in string without *
 * @s2: Pointer to first char in string with *
 * @s2_temp: Pointer to store chars of s2
 * Return: 1 if identical, else 0
 */
int wild_rec(char *s1, char *s2, char *s2_temp)
{
	if (s2 == NULL)
		return (0);
	if (!*s1 && !*s2)
		return (1);
	if (*s2 == '*')
		return (wild_rec(s1, s2 + 1, s2 + 1));
	if (*s1 && *s2 != *s1)
	{
		if (s2_temp == s2)
			return (wild_rec(s1 + 1, s2, s2_temp));
		return (wild_rec(s1, s2_temp, s2_temp));
	}
	if (*s1 == *s2)
		return (wild_rec(s1 + 1, s2 + 1, s2_temp));
	return (0);
}

/**
 * wildcmp - Compares 2 strings.
 * @s1: Pointer to first char in string without * special character
 * @s2: Pointer to first char in string potentially including *
 * Return: 1 if considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	char *s2_temp = NULL;
	return (wild_rec(s1, s2, s2_temp));
}
