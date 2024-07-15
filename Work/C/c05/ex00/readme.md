# Énoncé

| Exercice : 00                                |
| -------------------------------------------- |
| ft_iterative_factorial                       |
| Dossier de rendu : ex00/                     |
| Fichiers à rendre : ft_iterative_factorial.c |
| Fonctions Autorisées : Aucune                |
• Écrire une fonction itérative qui renvoie un nombre. Ce nombre est le résultat de
l’opération factorielle à partir du nombre passé en paramètre.
• Si l’argument n’est pas valide, la fonction doit renvoyer 0.
• Il ne faut pas gerer les "int overflow", le retour de la fonction sera indefini.
• Elle devra être prototypée de la façon suivante :
```C
int ft_iterative_factorial(int nb);
```
# Correction

```C
int	ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		factorial = factorial * nb;
		nb--;
	}
	return (factorial);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nres : {%d}\n", ft_iterative_factorial(nb));
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
Repo Git : Practice42/Work/C/c05/ex00  (main) $ norminette -RCheckForbiddenSourceHeader ft_iterative_factorial.c 
ft_iterative_factorial.c: Error!
Error: INCLUDE_START_FILE   (line:  28, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex00  (main) $ gcc -Wall -Wextra -Werror ft_iterative_factorial.c 
Repo Git : Practice42/Work/C/c05/ex00  (main) $ ./a.out 

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
Repo Git : Practice42/Work/C/c05/ex00  (main) $ 
```
# Explications

**Objectif :** Calculer la factorielle d'un nombre entier non-négatif de manière itérative.

**Paramètres :**
- `int nb` : Le nombre entier pour lequel la factorielle est calculée.

**Retour :**
- La factorielle de `nb` si `nb` est non-négatif.
- `0` si `nb` est négatif, pour indiquer une erreur car la factorielle n'est pas définie pour les nombres négatifs.

**Description du Code :**
- **Initialisation :** 
  - `int factorial = 1;` : Initialise la factorielle à 1, la factorielle de 0 étant 1.
  
- **Condition Initiale :**
  - `if (nb < 0) return (0);` : Vérifie si l'input est négatif. Si oui, retourne 0 car la factorielle n'est pas définie.
  
- **Boucle :**
  - `while (nb > 0) { ... }` : Itère tant que `nb` est supérieur à 0.
  - À chaque itération, la valeur de `factorial` est multipliée par `nb`.
  - Décrémente `nb` après chaque multiplication pour éviter une boucle infinie et réduire `nb` vers 0.

**Complexité :**
- **Temporelle :** O(n) - la boucle exécute n itérations où n est la valeur de `nb`.
- **Spatiale :** O(1) - utilise une quantité constante de mémoire.

**Cas Test :**
- `ft_iterative_factorial(5)` doit retourner `120`.
- `ft_iterative_factorial(0)` doit retourner `1`.
- `ft_iterative_factorial(-1)` doit retourner `0`.