#ifndef _REGEX_H_
#define _REGEX_H_

int regex_match(char const *str, char const *pattern);
int string_max_index(char const *str);
int check_last(char const *pattern, char const *str, int pat_len, int str_len);

#endif
