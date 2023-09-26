#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
	int sums = 0;
	listint_t *tempp = head;

	while (tempp)
	{
		sums += tempp->n;
		tempp = tempp->next;
	}

	return (sums);
}
