#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: A pointer to the head of the list.
 * @node1: A pointer to the first node.
 * @node2: A pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (!node1 || !node2)
		return;

	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 *                      ascending order using the Cocktail shaker
 *                      sort algorithm.
 * @list: A pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *tail = NULL;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;

	temp = *list;
	while (swapped)
	{
		swapped = 0;
		while (temp->next != tail)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		tail = temp;
		while (temp != *list)
		{
			temp = temp->prev;
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
		}
		temp = *list;
	}
}
