#include "palindrome.h"
/**
*is_palindrome - that checks whether or not a given unsigned integer is a palindrome.
*@n: The number to be checked
*Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
int rn = 0;
int res, x = n;
while (n != 0)
{
res = n % 10;
rn = rn * 10 + res;
n = n / 10;
}
if (x == rn)
return (1);
return (0);
}