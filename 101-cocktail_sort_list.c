#include "sort.h"

/**
* swap_node - Swap two nodes in a double linked list.
* @node: node to swap with.
* @list: the double linked list.
*/
void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
* cocktail_sort_list - Sort a doubly linked list of integers in ascending order
* using the Cocktail shaker sort algorithm.
* @list: the list to be sorted.
*/
void cocktail_sort_list(listint_t **list)
{
	int swap = 1;
	listint_t *tmp;

	if (!list || !*list)
		return;
	tmp = *list;
	while (swap)
	{
		swap = 0;
		while (tmp->next)
		{
			if (tmp->next->n < tmp->n)
			{
				swap_node(list, tmp);
				swap = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (!swap)
			break;
		swap = 0;
		while (tmp->prev)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_node(list, tmp->prev);
				swap = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
