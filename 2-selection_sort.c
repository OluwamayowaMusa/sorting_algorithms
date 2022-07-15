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
 * selection_sort - Sorts an array using selection sort algorithm
 * @array: Array passed
 * @size: Size of @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0, index;
	int min, temp;

	while (array)
	{
		if (sorted_array(array, size) == 1)
			break;
		i = j;
		min = array[i];
		temp = min;
		while (i < size)
		{
			if (min > array[i])
				min = array[i], index = i;
			i++;
		}
		if (temp != min)
		{
			temp = array[j];
			array[j] = min;
			array[index] = temp;
			print_array(array, size);
		}
		j++;
	}
}
