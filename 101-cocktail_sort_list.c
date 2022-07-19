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
 * forward_sort - Sort doubly linked list by moving forward
 *
 * @list_0: Doubly linked list
 * @head: Head of doubly linked list passed
 */
void forward_sort(listint_t **head, listint_t **list_0)
{
	listint_t *list, *list_1 = NULL, *list_2, *list_3;

	list = *list_0;
	while (1)
	{
		if (list->next == NULL)
		{
			*list_0 = list;
			return;
		}
		if (list->n <= list->next->n)
			list = list->next;
		else if (list->n > list->next->n)
		{
			list->prev != NULL ? list_1 = list->prev : NULL;
			list_2 = list->next;
			list_3 = list->next->next;
			list_1 != NULL ? list_1->next = list_2 : NULL;
			list_2->prev = list_1;
			list_2->next = list;
			list->prev = list_2;
			list->next = list_3;
			list_3 != NULL ? list_3->prev = list : NULL;
			list_1 == NULL ? *head = list_2 : NULL;
			print_list(*head);
		}
	}
}

/**
 * backward_sort - Sort the doubly linked list by moving backward
 *
 * @list_0: Doubly linked list
 * @tail: Tail of Doubly linked list
 */
void backward_sort(listint_t **list_0, listint_t **tail)
{
	listint_t *list, *list_1, *list_2, *list_3;

	list = *tail;
	while (1)
	{
		if (list->prev == NULL)
		{
			*tail = list;
			return;
		}
		if (list->n >= list->prev->n)
			list = list->prev;
		else if (list->n < list->prev->n)
		{
			list_1 = list->next;
			list_2 = list->prev;
			list_3 = list->prev->prev;
			list_2->next = list_1;
			list_1->prev = list_2;
			list->next = list_2;
			list_2->prev = list;
			list->prev = list_3;
			if (list_3 != NULL)
				list_3->next = list;
			else
				*list_0 = list;
			print_list(*list_0);

		}
	}
}

/**
 * cocktail_sort_list - Sort a doubly linked list using
 * cocktail sort algorithm
 *
 * @list: Pointer to Pointer of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL;

	temp = *list;
	while (temp)
	{
		if (sorted_list(temp) == 1)
			return;
		forward_sort(list, &temp);
		backward_sort(list, &temp);
	}
}
