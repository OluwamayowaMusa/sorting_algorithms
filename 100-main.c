#include "sort.h"

/**
 * main - Test function
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {81, 18, 124, 50, 109, 51, 86, 13, 100, 188, 171, 69, 108, 14, 74};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
