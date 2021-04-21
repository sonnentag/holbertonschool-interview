#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list
 * @value: value to search for
 * Return: pointer to the first node where value is located or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{

	if (!list)
		return (NULL);

	while ((list->express) && (list->express->n < value))
	{
		printf("Value checked at index [%lu] = [%d]\n",
			list->express->index, list->express->n);
		list = list->express;
	}

	if (list->express)
		printf("Value found between indexes [%lu] and [%lu]\n",
			list->index, list->express->index);

	while (list->n != value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			list->index, list->n);
		if (list->next)
			list = list->next;
		else
			break;
	}

	if (list->n == value)
	{
		return (list);
	}

	return (NULL);
}
