#include "sort.h"

/**
 * main - Test function
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 7, 7, 7, 7, 7, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	cocktail_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
