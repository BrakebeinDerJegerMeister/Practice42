# Énoncé

| Exercice : 11                                 |
| --------------------------------------------- |
| ft_list_find                                  |
| Dossier de rendu : ex11/                      |
| Fichiers à rendre : ft_list_find.c, ft_list.h |
| Fonctions Autorisées : Aucune                 |
• écrire la fonction ft_list_find qui renvoie l’adresse du premier élément dont la
donnée comparée à data_ref à l’aide de cmp, fait que cmp renvoie 0.
• Elle devra être prototypée de la façon suivante :
```C
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
```
• La fonctions pointée par cmp sera utilisée de la façon suivante :
```C
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

ft_list_find.c :
```C
#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		if ((*cmp)(list_ptr->data, data_ref) == 0)
			return (list_ptr);
		list_ptr = list_ptr->next;
	}
	return (NULL);
}

```
# Explications


**Description** :
`ft_list_find` parcourt une liste chaînée pour trouver le premier élément qui correspond à une référence spécifiée, en utilisant une fonction de comparaison fournie par l'utilisateur. Elle retourne un pointeur vers le nœud correspondant ou `NULL` si aucun élément correspondant n'est trouvé.

**Signature de la Fonction** :
```c
t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
```

**Paramètres** :
- `begin_list` : Un pointeur sur le premier nœud de la liste chaînée.
- `data_ref` : Un pointeur vers les données de référence utilisées pour la comparaison.
- `cmp` : Un pointeur vers une fonction de comparaison qui prend deux arguments (`void*`) et retourne un entier. La fonction doit retourner `0` si les deux arguments sont considérés comme équivalents.

**Algorithme** :
1. **Initialisation** : Un pointeur `list_ptr` est utilisé pour parcourir la liste, initialisé au premier élément de la liste (`begin_list`).

2. **Itération** : La liste est parcourue en utilisant une boucle `while` qui continue tant que `list_ptr` n'est pas `NULL`.

3. **Comparaison** : À chaque itération, la fonction `cmp` est appelée avec les données du nœud courant (`list_ptr->data`) et `data_ref`. Si `cmp` retourne `0`, cela signifie que les données du nœud correspondent à `data_ref`, et le nœud courant est retourné immédiatement.

4. **Avancement** : Si le nœud courant ne correspond pas, le parcours continue au nœud suivant (`list_ptr = list_ptr->next`).

5. **Conclusion** : Si la fin de la liste est atteinte sans trouver de correspondance, la fonction retourne `NULL`.

**Complexité** :
- **Temporelle** : O(n), où n est le nombre de nœuds dans la liste, car en pire cas, tous les nœuds doivent être vérifiés.
- **Spatiale** : O(1), car aucun espace supplémentaire n'est alloué.

**Usage** :
Cette fonction est utile pour rechercher des éléments dans des listes chaînées sans ordre spécifique, où des comparaisons complexes entre données sont nécessaires. Elle est fréquemment utilisée dans des contextes où les données peuvent être diverses et où une égalité personnalisée doit être définie par l'utilisateur.

La précision de la fonction et sa capacité à intégrer des critères de comparaison personnalisés la rendent essentielle pour des applications nécessitant des filtrages ou des recherches spécifiques au sein de collections de données non indexées.