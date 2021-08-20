#include "substring.h"


/**
 * find_substring - finds all substrings containing a list of words
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of elements
 * @n: number of elements in the returned array
 * Return: array of indices where words were found
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	if (!s || !words || !*words || !nb_words || !n)
		return (NULL);

	return (NULL);
}
