#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *sloww = head;
	listint_t *fastt = head;

	if (!head)
		return (NULL);

	while (sloww && fastt && fastt->next)
	{
		fastt = fastt->next->next;
		sloww = sloww->next;
		if (fastt == sloww)
		{
			sloww = head;
			while (sloww != fastt)
			{
				sloww = sloww->next;
				fastt = fastt->next;
			}
			return (fastt);
		}
	}

	return (NULL);
}
