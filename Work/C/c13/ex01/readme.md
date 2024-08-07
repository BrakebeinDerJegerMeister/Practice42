# Énoncé

| Exercice : 01                                        |
| ---------------------------------------------------- |
| btree_apply_prefix                                   |
| Dossier de rendu : ex01/                             |
| Fichiers à rendre : btree_apply_prefix.c, ft_btree.h |
| Fonctions Autorisées : Aucune                        |
• Écrire la fonction btree_apply_prefix qui applique la fonction passée en paramètre à l’item de chaque node, en parcourant l’arbre de manière prefix.
• Elle devra être prototypée de la façon suivante :
```C
void btree_apply_prefix(t_btree *root, void (*applyf)(void *));
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

btree_apply_prefix.c :
```C
#include "ft_btree.h"
#include <stdlib.h>

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return;
	(*applyf)(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
```
# Explications

### Fonction `btree_apply_prefix`

#### Objectif
Appliquer une fonction donnée à chaque nœud d'un arbre binaire selon un ordre de parcours préordre (préfixe), où chaque nœud est traité avant ses descendants.

#### Concept de Parcours Préordre (Préfixe)
Le parcours préordre est une méthode de traversée d'un arbre où le nœud courant est visité en premier, suivi par le parcours récursif du sous-arbre gauche, puis du sous-arbre droit. Ce modèle de visite "racine, gauche, droit" est essentiel pour des applications nécessitant une action préliminaire sur la racine avant de traiter les branches, comme dans la configuration initiale ou l'évaluation des expressions.

#### Méthodologie
La fonction initie la récursion au nœud racine et applique la fonction passée en argument (`applyf`) au contenu du nœud. Après le traitement du nœud courant, la fonction se réplique sur les sous-arbres gauche et droit, suivant la logique préordre :
1. Traitement du nœud courant via `applyf`.
2. Appel récursif pour parcourir le sous-arbre gauche.
3. Appel récursif pour parcourir le sous-arbre droit.

#### Gestion des erreurs
Une condition de base vérifie si le pointeur de nœud est `NULL` avant de procéder à toute opération, ce qui protège contre les appels de fonction sur des pointeurs non valides et termine la récursion lorsque les feuilles de l'arbre sont atteintes.

#### Performance et sécurité
Le traitement en préordre assure que chaque nœud est visité une seule fois, aboutissant à une complexité de O(n). Toutefois, l'usage intensif de la récursion peut entraîner un risque de dépassement de pile si l'arbre est extrêmement déséquilibré (profond).

#### Applications typiques
Typiquement utilisé pour configurer ou modifier l'état d'un arbre avant d'autres opérations, le parcours préordre est également utile pour exporter la structure de l'arbre, comme dans la sérialisation ou l'impression de debug.

#### Extensibilité
Cette méthode de parcours peut être adaptée pour inclure des vérifications ou des traitements conditionnels au niveau de chaque nœud, permettant une grande flexibilité dans la manipulation des données de l'arbre.

Cette fiche fournit un aperçu détaillé de l'implémentation et de l'utilisation du parcours préordre dans la manipulation des arbres binaires, soulignant son importance et sa versatilité dans divers scénarios de programmation.