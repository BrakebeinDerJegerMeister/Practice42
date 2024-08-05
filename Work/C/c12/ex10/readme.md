# Énoncé

| Exercice : 10                                       |
| --------------------------------------------------- |
| ft_list_foreach_if                                  |
| Dossier de rendu : ex10/                            |
| Fichiers à rendre : ft_list_foreach_if.c, ft_list.h |
| Fonctions Autorisées : Aucune                       |
• écrire la fonction ft_list_foreach_if qui applique une fonction donnée en pa-
ramètre à la valeur contenue dans certains éléments de la liste.
• f ne sera appliqué que sur les éléments qui passé en argument à cmp avec data_ref,
cmp renvoie 0
• f doit être appliquée dans l’ordre des éléments de la liste
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
```
• Les fonctions pointées par f et par cmp seront utilisées de la façon suivante :
```C
(*f)(list_ptr->data);
(*cmp)(list_ptr->data, data_ref);
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

ft_list_foreach_if.c :
```C
#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
```
# Explications

Voir exercice précédent...