# Énoncé

| Exercice : 01                  |
| ------------------------------ |
| ft_range                       |
| Dossier de rendu : ex01/       |
| Fichiers à rendre : ft_range.c |
| Fonctions Autorisées : malloc  |
• Écrire une fonction ft_range qui retourne un tableau d’int. Ce tableau d’int
contiendra toutes les valeurs entre min et max.
• Min inclu - max exclu.
• Elle devra être prototypée de la façon suivante :
```C
int *ft_range(int min, int max);
```
• Si la valeur min est supérieure ou égale à la valeur max, un pointeur nul sera
retourné.
# Correction

```C
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*res;
	int	i;

	if (max - min <= 0)
		return (NULL);
	res = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < max - min)
	{
		res[i] = min + i;
		i++;
	}
	return (res);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int min, int max)
{
	int	*res;
	int	i;

	printf("\nmin : {%d}", min);
	printf("\nmax : {%d}", max);
	res = ft_range(min, max);
	printf("\nres : {");
	if (!res)
		printf("NULL");
	else
	{
		i = 0;
		printf("(size : %d) ", i);
		while (i < max - min)
		{
			printf("%d", res[i]);
			if (i < max - min - 1)
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
Repo Git : Practice42/Work/C/c07/ex01  (main) $ norminette -RCheckForbiddenSourceHeader ft_range.c 
ft_range.c: Error!
Error: INCLUDE_START_FILE   (line:  32, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c07/ex01  (main) $ gcc -Wall -Wextra -Werror ft_range.c 
Repo Git : Practice42/Work/C/c07/ex01  (main) $ ./a.out

min : {50}
max : {55}
res : {(size : 0) 50, 51, 52, 53, 54}

min : {9}
max : {4}
res : {NULL}

min : {-2}
max : {8}
res : {(size : 0) -2, -1, 0, 1, 2, 3, 4, 5, 6, 7}
Repo Git : Practice42/Work/C/c07/ex01  (main) $
```
# Explications

La fonction `ft_range` en C est conçue pour créer un tableau dynamique d'entiers qui contient toutes les valeurs entre deux bornes, `min` et `max`. Le tableau commence à `min` et se termine juste avant `max`. Voici comment elle fonctionne étape par étape :

1. **Vérification des paramètres** : La fonction commence par vérifier si la différence entre `max` et `min` est négative ou nulle (`max - min <= 0`). Si c'est le cas, cela signifie que les bornes sont incorrectes (la borne inférieure est supérieure ou égale à la borne supérieure), et la fonction retourne immédiatement `NULL`. Cela sert de contrôle pour éviter des allocations inutiles et des comportements non définis.

2. **Allocation de mémoire** : Si les paramètres sont valides, la fonction utilise `malloc` pour allouer de la mémoire pour le tableau. `malloc` est une fonction de la bibliothèque standard C (`stdlib.h`) qui permet d'allouer une quantité spécifique de mémoire sur le tas (heap). L'expression `sizeof(int) * (max - min)` calcule la quantité de mémoire nécessaire pour stocker `(max - min)` entiers. Chaque `int` nécessite une certaine quantité d'octets en mémoire (généralement 4 octets sur la plupart des systèmes modernes), et `malloc` retourne un pointeur vers le premier octet de l'espace de mémoire alloué.

   - **Point sur `malloc`** : `malloc` retourne un pointeur de type `void*`, qui est généralement converti en un type de données approprié, ici `int*`. Si `malloc` ne peut pas allouer la mémoire demandée (par exemple, en raison d'un manque de mémoire disponible), elle retourne `NULL`.

3. **Initialisation du tableau** : Une fois la mémoire allouée, la fonction utilise une boucle `while` pour initialiser le tableau. La boucle commence à `i = 0` et continue tant que `i` est inférieur à `max - min`. À chaque itération, l'élément `i` du tableau `res` est défini à `min + i`. Cela remplit le tableau avec les valeurs séquentielles commençant par `min` et se terminant à `max - 1`.

4. **Retour du tableau** : Après avoir rempli le tableau, la fonction retourne le pointeur `res`. Ce pointeur peut ensuite être utilisé pour accéder aux éléments du tableau, mais il est important de se rappeler de libérer cette mémoire avec `free(res)` une fois que le tableau n'est plus nécessaire pour éviter les fuites de mémoire.

En résumé, `ft_range` crée un tableau d'entiers dans une plage spécifiée, utilisant `malloc` pour l'allocation dynamique de mémoire. Cette méthode permet de gérer des quantités de données qui ne sont pas connues à la compilation et dont la taille peut varier dynamiquement à l'exécution.