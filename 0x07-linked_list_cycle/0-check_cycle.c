#include "lists.h"

/**
 * check_cycle - check list for cycle
 * @list: list to check
 * Return: 1 if true else 0
 */
int check_cycle(listint_t *list)
{
	/* make sure we were passed a list to then descend */
	return (!list || !list->next ? 0 : compare_nodes(list, list->next));
}

/**
 * compare_nodes - descend into list
 * @slow: slow moving next
 * @fast: fast moving next
 * Return: 1 if nodes are same else 0
 */
int compare_nodes(listint_t *slow, listint_t *fast)
{
	/* if we were passed a fast next node which is not at the end */
	if (fast && fast->next)     /* return 1 if nodes match or else recurse */
		return (slow == fast ? 1 : compare_nodes(slow->next, fast->next->next));

	return (0);
}
