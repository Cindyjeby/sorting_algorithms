#include "sort.h"

/**
 * swap_node - function that swaps two nodes in a doubly linked list
 * @list: is the pointer to the head of the list
 * @first: first node to be swaped
 * @second: second node to be swaped
 */
void swap_node(listint_t **list, listint_t *first, listint_t *second)
{
	if (!first || !second)
		return;

	if (first->prev)
		first->prev->next = second;
	if (second->next)
		second->next->prev = first;

	first->next = second->next;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;

	if (second->prev == NULL)
		*list = second;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of int
 * in ascending order using cocktail shaker sort algorithm
 * @list: the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL;
	int swap = 0;

	if (!list || !(*list) || !(*list)->next)
		return;
	do
	{
		swap = 0;
		for (start = *list; start->next != NULL; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_node(list, start, start->next);
				swap = 1;
			}
		}
		if (swap == 0)
			break;

		swap = 0;
		for (; start->prev != NULL; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_node(list, start->prev, start);
				print_list(*list);
				swap = 1;
			}
		}
	} while (swap);
}
