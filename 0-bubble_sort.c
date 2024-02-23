#include "sort.h"


/**
  * swap - function that swaps two variables containing integers.
  * @a: the first integer.
  * @b: the second integer.
  * Return: void
  */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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
				swap(array + j, array + j + 1);
                print_array(array, size);
                swapped = false;
            }
        }
        len--;
    }
}

