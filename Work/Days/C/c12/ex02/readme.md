# Énoncé

| Exercice : 02                                 |
| --------------------------------------------- |
| ft_list_size                                  |
| Dossier de rendu : ex02/                      |
| Fichiers à rendre : ft_list_size.c, ft_list.h |
| Fonctions Autorisées : Aucune                 |
• écrire la fonction ft_list_size qui renvoie le nombre d’éléments dans la liste.
• Elle devra être prototypée de la façon suivante :
```C
int ft_list_size(t_list *begin_list);
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

ft_list_size.c :
```C
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		count;
	t_list	*n_list;

	count = 0;
	n_list = begin_list;
	while (n_list)
	{
		n_list = n_list->next;
		count++;
	}
	return (count);
}
```
# Explications


La fonction `ft_list_size` calcule le nombre d'éléments dans une liste chaînée :

1. **Initialisation des Variables** :
   - `count` est initialisée à 0. Cette variable sert de compteur pour le nombre d'éléments dans la liste.
   - `n_list` est un pointeur sur `t_list` qui est initialisé pour pointer sur le premier élément de la liste (`begin_list`). Ce pointeur est utilisé pour parcourir la liste.

2. **Parcours de la Liste** :
   - La boucle `while` continue tant que `n_list` n'est pas `NULL`. `NULL` signifie que le pointeur a atteint la fin de la liste.
   - À chaque itération, le pointeur `n_list` est déplacé vers le prochain élément de la liste avec `n_list = n_list->next`.
   - À chaque passage dans la boucle, `count` est incrémenté de 1. Cela compte chaque nœud traversé par le pointeur.

3. **Fin de la Boucle** :
   - Lorsque `n_list` atteint `NULL`, la boucle se termine, car il n'y a plus d'éléments à compter.

4. **Renvoi du Résultat** :
   - La fonction renvoie la valeur de `count`, qui est le nombre total d'éléments dans la liste.

Ce mécanisme permet de comptabiliser efficacement le nombre de nœuds dans une liste chaînée, ce qui est une opération commune dans la gestion des structures de données linéaires.