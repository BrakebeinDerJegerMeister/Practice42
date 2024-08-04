# Énoncé

| Exercice : 01                                       |
| --------------------------------------------------- |
| ft_list_push_front                                  |
| Dossier de rendu : ex01/                            |
| Fichiers à rendre : ft_list_push_front.c, ft_list.h |
| Fonctions Autorisées : ft_create_elem               |
• écrire la fonction ft_list_push_front qui ajoute au début de la liste un nouvel
élément de type t_list.
• Elle devra assigner data au paramètre fourni.
• Elle mettra à jour, si nécéssaire, le pointeur sur le début de liste.
• Elle devra être prototypée de la façon suivante :
```
void ft_list_push_front(t_list **begin_list, void *data);
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

ft_list_push_front.c :
```C
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (elem)
	{
		if (*begin_list)
			elem->next = *begin_list;
		*begin_list = elem;
	}
}
```
# Explications

Objectif : Ajouter un nouvel élément au début d'une liste chaînée.

### Structure de la Fonction

```c
void	ft_list_push_front(t_list **begin_list, void *data)
```

Cette fonction prend deux paramètres :
1. `t_list **begin_list` : un double pointeur vers le premier élément de la liste, ce qui permet de modifier l'adresse du premier élément directement.
2. `void *data` : un pointeur générique vers la donnée à ajouter à la liste.

### Corps de la Fonction

1. **Création d'un Nouvel Élément :**
   ```c
   t_list	*elem;
   elem = ft_create_elem(data);
   ```
   Ici, `ft_create_elem` est appelée pour créer un nouvel élément avec la donnée fournie. Cet élément est stocké dans `elem`.

2. **Vérification de l'Élément Créé :**
   ```c
   if (elem)
   ```
   Cette condition vérifie si `elem` est non-null, ce qui signifie que l'allocation de mémoire a réussi.

3. **Ajout en Tête de Liste :**
   ```c
   if (*begin_list)
       elem->next = *begin_list;
   *begin_list = elem;
   ```
   - `if (*begin_list)` vérifie si la liste n'est pas vide. Si c'est le cas, le pointeur `next` de `elem` est défini pour pointer vers l'actuel premier élément de la liste.
   - `*begin_list = elem;` place ensuite `elem` comme le nouveau premier élément de la liste.

### Analyse

Le code fonctionne correctement pour les opérations suivantes :
- **Ajout d'un Élément à une Liste Vide :** Si `*begin_list` est NULL, `elem->next` reste NULL, et `elem` devient le premier élément.
- **Ajout à une Liste Non-Vide :** L'élément précédent en tête de liste devient le deuxième élément, et `elem` prend sa place en tête.

