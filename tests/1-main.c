#include "sort.h"

/**
 * main - Test functions
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {9, 12, 17, 25, 32, 47, 69, 94, 95};
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
