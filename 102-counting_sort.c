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
 * max_num - Maximum number in an array
 *
 * @array: Array passed
 * @size: Size of @array
 *
 * Return: Maximum number in array
 */
int max_num(int *array, size_t size)
{
	size_t index;
	int result;

	result = array[0];
	for (index = 1; index < size; index++)
	{
		if (result < array[index])
			result = array[index];
	}
	return (result);
}

/**
 * counting_sort - Sort an array using counting sort algorithm
 *
 * @array: Array passed
 * @size: Size of @array
 *
 */
void counting_sort(int *array, size_t size)
{
	int max, *count = NULL, index, *output = NULL;
	size_t i;

	if (array == NULL || size == 1)
		return;
	max = max_num(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;
	for (index = 0; index < (max + 1); index++)
		count[index] = 0;
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	for (index = 1; index < (max + 1); index++)
		count[index] += count[index - 1];
	for (index = 0; index < (max + 1); index++)
		index != max ? printf("%d, ", count[index]) : printf("%d\n", count[index]);
	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	for (i = 0; i < size; i++)
		output[--count[array[i]]] = array[i];
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
