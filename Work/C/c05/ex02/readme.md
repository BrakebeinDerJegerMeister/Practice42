# Énoncé

| Exercice : 02                            |
| ---------------------------------------- |
| ft_iterative_power                       |
| Dossier de rendu : ex02/                 |
| Fichiers à rendre : ft_iterative_power.c |
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
int	ft_iterative_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power > 0)
	{
		res = nb * res;
		power--;
	}
	return (res);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int nb, int power)
{
	printf("\nnb : {%d}, power : {%d}", nb, power);
	printf("\nres : {%d}\n", ft_iterative_power(nb, power));
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
Repo Git : Practice42/Work/C/c05/ex02  (main) $ norminette -RCheckForbiddenSourceHeader ft_iterative_power.c 
ft_iterative_power.c: Error!
Error: INCLUDE_START_FILE   (line:  28, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex02  (main) $ gcc -Wall -Wextra -Werror ft_iterative_power.c 
Repo Git : Practice42/Work/C/c05/ex02  (main) $ ./a.out 

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
Repo Git : Practice42/Work/C/c05/ex02  (main) $ 
```
# Explications

#### Objectif
La fonction `ft_iterative_power` calcule la puissance d'un nombre entier de manière itérative. Elle est destinée à des utilisateurs ayant une compréhension de base de la programmation, particulièrement dans la manipulation de boucles et conditions.

#### Prototype
```c
int ft_iterative_power(int nb, int power);
```

#### Paramètres
- `int nb`: Le nombre de base.
- `int power`: L'exposant auquel le nombre de base doit être élevé. Si l'exposant est négatif, la fonction retourne 0, car la fonction ne gère pas les fractions.

#### Retour
- Retourne `nb` élevé à la puissance `power`. Si `power` est inférieur à 0, la fonction retourne 0 comme mentionné précédemment. Pour `power` égal à 0, le résultat est toujours 1 conformément à la définition mathématique.

#### Logique de la Fonction
1. **Initialisation** : 
   - `int res = 1;`: Initialise le résultat à 1. C'est l'élément neutre de la multiplication, ce qui est essentiel pour calculer la puissance.

2. **Condition d'Erreur** :
   - `if (power < 0) return (0);`: Vérifie si l'exposant est négatif. La fonction retourne 0 car elle ne prend pas en charge les puissances négatives qui mèneraient à des fractions ou des nombres décimaux.

3. **Boucle de Calcul** :
   - `while (power > 0)`: La boucle continue tant que l'exposant est supérieur à 0.
   - `res = nb * res;`: Multiplie le résultat courant par le nombre de base, accumulant ainsi le résultat de la puissance.
   - `power--;`: Décrémente la puissance après chaque multiplication pour converger vers 0, condition d'arrêt de la boucle.
