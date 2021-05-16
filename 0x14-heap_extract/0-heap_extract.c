#include "binary_trees.h"

/**
 * tree_height - THE FN measures the height of a binary tree
 * @tree: the pointer to the node
 * Return: The height of the tree from node
 **/

size_t tree_height(const heap_t *tree)
{
size_t left, right;

if (tree == NULL)
return (0);
if (!tree->left && !tree->right)
return (0);

right = tree_height(tree->right) + 1;
left = tree_height(tree->left) + 1;

if (left > right)
return (left);
else
return (right);
}

/**
 * preorder - the Recursive function that goes through a binary tree
 * @tree: the pointer to root
 * @node: the pointer to node in the tree
 * @h: the height of the tree
 * @level: the layer in the tree
 * Return: 0
 **/

void preorder(heap_t *tree, heap_t **node, size_t h, size_t level)
{
if (tree == NULL)
return;
if (h == level)
*node = tree;

level++;

if (tree->left)
preorder(tree->left, node, h, level);
if (tree->right)
preorder(tree->right, node, h, level);
}

/**
 * heap_extract - the Function that extracts the rootnode from a Max Binary Heap
 * @root: the pointer to the root node of the heap
 * Return: value stored in the root node, otherwhise 0 on Fail
 **/

int heap_extract(heap_t **root)
{
int value, v_aux;
size_t level = 0;
heap_t *aux, *node;

if (!root || !*root)
return (0);
aux = *root;
value = aux->n;
if (!aux->left && !aux->right)
{
*root = NULL;
free(aux);
return (value);
}
preorder(aux, &node, tree_height(aux), level);
while (aux->left || aux->right)
if (!aux->right || aux->left->n > aux->right->n)
{
v_aux = aux->n;
aux->n = aux->left->n;
aux->left->n = v_aux;
aux = aux->left;
}
else if (!aux->left || aux->left->n < aux->right->n)
{
v_aux = aux->n;
aux->n = aux->right->n;
aux->right->n = v_aux;
aux = aux->right;
}
aux->n = node->n;
if (node->parent->right)
node->parent->right = NULL;
else
node->parent->left = NULL;
free(node);
return (value);
}
