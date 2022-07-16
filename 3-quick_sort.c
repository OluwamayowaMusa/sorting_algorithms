#include "sort.h"

/**
 * sorted_array - Check if an array is sorted
 * @array: Array passed
 * @size: Size of @array
 *
 * Return: 1 - if sorted
 *         0 - Otherwise
 */
int sorted_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] > array[i + 1])
			return (0);
	}
	return (1);
}

/**
 * lomuto_partition - Lomuto partition
 * @array: Array passed
 * @low: Least Index
 * @high: Highest Index
 * @size: Size of array
 *
 * Return: Index of Pivot
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	size_t i = low, j;
	int pivot = array[high - 1], temp;

	for (j = low; j < high - 1; j++)
	{
		if (pivot >= array[j])
		{
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != pivot)
	{
		temp = array[i];
		array[i] = pivot;
		array[high - 1] = temp;
		print_array(array, size);
	}
	return (i);
}


/**
 * quick_sort_algo - Implements quick sort algorithm using lomuto partition
 * @array: Array passed
 * @low: Lowest index in partion
 * @high: Highest index in partition
 * @size: Size of @array
 *
 */
void quick_sort_algo(int *array, size_t low, size_t high, size_t size)
{
	size_t partition;

	if (low >= high)
		return;
	partition = lomuto_partition(array, low, high, size);
	quick_sort_algo(array, low, partition, size);
	quick_sort_algo(array, partition + 1, high, size);
}



/**
 * quick_sort - Sort an array using the quicksort algorithm
 *
 * @array: Array passed
 * @size: Size of @array
 */
void quick_sort(int *array, size_t size)
{
	if (array)
	{
		if (sorted_array(array, size) == 1)
			return;
		quick_sort_algo(array, 0, size, size);
	}
}

