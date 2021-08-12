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
	int i_str = 0;
	int i_pat = 0;
	int pat_len, str_len;

	pat_len = string_max_index(pattern);
	str_len = string_max_index(str);
	while (i_pat < pat_len)
	{
		if (str[i_str] == '.' || str[i_str] == '*')
			return (0);
		else if (pattern[i_pat] == '*')
			i_pat++;
		else if (pattern[i_pat + 1] == '*')
			i_pat = i_pat + 2;
		else if (pattern[i_pat] == '.' || str[i_str] == pattern[i_pat])
		{
			i_pat++;
			i_str++;
		}
		else
		{
			while (i_str < str_len)
			{
				if (str[i_str] != pattern[i_pat])
					i_str++;
			}
			if (str[i_str] != pattern[i_pat])
				return (0);
			i_pat++;
			i_str++;
		}
	}
	if (i_pat > pat_len)
		return (1);
	return (check_last(pattern, str, pat_len, str_len));
}

/**
 * check_last - a function made to keep another function under 40 lines
 * @pattern: the regex pattern
 * @str: the string we're checking
 * @pat_len: index of last char in pattern string
 * @str_len: index of last char in str
 * Return: 1 if the last character matches or doesn't need to, 0 otherwise
 */
int check_last(char const *pattern, char const *str, int pat_len, int str_len)
{
	if (pattern[pat_len] != '.' && pattern[pat_len] != '*')
	{
		if (pat_len && str_len)
		{
			if (pattern[pat_len] == str[str_len])
				return (1);
			return (0);
		}
	}
	return (1);
}


/**
 * string_max_index - returns the index of the last char before '\0'
 * @str: pointer to first char in a string
 * Return: length
 */
int string_max_index(char const *str)
{
	int len = 0;
	int i = 0;

	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len - 1);
}
