#include "sort.h"


/**
  * insertion_sort_list - function that sorts a doubly linked list of integers
  * in ascending order using the insertion sort algorithm.
  * @list: list of nodes
  * Return: void
  */


void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *curr;

	if (list == NULL || *list == NULL)
		return;

	curr = (*list)->next;
	while (curr != NULL)
	{
		temp = curr;

		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
		}
		curr = curr->next;
	}
}
