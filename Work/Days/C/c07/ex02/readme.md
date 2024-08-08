# Énoncé

| Exercice : 02                           |
| --------------------------------------- |
| ft_ultimate_range                       |
| Dossier de rendu : ex02/                |
| Fichiers à rendre : ft_ultimate_range.c |
| Fonctions Autorisées : malloc           |
• Écrire une fonction ft_ultimate_range qui alloue et assigne un tableau d’int.
Ce tableau d’int contiendra toutes les valeurs entre min et max.
• Min inclu - max exclu.
• Elle devra être prototypée de la façon suivante :
```C
int ft_ultimate_range(int **range, int min, int max);
```
• La taille de range sera retournée (ou -1 en cas de problème).
• Si la valeur min est supérieure ou égale à la valeur max, range pointera sur NULL
et on renverra 0.
# Correction

```C
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*res;
	int	i;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	res = (int *)malloc(sizeof(int) * (max - min));
	if (res == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	*range = res;
	return (max - min);
}
```

# Démonstration

```C
#include <stdio.h>

void	test(int min, int max)
{
	int	*res;
	int	i;
	int	nb;

	printf("\nmin : {%d}", min);
	printf("\nmax : {%d}", max);
	nb = ft_ultimate_range(&res, min, max);
	printf("\nres : {");
	if (!res)
		printf("NULL");
	else
	{
		i = 0;
		printf("(size : %d) ", nb);
		while (i < nb)
		{
			printf("%d", res[i]);
			if (i < nb - 1)
				printf(", ");
			i++;
		}
	}
	printf("}\n");
}

int	main(void)
{
	test(50, 55);
	test(9, 4);
	test(-2, 8);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c07/ex02  (main) $ norminette -RCheckForbiddenSourceHeader ft_ultimate_range.c 
ft_ultimate_range.c: Error!
Error: INCLUDE_START_FILE   (line:  36, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c07/ex02  (main) $ gcc -Wall -Wextra -Werror ft_ultimate_range.c 
Repo Git : Practice42/Work/C/c07/ex02  (main) $ ./a.out 

min : {50}
max : {55}
res : {(size : 5) 50, 51, 52, 53, 54}

min : {9}
max : {4}
res : {NULL}

min : {-2}
max : {8}
res : {(size : 10) -2, -1, 0, 1, 2, 3, 4, 5, 6, 7}
Repo Git : Practice42/Work/C/c07/ex02  (main) $ 
```
# Explications

La fonction `ft_ultimate_range` est conçue pour créer un tableau dynamique de nombres entiers allant de `min` à `max` (exclus). Celle-ci utilise les pointeurs et `malloc` pour allouer de la mémoire nécessaire au stockage du tableau. 
### Définition et Paramètres

La fonction `ft_ultimate_range` prend trois paramètres :
- `int **range` : un pointeur vers un pointeur d'entier. Ce niveau de pointage supplémentaire permet de modifier l'adresse à laquelle le pointeur initial pointe, ce qui est essentiel pour retourner un tableau dynamiquement alloué depuis une fonction.
- `int min` et `int max` : les bornes entre lesquelles les valeurs du tableau seront générées.

### Logique de la Fonction

1. **Vérification des bornes** :
   - Si `max` est inférieur ou égal à `min`, il n'y a pas de plage de nombres à générer. La fonction met alors `*range` à `NULL` (signifiant qu'il n'y a pas de tableau) et retourne `0` comme taille du tableau, car il n'y a aucun élément entre `min` et `max`.

2. **Allocation de mémoire** :
   - `res` est un pointeur d'entier (`int*`) vers lequel `malloc` tente d'allouer suffisamment de mémoire pour contenir tous les entiers entre `min` et `max` (non inclus). La quantité de mémoire nécessaire est calculée comme `sizeof(int) * (max - min)`, où `sizeof(int)` est la taille en octets d'un entier.
   - Si `malloc` échoue (c'est-à-dire, retourne `NULL`), la fonction assigne à `*range` la valeur `NULL` et retourne `-1` pour indiquer une erreur lors de l'allocation de mémoire.

3. **Remplissage du tableau** :
   - La boucle `while` remplit le tableau `res`. Pour chaque indice `i` de `0` à `max - min`, l'élément à l'indice `i` est défini à `min + i`. Cela génère une séquence de nombres de `min` à `max - 1`.

4. **Finalisation** :
   - Après remplir le tableau, `*range` est mis à pointer sur `res`, ce qui signifie que le pointeur passé à la fonction pointera désormais sur le tableau alloué.
   - La fonction retourne la taille du tableau, qui est `max - min`.

### Concepts Clés

- **Pointeurs** : `int **range` est un pointeur vers un pointeur. Cela est crucial car cela permet à la fonction de modifier l'adresse du pointeur original. En mettant `*range = res;`, la fonction modifie le pointeur original pour qu'il pointe vers le tableau nouvellement alloué.
- **Allocation dynamique** : `malloc` est utilisé pour allouer de la mémoire basée sur le nombre d'éléments désiré multiplié par la taille en octets de chaque élément. Cela permet de créer des tableaux de taille flexible pendant l'exécution du programme.