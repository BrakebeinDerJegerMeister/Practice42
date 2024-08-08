# Énoncé

| Exercice : 02                                       |
| --------------------------------------------------- |
| btree_apply_infix                                   |
| Dossier de rendu : ex02/                            |
| Fichiers à rendre : btree_apply_infix.c, ft_btree.h |
| Fonctions Autorisées : Aucune                       |
• Écrire la fonction btree_apply_infix qui applique la fonction passée en para-
mètre à l’item de chaque node, en parcourant l’arbre de manière infix.
• Elle devra être prototypée de la façon suivante :
```C
void btree_apply_infix(t_btree *root, void (*applyf)(void *));
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

btree_apply_infix.c :
```C
#include "ft_btree.h"
#include <stdlib.h>

void	btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return;
	btree_apply_infix(root->left, applyf);
	(*applyf)(root->item);
	btree_apply_infix(root->right, applyf);
}
```
# Explications

La méthode **infixe** (ou parcours en ordre) est une autre manière de parcourir un arbre binaire. Dans un parcours infixe, les nœuds sont visités dans l'ordre suivant : d'abord le sous-arbre gauche, ensuite le nœud courant, et enfin le sous-arbre droit. Ce mode de parcours est particulièrement important pour les arbres binaires de recherche (ABR), car il permet de visiter les nœuds dans un ordre croissant (ou décroissant, selon l'arbre) de leurs clés ou valeurs.

### Détails du Parcours Infixe

#### Processus de Visite
1. **Visiter le sous-arbre gauche** : Commencez par parcourir récursivement tout le sous-arbre gauche du nœud courant. Cela garantit que les éléments les plus petits sont traités en premier.
2. **Traiter le nœud courant** : Après avoir terminé avec le sous-arbre gauche, la valeur du nœud courant est traitée. Cela peut impliquer d'imprimer la valeur, de l'ajouter à une liste, ou toute autre opération spécifique.
3. **Visiter le sous-arbre droit** : Enfin, le parcours se poursuit avec le sous-arbre droit, permettant de traiter les valeurs plus grandes.

#### Applications
- **Impression ou extraction des éléments triés** : Pour les arbres binaires de recherche, le parcours infixe affiche ou extrait les éléments dans l'ordre croissant ou décroissant de leurs clés. C'est idéal pour afficher des données triées sans nécessiter de tri supplémentaire.
- **Calculs arithmétiques** : Dans les arbres d'expressions arithmétiques, un parcours infixe permet de générer la notation infixée de l'expression, qui est la manière habituelle d'écrire des expressions mathématiques (par exemple, A + B * C).

#### Avantages
- **Simplicité** : Le parcours infixe est conceptuellement simple et peut être implémenté facilement avec une récursion.
- **Utilité** : Pour les arbres binaires de recherche, ce parcours garantit une visite des éléments selon l'ordre naturel de leurs clés, ce qui est pratique pour de nombreuses applications qui dépendent de l'ordre des données.