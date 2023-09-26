#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoisee, *hare;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tortoisee = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (tortoisee == hare)
		{
			tortoisee = head;
			while (tortoisee != hare)
			{
				nodes++;
				tortoisee = tortoisee->next;
				hare = hare->next;
			}

			tortoisee = tortoisee->next;
			while (tortoisee != hare)
			{
				nodes++;
				tortoisee = tortoisee->next;
			}

			return (nodes);
		}

		tortoisee = tortoisee->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodess, index = 0;

	nodess = looped_listint_len(head);

	if (nodess == 0)
	{
		for (; head != NULL; nodess++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nodess; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nodess);
}
