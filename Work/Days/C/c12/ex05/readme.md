# Énoncé

| Exercice : 05                                      |
| -------------------------------------------------- |
| ft_list_push_strs                                  |
| Dossier de rendu : ex05/                           |
| Fichiers à rendre : ft_list_push_strs.c, ft_list.h |
| Fonctions Autorisées : ft_create_elem              |
• écrire la fonction ft_list_push_strs qui crée une nouvelle liste en y mettant les
chaines de caracteres pointées par les éléments tableau strs.
• size est la taille de strs
• Le premier élément du tableau se retrouvera à la fin de la liste.
• L’adresse du premier élément de la liste est renvoyée.
• Elle devra être prototypée de la façon suivante :
```C
t_list *ft_list_push_strs(int size, char **strs);
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

ft_list_push_strs.c :
```C
#include "ft_list.h"
#include <unistd.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*my_list;
	t_list	*tmp_list;

	my_list = NULL;
	i = 0;
	while (i < size)
	{
		tmp_list = ft_create_elem(strs[i]);
		tmp_list->next = my_list;
		my_list = tmp_list;
		i++;
	}
	return (my_list);
}
```
# Explications

La fonction `ft_list_push_strs` crée une liste chaînée en insérant les éléments en partant du début du tableau `strs` jusqu'à la fin, ce qui signifie que le premier élément du tableau `strs` deviendra le dernier élément de la liste chaînée.

### Analyse de la Fonction `ft_list_push_strs`

- **Initialisation** :
  - `my_list` est initialisée à `NULL` pour commencer une nouvelle liste.
  - `i` est initialisé à 0 pour commencer à parcourir le tableau `strs` depuis le premier élément.

- **Boucle de Création de Liste** :
  - La boucle `while` itère tant que `i` est inférieur à `size`, permettant de traiter chaque élément du tableau `strs`.
  - À chaque itération :
    - Un nouvel élément de liste est créé avec `ft_create_elem(strs[i])`, où `strs[i]` est la chaîne de caractères courante du tableau.
    - Le champ `next` du nouvel élément (`tmp_list`) est initialisé au pointeur actuel de la tête de la liste (`my_list`), ce qui le lie à la liste existante.
    - `my_list` est mis à jour pour pointer sur ce nouvel élément (`tmp_list`), faisant de lui la nouvelle tête de la liste.
    - `i` est incrémenté pour passer à l'élément suivant dans le tableau `strs`.

- **Fin de la Fonction** :
  - La fonction retourne `my_list`, qui pointe maintenant sur la tête de la liste nouvellement formée. Puisque les éléments sont ajoutés à la tête, les derniers éléments ajoutés sont en début de liste, ce qui place le premier élément du tableau `strs` à la fin de la liste chaînée.
