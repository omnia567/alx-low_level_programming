#include "lists.h"

/**
 * pop_listint - deletes the head node of a linked list
 * @head: pointer to the first element in the linked list
 *
 * Return: the data inside the elements that was deleted,
 * or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
	listint_t *tempp;
	int number;

	if (!head || !*head)
		return (0);

	number = (*head)->n;
	tempp = (*head)->next;
	free(*head);
	*head = tempp;

	return (number);
}
