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

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	new->next = '\0';

	while ((current->n < number) && (current->next))
	{
		temp = current;
		current = current->next;
	}

	if (current->next)
		new->next = current;
	else
		temp = current;

	temp->next = new;

	return (new);
}
