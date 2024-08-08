# Énoncé

| Exercice : 05                 |
| ----------------------------- |
| ft_sqrt                       |
| Dossier de rendu : ex05/      |
| Fichiers à rendre : ft_sqrt.c |
| Fonctions Autorisées : Aucune |
• Écrire une fonction qui renvoie la racine carrée entière d’un nombre si elle existe,
0 si la racine carrée n’est pas entière.
• Elle devra être prototypée de la façon suivante :
```C
int ft_sqrt(int nb);
```
# Correction

```C
int	int_sqrt(int nb, int i)
{
	if ((i * i) == nb)
		return (i);
	else if ((i * i) > nb)
		return (0);
	else
		return (int_sqrt(nb, i + 1));
}

int	ft_sqrt(int nb)
{
	return (int_sqrt(nb, 0));
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nsqrt : {%d}\n", ft_sqrt(nb));
}

int	main(void)
{
	test(25);
	test(0);
	test(-5);
	test(26);
	test(1);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c05/ex05  (main) $ norminette -RCheckForbiddenSourceHeader ft_sqrt.c 
ft_sqrt.c: Error!
Error: INCLUDE_START_FILE   (line:  28, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex05  (main) $ gcc -Wall -Wextra -Werror ft_sqrt.c 
Repo Git : Practice42/Work/C/c05/ex05  (main) $ ./a.out 

nb : {25}
sqrt : {5}

nb : {0}
sqrt : {0}

nb : {-5}
sqrt : {0}

nb : {26}
sqrt : {0}

nb : {1}
sqrt : {1}
Repo Git : Practice42/Work/C/c05/ex05  (main) $ 
```
# Explications

#### Objectif
Les fonctions `ft_sqrt` et `int_sqrt` sont utilisées pour calculer la racine carrée entière d'un nombre, si elle existe, en utilisant la récursivité. Ce type d'implémentation est une illustration de l'application de la récursivité à un problème numérique simple, destinée principalement à des fins éducatives.

#### Prototypes
```c
int int_sqrt(int nb, int i);
int ft_sqrt(int nb);
```

#### Paramètres
- `int nb`: Le nombre dont on souhaite calculer la racine carrée entière.
- `int i`: L'itérateur utilisé dans la fonction récursive pour vérifier chaque nombre entier à partir de 0 jusqu'à ce que \( i^2 \) soit égal ou dépasse `nb`.

#### Retours
- `int_sqrt`: Retourne `i` si \( i^2 \) est exactement égal à `nb`, sinon 0 si \( i^2 \) dépasse `nb` sans trouver de racine carrée exacte.
- `ft_sqrt`: Initie l'appel récursif en démarrant `i` à 0 et retourne le résultat de `int_sqrt`.

#### Logique des Fonctions
1. **`int_sqrt`**:
   - **Vérification Exacte**:
     - `if ((i * i) == nb) return (i);`: Si \( i^2 \) est exactement égal à `nb`, retourne `i` comme la racine carrée entière de `nb`.
   - **Dépassement de la Valeur**:
     - `else if ((i * i) > nb) return (0);`: Si \( i^2 \) dépasse `nb`, cela signifie qu'il n'existe pas de racine carrée entière pour `nb`, donc la fonction retourne 0.
   - **Appel Récursif**:
     - `else return (int_sqrt(nb, i + 1));`: Si \( i^2 \) est inférieur à `nb`, incrémente `i` et fait un nouvel appel récursif.

2. **`ft_sqrt`**:
   - **Initialisation de la Récursivité**:
     - `return (int_sqrt(nb, 0));`: Commence la recherche de la racine carrée à partir de 0.
