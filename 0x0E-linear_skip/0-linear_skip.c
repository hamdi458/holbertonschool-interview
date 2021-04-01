#include "search.h"
/**
 * find - fn
 * @p: p
 * @actu: actu
 * @value: val
 * Return: node or null
 */
skiplist_t *find(skiplist_t *p, skiplist_t *actu, int value)
{
while (p && p->index <= actu->index)
{
printf("Value checked at index [%lu] = [%i]\n", p->index, p->n);
if (p->n == value)
{
return (p);
}
p = p->next;
}
return (NULL);
}

/**
 * linear_skip - function that searches for a value
 * @list: list of search
 * @value: value
 * Return: the pointer or NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *actu, *p;
size_t actut, pv;
if (!list)
return (NULL);
actu = list;
while (actu->express != NULL)
{
p = actu;
actu = actu->express;
actut = actu->index;
pv = p->index;
printf("Value checked at index [%lu] = [%i]\n", actut, actu->n);
if (p->n > value && p->index == 0)
return (NULL);
if (actu->n >= value)
{
break;
}
}
if (!actu->express && actu->n < value)
{
p = actu;
pv = p->index;
while (actu->next)
actu = actu->next;
actut = actu->index;
}
printf("Value found between indexes [%lu] and [%lu]\n", pv, actut);
return (find(p, actu, value));
}
