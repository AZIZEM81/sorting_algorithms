#include "sort.h"

/**
 * heapify - Heapifies the subarray of `array` from `start` to `size`.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @start: The starting index of the subarray to be heapified.
 * @end: The ending index of the subarray to be heapified.
 */
void heapify(int *array, size_t size, int start, int end)
{
	int root = start, left, right, temp, swap;

	while (1)
	{
		left = 2 * root + 1;
		right = 2 * root + 2;
		swap = root;

		if (left < (int)end && array[swap] < array[left])
			swap = left;
		if (right < (int)end && array[swap] < array[right])
			swap = right;

		if (swap == root)
			break;

		temp = array[root];
		array[root] = array[swap];
		array[swap] = temp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int end, temp;
