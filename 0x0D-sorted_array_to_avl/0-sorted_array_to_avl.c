#include "binary_trees.h"

/**
* sorted_array_to_avl -function that builds an AVL tree from an array
* @array: int
* @size: int
* Return: pointer to the root node of the created AVL tree, or NULL
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
avl_t *tree;

if (!array || size <= 0)
return (NULL);

tree = add_noeud(0, NULL, size - 1, array);
return (tree);
}


/**
* add_noeud - create tree
* @array: int
* @debut: int
* @fin: int
* @parent: int
* Return: pointeur(mean true)
*/
avl_t *add_noeud(size_t d, avl_t *parent, size_t f, int *array)
{
size_t m;
avl_t *tree;

if (d > f)
return (NULL);

m = (d + f) / 2;
tree = new_noeud(parent, array[m]);
if (!tree)
return (NULL);

if (m != f)
tree->right = add_noeud(m + 1, tree, f, array);

if (m != d)
tree->left = add_noeud(d, tree, m - 1, array);

return (tree);
}

/**
* new_noeud - creation de nouveau noeud
* @parent: pointeur
* @n: int
* Return: noeud(mean true)
*/
avl_t *new_noeud(avl_t *p, size_t n)
{
avl_t *new;

new = malloc(sizeof(avl_t));

if (!new)
return (NULL);

new->n = n;
new->right = NULL;
new->parent = p;
new->left = NULL;
return (new);
}