#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *add_node -  adds a new node at the beginning of a list_t list.
 *@head : head of linked list
 *@str : str of node
 *Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *nouveau = malloc(sizeof(*nouveau));
if (head == NULL || nouveau == NULL)
return (NULL);
nouveau->n = number;
nouveau->next = *head;
*head = nouveau;
return (nouveau);
}