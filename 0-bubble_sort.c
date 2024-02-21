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
	unsigned int i, j, temp;
	int swapped = 0;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1;
			}
			print_array(array, size);
		}
		if (swapped == 0)
			break;
	}
}