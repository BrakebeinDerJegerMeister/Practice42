# Énoncé

| Exercice : 16                                          |
| ------------------------------------------------------ |
| ft_sorted_list_insert                                  |
| Dossier de rendu : ex16/                               |
| Fichiers à rendre : ft_sorted_list_insert.c, ft_list.h |
| Fonctions Autorisées : ft_create_elem                  |
• écrire la fonction ft_sorted_list_insert qui crée un nouvel élément et l’insère
dans une liste triée de sorte que la liste reste triée par ordre croissant.
• Elle devra être prototypée de la façon suivante :
```C
void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
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

ft_sorted_list_insert.c :
```C
#include "ft_list.h"
#include <stdlib.h>

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*prev;
	t_list	*current;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
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
	return ;
}
```
# Explications

Cette fonction insère un nouvel élément dans une liste chaînée tout en maintenant l'ordre de tri spécifié par une fonction de comparaison. Elle est conçue pour des listes chaînées où l'ordre est crucial pour des opérations de recherche ou de manipulation ultérieures.

### Description
- **Paramètres :**
  - `t_list **begin_list` : Un pointeur double vers le premier nœud de la liste, permettant de modifier directement le pointeur de tête de la liste.
  - `void *data` : Un pointeur vers les données à insérer dans la liste.
  - `int (*cmp)(void *, void *)` : Un pointeur vers une fonction de comparaison qui détermine l'ordre des éléments dans la liste. La fonction doit retourner un entier positif si le premier argument est considéré comme supérieur au second, zéro s'ils sont égaux, ou un entier négatif si le premier est inférieur.

### Fonctionnement
1. **Création d'un nouvel élément :** La fonction commence par créer un nouvel élément de liste avec les données fournies en utilisant `ft_create_elem(data)`. Si l'allocation de mémoire échoue, la fonction se termine immédiatement.
2. **Insertion en tête de liste :** Si la liste est initialement vide (`*begin_list == NULL`), l'élément nouvellement créé devient la nouvelle tête de la liste.
3. **Recherche de la position d'insertion :** La fonction parcourt la liste jusqu'à trouver le premier élément dont les données sont supérieures à celles de l'élément à insérer, selon la fonction de comparaison `cmp`.
4. **Insertion de l'élément :** Une fois la position trouvée, l'élément est inséré dans la liste de manière à maintenir l'ordre. Si l'élément est à insérer au milieu ou à la fin de la liste, il est placé entre les nœuds `prev` (le dernier nœud avec une valeur inférieure) et `current` (le premier nœud avec une valeur supérieure ou égale).
5. **Gestion des pointeurs :** Les pointeurs sont ajustés pour intégrer correctement le nouvel élément dans la liste. Si l'élément est inséré en tête de liste (c'est-à-dire si `prev` est `NULL`), le pointeur de tête de la liste est mis à jour.

### Utilisation
Cette fonction est utilisée pour insérer des éléments dans des listes qui doivent rester triées pour des opérations efficaces comme la recherche binaire. Elle est particulièrement utile dans les systèmes où les données doivent être maintenues en ordre continu, tels que les bases de données en mémoire, les listes de gestion de priorités, etc.

### Avantages
- **Efficacité :** L'insertion se fait en temps linéaire, ce qui est optimal pour une liste chaînée non triée.
- **Simplicité :** L'interface de la fonction est simple et les manipulations de pointeurs sont directes, réduisant les risques d'erreurs.

### Limitations
- **Complexité Temporelle :** Bien que l'insertion elle-même soit efficace, la recherche du point d'insertion est en O(n), ce qui peut être coûteux pour de grandes listes.
- **Allocation Dynamique :** La fonction dépend de la réussite de l'allocation dynamique pour la création du nouvel élément.
