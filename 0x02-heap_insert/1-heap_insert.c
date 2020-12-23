#include "binary_trees.h"
/**
 * heap_insert -  inserts a value into a Max Binary Heap:
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value store in the node to be inserted
 * Return: pointer to the new node, or NULL on failure
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
return (node);
}