#include "substring.h"


/**
 * find_substring - finds all the possible substrings containing a list
 * of words, within a given string.
 * @s: string to check
 * @words: list of words
 * @nb_words: size of @words
 * @n: size of result array
 * Return: list of indecies where permutations start
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (!s || !words || !*words || !nb_words || !n)
		return (NULL);

	return ([]);
}
