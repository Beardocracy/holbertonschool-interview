#include <stdlib.h>
#include <stdio.h>
#include "regex.h"

/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: the string to test for a match
 * @pattern: the regex pattern
 * Return: 1 if match, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	if (!*str)
	{
		if (*pattern)
		{
			if (pattern[1] == '*' && regex_match(str, pattern + 2))
				return (1);
			return (0);
		}
		return (1);
	}

	if (pattern[1] == '*')
	{
		if (*pattern == '.' || *str == *pattern)
		{
			return (regex_match(str + 1, pattern) ||
				regex_match(str, pattern + 2));
		}
		return (regex_match(str, pattern + 2));
	}
	if (*pattern == '.' || *pattern == *str)
		return (regex_match(str + 1, pattern + 1));
	return (0);
}
