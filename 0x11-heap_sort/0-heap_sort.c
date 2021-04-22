#include "sort.h"
/**
 * move - move 
 * @array1: array1
 * @array2: array2
 * Return: 0
 */

void move(int *array1, int *array2)
{
int aux;

aux = *array1;
*array1 = *array2;
*array2 = aux;
}
/**
 * heap - heap array
 * @array: array
 * @size: size
 * @i: i
 * @length: lenght
 * Return:0
 */

void heap(int *array, int size, int i, int length)
{
int max = i;
int left = 2 * i + 1;
int right = 2 * i + 2;

if (left < size && array[max] < array[left])
max = left;

if (right < size && array[max] < array[right])
max = right;

if (max != i)
{
move(&array[i], &array[max]);
print_array(array, length);
heap(array, size, max, length);
}
}

/**
 * heap_sort - sorts an array of integers
 * @array: array to sort
 * @size: size of array
 * Return: 0
 */
void heap_sort(int *array, size_t size)
{
int i;

if (size == NULL || array == NULL)
return;
for (i = size / 2 - 1; i >= 0; i--)
heap(array, size, i, size);
for (i = size - 1; i > 0; i--)
{
if (array[0] >= array[i])
{
move(&array[0], &array[i]);
print_array(array, size);
}
heap(array, i, 0, size);
}
}