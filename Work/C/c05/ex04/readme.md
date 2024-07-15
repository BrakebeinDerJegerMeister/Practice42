# Énoncé

| Exercice : 04                      |
| ---------------------------------- |
| ft_fibonacci                       |
| Dossier de rendu : ex04/           |
| Fichiers à rendre : ft_fibonacci.c |
| Fonctions Autorisées : Aucune      |
• Écrire une fonction ft_fibonacci qui renvoie le n-ième élément de la suite de
Fibonacci, le premier élément étant à l’index 0. Nous considererons que la suite de
Fibonacci commence par 0, 1, 1, 2.
• Les overflows ne devront pas être gerés.
• Elle devra être prototypée de la façon suivante :
```C
int ft_fibonacci(int index);
```
• Évidemment, ft_fibonacci devra être récursive.
• Si index est inférieur à 0, la fonction renverra -1.
# Correction

```C
int	fibonacci(int index)
{
	if (index > 1)
		return (fibonacci(index - 1) + fibonacci(index - 2));
	else
		return (index);
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (fibonacci(index));
}
```
# Algorithme

La suite de Fibonacci est définie comme suit:

- F(0) = 0
- F(1) = 1
- F(n) = F(n-1) + F(n-2) pour n > 1

Prenons un exemple plus simple, disons le calcul de F(5):

1. **Calcul de F(5)**:
    - Nécessite F(4) et F(3)
2. **Calcul de F(4)**:
    - Nécessite F(3) et F(2)
3. **Calcul de F(3) (pour F(4))**:
    - Nécessite F(2) et F(1)
4. **Calcul de F(2) (pour F(3) de F(4))**:
    - Nécessite F(1) et F(0)

À chaque étape, nous voyons que le calcul d’un terme nécessite les deux termes précédents. Sans optimisation, ce code fait beaucoup de calculs redondants. Par exemple, F(3) est calculé deux fois indépendamment dans l'arbre d'appel pour F(5). Pour de plus grandes valeurs comme F(25), le nombre d'appels récursifs explose de manière exponentielle.

# Démonstration

```C
#include <stdio.h>

void	test(int index)
{
	printf("\nindex : {%d}", index);
	printf("\nres : {%d}\n", ft_fibonacci(index));
}

int	main(void)
{
	test(0);
	test(1);
	test(2);
	test(3);
	test(4);
	test(-5);
	test(25);
	test(35);
	test(45);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c05/ex04  (main) $ norminette -RCheckForbiddenSourceHeader ft_fibonacci.c 
ft_fibonacci.c: Error!
Error: INCLUDE_START_FILE   (line:  28, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex04  (main) $ gcc -Wall -Wextra -Werror ft_fibonacci.c 
Repo Git : Practice42/Work/C/c05/ex04  (main) $ ./a.out 

index : {0}
res : {0}

index : {1}
res : {1}

index : {2}
res : {1}

index : {3}
res : {2}

index : {4}
res : {3}

index : {-5}
res : {-1}

index : {25}
res : {75025}

index : {35}
res : {9227465}

index : {45}
res : {1134903170}
Repo Git : Practice42/Work/C/c05/ex04  (main) $
```
# Explications

#### Objectif
Les fonctions `fibonacci` et `ft_fibonacci` sont conçues pour calculer le terme correspondant à l'indice donné dans la suite de Fibonacci, en utilisant la récursivité. Ces fonctions sont optimales pour enseigner les principes de récursivité en programmation, bien qu'elles ne soient pas les plus efficaces en termes de performance.

#### Prototypes
```c
int fibonacci(int index);
int ft_fibonacci(int index);
```

#### Paramètres
- `int index`: L'indice du terme dans la suite de Fibonacci à calculer. Pour `fibonacci`, cet indice est supposé être non-négatif. La fonction `ft_fibonacci` gère explicitement les indices négatifs en retournant -1.

#### Retours
- `fibonacci`: Retourne le terme de la suite de Fibonacci correspondant à l'indice donné.
- `ft_fibonacci`: Retourne le terme de la suite de Fibonacci pour des indices non-négatifs ou -1 pour les indices négatifs.

#### Logique des Fonctions
1. **`fibonacci`**:
   - **Cas de base**:
     - `if (index > 1)`: Si l'indice est supérieur à 1, la fonction procède à un appel récursif.
     - `else return (index);`: Pour les indices 0 et 1, la fonction retourne l'indice lui-même, car F(0) = 0 et F(1) = 1 dans la suite de Fibonacci.
   - **Récursion**:
     - `return (fibonacci(index - 1) + fibonacci(index - 2));`: Calcul récursif des deux termes précédents de la suite.

2. **`ft_fibonacci`**:
   - **Gestion des indices négatifs**:
     - `if (index < 0) return (-1);`: Retourne -1 si l'indice est négatif pour signaler une erreur, car la suite de Fibonacci n'est pas définie pour des indices négatifs.
   - **Appel récursif**:
     - `return (fibonacci(index));`: Appelle la fonction `fibonacci` pour calculer le terme si l'indice est valide.
