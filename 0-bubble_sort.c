#include "sort.h"

/**
 * bubble_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	int ctrl = 1, i = 0, temp, j;

	while (ctrl)
	{
		if (i + 1 == (int)size)
		{
			for (j = 0; j < (int)size - 1; j++)
			{
				if (array[j] < array[j + 1])
				{
					ctrl = 0;
					continue;
				}
				if (array[j] > array[j + 1])
				{
					ctrl = 1;
					break;
				}
			}
		}
		if (ctrl == 0)
			break;
		if (i + 1 == (int)size)
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
