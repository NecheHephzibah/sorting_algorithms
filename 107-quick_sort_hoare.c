#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @a: first integer to swap
 * @b: second integer to swap
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - orders a subset of an array of integers according to
 * the Hoare partition scheme
 * @array: array of integers
 * @size: size of the array
 * @low: low index of the subset to order
 * @high: high index of the subset to order
 * Return: the final partition index
 */
int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int i, j;

	pivot = array[high];
	i = low -1;
	j = high + 1;

	while (1)
	{
		do 
		{
 			i++;
		}
		while (array[i] < pivot);
		do
		{
			j--;
		}

		while (array[j] > pivot);

		if (i >= j)
			return (j);
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_hoare_recursion - sorts an array of integers in ascending
 * order using the Quick sort algorithm and the Hoare partition scheme
 * @array: array of integers
 * @size: size of the array
 * @low: low index of the subset to sort
 * @high: high index of the subset to sort
 */
void quick_sort_hoare_recursion(int *array, size_t size, int low, int high)
{
	int pi;

	if (low < high)
	{
		pi = hoare_partition(array, size, low, high);
		quick_sort_hoare_recursion(array, size, low, pi);
		quick_sort_hoare_recursion(array, size, pi + 1, high);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_hoare_recursion(array, size, 0, size - 1);
}

