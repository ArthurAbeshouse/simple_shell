#include "shell.h"
/**
 * print_list - prints all elements of a list
 * @h: pointer to node struct
 * Return: number of nodes
 */
size_t print_list(list_t *h)
{
	size_t i = 0;

	if (h == NULL)
		return (0);

	while (h)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);

		h = h->next;
		++i;
	}
	return (i);
}

/**
 * *add_node_end - adds a new element at the end of a list
 * @head: beginning of list
 * @str: new node to add
 * Return: address of new node, or NULL if it fails
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *temp;
	list_t *first;
	unsigned int counter;

	counter = 0;

	if (head == NULL || str == NULL)
		return (NULL);

	while (str[counter] != '\0')
	{
		++counter;
	}

	first = malloc(sizeof(list_t));
	if (first ==  NULL)
		return (NULL);
	first->str  = strdup(str);
	first->len  = counter;

	if (*head == NULL)
	{
		*head = first;
		first->next = NULL;
		return (*head);
	}
	temp =  *head;

	/* adds a new node at the end of a list*/
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = first;
	first->next = NULL;

	return (*head);
}

/**
  * delete_nodeint_at_index - delete a node at index
  * @head: head of the list
  * @index: location of the node to delete
  *
  * Return: pointer to head of list
  */
int delete_nodeint_at_index(list_t **head, int index)
{
	unsigned int i;
	list_t *current, *subsequent;

	if (!head || !*head)
		return (-1);
	current = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}
	for (i = 0; i < (index - 1); i++)
	{
		current = current->next;
		if (current == NULL)
			return (-1);
	}
	subsequent = current->next;
	current->next = subsequent->next;
	free(subsequent);
	return (1);
}

/**
 * free_list - frees a list_t list
 * @head: list to free
 */
void free_linked_list(list_t *head)
{
	while (head)
	{
		head = head->next;
		free(head->str);
                free(head);
	}
}
