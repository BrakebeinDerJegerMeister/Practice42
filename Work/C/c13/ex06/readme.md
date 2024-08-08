# Énoncé

| Exercice : 06                                       |
| --------------------------------------------------- |
| btree_level_count                                   |
| Dossier de rendu : ex06/                            |
| Fichiers à rendre : btree_level_count.c, ft_btree.h |
| Fonctions Autorisées : Aucune                       |
• Écrire la fonction btree_level_count qui retourne la taille de la plus grande
branche passée en paramètre.
• Elle devra être prototypée de la façon suivante :
```C
int btree_level_count(t_btree *root);
```
# Correction

btree_level_count.c :
```C
#include "ft_btree.h"

void	get_level(t_btree *root, int current_level, int *max_level)
{
	if (!root)
		return ;
	if (current_level > *max_level)
		*max_level = current_level;
	get_level(root->left, current_level + 1, max_level);
	get_level(root->right, current_level + 1, max_level);
}

int	btree_level_count(t_btree *root)
{
	int	max_level;

	max_level = 0;
	get_level(root, 1, &max_level);
	return (max_level);
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

### Fiche Technique : Calcul du Nombre de Niveaux dans un Arbre Binaire

**Objectif** : Déterminer le nombre de niveaux (hauteur) dans un arbre binaire.

**Structure de Données** : `t_btree`
- Cette structure doit être définie par l'utilisateur et contient généralement au moins les éléments suivants :
  - `t_btree *left;` (pointeur vers le sous-arbre gauche)
  - `t_btree *right;` (pointeur vers le sous-arbre droit)
  - Une variable de données (par exemple, `int data;`).

**Fonctions Impliquées** :
1. **`get_level(t_btree *root, int current_level, int *max_level)`**
   - **Paramètres** :
     - `t_btree *root` : Pointeur vers le nœud racine de l'arbre ou sous-arbre.
     - `int current_level` : Niveau courant dans l'arbre, initialement défini à 1 pour la racine.
     - `int *max_level` : Pointeur vers une variable stockant le niveau maximum atteint.
   - **Comportement** :
     - La fonction vérifie si le nœud courant est `NULL`, auquel cas elle retourne immédiatement.
     - Si le niveau courant est supérieur à la valeur pointée par `max_level`, met à jour `max_level`.
     - Récurrence pour les sous-arbres gauche et droit en incrémentant le `current_level`.
   - **Retour** : Aucun (effet de bord sur `*max_level`).

2. **`btree_level_count(t_btree *root)`**
   - **Paramètres** :
     - `t_btree *root` : Pointeur vers la racine de l'arbre.
   - **Comportement** :
     - Initialise `max_level` à 0.
     - Appelle `get_level` en passant la racine, le niveau initial 1, et l'adresse de `max_level`.
     - Retourne la valeur de `max_level` comme le nombre de niveaux dans l'arbre.
   - **Retour** : Le nombre total de niveaux dans l'arbre (int).

**Complexité** : 
- **Temporelle** : O(n), où n est le nombre de nœuds dans l'arbre, car chaque nœud est visité une fois.
- **Spatiale** : O(h), où h est la hauteur de l'arbre, due à la profondeur de la pile d'appels récursifs.

**Utilisation** :
- Cette implémentation est adaptée pour évaluer la hauteur d'un arbre binaire, utile dans les analyses de performance d'algorithmes sur des structures arborescentes et pour l'optimisation de requêtes dans les bases de données utilisant des index arbres.

**Précautions** :
- L'arbre ne doit pas être modifié pendant l'exécution de `btree_level_count` pour garantir l'exactitude des résultats.
- Assurez-vous que la structure `t_btree` est correctement définie et que les nœuds de l'arbre sont correctement initialisés avant de lancer ces fonctions.