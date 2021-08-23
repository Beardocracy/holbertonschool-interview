#include "substring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* find_substring - finds all the possible substring containing a list of words
* @s: the string to scan
* @words: array of words all substring must be a concatenation arrangement of
* @nb_words: number of elements in the array words
* @n: holds the address at which to store the number of elements in the
*	returned array.
* Return: array with each index in s at which a substring was found. Or null.
*/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, *temp, *ret_inds, i, j, word, i_str;

	if (strlen(s) == 0 || nb_words == 0 || !n)
		return (0);

	ret_inds = malloc(sizeof(int) * strlen(s));
	temp = malloc(sizeof(int) * nb_words);
	*n = 0;
	word_len = strlen(words[0]);

	for (i = 0; s[i]; i++)
	{
		for (j = 0; j < nb_words; j++)
			temp[j] = 0;
		for (word = 0; word < nb_words; word++)
		{
			i_str = i + (word * word_len);
			if (helper(temp, nb_words, s + i_str, word_len, words))
				break;
		}
		if (nb_words == word)
			ret_inds[(*n)++] = i;
	}
	free(temp);
	return (ret_inds);
}

/**
 * helper - checks for matches
 * @temp: int array to store if word is matched
 * @nb_words: number of words in words
 * @s: string to search
 * @word_len: length of the search words
 * @words: array of search words
 * Return: 1 if matched, else 0
 */
int helper(int *temp, int nb_words, char const *s, int word_len,
	char const **words)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if (strncmp(s, words[i], word_len) == 0 && temp[i] == 0)
		{
			temp[i] = 1;
			break;
		}
	}
	return (i == nb_words ? 1 : 0);
}
