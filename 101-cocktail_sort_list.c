#include "sort.h"

/**
 * cocktail_sort_list - function that sorts
 * a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 *
 * @list: Double pointer to head of list to sort.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *node = NULL;
	int sorted = 0;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	while (sorted == 0)
	{
		sorted = 1;
		while (node->next != NULL)
		{
			if ((node->n) > (node->next)->n)
			{
				swap_nodes(node);
				while ((*list)->prev != NULL)
					*list = (*list)->prev;
				print_list(*list), sorted = 0;
				node = node->prev;
			}
			if (node->next != NULL)
				node = node->next;
		}

		if (sorted == 0)
		{
			while (node->prev != NULL)
			{
				if ((node->prev)->n > node->n)
				{
					swap_nodes(node->prev);
					while ((*list)->prev != NULL)
						*list = (*list)->prev;
					print_list(*list), sorted = 0;
					node = node->next;
				}
				if (node->prev != NULL)
					node = node->prev;
			}
		}
	}
}

/**
 * swap_nodes - swap consecutive nodes of
 * a dobble linked list. In case of swap
 * between head and another node, you must
 * manually, point to the new head.
 *
 * @list: pointer to the first node
 * of two to swap in the dobble linked list.
 *
 * Return: 1 if it success 0 if not.
 */

int swap_nodes(listint_t *list)
{
	listint_t *a = NULL, *b = NULL, *aux = NULL;

	if (list == NULL)
		return (0);
	if (list->next == NULL)
		return (0);

	a = list;
	b = list->next;

	aux = b->next; /*let's swap the nodes.*/
	b->next = a;
	b->prev = a->prev;
	a->next = aux;
	a->prev = b;

	if (b->prev != NULL)
		(b->prev)->next = b;
	if (a->next != NULL)
		(a->next)->prev = a;

	return (1);
}
