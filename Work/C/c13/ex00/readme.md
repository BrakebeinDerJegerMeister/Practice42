# Énoncé

| Exercice : 00                                       |
| --------------------------------------------------- |
| btree_create_node                                   |
| Dossier de rendu : ex00/                            |
| Fichiers à rendre : btree_create_node.c, ft_btree.h |
| Fonctions Autorisées : malloc                       |
• Écrire la fonction btree_create_node qui alloue un nouvel élément, initialise son item à la valeur du paramètre et tous les autres éléments à 0.
• L’adresse de la node créée est renvoyée.
• Elle devra être prototypée de la façon suivante :
```C
t_btree *btree_create_node(void *item);
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

#endif
```

btree_create_node.c :
```C
#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void	*item)
{
	t_btree	*node;

	node = malloc(sizeof (t_btree));
	if (node)
	{
		node->item = item;
		node->left = NULL;
		node->right = NULL;
	}
	return (node);
}
```
# Explications

### Fonction `btree_create_node`

#### Objectif
Initialiser et allouer un nœud d'arbre binaire contenant une donnée générique.

#### Méthodologie
Allocation dynamique de mémoire pour un nouveau nœud via `malloc`, suivi par l'initialisation des pointeurs de branches à `NULL` et l'assignation de la valeur de l'item. Cette approche permet une insertion flexible dans l'arbre binaire.

#### Gestion des erreurs
La vérification post-allocation est cruciale pour assurer que la mémoire a été correctement allouée. En cas d'échec de `malloc`, la fonction renvoie `NULL`, permettant de gérer les erreurs en amont lors de la construction de l'arbre.

#### Performance et sécurité
L'allocation manuelle de mémoire et la gestion des pointeurs nécessitent une attention particulière pour prévenir les fuites de mémoire et les accès invalides, surtout dans des structures récursives comme les arbres binaires.

#### Applications typiques
Utilisée dans les structures de données où les éléments sont organisés de manière hiérarchique, facilitant des opérations telles que l'insertion, la recherche, et le parcours d'arbre avec des temps d'exécution potentiellement log(n) selon la balance de l'arbre.

#### Extensibilité
Adaptable pour inclure des fonctionnalités supplémentaires comme des marqueurs pour arbres auto-équilibrés ou des attributs spécifiques pour des implémentations d'arbres spécialisés (par exemple, arbres rouge-noir).