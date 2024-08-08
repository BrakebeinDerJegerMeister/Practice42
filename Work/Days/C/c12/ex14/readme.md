# Énoncé

| Exercice : 14                                 |
| --------------------------------------------- |
| ft_list_sort                                  |
| Dossier de rendu : ex14/                      |
| Fichiers à rendre : ft_list_sort.c, ft_list.h |
| Fonctions Autorisées : Aucune                 |
• écrire la fonction ft_list_sort qui trie par ordre croissant le contenu de la liste,
en comparant deux éléments grâce à une fonction de comparaison de données des deux éléments.
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_sort(t_list **begin_list, int (*cmp)());
```
• La fonctions pointée par cmp sera utilisée de la façon suivante :
```C
(*cmp)(list_ptr->data, other_list_ptr->data);
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

ft_list_sort.c :
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

void	swap_datas(t_list *a, t_list *b)
{
	void	*c;

	c = a->data;
	a->data = b->data;
	b->data = c;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		max;
	int		i;
	int		swapped;
	t_list	*list_ptr;
	t_list	*other_list_ptr;

	max = ft_list_size(*begin_list);
	swapped = 1;
	while (swapped && max > 1)
	{
		i = 0;
		swapped = 0;
		list_ptr = *begin_list;
		while (i++ < (max - 1))
		{
			other_list_ptr = list_ptr->next;
			if ((*cmp)(list_ptr->data, other_list_ptr->data) > 0)
			{
				swap_datas(list_ptr, other_list_ptr);
				swapped = 1;
			}
			list_ptr = list_ptr->next;
		}
		max--;
	}
}
```
# Explications


### Code pour Tri de Liste Chaînée en C

**Description:**
Implémentation du tri à bulles optimisé pour les listes chaînées en C. Ce code permet de trier une liste chaînée selon une fonction de comparaison fournie par l'utilisateur. 

**Fonctions:**
1. **`ft_list_size`**: Calcule la taille d'une liste chaînée.
   - **Paramètres**: `t_list *begin_list` (pointeur vers le début de la liste).
   - **Retour**: `int` (nombre de nœuds dans la liste).

2. **`swap_datas`**: Échange les données entre deux nœuds de la liste.
   - **Paramètres**:
     - `t_list *a`: pointeur vers le premier nœud.
     - `t_list *b`: pointeur vers le second nœud.

3. **`ft_list_sort`**: Tri une liste chaînée en utilisant le tri à bulles.
   - **Paramètres**:
     - `t_list **begin_list`: adresse du pointeur vers le début de la liste.
     - `int (*cmp)(void*, void*)`: pointeur vers une fonction de comparaison qui prend deux pointeurs `void*` et retourne un `int`. La fonction doit retourner un nombre positif si le premier argument est plus grand que le second, zéro s'ils sont égaux, et un nombre négatif sinon.

**Logique de `ft_list_sort`:**
- Calcule la taille de la liste avec `ft_list_size`.
- Utilise un indicateur `swapped` pour suivre si des échanges ont été faits durant un passage pour optimiser le tri et arrêter tôt si la liste est déjà triée.
- Effectue des passages répétés sur la liste, en réduisant progressivement le nombre d'éléments à examiner grâce à la variable `max`.
- À chaque passage, parcourt la liste jusqu'à l'avant-dernier élément non trié, en comparant les nœuds adjacents et en les échangeant si nécessaire selon la fonction `cmp`.

**Optimisation:**
- Le tri à bulles est naturellement inefficace avec une complexité en O(n²), mais l'utilisation de `swapped` réduit les passages inutiles en arrêtant le tri dès qu'aucun échange n'est nécessaire durant un passage complet, ce qui peut grandement améliorer les performances sur des listes partiellement triées.

**Usage:**
Ce code est idéal pour des contextes où la structure de données de liste chaînée est privilégiée et les tailles de liste ne sont pas extrêmement grandes, ou pour des applications où la complexité de la manipulation des pointeurs (comme dans les tris plus complexes) est à éviter.


Ce code est une illustration claire de l'application d'un concept algorithmique classique à une structure de données spécifique, montrant des adaptations nécessaires pour maintenir l'efficacité et la simplicité dans la gestion de structures de données non linéaires.