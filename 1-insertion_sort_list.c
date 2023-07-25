#include "sort.h"

/**
 * len_list - function to return the length of a linked list
 * @h: pointer to the list
 *
 * Return: length of list
 */
int len_list(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - function to sort linked list with the Insert Sort algorithm
 * @list: double pointer to the list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr_node = NULL, *one = NULL;
	listint_t *two = NULL, *three = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;

	curr_node = *list;

	while (curr_node)
	{
		if (curr_node->prev && curr_node->n < curr_node->prev->n)
		{
			one = curr_node->prev->prev;
			two = curr_node->prev;
			three = curr_node;
			four = curr_node->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			curr_node = *list;
			print_list(*list);
			continue;
		}
		else
			curr_node = curr_node->next;
	}
}
