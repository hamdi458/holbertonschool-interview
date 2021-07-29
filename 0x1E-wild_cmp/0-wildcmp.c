#include "holberton.h"

/**
 * len - lenght function without Using strlen()
 * @s: the string
 * Return: lenght of s
 **/

int len(char *s)
{
int i;
for (i = 0; s[i] != '\0'; ++i);
return i;
}

/**
 * compare - compare strings
 * @str1: the string 1
 * @str2: the string 2
 * @i: i
 * @j: j
 * @wc: the wildcard
 * @lwc: the last wildcard
 * @l: the length of str1
 * Return: 1 otherwise 0.
 **/
int compare(char *str1, char *str2, int i, int j, int wc, int lwc, int l)
{
if (str2[j] == '\0' && (str2[j - 1] == '*' || str2[j - 1] == str1[l - 1]))
return (1);
if (str2[j] == '*')
{
lwc = ++j;
wc = 1;
return (compare(str1, str2, i, j, wc, lwc, l));
}
if (str2[j] == str1[i])
{
i++;
j++;
wc = 0;
return (compare(str1, str2, i, j, wc, lwc, l));
}
if (str1[i] != str2[j] && wc == 1)
{
if (str1[i] == '\0')
{
return (0);
}
i++;
return (compare(str1, str2, i, j, wc, lwc, l));
}
if (str1[i] == '\0')
return (0);
if (str1[i] != str2[j] && wc == 0)
{
j = lwc;
wc = 1;
if (lwc == 0)
return (0);
return (compare(str1, str2, i, j, wc, lwc, l));
}
return (0);
}

/**
 * wildcmp - compare two strings and can be considered identical.
 * @str1: string 1
 * @str2: string 2
 * Return: 1 if identical otherwise 0.
 */

int wildcmp(char *str1, char *str2)
{
int i = 0, j = 0, wc = 1;
int lwc = 0;
return (compare(str1, str2, i, j, wc, lwc, len(str1)));
}
