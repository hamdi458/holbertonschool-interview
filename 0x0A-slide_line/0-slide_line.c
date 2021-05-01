
#include "slide_line.h"

/**
 * slide_line - the Slide and merge an array
 * @line: the Pointer
 * @size: the Size
 * @direction: the Direction to slide and merge
 * Return: 1 , or 0
 */

int slide_line(int *line, size_t size, int direction)
{
size_t h, current = 0, pos1 = 0, pos2 = 1, i, j;

if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
return (0);
pos1 = (direction == SLIDE_RIGHT) ? size - 1 : pos1;
pos2 = (direction == SLIDE_RIGHT) ? size - 2 : pos2;

for (i = 0; i < size; i++)
{       h = pos2;
current = 0;
for (j = i + 1; j < size; j++)
{
if (line[pos1] != 0 && line[pos2] == line[pos1])
{
line[pos1] = line[pos1] * 2;
line[pos2] = 0;
break;
}
if (line[pos1] == 0 && line[pos2] != 0)
{
line[pos1] = line[pos2];
line[pos2] = 0;
current = 1;
pos2 = h;
i--;
break;
}
if (line[pos2] != 0)
break;
direction == SLIDE_LEFT ? pos2++ : pos2--;
}
if (line[pos1] == 0)
break;
if (current == 0)
{	pos1 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos1;
pos1 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos1;
pos2 = (direction == SLIDE_LEFT) ? pos1 + 1 : pos2;
pos2 = (direction == SLIDE_RIGHT) ? pos1 - 1 : pos2; }
}
return (1);
}
