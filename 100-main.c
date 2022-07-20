#include "sort.h"

/**
 * main - Test function
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {1};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	shell_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
