# Énoncé

| Exercice : 01                 |
| ----------------------------- |
| ft_map                        |
| Dossier de rendu : ex01/      |
| Fichiers à rendre : ft_map.c  |
| Fonctions Autorisées : malloc |
• Écrire une fonction ft_map qui, pour un tableau d’entiers donné, appliquera une
fonction sur tous les éléments de ce tableau (dans l’ordre) et retournera un tableau
de toutes les valeurs de retour.
• Cette fonction sera appliquée dans l’ordre du tableau.
• La fonction sera prototypée de la manière suivante :
```C
int *ft_map(int *tab, int length, int(*f)(int));
```
# Correction

```C
#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*ret;

	ret = malloc(length * sizeof(int));
	i = 0;
	while (i < length)
	{
		ret[i] = f(tab[i]);
		i++;
	}
	return (ret);
}
```
# Démonstration

```C
#include <stdio.h>

int	square(int nb)
{
	return (nb * nb);
}

void	disp(int *t, int l)
{
	int	i;

	i = 0;
	printf("{");
	while (i < l)
	{
		printf("%d", t[i]);
		i++;
		if (i < l)
			printf(", ");
	}
	printf("}\n");
}

int	main(void)
{
	int	t[5] = {10, -5, 3, 9, 100};
	int	*r;

	r = malloc(5);
	disp(t, 5);
	r = ft_map(t, 5, &square);
	disp(r, 5);
	free(r);
	return (0);
}
```

```
Appuyez sur ENTRÉE ou tapez une commande pour continuer
ft_map.c: Error!
Error: INCLUDE_START_FILE   (line:  35, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  55, col:  14):	Declaration and assignation on a single line

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer
{10, -5, 3, 9, 100}
{100, 25, 9, 81, 10000}

Appuyez sur ENTRÉE ou tapez une commande pour continuer
```
# Explications

La fonction `ft_map` présentée ici en C est un exemple classique d'implémentation de la fonctionnalité de "map", similaire à celle que l'on retrouve dans de nombreux langages de programmation de haut niveau. Elle permet de transformer chaque élément d'un tableau selon une fonction spécifiée et de retourner un nouveau tableau contenant les résultats. Voici une explication détaillée :

### Prototype de la fonction

```c
int *ft_map(int *tab, int length, int (*f)(int));
```

- **`int *tab`** : Un pointeur vers le tableau d'entiers sur lequel les transformations seront appliquées.
- **`int length`** : La taille du tableau.
- **`int (*f)(int)`** : Un pointeur vers la fonction qui sera appliquée à chaque élément du tableau. Cette fonction doit prendre un entier comme argument et retourner un entier.

### Détails de l'implémentation

1. **Allocation de mémoire**:
   La fonction commence par allouer de la mémoire pour un nouveau tableau d'entiers, `ret`, qui contiendra les résultats transformés. Elle utilise `malloc` pour allouer un espace mémoire suffisant pour `length` entiers. Si l'allocation échoue, `malloc` retournera `NULL`.

2. **Transformation des éléments**:
   Une boucle `while` parcourt chaque élément du tableau `tab`. Pour chaque élément, la fonction pointée par `f` est appelée avec cet élément comme argument, et le résultat est stocké dans le tableau `ret` à la position correspondante.

3. **Retour du nouveau tableau**:
   Après avoir transformé tous les éléments, la fonction retourne le pointeur `ret`. Ce tableau doit être libéré avec `free` par l'utilisateur pour éviter une fuite de mémoire.

### Bonnes pratiques

- **Gestion de la mémoire** : Il est crucial de s'assurer que la mémoire allouée par `ft_map` soit libérée par l'utilisateur après utilisation pour éviter les fuites de mémoire (ce qui n'a pas été fait ici).
- **Vérification de l'allocation** : Avant de procéder à la transformation, il est recommandé de vérifier si `malloc` a réussi à allouer la mémoire nécessaire. Si `malloc` retourne `NULL`, la fonction devrait gérer cette erreur en conséquence, par exemple en retournant `NULL`.
- **Optimisation** : Pour des tableaux de grande taille ou des opérations complexes, il peut être utile d'explorer des méthodes d'optimisation, comme le parallélisme ou l'utilisation de techniques spécifiques à l'architecture matérielle pour accélérer les calculs.