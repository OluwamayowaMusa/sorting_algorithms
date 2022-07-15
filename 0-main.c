#include "sort.h"

/**
 * main - Entry Point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {7, 13, 19, 48, 52, 71, 73, 86, 96, 99};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	bubble_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}