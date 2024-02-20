#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list -sorts a doubly linked list of integers in ascending order
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (!list || !*list)
		return;

	current = (*list)->next;

	while (current)
	{
		next = current->next;
		prev = current->prev;

	while (prev && prev->n > current->n)
	{
		prev->next = current->next;
		if (current->next)
			current->next->prev = prev;
		current->next = prev;
		current->prev = prev->prev;
		if (prev->prev)
			prev->prev->next = current;
		prev->prev = current;

		if (!current->prev)
			*list = current;

		print_list(*list);

		prev = current->prev;
	}
	current = next;
	}
}

