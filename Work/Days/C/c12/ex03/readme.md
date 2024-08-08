# Énoncé

| Exercice : 03                                 |
| --------------------------------------------- |
| ft_list_last                                  |
| Dossier de rendu : ex03/                      |
| Fichiers à rendre : ft_list_last.c, ft_list.h |
| Fonctions Autorisées : Aucune                 |
• écrire la fonction ft_list_last qui renvoie le dernier élément de la liste.
• Elle devra être prototypée de la façon suivante :
```C
t_list *ft_list_last(t_list *begin_list);
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

ft_list_last.c :
```C
#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*n_list;

	if (!begin_list)
		return (begin_list);
	n_list = begin_list;
	while (n_list->next)
	{
		n_list = n_list->next;
	}
	return (n_list);
}
```
# Explications

La fonction `ft_list_last` a pour objectif de retrouver le dernier nœud d'une liste chaînée :

### 1. **Vérification de la Liste Initiale** :
   - La fonction commence par vérifier si la liste passée en paramètre (`begin_list`) est vide. Elle utilise `if (!begin_list)` pour tester si `begin_list` est `NULL`.
   - Si la liste est vide (`begin_list` est `NULL`), la fonction retourne immédiatement `NULL`, indiquant qu'il n'y a pas de dernier élément.

### 2. **Initialisation du Pointeur de Parcours** :
   - Si la liste contient au moins un élément, `n_list` est initialisé pour pointer sur le premier élément de la liste (`begin_list`). Ce pointeur sera utilisé pour parcourir la liste.

### 3. **Parcours de la Liste** :
   - La boucle `while` (`while (n_list->next)`) permet de parcourir la liste. La condition `n_list->next` vérifie si l'élément courant a un successeur.
   - Tant que l'élément courant a un successeur (i.e., `n_list->next` n'est pas `NULL`), `n_list` est mis à jour pour pointer sur le prochain élément avec `n_list = n_list->next`.
   - Cette boucle se poursuit jusqu'à ce que `n_list` pointe sur le dernier élément de la liste, c'est-à-dire un élément dont le champ `next` est `NULL`.

### 4. **Retour du Dernier Élément** :
   - À la sortie de la boucle, `n_list` pointe sur le dernier élément de la liste. La fonction retourne alors ce pointeur.
   - Le nœud retourné par la fonction est donc le dernier élément de la liste, permettant à l'appelant de la fonction d'accéder à ses données ou de continuer le traitement spécifique à ce dernier nœud.

Cette fonction est efficace pour les opérations qui nécessitent l'accès au dernier élément de la liste, comme l'ajout d'un élément à la fin ou certaines manipulations spécifiques aux structures de données chaînées.