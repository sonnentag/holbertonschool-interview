#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a new node into sorted listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *temp, *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	/* if we were not given a list, this will be our first node */
	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		/* should our number go before the first node? */
		if (number <= current->n)
			new->next = current, *head = new;
		else
		{ /* move past nodes which should come before ours */
			while ((current->n < number) && (current->next))
				temp = current, current = current->next;

			/* if we are not on the last node, insert here */
			if (current->next)
				new->next = current, temp->next = new;
			else /* insert after, or before this last node */
				if (number > current->n)
					temp = current, temp->next = new;
				else
					temp->next = new, new->next = current;
		}
	}

	return (new);
}
