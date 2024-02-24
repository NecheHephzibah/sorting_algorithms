#include "sort.h"

void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2);

/**
  * insertion_sort_list - function that sorts a doubly linked list of integers
  * in ascending order using the insertion sort algorithm.
  * @list: list of nodes
  * Return: void
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *insertionPoint;
	listint_t *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insertionPoint = current->prev;

		while (insertionPoint != NULL && current->n < insertionPoint->n)
		{
			swap_nodes(list, &insertionPoint, current);
			print_list((const listint_t *)*list);
		}
	}
}


/**
  * swap_nodes - function that swaps nodes.
  * @h: the head of the node.
  * @node1: The first node to swap.
  * @node2: The second node.
  */

void swap_nodes(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
