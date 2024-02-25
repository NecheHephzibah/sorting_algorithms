#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges two subarrays of array[]
 * @array: input array
 * @size: size of the array
 * @temp: temporary array for merging
 * @mid: middle index
 */
void merge(int *array, size_t size, int *temp, int mid)
{
	int i = 0;
	int j = mid;
	int k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, mid);
	printf("[right]: ");
	print_array(array + mid, size - mid);
	while (i < mid && j < (int)size)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
	temp[k++] = array[i++];
	while (j < (int)size)
		temp[k++] = array[j++];
	for (i = 0; i < (int)size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(temp, size);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int mid = size / 2;
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);
	merge(array, size, temp, mid);

	free(temp);
}

