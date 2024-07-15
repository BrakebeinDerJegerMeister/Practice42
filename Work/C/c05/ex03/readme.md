# Énoncé

| Exercice : 03                            |
| ---------------------------------------- |
| ft_recursive_power                       |
| Dossier de rendu : ex03/                 |
| Fichiers à rendre : ft_recursive_power.c |
| Fonctions Autorisées : Aucune            |
• Écrire une fonction itérative qui renvoie une puissance d’un nombre. Une puissance
inferieur à 0 renverra 0.
• Comme il n’y a pas de concensus sur 0 puissance 0, nous considererons que le
resultat sera 1.
• Il ne faut pas gerer les "int overflow", le retour de la fonction sera indefini.
• Elle devra être prototypée de la façon suivante :
```C
int ft_iterative_power(int nb, int power);
```
# Correction

```C
int	fast_recursive_power(int nb, int power)
{
	if (power > 0)
		return (nb * fast_recursive_power(nb, power - 1));
	return (1);
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	return (fast_recursive_power(nb, power));
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int nb, int power)
{
	printf("\nnb : {%d}, power : {%d}", nb, power);
	printf("\nres : {%d}\n", ft_recursive_power(nb, power));
}

int	main(void)
{
	test(3, 6);
	test(-2, 4);
	test(25, 2);
	test(8, 0);
	test(0, 5);
	test(0, 0);
	test(1, -3);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c05/ex03  (main) $ norminette -RCheckForbiddenSourceHeader ft_recursive_power.c 
ft_recursive_power.c: Error!
Error: INCLUDE_START_FILE   (line:  27, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex03  (main) $ gcc -Wall -Wextra -Werror ft_recursive_power.c 
Repo Git : Practice42/Work/C/c05/ex03  (main) $ ./a.out 

nb : {3}, power : {6}
res : {729}

nb : {-2}, power : {4}
res : {16}

nb : {25}, power : {2}
res : {625}

nb : {8}, power : {0}
res : {1}

nb : {0}, power : {5}
res : {0}

nb : {0}, power : {0}
res : {1}

nb : {1}, power : {-3}
res : {0}
Repo Git : Practice42/Work/C/c05/ex03  (main) $ 

```
# Explications

#### Objectif
Les fonctions `ft_recursive_power` et `fast_recursive_power` travaillent conjointement pour calculer la puissance d'un nombre entier en utilisant la récursivité. Elles sont conçues pour des programmeurs ayant une compréhension des principes de la récursivité en programmation.

#### Prototypes
```c
int fast_recursive_power(int nb, int power);
int ft_recursive_power(int nb, int power);
```

#### Paramètres
- `int nb`: Le nombre de base.
- `int power`: L'exposant auquel le nombre de base doit être élevé. Si l'exposant est négatif, `ft_recursive_power` retourne 0, car elle n'est pas conçue pour gérer les puissances négatives.

#### Retours
- Les fonctions retournent `nb` élevé à la puissance `power`. Si `power` est inférieur à 0, `ft_recursive_power` retourne 0. `fast_recursive_power` retourne 1 quand `power` atteint 0, ce qui sert de cas de base pour la récursion.

#### Logique des Fonctions
1. **`ft_recursive_power`**:
   - **Gestion des cas d'erreur**:
     - `if (power < 0) return (0);`: Vérifie si l'exposant est négatif et retourne 0 en conséquence.
   - **Appel récursif**:
     - `return (fast_recursive_power(nb, power));`: Appelle la fonction `fast_recursive_power` pour gérer la récursion si `power` est non-négatif.

2. **`fast_recursive_power`**:
   - **Cas de base**:
     - `if (power > 0)`: Continue les appels récursifs tant que `power` est supérieur à 0.
     - `return (1);`: Retourne 1 lorsque `power` est 0, ce qui termine la récursion avec le produit correct.
   - **Récursion**:
     - `return (nb * fast_recursive_power(nb, power - 1));`: Multiplie `nb` par le résultat de la fonction appelée avec `power - 1`, effectuant ainsi la multiplication de manière récursive jusqu'à ce que `power` soit réduit à 0.
