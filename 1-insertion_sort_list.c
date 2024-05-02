#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		next = current->next;

		while (prev && prev->n > current->n)
		{
			prev->next = next;
			if (next)
				next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			if (prev->prev)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			print_list(*list);
			prev = current->prev;
		}
		current = next;
	}
}
