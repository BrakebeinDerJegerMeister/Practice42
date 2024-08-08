# Énoncé

| Exercice : 01                                |
| -------------------------------------------- |
| ft_recursive_factorial                       |
| Dossier de rendu : ex01/                     |
| Fichiers à rendre : ft_recursive_factorial.c |
| Fonctions Autorisées : Aucune                |

# Correction

```C
int	ft_recursive_factorial(int nb)
{
	if (nb > 0)
		return (nb * ft_recursive_factorial(nb -1));
	if (nb < 0)
		return (0);
	else
		return (1);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nres : {%d}\n", ft_recursive_factorial(nb));
}

int	main(void)
{
	test(3);
	test(-2);
	test(25);
	test(8);
	test(0);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c05/ex01  (main) $ norminette -RCheckForbiddenSourceHeader ft_recursive_factorial.c 
ft_recursive_factorial.c: Error!
Error: INCLUDE_START_FILE   (line:  23, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex01  (main) $ gcc -Wall -Wextra -Werror ft_recursive_factorial.c 
Repo Git : Practice42/Work/C/c05/ex01  (main) $ ./a.out 

nb : {3}
res : {6}

nb : {-2}
res : {0}

nb : {25}
res : {2076180480}

nb : {8}
res : {40320}

nb : {0}
res : {1}
Repo Git : Practice42/Work/C/c05/ex01  (main) $ 
```
# Explications

1. **Signature de la fonction** :
   - `int ft_recursive_factorial(int nb)`: La fonction prend un entier `nb` en paramètre et retourne un entier. Elle est nommée de manière à suggérer qu'elle calcule la factorielle de manière récursive.

2. **Condition de terminaison (cas de base)** :
   - `if (nb < 0) return (0);`: Si `nb` est négatif, la fonction retourne 0 immédiatement. Cela traite le cas où l'entrée est invalide pour le calcul de la factorielle, qui n'est pas définie pour les entiers négatifs.
   - `else return (1);`: Si `nb` est égal à 0, la fonction retourne 1, conformément à la définition de 0! qui est égal à 1.

3. **Cas récursif** :
   - `if (nb > 0) return (nb * ft_recursive_factorial(nb - 1));`: Si `nb` est positif, la fonction entre dans ce cas. Elle retourne le produit de `nb` par la factorielle de `nb - 1`. C'est là que la récursivité est utilisée : la fonction s'appelle elle-même avec un argument diminué de 1, se rapprochant ainsi progressivement du cas de base.

4. **Flux d'exécution** :
   - La récursion se poursuit jusqu'à ce que `nb` soit réduit à 0, point auquel la chaîne de récursivité remonte, multipliant les valeurs successives de `nb` pour donner le résultat final, la factorielle de `nb`.

Cette approche de la factorielle via la récursivité illustre un cas classique d'utilisation de la récursion pour simplifier le traitement de problèmes pouvant être divisés en sous-problèmes plus petits de même nature. La récursion doit être manipulée avec précaution, car des valeurs élevées de `nb` peuvent mener à un débordement de pile dû à de trop nombreux appels récursifs.