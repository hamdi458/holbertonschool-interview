#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 *insert_node -  adds a new node at the beginning of a list_t list.
 *@head : head of linked list
 *@number : int
 *Return: new node
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *current = *head;
listint_t *nouveau = malloc(sizeof(*nouveau)), *suivant;
if (nouveau == NULL)
return (NULL);
nouveau->n = number;
nouveau->next = NULL;
if (*head == NULL)
{
*head = nouveau;
return (nouveau);
}
if (number < current->n)
{
nouveau->next = *head;
*head = nouveau;
}
else
{
suivant = *head;
while (suivant->next != NULL && suivant->next->n < number)
suivant = suivant->next;
nouveau->next = suivant->next;
suivant->next = nouveau;
}
return (nouveau);
}