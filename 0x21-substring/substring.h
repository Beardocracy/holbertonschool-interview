#ifndef __SUBSTRING_H__
#define __SUBSTRING_H__

int *find_substring(char const *s, char const **words, int nb_words, int *n);
int helper(int *temp, int nb_words, char const *s, int word_len,
	char const **words);

#endif
