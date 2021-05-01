#include "menger.h"

/**
 * menger - Fn that draws a 2D Menger Sponge
 * @level: level
 * Return: 0
*/
void menger(int level)
{
int i, j, size, h, w;
char sim;

size = pow(3, level);

for (i = 0; i < size; i++)
{
for (j = 0; j < size; j++)
{
h = i;
w = j;
sim = '#';
while (h > 0)
{
if (h % 3 == 1 && w % 3 == 1)
sim = ' ';
h = h / 3;
w = w / 3;
}
printf("%c", sim);
}
printf("\n");
}
}
