#include "lists.h"

/**
 * find_listint_loop - the Function that finds the loop
 * @head: the pointer
 * Return: address otherwise NULL
*/

listint_t *find_listint_loop(listint_t *head)
{
listint_t *first, *s;

if (head == NULL)
return (NULL);
first = head;
s = head;
while (s && first && first->next)
{
if (s->next)
s = s->next;
if (first->next && first->next->next)
first = first->next->next;
else
return (NULL);
if (s == first)
{
s = head;
while (s && first && first->next)
{
if (s == first)
{
return (s);
}
s = s->next;
first = first->next;
}
}
}
return (NULL);
}
