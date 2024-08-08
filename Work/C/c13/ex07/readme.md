# Énoncé

| Exercice : 07                                          |
| ------------------------------------------------------ |
| btree_apply_by_level                                   |
| Dossier de rendu : ex07/                               |
| Fichiers à rendre : btree_apply_by_level.c, ft_btree.h |
| Fonctions Autorisées : malloc, free                    |
• Écrire la fonction btree_apply_by_level qui applique la fonction passée en pa-
ramètre à chaque noeud de l’arbre. L’arbre doit être parcouru étage par étage. La fonction appelée prendra trois paramètres :
◦ Le premier paramètre, de type void *, correspond à l’item du node ;
◦ Le second paramètre, de type int, correspond au niveau sur lequel on se trouve :
0 pour le root, 1 pour ses enfants, 2 pour ses petits-enfants, etc. ;
◦ Le troisième paramètre, de type int, vaut 1 s’il s’agit du premier node du
niveau, 0 sinon.
• Elle devra être prototypée de la façon suivante :
```C
void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
```
# Correction

btree_apply_by_level.c :
```C
#include "ft_btree.h"
#include <stdlib.h>

t_list	*ft_create_list_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->data = data;
		elem->next = NULL;
	}
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*n_list;

	if (*begin_list)
	{
		n_list = *begin_list;
		while (n_list->next)
			n_list = n_list->next;
		n_list->next = ft_create_list_elem(data);
	}
	else
		*begin_list = ft_create_list_elem(data);
}

void	tree_to_list(t_btree *root, t_list **vlist)
{
	if (!root)
		return ;
	if (!*vlist)
		*vlist = ft_create_list_elem(NULL);
	ft_list_push_back((t_list **)&((*vlist)->data), root);
	tree_to_list(root->left, &((*vlist)->next));
	tree_to_list(root->right, &((*vlist)->next));
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_list	*tree_list;
	t_list	*node_list;
	t_btree	*node;
	int		nb[2];

	if (!root)
		return ;
	tree_list = NULL;
	nb[0] = 0;
	nb[1] = 1;
	tree_to_list(root, &tree_list);
	while (tree_list)
	{
		node_list = (t_list *)tree_list->data;
		while (node_list)
		{
			node = (t_btree *)node_list->data;
			if (node && node->item)
				(*applyf)(node->item, nb[0], nb[1]);
			node_list = node_list->next;
			nb[1] = 0;
		}
		nb[0]++;
		tree_list = tree_list->next;
	}
}
```

ft_btree.h :
```C
#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

t_btree	*btree_create_node(void *item);

#endif
```
# Explications

Application Fonctionnelle par Niveau sur Arbre Binaire

**Fonctionnalité** : 
Cette méthode permet d'appliquer une fonction spécifiée à chaque élément d'un arbre binaire, parcourant l'arbre niveau par niveau. Cela est souvent utilisé pour des opérations de traitement en masse où la relation hiérarchique et le niveau des nœuds sont pertinents pour l'opération.

**Contexte d'Utilisation** : 
- Analyse et manipulation de structures de données arborescentes.
- Applications nécessitant un traitement par couches, telles que les algorithmes de rendu, les simulations hiérarchiques, ou l'analyse sémantique dans les arbres de décision.

**Structures de Données** : 
- `t_btree` : Un nœud de l'arbre binaire, contenant des pointeurs vers les nœuds enfants gauche et droit, ainsi qu'un pointeur vers des données (`item`).
- `t_list` : Une structure de liste chaînée utilisée pour stocker temporairement les nœuds à chaque niveau pendant le parcours de l'arbre.

**Implémentation** :
1. **Création et manipulation de listes** :
   - `ft_create_list_elem(void *data)`: Crée un nouvel élément de liste avec les données fournies.
   - `ft_list_push_back(t_list **begin_list, void *data)`: Ajoute un élément à la fin d'une liste chaînée.
  
2. **Construction de la liste par niveaux** :
   - `tree_to_list(t_btree *root, t_list **vlist)`: Convertit un arbre binaire en une structure de liste de listes, chaque sous-liste contenant les nœuds d'un même niveau. Utilise la récursivité pour parcourir l'arbre et la gestion dynamique des listes pour accommoder un nombre indéterminé de niveaux.

3. **Application de la fonction par niveau** :
   - `btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))`: Parcourt l'arbre transformé en liste de listes, appliquant la fonction `applyf` à chaque nœud. La fonction `applyf` est appelée avec l'item du nœud, le niveau du nœud, et un booléen indiquant si le nœud est le premier du niveau.
   - Utilisation d'un tableau `int nb[2]` pour suivre le niveau actuel (`nb[0]`) et si le nœud est le premier de son niveau (`nb[1]`).

**Complexité** :
- **Temporelle** : O(n) où n est le nombre total de nœuds dans l'arbre, car chaque nœud est visité exactement une fois.
- **Spatiale** : O(w) où w est la largeur maximale de l'arbre à un niveau donné, reflétant l'espace nécessaire pour stocker la file d'attente des nœuds au niveau le plus large.

**Avantages** :
- Permet un traitement différencié basé sur la profondeur de l'arbre, utile pour les algorithmes qui nécessitent une connaissance du contexte hiérarchique.
- Flexible et adaptable à divers types de données et de traitements via le pointeur de fonction.

**Limitations** :
- La gestion de la mémoire doit être rigoureusement contrôlée pour éviter les fuites, particulièrement avec la création dynamique de nombreux éléments de liste.

**Utilisation Recommandée** :
- Traitement de données structurées en arbre où l'ordre de traitement et la reconnaissance du niveau sont cruciaux.
- Idéal pour les environnements où la complexité spatiale est moins critique que la nécessité d'un traitement ordonné et structuré des données.