#include "lists.h"

/**
 * check_cycle - check list for cycle
 * @list: list to check
 * Return: 1 if true else 0
 */
int check_cycle(listint_t *list)
{
	if ((!list) || (!list->next))
		return (0);

	return (compare_nodes(list, list->next));
}

/**
 * compare_nodes - descend into list
 * @slow: slow moving next
 * @fast: fast moving next
 * Return: 1 if nodes are same else 0
 */
int compare_nodes(listint_t *slow, listint_t *fast)
{
	if (fast)
	{
		if (slow == fast)
			return (1);

		while (fast->next)
			return (compare_nodes(slow->next, fast->next->next));
	}

	return (0);
}
