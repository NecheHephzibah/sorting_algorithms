#include "sort.h"


/**
  * bubble_sort - function that sorts an array of integers in ascending order
  * using the Bubble sort algorithm.
  * @array: an array of integers.
  * @size: size of the array.
  * Return: void
  */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped = 0;

	if (array == NULL || size < 2)
		return;

	while (swapped == 0)
	{
		swapped = 1;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = 0;
			}
		}
		size--;
	}
}
