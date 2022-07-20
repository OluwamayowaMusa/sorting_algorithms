#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * Using insertion algorithm
 *
 * @list: Pointer to Pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = NULL, *current, *mv, *tmp_1, *tmp_2;

	list != NULL ? tmp = *list : NULL;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->n <= tmp->next->n)
			tmp = tmp->next;
		else if (tmp->n > tmp->next->n)
		{
			current = tmp, mv = tmp->next, current->next = mv->next;
			mv->next != NULL ? mv->next->prev = current : NULL;
			while (mv->n < tmp->n)
			{
				if (tmp->prev != NULL)
				{
					tmp = tmp->prev, tmp_1 = tmp->next, tmp->next = mv;
					if (tmp_1->next != NULL && tmp->next == tmp_1->next)
					{
						tmp_2 = tmp_1->next->next, tmp_1->next = tmp_2;
						tmp_2 != NULL ? tmp_2->prev = tmp_1 : NULL;
					}
					mv->prev = tmp, mv->next = tmp_1, tmp_1->prev = mv, print_list(*list);
				}
				else
				{
					mv->prev = NULL;
					if (tmp->next != NULL && tmp->next == mv)
					{
						tmp_2 = tmp->next->next, tmp->next = tmp_2;
						tmp_2 != NULL ? tmp_2->prev = tmp : NULL;
					}
					mv->next = tmp, tmp->prev = mv, *list = mv, print_list(*list);
					break;
				}
			}
			tmp = current;
		}
	}

}
