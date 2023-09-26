#include "lists.h"

/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prevv = NULL;
	listint_t *nextt = NULL;

	while (*head)
	{
		nextt = (*head)->nextt;
		(*head)->nextt = prevv;
		prevv = *head;
		*head = nextt;
	}

	*head = prevv;

	return (*head);
}
