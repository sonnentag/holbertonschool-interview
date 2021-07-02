#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Add node to end of double circular linked list
 * @list: list to add to
 * @str: string to copy
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *temp = NULL, *new = NULL;

	new = malloc(sizeof(List));
	if (new)
		new->str = strdup(str);
	if (!new->str)
		return (NULL);

	new->next = new;
	if (!*list)
	{
		new->prev = new;
		*list = new;

		return (*list);
	}

	temp = *list;
	while (temp->next && temp->next != *list)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;
	new->next = *list;
	(*list)->prev = new;
	temp = new;

	return (temp);
}

/**
 * add_node_begin - Add node to start of double circular linked list
 * @list: list to add to
 * @str: string to copy
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *temp = NULL, *new = NULL;

	new = malloc(sizeof(List));
	if (new)
		new->str = strdup(str);
	if (!new->str)
		return (NULL);

	new->next = new;
	if (!*list)
	{
		new->prev = new;
		new->next = new;
		*list = new;

		return (*list);
	}

	temp = *list;
	while (temp->next && temp->next != *list)
		temp = temp->next;

	(*list)->prev = new;
	new->next = *list;
	new->prev = temp;
	temp->next = new;
	*list = new;

	return (*list);
}
