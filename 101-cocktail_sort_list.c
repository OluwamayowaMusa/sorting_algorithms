#include "sort.h"

/**
 * sorted_list - Check if doubly linked list is sorted
 *
 * @list: List Passed
 *
 * Return: 1 - if sorted
 *         0 - Otherwise
 */
int sorted_list(listint_t *list)
{
	while (list->next != NULL)
	{
		if (list->n > list->next->n)
			return (0);
		list = list->next;
	}
	return (1);
}

/**
 * cocktail_sort_list - Sort a doubly linked list using
 * cocktail sort algorithm
 *
 * @list: Pointer to Pointer of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *t_0 = NULL, *t_1, *t_2, *t_3;
	int ctrl = 1;

	t_0 = *list;
	while (t_0)
	{
		if (sorted_list(t_0) == 1)
			return;

		while (ctrl == 1)
		{
			if (t_0->next == NULL)
			{
				ctrl = 0;
				break;
			}
			if (t_0->n <= t_0->next->n)
				t_0 = t_0->next;
			else if (t_0->n > t_0->next->n)
			{

				t_1 = t_0->prev, t_2 = t_0->next, t_3 = t_0->next->next, t_1->next = t_2;
				t_2->prev = t_1, t_2->next = t_0, t_0->prev = t_2, t_0->next = t_3;
				t_3 != NULL ? t_3->prev = t_0 : NULL;
				print_list(*list);
			}
		}
		while (ctrl == 0)
		{
			if (t_0->prev == NULL)
			{
				ctrl = 1;
				break;
			}
			if (t_0->n >= t_0->prev->n)
				t_0 = t_0->prev;
			else if (t_0->n < t_0->prev->n)
			{
				t_1 = t_0->next, t_2 = t_0->prev, t_3 = t_0->prev->prev, t_2->next = t_1;
				t_1->prev = t_2, t_0->next = t_2, t_2->prev = t_0, t_0->prev = t_3;
				if (t_3 != NULL)
					t_3->next = t_0;
				else
					*list = t_0;
				print_list(*list);
			}
		}
	}
}
