#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * check_arg - checks if argument is valid
 * @argv:  argument
 * Return: length of argument or error
 */
int check_arg(char *argv)
{
int i;
for (i = 0; argv[i]; i++)
{
if (argv[i] < '0' || argv[i] > '9')
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}
}
return (i);
}

/**
 * alloc - alloc memory
 * @length: the length
 * Return: 0
 */
char *alloc(int length)
{
char *p;
int i;
p = malloc(sizeof(char) * (length + 1));
if (!p)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}
for (i = 0; i < length; i++)
{
p[i] = '0';
}
p[i] = '\0';
return (p);
}

/**
 * insert - insert in array
 * @result: var
 * @x: var
 * @position: pos of insert
 */
void insert(char *result, int x, int position)
{
x = x + (result[position] - '0');
while (x > 0)
{
result[position] = (x % 10) + '0';
x /= 10;
if (x == 0)
break;
position--;
x += (result[position] - '0');
}
}

/**
 * main - Main function
 * @argc : number of arguments
 * @argv: array of pointers to arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
int m, j, i, l1, l2;
char *result, *u, *v;
if (argc != 3)
{
_putchar('E');
_putchar('r');
_putchar('r');
_putchar('o');
_putchar('r');
_putchar('\n');
exit(98);
}
l1 = check_arg(argv[1]);
l2 = check_arg(argv[2]);
result = alloc(l1 + l2);
u = argv[1];
v = argv[2];
for (m = l2 - 1; m >= 0; m--)
{
for (j = l1 - 1; j >= 0; j--)
{
insert(result, ((u[m] - '0') * (v[j] - '0')), m + j + 1);
}
}
for (i = 0; result[i] == '0' && result[i + 1]; i++)
{
;
}
printf("%s\n", &result[i]);
free(result);
return (0);
}
