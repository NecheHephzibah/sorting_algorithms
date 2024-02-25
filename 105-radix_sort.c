#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - get the maximum number in an array
 * @array: array of integers
 * @size: size of the array
 * Return: the maximum number in the array
 */
int get_max(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
        if (array[i] > max)
            max = array[i];
    return max;
}

/**
 * counting_sort_radix - counting sort of the array depending on significant
 * digits represented by the exp variable
 * @array: array to be sorted
 * @size: size of the array
 * @exp: significant digit to sort by
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int exp;

	if (size < 2)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}

