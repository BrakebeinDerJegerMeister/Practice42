# Énoncé

| Exercice : 12                                      |
| -------------------------------------------------- |
| ft_list_remove_if                                  |
| Dossier de rendu : ex12/                           |
| Fichiers à rendre : ft_list_remove_if.c, ft_list.h |
| Fonctions Autorisées : free                        |
• écrire la fonction ft_list_remove_if qui efface de la liste tous les éléments dont la donnée comparée à data_ref à l’aide de cmp, fait que cmp renvoie 0.
• La data d’un élément à effacer devra aussi être libèrée à l’aide de free_fct
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
```
• Les fonctions pointées par free_fct et par cmp seront utilisées de la façon suivante :
```C
(*cmp)(list_ptr->data, data_ref);
(*free_fct)(list_ptr->data);
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

ft_list_remove_if.c :
```C
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list_ptr;
	t_list	*prev;

	prev = NULL;
	list_ptr = *begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
		{
			if (prev)
				prev->next = list_ptr->next;
			else
				*begin_list = list_ptr->next;
			(*free_fct)(list_ptr->data);
			free(list_ptr);
			return ;
		}
		prev = list_ptr;
		list_ptr = list_ptr->next;
	}
}
```
# Explications


Cette fonction est destinée à parcourir une liste chaînée et à supprimer le premier élément qui correspond à un critère spécifié par une fonction de comparaison fournie par l'utilisateur. Elle modifie la liste en place et gère la libération de la mémoire associée à l'élément supprimé.

#### Paramètres
- **begin_list** : Un double pointeur sur le premier élément de la liste, permettant à la fonction de modifier l'adresse du premier nœud directement si nécessaire.
- **data_ref** : Un pointeur vers la donnée de référence utilisée pour la comparaison.
- **cmp** : Un pointeur vers une fonction de comparaison qui prend deux pointeurs `void*` (l'un pointant vers les données d'un élément de la liste, l'autre vers `data_ref`) et retourne un entier. La convention typique est que cette fonction retourne 0 si les données comparées sont équivalentes.
- **free_fct** : Un pointeur vers une fonction de libération, utilisée pour libérer correctement la mémoire allouée aux données de l'élément supprimé.

#### Logique de Fonctionnement
1. **Initialisation des Pointeurs** :
   - **list_ptr** : Initialement pointe sur le premier élément de la liste (`*begin_list`), utilisé pour parcourir la liste.
   - **prev** : Un pointeur vers l'élément précédent dans la liste, initialement `NULL`, qui aide à relier la liste après la suppression d'un élément.

2. **Parcours de la Liste** :
   - La boucle `while` itère sur chaque élément de la liste tant que `list_ptr` n'est pas `NULL`.
   - À chaque itération, la fonction `cmp` est appelée avec les données courantes de la liste (`list_ptr->data`) et `data_ref`.

3. **Condition de Suppression** :
   - Si `cmp` retourne 0 (indiquant une correspondance), la fonction procède à la suppression :
     - Si `prev` n'est pas `NULL`, cela signifie que l'élément à supprimer n'est pas le premier élément, et donc `prev->next` est ajusté pour pointer vers `list_ptr->next`.
     - Si `prev` est `NULL`, cela signifie que l'élément à supprimer est le premier de la liste, et donc `*begin_list` est mis à jour pour pointer vers `list_ptr->next`.
   - L'élément est ensuite libéré en appelant `free_fct` sur `list_ptr->data` pour nettoyer les données, puis `free(list_ptr)` pour libérer la structure de l'élément lui-même.
   - La fonction termine son exécution en retournant après la suppression, donc elle ne supprime qu'un seul élément correspondant.

4. **Mise à Jour des Pointeurs** :
   - Si aucun élément n'est supprimé dans l'itération courante, `prev` est mis à jour pour pointer sur `list_ptr`, et `list_ptr` est mis à jour pour passer au prochain élément.


Cette fonction est efficace pour des cas où il est nécessaire de supprimer rapidement le premier élément correspondant d'une liste chaînée, tout en gérant proprement la libération des ressources. Elle est particulièrement utile dans les situations où la suppression d'un seul élément spécifique est requise sans affecter le reste de la liste.