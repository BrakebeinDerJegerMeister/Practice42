# Énoncé

| Exercice : 15                                        |
| ---------------------------------------------------- |
| ft_list_reverse_fun                                  |
| Dossier de rendu : ex15/                             |
| Fichiers à rendre : ft_list_reverse_fun.c, ft_list.h |
| Fonctions Autorisées : Aucune                        |
• écrire la fonction ft_list_reverse_fun qui inverse l’ordre des éléments de la liste.
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_reverse_fun(t_list *begin_list);
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

ft_list_reverse_fun.c :
```C
#include "ft_list.h"
#include <stdlib.h>

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

void	swap_datas(t_list *begin_list, unsigned int a, unsigned int b)
{
	void	*data_c;
	t_list	*list_a;
	t_list	*list_b;

	list_a = ft_list_at(begin_list, a);
	list_b = ft_list_at(begin_list, b);
	data_c = list_a->data;
	list_a->data = list_b->data;
	list_b->data = data_c;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	max;
	int	i;

	max = ft_list_size(begin_list);
	i = 0;
	while (i < (max / 2))
	{
		swap_datas(begin_list, i, max - 1 - i);
		i++;
	}
}
```
# Explications

### Description des Fonctions:

1. **`ft_list_size(t_list *begin_list)`**
   - **Objectif :** Calcule le nombre de nœuds dans une liste chaînée.
   - **Paramètres :** `t_list *begin_list` - pointeur vers le premier nœud de la liste.
   - **Retour :** `int` - le nombre de nœuds dans la liste.
   - **Comportement :** Parcourt la liste chaînée, incrémentant un compteur jusqu'à ce que le pointeur de nœud soit `NULL`.

2. **`ft_list_at(t_list *begin_list, unsigned int nbr)`**
   - **Objectif :** Récupère le nœud à l'indice spécifié dans la liste chaînée.
   - **Paramètres :**
     - `t_list *begin_list` - pointeur vers le premier nœud de la liste.
     - `unsigned int nbr` - l'indice du nœud à récupérer.
   - **Retour :** `t_list*` - pointeur vers le nœud à l'indice spécifié ou `NULL` si l'indice est hors de la liste.
   - **Comportement :** Parcourt la liste jusqu'à atteindre l'indice souhaité ou la fin de la liste.

3. **`swap_datas(t_list *begin_list, unsigned int a, unsigned int b)`**
   - **Objectif :** Échange les données entre deux nœuds spécifiés par leurs indices.
   - **Paramètres :**
     - `t_list *begin_list` - pointeur vers le premier nœud de la liste.
     - `unsigned int a`, `unsigned int b` - indices des nœuds dont les données doivent être échangées.
   - **Comportement :** Utilise `ft_list_at` pour obtenir les nœuds aux indices `a` et `b`, puis échange leurs données.

4. **`ft_list_reverse_fun(t_list *begin_list)`**
   - **Objectif :** Inverse les données dans tous les nœuds de la liste chaînée pour que l'ordre des données soit inversé, tandis que l'ordre des nœuds reste le même.
   - **Paramètres :** `t_list *begin_list` - pointeur vers le premier nœd de la liste.
   - **Comportement :** Utilise `ft_list_size` pour déterminer le nombre total de nœuds, puis échange les données entre les nœuds de manière symétrique à partir des extrémités vers le centre en utilisant `swap_datas`.

### Usage Avancé:

- **Efficacité :** La fonction d'inversion est efficace en termes de complexité spatiale, car elle ne requiert aucun espace supplémentaire au-delà des variables temporaires. Toutefois, sa complexité temporelle est O(n²) à cause des appels répétés à `ft_list_at` qui parcourt la liste à chaque fois.
- **Sécurité :** Toutes les opérations sont effectuées en place. Assurez-vous que les données pointées ne requièrent pas de gestion spécifique de la mémoire lors des échanges pour éviter les fuites de mémoire ou d'autres problèmes.
- **Adaptabilité :** Bien que conçue pour des types de données simples, cette approche peut être étendue à des types de données plus complexes, à condition que l'opération d'échange de données soit viable sans effets secondaires indésirables.


Cette suite de fonctions fournit une méthode robuste pour inverser l'ordre des données dans une liste chaînée sans altérer l'ordre des nœuds eux-mêmes, adaptée pour une utilisation dans des contextes où les modifications structurelles des listes chaînées sont restreintes ou indésirables.