#include "sort.h"
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void recursively_sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);


/**
 * swap - Swaps two integers
 * @a: The first integer
 * @b: The second integer
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int *key = array + high;
	int i;
	int j;

	for (i = j = low; j < high; j++)
	{
		if (array[j] < *key)
		{
			if (i < j)
			{
				swap(array + j, array + j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *key)
	{
		swap(array + i, key);
		print_array(array, size);
	}
	return (i);
}

/**
 * recursively_sort - Recursively sorts the array using Quick sort
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 */
void recursively_sort(int *array, int low, int high, size_t size)
{
	int key;
	if (low < part)
	{
		key = lomuto_partition(array, low, high, size);

		recursively_sort(array, low, key - 1, size);
		recursively_sort(array, key + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursively_sort(array, 0, size - 1, size);
}
