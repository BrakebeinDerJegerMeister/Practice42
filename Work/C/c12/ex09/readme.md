# Énoncé

| Exercice : 09                                    |
| ------------------------------------------------ |
| ft_list_foreach                                  |
| Dossier de rendu : ex09/                         |
| Fichiers à rendre : ft_list_foreach.c, ft_list.h |
| Fonctions Autorisées : Aucune                    |
• écrire la fonction ft_list_foreach qui applique une fonction donnée en paramètre
à la valeur contenue dans chaque élément de la liste.
• f doit être appliquée dans l’ordre des éléments de la liste
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
```
• La fonction pointée par f sera utilisée de la façon suivante :
```C
(*f)(list_ptr->data);
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

ft_list_foreach.c :
```C
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
```

# Explications

La fonction `ft_list_foreach` est un utilitaire de programmation fonctionnelle conçu pour appliquer une opération spécifiée par l'utilisateur à chaque élément d'une liste chaînée. Voici une exploration détaillée de sa mise en œuvre et de son application, adaptée à un public de programmeurs avancés.

### Signature de la Fonction
```c
void ft_list_foreach(t_list *begin_list, void (*f)(void *));
```
- **Paramètres**:
  - `begin_list` : Un pointeur vers le premier nœud de la liste chaînée. Il sert de point d'entrée pour l'itération sur la liste.
  - `f` : Un pointeur vers une fonction qui prend un pointeur `void *` en argument. Cette conception permet d'appliquer `f` à des données de n'importe quel type, augmentant ainsi la réutilisabilité et la flexibilité de la fonction.

### Déroulement de la Fonction
- **Initialisation** :
  - Un pointeur local `list_ptr` est utilisé pour traverser la liste. Il est initialisé avec la valeur de `begin_list`, ce qui permet de commencer l'itération au début de la liste.

- **Itération sur la Liste** :
  - La structure de contrôle principale est une boucle `while` qui se poursuit tant que `list_ptr` n'est pas `NULL`. Cette condition assure que l'itération couvre tous les éléments de la liste jusqu'à son terme naturel.
  - À chaque itération, la fonction pointée par `f` est invoquée avec `list_ptr->data` comme argument. Cela permet d'effectuer des opérations sur les données contenues dans chaque nœud.
  - Après l'appel de la fonction, `list_ptr` est mis à jour pour pointer vers le nœud suivant de la liste (`list_ptr->next`). Cela prépare la boucle pour l'itération suivante.

### Considérations Techniques
- **Gestion de la Mémoire** : La fonction assume que la mémoire associée aux données du nœud est gérée en dehors de `ft_list_foreach`. Cela signifie que si `f` modifie les données des nœuds d'une manière qui nécessite une allocation ou une libération de mémoire, ces opérations doivent être prises en charge par `f` elle-même.
- **Sécurité d'Exécution** : La fonction est sécuritaire par rapport aux listes vides, car la condition initiale de la boucle empêche toute opération sur un pointeur `NULL`. Cependant, elle ne gère pas les modifications de la liste par `f` pendant l'itération, ce qui pourrait potentiellement altérer le parcours de la liste si `f` insère ou supprime des nœuds.

### Application
`ft_list_foreach` est particulièrement utile dans des contextes où une opération doit être uniformément appliquée à tous les éléments d'une liste sans modifier la structure de la liste elle-même. Exemples d'applications incluent la mise à jour de valeurs, la validation de données, ou l'exécution de routines de nettoyage.

### Conclusion
Cette fonction illustre un principe fondamental de la programmation fonctionnelle en C, à savoir l'application d'effets à travers des structures de données mutables, tout en maintenant une interface simple et flexible. Elle démontre comment une abstraction efficace et une généralisation prudente peuvent faciliter des opérations complexes sur des structures de données dans des systèmes bas niveau.