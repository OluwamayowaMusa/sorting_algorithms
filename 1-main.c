#include "sort.h"

/**
 * main - Test functions
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = { 52, 97, 40, 75, 28, 64, 86, 77, 7, 43, 84, 23, 8, 49, 94};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
