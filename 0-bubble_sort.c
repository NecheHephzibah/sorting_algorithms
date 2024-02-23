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
	size_t j, len = size;
	int temp;
	bool swapped = false;

	if (array == NULL || size < 2)
		return;

	while (swapped == false)
	{
		swapped = true;
		for (j = 0; j < len - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				swapped = false;
			}
		}
		len--;
	}
}
