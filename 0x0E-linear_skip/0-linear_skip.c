#include "search.h"
/**
 * linear_skip - fn
 * @list: list
 * @value: val
 * Return: NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{

if (list == NULL)
return (NULL);
skiplist_t *sctr = list, *tmpsctr = NULL;
size_t tempIndex = 0;
char *verif = "Value checked at index [%lu] = [%d]\n";
char *f = "Value f between indexes [%lu] and [%lu]\n";

while (sctr->express)
{
if (sctr->express->n == value)
		{
			printf("Value checked at index [%lu] = [%d]\n", sctr->index, sctr->n);
			return (sctr->express);
		}
	if (sctr->express->n > value)
	{
		printf(verif, sctr->express->index, sctr->express->n);
		printf(f, sctr->index, sctr->express->index);
		while (sctr->next)
		{
			printf("Value checked at index [%lu] = [%d]\n", sctr->index, sctr->n);
			if (sctr->n == value)
				return (sctr);
			sctr = sctr->next; 
		}
	}
	sctr = sctr->express;
	printf("Value checked at index [%lu] = [%d]\n", sctr->index, sctr->n);
	}
	tmpsctr = sctr;
	tempIndex = sctr->index;
	while (sctr->next)
		sctr = sctr->next;
	printf(f, tempIndex, sctr->index);
	while (tmpsctr->next)
	{
		printf(verif, tmpsctr->index, tmpsctr->n);
		tmpsctr = tmpsctr->next;
		}
	printf(verif, tmpsctr->index, tmpsctr->n);
	return (NULL);
}