#include "binary_trees.h"
/**
 * heap_insert - inserts value
 * @root: is a pointer to the parent node of the node to create.
 * @value: the value of the new node
 * Return: return a pointer to the new node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *node;
node = (struct binary_tree_s *)malloc(sizeof(struct binary_tree_s));
if (!node)
{
return (NULL);
}
node->n = value;
node->parent = *root;
node->right = NULL;
node->left = NULL;
return (node);
}