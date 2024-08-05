# Énoncé

| Exercice : 08                         |
| ------------------------------------- |
| ft_list_reverse                       |
| Dossier de rendu : ex08/              |
| Fichiers à rendre : ft_list_reverse.c |
| Fonctions Autorisées : Aucune         |
• écrire la fonction ft_list_reverse qui inverse l’ordre des éléments de la liste.
Seuls les jeux de pointeurs sont admis.
• Attention dans cet exercice nous utiliserons notre propre ft_list.h
• Elle devra être prototypée de la façon suivante :
```C
void ft_list_reverse(t_list **begin_list);
```
# Correction

```C
#include <stdlib.h>

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	current = *begin_list;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}
```
# Explications

La fonction `ft_list_reverse` est conçue pour inverser une liste chaînée. Elle modifie les pointeurs de nœuds existants pour que l'ordre des éléments soit renversé, et ce, sans allouer de mémoire supplémentaire. Voici une explication détaillée de son fonctionnement adaptée à un programmeur ayant une compréhension avancée des structures de données et des pointeurs.

### Paramètres
- **begin_list** : Un double pointeur vers la tête de la liste chaînée. Le double pointeur est utilisé pour que toute modification de la tête de la liste dans la fonction soit reflétée dans la liste originale.

### Fonctionnement

1. **Initialisation des Pointeurs** :
   - **prev** : Un pointeur initialisé à `NULL`. Il servira à relier le nœud courant au précédent dans le nouveau contexte de la liste inversée.
   - **current** : Un pointeur qui commence à la tête de la liste (`*begin_list`). Il est utilisé pour parcourir la liste d'origine.
   - **next** : Un pointeur qui aide à maintenir le parcours de la liste sans perdre de nœuds lors de l'inversion des liens.

2. **Parcours et Inversion** :
   - La boucle `while` continue jusqu'à ce que `current` soit `NULL`, indiquant que tous les nœuds ont été traités.
   - À chaque itération :
     - **next** est défini sur `current->next`, ce qui préserve la référence au prochain nœud avant de modifier le lien de `current`.
     - **current->next** est ensuite mis à jour pour pointer vers **prev**, inversant effectivement le lien du nœud courant. Initialement, comme `prev` est `NULL`, le premier élément de la liste pointera sur `NULL` après l'inversion, devenant ainsi le dernier élément de la liste inversée.
     - **prev** est mis à jour pour pointer sur `current`, déplaçant le pointeur de l'élément inversé en avant.
     - **current** est mis à jour pour passer au prochain nœud original, `next`.

3. **Finalisation** :
   - Après la sortie de la boucle, **prev** pointe sur le dernier nœud traité, qui est maintenant le premier nœud de la liste inversée. Le pointeur de tête original (`*begin_list`) est mis à jour pour pointer vers **prev**.

### Complexité
- **Complexité Temporelle** : O(n), où n est le nombre de nœuds dans la liste, car chaque nœud est visité une seule fois.
- **Complexité Spatiale** : O(1), car l'inversion est réalisée en place sans allocation mémoire supplémentaire.

### Implications Pratiques
Cette fonction est utile pour manipuler des listes chaînées lorsque l'ordre des éléments doit être inversé, que ce soit pour des raisons de logique métier ou d'optimisation d'algorithme. Le fait d'effectuer cette opération en place est particulièrement avantageux en termes d'efficacité de la mémoire, ce qui est crucial dans des environnements avec des ressources limitées ou pour des applications nécessitant une haute performance.