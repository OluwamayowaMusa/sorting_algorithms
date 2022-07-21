#include "sort.h"

/**
 * print_sublist - Print sublist to be merge
 *
 * @array: Array paased
 * @start: Start Index
 * @stop: Stop Index
 */
void print_sublist(int *array, size_t start, size_t stop)
{
	size_t i;

	for (i = start; i < stop; i++)
		i != stop - 1 ? printf("%d, ", array[i]) : printf("%d\n", array[i]);
}

/**
 * top_down_merge - Merge sublists
 *
 * @array: Array Passed
 * @begin: Starting Index
 * @middle: Middle Index
 * @end: End Index
 * @copy: Copy array
 */
void top_down_merge(int *array, size_t begin,
		size_t middle, size_t end, int *copy)
{
	size_t i = begin, j = middle, k;

	printf("Merging...\n");
	for (k = begin; k < end; k++)
	{
		if (k == begin)
		{
			printf("[left]: "), print_sublist(array, begin, middle);
			printf("[right]: "), print_sublist(array, middle, end);
		}
		if (i < middle && (j >= end || array[i] <= array[j]))
			copy[k] = array[i], i += 1;
		else
		{
			copy[k] = array[j], j += 1;
		}
	}
	printf("[Done]: "), print_sublist(copy, begin, end);
}

/**
 * top_down_split_merge - Split the array into sub lists
 *
 * @copy: Copy array
 * @begin: Starting Index
 * @end: End Index
 * @array: Array passed
 */
void top_down_split_merge(int *copy, size_t begin, size_t end, int *array)
{
	size_t middle;

	if (end - begin <= 1)
		return;
	middle = (end + begin) / 2;
	top_down_split_merge(array, begin, middle, copy);
	top_down_split_merge(array, middle, end, copy);
	top_down_merge(copy, begin, middle, end, array);
}

/**
 * merge_sort - Sort using merge sort algorithm(top down)
 *
 * @array: Array passed
 * @size: Size of @array
 */
void merge_sort(int *array, size_t size)
{
	int *copy_array = NULL;
	size_t index;

	if (array == NULL || size == 1)
		return;
	copy_array = malloc(sizeof(int) * size);
	if (!copy_array)
		return;
	for (index = 0; index < size; index++)
		copy_array[index] = array[index];
	top_down_split_merge(copy_array, 0, size, array);
	free(copy_array);
}
