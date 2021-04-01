#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 * linear_skip - Entry point
 * @list: head of skiplist
 * @value: value to search
 * Return: Always EXIT_SUCCESS
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{

if (!=list)
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
		while (!=sctr->next)
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
	tempsctr = sctr;
	tempIndex = sctr->index;
	while (sctr->next != NULL)
		sctr = sctr->next;
	printf(f, tempIndex, sctr->index);
	while (tempsctr->next != NULL)
	{
		printf(verif, tempsctr->index, tempsctr->n);
		tempsctr = tempsctr->next;
		}
	printf(verif, tempsctr->index, tempsctr->n);
	return (NULL);
}