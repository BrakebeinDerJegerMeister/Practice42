# Énoncé

| Exercice : 05                                       |
| --------------------------------------------------- |
| btree_search_item                                   |
| Dossier de rendu : ex05/                            |
| Fichiers à rendre : btree_search_item.c, ft_btree.h |
| Fonctions Autorisées : Aucune                       |
• Écrire la fonction btree_search_item qui retourne le premier élèment correspondant à la donnée de référence passée en paramètre. L’arbre devra être parcouru de manière infix. Si l’élément n’est pas trouvé, la fonction devra retourner NULL.
• Elle devra être prototypée de la façon suivante :
```C
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));
```
# Correction

btree_search_item.c :
```C
#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree	*res;

	if (!root)
		return (NULL);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root);
	res = btree_search_item(root->left, data_ref, cmpf);
	if (!res)
		res = btree_search_item(root->right, data_ref, cmpf);
	return (res);
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

t_btree	*btree_create_node(void *item);

#endif
```
# Explications

La fonction `btree_search_item` est implémentée pour effectuer une recherche dans un arbre binaire (pas nécessairement un arbre binaire de recherche) en utilisant une stratégie de recherche en profondeur. Cette fonction parcourt l'arbre de manière récursive pour localiser un élément spécifique, déterminé par une fonction de comparaison.

### Fonction `btree_search_item`

#### Description
La fonction navigue à travers un arbre binaire à partir d'un nœud racine donné, recherchant un élément de référence spécifié par `data_ref`. La comparaison entre les éléments de l'arbre et l'élément de référence est effectuée par une fonction de comparaison `cmpf`.

#### Paramètres
- **root** : Pointeur vers le nœud racine de l'arbre binaire.
- **data_ref** : Pointeur vers l'élément de référence recherché.
- **cmpf** : Fonction de comparaison qui prend deux arguments de type `void*` et renvoie un entier. La fonction doit renvoyer `0` si les deux éléments comparés sont équivalents.

#### Algorithme
1. **Vérification initiale** : Si le nœud courant (`root`) est `NULL`, la fonction renvoie `NULL`, indiquant que l'élément n'est pas trouvé dans la branche courante.
2. **Comparaison à la racine** : Si la fonction de comparaison `cmpf` appliquée à l'élément du nœud courant et à `data_ref` renvoie `0`, cela signifie que l'élément recherché a été trouvé. Le pointeur vers ce nœud est alors renvoyé.
3. **Recherche récursive dans le sous-arbre gauche** : Si l'élément n'est pas trouvé à la racine, la fonction effectue un appel récursif pour rechercher dans le sous-arbre gauche.
4. **Recherche dans le sous-arbre droit** : Si la recherche dans le sous-arbre gauche ne retourne aucun résultat (`NULL`), un appel récursif est effectué pour rechercher dans le sous-arbre droit.

#### Comportement et Performance
- La fonction parcourt l'arbre en profondeur, explorant chaque branche jusqu'à ses feuilles si nécessaire. Cela peut entraîner un temps d'exécution proportionnel au nombre de nœuds dans l'arbre dans le pire des cas.
- La récursivité peut entraîner une consommation importante de la pile d'appels, surtout pour les grands arbres ou ceux qui sont profondément déséquilibrés.

#### Applications
- Cette méthode est utile dans les arbres où l'ordre des nœuds n'est pas strictement défini par les clés, permettant une recherche flexible basée sur des critères personnalisés.
- Idéale pour des structures de données complexes où les nœuds peuvent contenir divers types d'informations ou pour des opérations de filtrage dans des arbres.

La fonction `btree_search_item` offre ainsi une méthode robuste et flexible pour naviguer et extraire des informations dans des structures arborescentes variées, adaptée à des usages multiples où les critères de recherche peuvent être définis de manière dynamique.