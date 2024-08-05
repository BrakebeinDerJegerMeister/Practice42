# Énoncé

| Exercice : 07                               |
| ------------------------------------------- |
| ft_list_at                                  |
| Dossier de rendu : ex07/                    |
| Fichiers à rendre : ft_list_at.c, ft_list.h |
| Fonctions Autorisées : Aucune               |
• écrire la fonction ft_list_at qui renvoie le n-ième élément de la liste, sachant
que le premier élément est l’élément 0.
• Elle renverra un pointeur nul en cas d’erreur.
• Elle devra être prototypée de la façon suivante :
```C
t_list *ft_list_at(t_list *begin_list, unsigned int nbr);
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

ft_list_at.c :
```C
#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;
	t_list			*n_list;

	count = 0;
	n_list = begin_list;
	while (n_list)
	{
		if (nbr == count)
			return (n_list);
		n_list = n_list->next;
		count++;
	}
	return (NULL);
}
```
# Explications

La fonction `ft_list_at` est conçue pour retrouver un élément spécifique dans une liste chaînée par son indice, assumant une indexation débutant à zéro. Cette approche est essentielle pour des manipulations précises et efficaces au sein de structures de données linéaires. Voici une explication technique du fonctionnement de cette fonction :

### Paramètres
- **begin_list** : Un pointeur sur le premier nœud de la liste, servant de point d'entrée pour le parcours.
- **nbr** : L'indice du nœud à retrouver, où `nbr = 0` correspond au premier nœud.

### Algorithme
1. **Initialisation** :
   - `count` est initialisé à 0 pour servir de compteur à travers les nœuds.
   - `n_list` pointe initialement sur `begin_list`, facilitant le début du parcours de la liste.

2. **Parcours de la Liste** :
   - La boucle continue tant que `n_list` est non nul, assurant que chaque nœud est vérifié jusqu'à la fin de la liste ou jusqu'à la découverte de l'élément cible.
   
3. **Évaluation Conditionnelle** :
   - À chaque nœud, la fonction évalue si le `count` actuel équivaut à `nbr`. Si c'est le cas, `n_list` est retourné immédiatement, donnant l'accès direct à l'élément recherché.
   - Si l'indice n'est pas celui recherché, la fonction procède au nœud suivant en mettant à jour `n_list` à `n_list->next` et incrémentant `count`.

4. **Gestion des Limites** :
   - Si `n_list` devient `NULL` avant que `nbr` ne soit trouvé, cela signifie que `nbr` excède le nombre d'éléments dans la liste. La fonction retourne alors `NULL`, indiquant une erreur de limite.

### Complexité
- La complexité temporelle est O(n), où n est le nombre de nœuds jusqu'à `nbr`, car chaque élément jusqu'au `nbr`-ième est potentiellement parcouru.
- La complexité spatiale est O(1) car aucune mémoire supplémentaire proportionnelle à la taille de la liste n'est utilisée.

### Usage
Cette fonction est cruciale pour des opérations qui nécessitent un accès direct à des éléments basés sur des indices dans des structures de données non-indexées naturellement, comme les listes chaînées. Elle permet d'effectuer des opérations de modification, d'extraction ou de vérification d'un élément spécifique de manière efficace, sans recourir à des reconstructions ou des parcours intégraux répétés.

Cet accès direct, normalement réservé à des structures comme les tableaux, est ainsi émulé avec une efficacité raisonnable, malgré la nature séquentielle des listes chaînées.