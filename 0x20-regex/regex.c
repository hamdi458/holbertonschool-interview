#include "regex.h"
/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: the string given
 * @pattern: the regular expression given
 * Return: 1 otherwise 0
 */

int regex_match(char const *str, char const *pattern)
{
int pnt = 0;
int star = 0;

if (str == NULL || pattern == NULL)
return (0);

pnt = *str && (*str == *pattern || *pattern == '.');
star = *(pattern + 1) == '*';

if (!*str && star == 0)
return (*pattern ? 0 : 1);
else if (pnt == 1 && star == 1)
return (regex_match(str + 1, pattern) || regex_match(str, pattern + 2));
else if (pnt && !star)
return (regex_match(str + 1, pattern + 1));
else if (star)
return (regex_match(str, pattern + 2));
return (0);
}
