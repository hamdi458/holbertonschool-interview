#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 *add_node -  adds a new node at the beginning of a list_t list.
 *@head : head of linked list
 *@str : str of node
 *Return: new node
 */
list_t *insert_node(listint_t **head, int number)
{
int s = 0;
listint_t *nouveau = malloc(sizeof(*nouveau));
if (head == NULL || nouveau == NULL)
return (NULL);
if (!number)
{
nouveau->str = NULL;
nouveau->len = 0;
}
else
{
nouveau->n = number;
}
nouveau->next = *head;
*head = nouveau;
return (nouveau);

}