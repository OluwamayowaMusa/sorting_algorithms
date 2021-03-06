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
 * bubble_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	int temp;

	while (array)
	{
		if (sorted_array(array, size) == 1)
			break;
		if (i + 1 == size)
			i = 0;
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);
		}
		i++;
	}
}
