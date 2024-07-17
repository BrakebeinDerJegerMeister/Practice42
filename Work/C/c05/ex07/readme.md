# Énoncé

| Exercice : 07                            |
| ---------------------------------------- |
| ft_find_next_prime                       |
| Dossier de rendu : ex07/                 |
| Fichiers à rendre : ft_find_next_prime.c |
| Fonctions Autorisées : Aucune            |
• Écrire une fonction qui renvoie le nombre premier immédiatement supérieur ou
égal au nombre passé en paramètre.
• Elle devra être prototypée de la façon suivante :
```C
int ft_find_next_prime(int nb);
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int nb)
{
	printf("\nnb : {%d}", nb);
	printf("\nnext nb : {%d}\n", ft_find_next_prime(nb));
}

int	main(void)
{
	test(50);
	test(0);
	test(110);
}
```

```
Repo Git : Practice42/Work/C/c05/ex07  (main) $ norminette -RCheckForbiddenSourceHeader ft_find_next_prime.c 
ft_find_next_prime.c: Error!
Error: INCLUDE_START_FILE   (line:  40, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex07  (main) $ gcc -Wall -Wextra -Werror ft_find_next_prime.c 
Repo Git : Practice42/Work/C/c05/ex07  (main) $ ./a.out 

nb : {50}
next nb : {53}

nb : {0}
next nb : {2}

nb : {110}
next nb : {113}
Repo Git : Practice42/Work/C/c05/ex07  (main) $ 
```

