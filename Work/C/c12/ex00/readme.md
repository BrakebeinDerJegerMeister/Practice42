# Énoncé

| Exercice : 00                                   |
| ----------------------------------------------- |
| ft_create_elem                                  |
| Dossier de rendu : ex00/                        |
| Fichiers à rendre : ft_create_elem.c, ft_list.h |
| Fonctions Autorisées : malloc                   |
• écrire la fonction ft_create_elem qui crée un nouvel élément de type t_list.
• Elle devra assigner data au paramètre fournis et next à NULL.
• Elle devra être prototypée de la façon suivante :
```C
t_list *ft_create_elem(void *data);
```
# Correction

ft_create_elem.c :
```C
#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->data = data;
		elem->next = NULL;
	}
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

#endif
```
# Explications

La fonction `ft_create_elem` fait partie d'une gestion basique de structures de données de type liste chaînée en C. 

### Définition de la Fonction

```c
t_list	*ft_create_elem(void *data)
```

Cette fonction prend en paramètre un pointeur `void *data`, ce qui signifie qu'elle est capable de stocker n'importe quel type de données. C'est pratique pour créer des listes chaînées génériques pouvant contenir divers types de données.

### Corps de la Fonction

1. **Initialisation de l'élément :**
   ```c
   t_list	*elem;
   elem = NULL;
   ```
   Ici, un pointeur vers une structure `t_list` est déclaré et initialisé à `NULL`. Cela assure que le pointeur est propre avant de lui attribuer une adresse mémoire allouée.

2. **Allocation de mémoire :**
   ```c
   elem = malloc(sizeof(t_list));
   ```
   `malloc` est utilisé pour allouer dynamiquement une quantité de mémoire suffisante pour stocker une structure `t_list`. Cette allocation est cruciale car elle permet à l'élément de la liste de persister même après la fin de l'exécution de la fonction.

3. **Initialisation des champs de la structure :**
   ```c
   elem->data = data;
   elem->next = NULL;
   ```
   - `elem->data = data;` assigne la donnée passée en argument à la fonction au champ `data` de l'élément de liste. Cela permet de stocker la donnée dans l'élément de la liste.
   - `elem->next = NULL;` initialise le pointeur `next` à `NULL`, indiquant que cet élément n'a pas encore de successeur dans la liste. C'est un élément terminal de la liste à ce stade.

### Retour de la Fonction

```c
return (elem);
```
La fonction renvoie le pointeur vers l'élément nouvellement créé. Ce retour permet d'intégrer cet élément dans une liste plus grande ou de l'utiliser comme début d'une nouvelle liste.

### Utilité et But

La fonction `ft_create_elem` est essentielle pour construire des listes chaînées. Chaque élément de la liste peut être connecté via le pointeur `next`, permettant ainsi la construction d'une séquence de données. Les listes chaînées sont des structures de données flexibles utilisées pour une variété d'applications, telles que la représentation de queues, de piles, de graphes et d'autres collections dynamiques. Le choix de `void *` pour le type de données permet une grande flexibilité, rendant la liste utile dans des contextes génériques où le type exact des données n'est pas connu à l'avance.