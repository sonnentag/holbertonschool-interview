#include "lists.h"
#include <stdio.h>

/**
 * is_palindrome - entry function to test if list is a palindrome
 * @head: linked list to test
 * Return: 1 if true, 0 if false
 */
int is_palindrome(listint_t **head)
{
	return (is_pal(&*head, *head)); /* pass list to be recursed */
}

/**
 * is_pal - recursive function to test if list is a palindrome
 * @h: head/left node to compare
 * @r: right node to compare
 * Return: 1 if true, 0 is false
 */
int is_pal(listint_t **h, listint_t *r)
{
	int x = 1;  /* assign return value for base case */

	if (r)      /* if right argument was passed */
	{
		/* recurse to right and compare nodes on return */
		x = is_pal(h, r->next) && ((*h)->n == r->n);

		/* move head on each returned pass */
		(*h) = (*h)->next;
	}

	return (x); /* return 0 if x is false */
}
