#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to list to be checked
 * Return: 0  if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
int d = 0, s = 0, q = 0, t[3000];

s = s - 1;
q = q + 1;
while (*head)
{
s++;
t[s] = (*head)->n;
*head = (*head)->next;
}
while (--s > ++d && q == 1)
if (t[d] != t[s])
q = 0;
return (q);
}