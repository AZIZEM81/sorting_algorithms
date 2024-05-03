#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max = 0;
	size_t i;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum element in the array */
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	/* Create the counting and output arrays */
	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (count == NULL || output == NULL)
		return;

	/* Initialize the counting array */
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	/* Count the occurrences of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Update the counting array with cumulative counts */
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	/* Print the counting array */
	print_array(count, max + 1);

	/* Populate the output array */
	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
