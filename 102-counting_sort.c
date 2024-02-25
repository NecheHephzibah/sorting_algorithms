#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0, *count, *output;

	if (!array || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	count = calloc(max + 1, sizeof(int));
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}

