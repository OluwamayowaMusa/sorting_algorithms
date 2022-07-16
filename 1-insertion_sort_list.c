#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list
 * Using insertion algorithm
 *
 * @list: Pointer to Pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = *list, *current, *move, *temp_1, *temp_2;

	if (list == NULL || *list == NULL || (*list)->next->next == NULL)
		return;
	while (temp->next != NULL)
	{
		if (temp->n < temp->next->n)
		{
			temp = temp->next;
		}
		else if (temp->n > temp->next->n)
		{
			current = temp, move = temp->next, current->next = move->next;
			while (move->n < temp->n)
			{
				if (temp->prev != NULL)
				{
					temp = temp->prev, temp_1 = temp->next, temp->next = move;
					if (temp_1->next != NULL && temp->next->n == temp_1->next->n)
					{
						temp_2 = temp_1->next->next, temp_1->next = temp_2;
						temp_2->prev = temp_1;
					}
					move->prev = temp, move->next = temp_1;
					temp_1->prev = move, print_list(*list);
					}
				else
				{
					move->prev = NULL, temp_2 = temp->next->next, temp->next = temp_2;
					temp_2->prev = temp, move->next = temp, temp->prev = move;
					*list = move, print_list(*list);
					break;
				}
			}
			temp = current;
		}
	}

}
