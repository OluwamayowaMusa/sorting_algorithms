#include "sort.h"

/**
 * sorted_array - Check if an array is sorted
 *
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
 * shell_sort - Sorts an array using the shell sort algorithm
 * using Knuth Sequence
 *
 * @array: Array Passed
 * @size: Size of @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j, ctrl = 0;
	int tmp;

	while (gap < size)
		gap = gap * 3 + 1;
	while (array && size != 1)
	{
		ctrl = 0;
		gap > 1 ? gap /= 3 : 0;
		for (j = 0; j < size - 1; j++)
		{
			i = j;
			if (gap > 1)
			{
				while (i + gap < size)
					i += gap;
				while (i > j)
				{
					if (array[i] < array[i - gap])
						tmp = array[i], array[i] = array[i - gap], array[i - gap] = tmp;
					i -= gap;
				}
			}
			else
			{
				if (array[i] > array[i + gap])
					tmp = array[i], array[i] = array[i + gap], array[i + gap] = tmp, ctrl = 1;
			}
		}
		if (gap != 1)
			print_array(array, size);
		else if (gap == 1 && ctrl == 0)
		{
			print_array(array, size);
			break;
		}
	}
}
