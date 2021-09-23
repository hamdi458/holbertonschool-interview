#include "substring.h"

/**
 * cmp - difference between values
 * @a: the first var
 * @b: the second var
 * Return: 0
 **/

int cmp(const void *a, const void *b)
{
return (*(int *)a - *(int *)b);
}

/**
 * check - chek continous words continous
 * @T: the array with index for ever word
 * @len: the var word size
 * @T_len: the var T size
 * Return: idx or 0
 **/

int check(int *T, int len, int T_len)
{
int i;

for (i = 0; i < T_len - 1; i++)
{
if (T[i + 1] - T[i]  != len)
return (0);
}
return (1);
}

/**
 * search - search words in string
 * @s: string
 * @words: array of words
 * @nb_words: number of words
 * Return: array with size of substring for every word, otherwise NULL
 **/

int *search(char const *s, char const **words, int nb_words)
{
int *T, i, j;
char *aux;
int len;

T = malloc((sizeof(int) * nb_words));
if (!T)
return (NULL);
for (i = 0; i < nb_words; i++)
{
aux = strstr(s, words[i]);
if (!aux)
{
free(T);
return (NULL);
}
len = (int)strlen(aux);
for (j = 0; j < i; j++)
{
if (len == T[j])
{
aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
if (!aux)
{
free(T);
return (NULL);
}
len = (int)strlen(aux);
T[i] = len;
continue;
}

}
T[i] = len;
}

return (T);

}

/**
 * find_substring - search words in string
 * @s: string
 * @words: array of words
 * @nb_words: number of words
 * @n: return size
 * Return: array with index for every word or NULL
 *
 **/

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
int *idx, *T, len, j, diff, s_len, f_idx, tmp;

*n = 0;
len = (int)strlen(words[0]);
s_len = (int)strlen(s);
for (j = 0; j < s_len; j++)
{
T = search(s, words, nb_words);
if (!T)
break;

qsort(T, nb_words, sizeof(int), cmp);

f_idx = check(T, len, nb_words);
tmp = T[nb_words - 1];
free(T);

if (f_idx == 1)
{
diff = s_len - tmp;
if (*n == 0 || diff != idx[*n - 1])
{
if (*n == 0)
{
idx = malloc((sizeof(int)));
if (!idx)
return (NULL);
}
else
idx = realloc(idx, sizeof(int) * (*n + 1));
idx[*n] = diff;
*n += 1;
}
}
s++;
}
if (*n == 0)
{
return NULL;
}
return idx;
}
