#include "sort.h"

/**
 * power_10 - Function that calculates power of 10
 * @n: n to calculate
 * Return: 10**n
 */

int power_10(int n)
{
int i;
int s = 1;

for (i = 0; i < n; i++)
s *= 10;

return (s);
}

/**
 * sort_matrix - sort matrix
 * @array: the array to sort
 * @tmp: the matrix
 * @size: the size of arrray
 * @level: the digit
 * Return: 0 otherwise 1
 */


int sort_matrix(int *array, int **tmp, size_t size, int level)
{
int n, k, max = 0;
int index[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
size_t i, j;

for (i = 0; i < size; i++)
{
n = (array[i] % power_10(level)) / power_10(level - 1);
tmp[n][index[n]++] = array[i];
if (array[i] > max)
max = array[i];
}

k = 0;
j = 0;

for (i = 0; i < 10; i++)
{
while (index[i] != 0 && k < index[i])
{
array[j + k] = tmp[i][k];
k++;
}
j += k;
k = 0;
}
print_array(array, size);

if (max / power_10(level) == 0)
return (0);
return (1);
}

/**
 * free - Function
 * @grid: the grid
 * Return: 0
 */

void fre(int **grid)
{
int i;

for (i = 0; i < 10; i++)
free(grid[i]);
free(grid);
}

/**
 * radix_sort - function
 * @array: the array to sort
 * @size: the size of the array
 * Return: 0
 */

void radix_sort(int *array, size_t size)
{
int **tmp, aux = 1, level = 1;
size_t i;
if (array == NULL || size < 2)
return;
tmp = malloc(sizeof(int *) * 10);
for (i = 0; i < 10; i++)
tmp[i] = malloc(sizeof(int) * size);
while (aux)
{
aux = sort_matrix(array, tmp, size, level++);
}
fre(tmp);
}
