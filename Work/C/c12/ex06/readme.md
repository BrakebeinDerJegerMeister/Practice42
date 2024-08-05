# Énoncé

| Exercice : 06                                  |
| ---------------------------------------------- |
| ft_list_clear                                  |
| Dossier de rendu : ex06/                       |
| Fichiers à rendre : ft_list_clear.c, ft_list.h |
| Fonctions Autorisées : free                    |
• écrire la fonction ft_list_clear qui retire et libère l’ensemble des éléments de la
liste.
• Chaque data devra aussi être libèré à l’aide de free_fct
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
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

ft_list_clear.c :
```C
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*next_list;
	t_list	*my_list;

	if (!begin_list)
		return ;
	my_list = begin_list;
	while (my_list)
	{
		next_list = my_list->next;
		if (my_list->data)
			free_fct(data);
		free(my_list);
		my_list = next_list;
	}
}
```
# Explications

La fonction `ft_list_clear` est conçue pour libérer la mémoire de tous les éléments d'une liste chaînée tout en assurant que toute donnée associée à chaque élément soit correctement libérée en utilisant une fonction spécifique fournie par l'utilisateur. Voici une explication détaillée du fonctionnement de cette fonction :

### Objectif de la Fonction

L'objectif de `ft_list_clear` est de parcourir une liste chaînée et de libérer la mémoire occupée par chaque nœud, en s'assurant également que les données potentiellement dynamiques stockées dans chaque nœud soient également libérées de manière appropriée.

### Structure et Fonctionnement

- **Vérification Initiale** :
  - La fonction commence par vérifier si le pointeur `begin_list` est `NULL`. Si c'est le cas, la fonction retourne immédiatement, car il n'y a rien à libérer. Cela évite les déréférencements de pointeur nul.

- **Initialisation des Pointeurs** :
  - `my_list` est initialisé pour pointer sur le premier élément de la liste (`begin_list`). Cela marque le début du parcours de la liste.
  - `next_list` est utilisé pour stocker temporairement le pointeur vers le nœud suivant dans la liste. Cela est crucial pour éviter de perdre l'accès aux éléments suivants une fois que le nœud courant est libéré.

- **Parcours et Libération** :
  - La boucle `while` itère sur chaque nœud de la liste tant que `my_list` n'est pas `NULL`.
  - À chaque itération de la boucle :
    - `next_list` est mis à jour pour pointer vers le nœud suivant (`my_list->next`). Cela préserve la référence au reste de la liste après que le nœud courant soit libéré.
    - Si `my_list->data` n'est pas `NULL`, la fonction pointée par `free_fct` est appelée pour libérer la mémoire des données du nœud. Cela permet de gérer différents types de données de manière flexible.
    - `free(my_list)` est appelée pour libérer la mémoire du nœud lui-même.
    - `my_list` est ensuite mis à jour pour pointer vers `next_list`, préparant ainsi la prochaine itération. Cela déplace le pointeur de parcours vers le nœud suivant dans la liste.



`ft_list_clear` est une fonction robuste pour nettoyer une liste chaînée, libérant chaque nœud et ses données associées de manière sécurisée et systématique. Cette méthode assure qu'il n'y a pas de fuite de mémoire et que les ressources sont correctement gérées, ce qui est crucial dans la gestion de la mémoire dynamique en C.