# Énoncé

| Exercice : 17                                         |
| ----------------------------------------------------- |
| ft_sorted_list_merge                                  |
| Dossier de rendu : ex17/                              |
| Fichiers à rendre : ft_sorted_list_merge.c, ft_list.h |
| Fonctions Autorisées : Aucune                         |
• écrire la fonction ft_sorted_list_merge qui intègre les éléments d’une liste triée
begin2 dans une autre liste triée begin1, de sorte que la liste begin1 reste triée
par ordre croissant.
• Elle devra être prototypée de la façon suivante :
```C
void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
```
• La fonctions pointée par cmp sera utilisée de la façon suivante :
```C
(*cmp)(list_ptr->data, other_list_ptr->data);
```
# Correction
ft_create_elem.c :
```C
#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = NULL;
	elem = malloc(sizeof(t_list));
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
```

ft_sorted_list_merge.c :
```C
#include "ft_list.h"
#include <stdlib.h>

void	insert_elem(t_list **begin_list, t_list *elem, int (*cmp)())
{
	t_list	*prev;
	t_list	*current;

	current = *begin_list;
	prev = NULL;
	if (!current)
		*begin_list = elem;
	while (current)
	{
		if ((*cmp)(data, current->data) > 0)
			break ;
		prev = current;
		current = current->next;
	}
	elem->next = current;
	if (prev)
		prev->next = elem;
	else
		*begin_list = elem;
}

void	ft_sorted_list_merge(t_list **begin_list1,
			t_list *begin_list2, int (*cmp)())
{
	t_list	*next;

	if (!begin_list2 || !*begin_list2)
		return ;
	while (begin_list2)
	{
		next = begin_list2->next;
		insert_elem(begin_list1, begin_list2, cmp);
		begin_list2 = next;
	}
}
```
# Explications


Rien de nouveau, se reporter à l'exercice précédent.