#include "sort.h"

void print_list(const listint_t *list);

/**
  * insertion_sort_list - function that sorts a doubly linked list of integers
  * in ascending order using the insertion sort algorithm.
  * @list: list of nodes
  * Return: void
  */


void insertion_sort_list(listint_t **list)
{
	listint *temp, *curr;
	int value;

	if (list == NULL || *list == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		temp = curr;
		value = curr->n;

		while (temp->prev != NULL && temp->prev->n > value)
		{
			temp->n = temp->prev->n;
			temp = temp->prev;
		}
		temp->n = value;
		curr = curr->next;
	}
}


/**
 * print_list - Prints a doubly linked list
 * @list: Pointer to the head of the doubly linked list
 */

void print_list(const listint_t *list)
{
	while (list != NULL)
	{
		print_list(list->n);
		list = list->next;
	}
	
}
