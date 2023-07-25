#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list of an integer,
 * in ascending order
 * @list: double linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *p, *c, *n;

	if (!list)
		return;

	current = *list;

	while (current)
	{
		if ( current->prev && current->prev->n > current->n)
		{
			/*stores the necessary pointers for swapping*/
			previous = current->prev->prev;
			p = current->prev;
			c = current;
			n = current->next;

			if (n)
				n->prev = p;
			c->prev = previous;
			c->next = p;

			if (previous)
				previous->next = c;
			else
				*list = c;

			p->prev = c;
			current = *list;
			print_list(*list);
			continue; /*continues to the next iteration*/
		}
		else
			current = current->next;
	}
}
