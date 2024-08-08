# Énoncé

| Exercice : 06                     |
| --------------------------------- |
| ft_is_prime                       |
| Dossier de rendu : ex06/          |
| Fichiers à rendre : ft_is_prime.c |
| Fonctions Autorisées : Aucune     |
• Écrire une fonction qui renvoie 1 si le nombre est premier et 0 si le nombre ne l’est
pas.
• Elle devra être prototypée de la façon suivante :
```C
int ft_is_prime(int nb);
```
# Correction

```C
int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	if (nb <= 3)
		return (1);
	if ((nb % 2) == 0 || (nb % 3) == 0)
		return (0);
	i = 5;
	while ((i * i) <= nb)
	{
		if ((nb % i) == 0 || (nb % (i + 2) == 0))
			return (0);
		i = i + 6;
	}
	return (1);
}
```
# Algorithme

1. **Vérification initiale** : 
   - Si `nb` est inférieur ou égal à 1, la fonction retourne `0` (faux), car ni 0 ni 1 ne sont des nombres premiers.
   - Si `nb` est inférieur ou égal à 3, la fonction retourne `1` (vrai), car 2 et 3 sont des nombres premiers.

2. **Elimination par divisibilité simple** :
   - Si `nb` est divisible par 2 ou par 3, la fonction retourne `0` (faux). Cette étape élimine rapidement tous les multiples de 2 et de 3, qui ne peuvent pas être des nombres premiers.

3. **Boucle de vérification plus complexe** :
   - La fonction initialise une variable `i` à 5. La boucle commence à partir de ce point.
   - Tant que le carré de `i` est inférieur ou égal à `nb`, la boucle continue. Cette condition assure que l'on ne vérifie que les diviseurs nécessaires (jusqu'à la racine carrée de `nb`).
   - Dans la boucle, si `nb` est divisible par `i` ou par `i + 2`, la fonction retourne `0`. Cela couvre les diviseurs potentiels en sautant les multiples de 2 et de 3 déjà vérifiés.
   - La variable `i` est incrémentée de 6 à chaque itération, ce qui permet de vérifier les nombres de la forme 6k ± 1, où k est un entier. Ce choix s'appuie sur le fait que tous les entiers peuvent être représentés sous la forme 6k, 6k+1, 6k+2, 6k+3, 6k+4, ou 6k+5, et parmi ceux-ci, seuls 6k+1 et 6k-1 ne sont pas immédiatement éliminables comme non premiers pour des raisons évidentes de divisibilité par 2 ou 3.

4. **Conclusion** :
   - Si aucune division exacte n’a été trouvée par les nombres testés, la fonction retourne `1`, indiquant que `nb` est un nombre premier.


# Démonstration

```C
#include <stdio.h>

void	test(int nb)
{
	int	res;

	res = ft_is_prime(nb);
	printf("\nnb : {%d} ", nb);
	if (res == 1)
		printf("est premier.\n");
	else
		printf("n'est pas premier.\n");
}

int	main(void)
{
	test(-1);
	test(499);
	test(42);
	test(3);
	test(7777);
	test(111);
	test(112);
	test(113);
}
```

```
Repo Git : Practice42/Work/C/c05/ex06  (main) $ norminette -RCheckForbiddenSourceHeader ft_is_prime.c 
ft_is_prime.c: Error!
Error: INCLUDE_START_FILE   (line:  33, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex06  (main) $ gcc -Wall -Wextra -Werror ft_is_prime.c 
Repo Git : Practice42/Work/C/c05/ex06  (main) $ ./a.out 

nb : {-1} n'est pas premier.

nb : {499} est premier.

nb : {42} n'est pas premier.

nb : {3} est premier.

nb : {7777} n'est pas premier.

nb : {111} n'est pas premier.

nb : {112} n'est pas premier.

nb : {113} est premier.
Repo Git : Practice42/Work/C/c05/ex06  (main) $ 
```

