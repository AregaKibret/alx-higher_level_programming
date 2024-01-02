#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}
	
	return count;
}

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	
	if (new_node == NULL)
		return NULL;
	
	new_node->n = n;
	new_node->next = *head;
	*head = new_node;
	
	return new_node;
}

void free_listint(listint_t *head)
{
	listint_t *temp;
	
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

int check_cycle(listint_t *list)
{
	listint_t *slow = list;
	listint_t *fast = list;
	
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast)
			return 1;
	}
	
	return 0;
}

#endif /* LISTS_H */
