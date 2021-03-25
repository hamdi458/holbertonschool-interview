#include "binary_trees.h"

/**
* sorted_array_to_avl - fonction de creation darbre
* @array: int
* @size: size_t
* Return: int(mean true)
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *arbre;

	if (array == NULL || size <= 0)
		return (NULL);

	arbre = ajout_noeud(0, NULL, size - 1, array);
	return (arbre);
}


/**
* ajout_noeud - creation darbre
* @array: int
* @debut: size_t
* @fin: size_t
* @parent: pointeur
* Return: pointeur(mean true)
*/
avl_t *ajout_noeud(size_t debut, avl_t *parent, size_t fin, int *array)
{
	size_t milieu;
	avl_t *arbre;

	if (debut > fin)
		return (NULL);

	milieu = (debut + fin) / 2;
	arbre = nvx_noeud(parent, array[milieu]);
	if (arbre == NULL)
		return (NULL);

	if (milieu != fin)
		arbre->right = ajout_noeud(milieu + 1, arbre, fin, array);

	if (milieu != debut)
		arbre->left = ajout_noeud(debut, arbre, milieu - 1, array);

	return (arbre);
}

/**
* nvx_noeud - creation de nouveau noeud
* @parent: pointeur
* @n: int
* Return: noeud(mean true)
*/
avl_t *nvx_noeud(avl_t *parent, size_t n)
{
	avl_t *nouveau;

	nouveau = malloc(sizeof(avl_t));

	if (nouveau == NULL)
		return (NULL);

	nouveau->n = n;
	nouveau->right = NULL;
	nouveau->parent = parent;
	nouveau->left = NULL;
	return (nouveau);
}