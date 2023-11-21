#include "sort.h"

/**
 * swap_nodes - This functions Swap two nodes in a listint_t doubly-linked list.
 * @h: This is A pointer to the head of the doubly-linked list.
 * @n1: This is  A pointer to the first node to swap.
 * @n2: second node to swap.
 * Written by Mayow Daniel
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - This function Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @list: This is A pointer to the head of a doubly-linked list of integers.
 *
 * Description: This Prints the list after each swap.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iters, *insert, *tmps;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iters = (*list)->next; iters != NULL; iters = tmps)
	{
		tmps = iters->next;
		insert = iters->prev;
		while (insert != NULL && iters->n < insert->n)
		{
			swap_nodes(list, &insert, iters);
			print_list((const listint_t *)*list);
		}
	}
}
