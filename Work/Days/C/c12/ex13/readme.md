# Énoncé

| Exercice : 13                                  |
| ---------------------------------------------- |
| ft_list_merge                                  |
| Dossier de rendu : ex13/                       |
| Fichiers à rendre : ft_list_merge.c, ft_list.h |
| Fonctions Autorisées : Aucune                  |
• écrire la fonction ft_list_merge qui met les éléments d’une liste begin2 à la fin
d’une autre liste begin1.
• La création d’éléments n’est pas autorisée.
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
```
# Correction
ft_list.h :
```C
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

t_list	*ft_create_elem(void *data);

#endif
```

ft_list_merge.c :
```C
#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list_ptr;

	if (*begin_list1)
	{
		list_ptr = *begin_list1;
		while (list_ptr->next)
		{
			list_ptr = list_ptr->next;
		}
		list_ptr->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
```
# Explications

### Fonction `ft_list_merge`

La fonction `ft_list_merge` est conçue pour concaténer deux listes chaînées, en ajoutant la deuxième liste (`begin_list2`) à la fin de la première liste (`begin_list1`). Cette opération est fondamentale pour les manipulations de structures de données dynamiques en programmation C, où la gestion efficace des listes chaînées est cruciale.

#### Paramètres de la Fonction

- **begin_list1** : Un pointeur de pointeur sur le premier élément de la première liste chaînée. L'utilisation d'un pointeur de pointeur permet à la fonction de modifier l'adresse du premier nœud directement si nécessaire, notamment dans le cas où la liste est initialement vide.
- **begin_list2** : Un pointeur sur le premier élément de la deuxième liste chaînée. Cette liste sera ajoutée à la fin de la première.

#### Algorithme de la Fonction

1. **Vérification initiale** :
   - La fonction commence par vérifier si la première liste est vide (`*begin_list1 == NULL`). Si c'est le cas, la fonction pointe simplement `*begin_list1` vers `begin_list2`, faisant de `begin_list2` la nouvelle tête de liste. Cela gère efficacement le cas où la liste initiale n'existe pas, permettant une intégration transparente de la deuxième liste.

2. **Parcours de la Première Liste** :
   - Si la première liste contient déjà des éléments, la fonction initialise un pointeur local (`list_ptr`) pour parcourir la liste. Le pointeur commence au premier élément de `*begin_list1`.
   - Elle utilise ensuite une boucle `while` pour naviguer à travers la liste jusqu'à atteindre le dernier élément, détecté lorsque `list_ptr->next` est `NULL`. Cette étape est cruciale pour localiser correctement le point d'insertion de la deuxième liste.

3. **Concaténation** :
   - Après avoir atteint le dernier nœud de la première liste, le champ `next` de ce nœud est mis à jour pour pointer vers le premier nœud de `begin_list2`. Cela effectue la fusion physique des deux listes, permettant aux éléments de `begin_list2` de suivre directement les éléments de `begin_list1`.

#### Considérations Techniques

- **Gestion de la Mémoire** : La fonction ne modifie que les pointeurs internes et n'effectue pas d'allocations ou de libérations de mémoire. Cela implique que la gestion de la mémoire pour les éléments de la liste reste à la charge de l'utilisateur, évitant ainsi toute modification imprudente qui pourrait entraîner des fuites de mémoire ou des erreurs de segmentation.
- **Performance** : L'opération de fusion a une complexité temporelle de O(n) pour la première liste, car elle nécessite un parcours complet de cette liste pour trouver son dernier élément. La complexité est linéaire par rapport à la taille de la première liste, mais indépendante de la taille de la deuxième liste.

#### Utilisation Pratique

Cette fonction est particulièrement utile dans les scénarios où plusieurs listes de données doivent être combinées en une seule séquence pour un traitement ultérieur, comme dans la gestion des tâches en file d'attente, la collecte de résultats de requêtes, ou l'agglomération de données issues de multiples sources.