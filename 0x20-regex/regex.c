#include "regex.h"

/**
 * regex_match - checks whether a given regex pattern matches a given string
 * @str: string to scan
 * @pattern: regex pattern
 * Return: 1 if match else 0
 */
int regex_match(char const *str, char const *pattern)
{
	int x = 0;

	if (*str == '\0' && *pattern == '\0')
		return (1);

	if ((*str == *pattern || *pattern == '.') && *(pattern + 1) != '*')
		return (regex_match(str + 1, pattern + 1));

	if (*(pattern + 1) == '*')
	{
		if (*str != '\0' && (*str == *pattern || *pattern == '.'))
			x = regex_match(str + 1, pattern);

		return (regex_match(str, pattern + 2) || x);
	}

	return (0);
}
