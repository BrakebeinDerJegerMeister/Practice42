# Énoncé

| Exercice : 03                                        |
| ---------------------------------------------------- |
| btree_apply_suffix                                   |
| Dossier de rendu : ex03/                             |
| Fichiers à rendre : btree_apply_suffix.c, ft_btree.h |
| Fonctions Autorisées : Aucune                        |
• Écrire la fonction btree_apply_suffix qui applique la fonction passée en para-
mètre à l’item de chaque node, en parcourant l’arbre de manière suffix.
• Elle devra être prototypée de la façon suivante :
```C
void btree_apply_suffix(t_btree *root, void (*applyf)(void *));
```
# Correction

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

t_btree	*btree_create_node(void *item);

#endif
```

btree_apply_suffix.c :
```C
#include "ft_btree.h"
#include <stdlib.h>

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}
```
# Explications

La méthode **suffixe** (ou parcours postordre) est une troisième façon classique de parcourir un arbre binaire. Dans ce type de parcours, chaque nœud est visité après ses sous-arbres, ce qui signifie que vous visitez d'abord le sous-arbre gauche, puis le sous-arbre droit, et enfin le nœud courant. Cette approche est souvent utilisée pour des opérations où il est nécessaire de traiter les enfants avant de traiter le parent, comme lors de la libération de la mémoire utilisée par l'arbre ou l'évaluation de certaines expressions arithmétiques complexes.

### Détails du Parcours Postordre

#### Processus de Visite
1. **Visiter le sous-arbre gauche** : La visite commence par un parcours récursif complet du sous-arbre gauche du nœud courant.
2. **Visiter le sous-arbre droit** : Ensuite, le parcours se poursuit avec le sous-arbre droit.
3. **Traiter le nœud courant** : Après avoir visité les deux sous-arbres, le nœud courant est traité. Cela pourrait être une opération telle que l'affichage de la valeur du nœud, la libération de la mémoire, ou l'application d'une fonction spécifique.

#### Applications
- **Destruction d'un arbre** : Parfait pour libérer proprement la mémoire d'un arbre, car il assure que la mémoire des enfants est libérée avant celle du parent.
- **Évaluation des expressions arithmétiques** : Dans les arbres d'expression, le parcours postordre permet de calculer d'abord les valeurs des opérandes avant d'appliquer les opérations, respectant ainsi l'ordre des opérations.
- **Calcul des propriétés dépendantes** : Utile pour propager des valeurs ou des états depuis les feuilles vers la racine, par exemple pour calculer la hauteur de l'arbre ou d'autres agrégats.

#### Avantages
- **Versatilité** : Très efficace pour des tâches nécessitant des actions ou des calculs de "bas en haut" dans l'arbre.
- **Intuitif pour certaines opérations** : Naturel pour des opérations qui nécessitent que les enfants soient complètement traités avant le parent.