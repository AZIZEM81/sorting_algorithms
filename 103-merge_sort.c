#include "sort.h"

/**
 * merge_subarr - Merges two subarrays of `array`.
 * @array: The array to be sorted.
 * @low: The starting index of the first subarray.
 * @mid: The ending index of the first subarray and starting index of the second subarray.
 * @high: The ending index of the second subarray.
 */
void merge_subarr(int *array, int low, int mid, int high)
{
	int i, j, k;
	int n1 = mid - low + 1, n2 = high - mid;
	int *left, *right;

	/* Create temporary subarrays */
	left = malloc(sizeof(int) * n1);
	right = malloc(sizeof(int) * n2);

	/* Copy data to temporary subarrays */
	for (i = 0; i < n1; i++)
		left[i] = array[low + i];
	for (j = 0; j < n2; j++)
		right[j] = array[mid + 1 + j];

	/* Merge the temporary subarrays back into array */
	i = j = 0;
	k = low;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, n1);
	printf("[right]: ");
	print_array(right, n2);
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	/* Copy remaining elements of left[], if any */
	while (i < n1)
		array[k++] = left[i++];

	/* Copy remaining elements of right[], if any */
	while (j < n2)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array + low, k - low);
	printf("\n");

	free(left);
	free(right);
}

/**
 * merge_sort_helper - Recursively divides the array and merges subarrays.
 * @array: The array to be sorted.
 * @low: The starting index of the subarray.
 * @high: The ending index of the subarray.
 */
void merge_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;

		merge_sort_helper(array, low, mid);
		merge_sort_helper(array, mid + 1, high);
		merge_subarr(array, low, mid, high);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	merge_sort_helper(array, 0, size - 1);
}
