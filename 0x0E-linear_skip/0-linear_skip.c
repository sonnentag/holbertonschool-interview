#include "search.h"


/**
 * linear_skip - search for a number in a linear skiping way
 * @list: the input
 * @value: the value to seaach
 * Return: the index of the value, or -1 when the values is not present
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *s, *e;

	if (!list)
		return (NULL);

	e = list;
	while (e != NULL)
	{
		s = e;
		if (e->express)
			e = e->express;
		else
		{
			while (e->next)
				e = e->next;
		}
		printf("Value checked at index [%li] = [%i]\n", e->index, e->n);
		if (e->n >= value || !e->next)
		{
			printf("Value found between indexes [%li] and [%li]\n", s->index, e->index);
			while (s != e->next)
			{
				printf("Value checked at index [%li] = [%i]\n", s->index, s->n);
				if (s->n == value)
					return (s);

				if (s->next)
					s = s->next;
					else
				return (NULL);
			}
		}
	}
	return (NULL);
}
