# Énoncé

| Exercice : 00                 |
| ----------------------------- |
| ft_ft                         |
| Dossier de rendu : ex00/      |
| Fichiers à rendre : ft_ft.c   |
| Fonctions Autorisées : Aucune |
• Écrire une fonction qui prend un pointeur sur int en paramètre et donne à l’int la
valeur de 42.
• Elle devra être prototypée de la façon suivante :
void
```
ft_ft(int *nbr);
```
# Correction

```C
#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

```

# Démonstration

```C
int	nextnumber(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
	write(1, &disp, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		write(1, &(char){'-'}, 1);
	}
	nextnumber(nb);
}

int	main(void)
{
	int	n;

	ft_ft(&n);
	ft_putnbr(n);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c01/ex00  (main) $ norminette -RCheckForbiddenSourceHeader ft_ft.c 
ft_ft.c: OK!
Repo Git : Practice42/Work/C/c01/ex00  (main) $ gcc ft_ft.c 
Repo Git : Practice42/Work/C/c01/ex00  (main) $ ./a.out
42Repo Git : Practice42/Work/C/c01/ex00  (main) $ 
```
# Explications

### Documentation sur les Pointeurs pour Débutants

Cette documentation explique comment fonctionne la fonction `ft_ft` et comment l'appeler dans un programme en C, avec un accent particulier sur l'utilisation des pointeurs.

#### Fonction `ft_ft`

```c
void ft_ft(int *nbr) {
    *nbr = 42;
}
```

- `void ft_ft(int *nbr) {`: Cette ligne déclare une fonction appelée `ft_ft` qui prend en argument un pointeur vers un entier (`int *nbr`) et ne retourne rien (`void`).
- `*nbr = 42;`: Cette ligne déréférence le pointeur `nbr`, c'est-à-dire qu'elle accède à l'entier pointé par `nbr`, et lui assigne la valeur 42. En d'autres termes, cela modifie la valeur de l'entier dont l'adresse a été passée à la fonction.

#### Programme Principal

```c
#include <unistd.h>

void ft_ft(int *nbr) {
    *nbr = 42;
}

int main(void) {
    int n;

    ft_ft(&n);
    ft_putnbr(n);
    return (0);
}
```

- `ft_ft(&n);`: Appelle la fonction `ft_ft` en passant l'adresse de la variable `n` à l'aide de l'opérateur `&`. Ceci permet à `ft_ft` de modifier directement la valeur de `n` en utilisant le pointeur.

### Explication des Pointeurs

Un pointeur est une variable qui contient l'adresse d'une autre variable. Dans ce cas :

- `int *nbr` signifie que `nbr` est un pointeur vers un entier.
- `&n` obtient l'adresse de la variable `n`.
- `*nbr` déréférence le pointeur `nbr`, accédant ainsi à la valeur stockée à cette adresse.

### Étapes de l'Exécution

1. La variable `n` est déclarée dans `main`.
2. L'adresse de `n` est passée à la fonction `ft_ft` avec `ft_ft(&n)`.
3. À l'intérieur de `ft_ft`, `*nbr` accède à `n` et lui assigne la valeur 42.
4. Après le retour de `ft_ft`, la valeur de `n` est maintenant 42.
5. `ft_putnbr(n)` affiche la valeur 42.

En utilisant des pointeurs, la fonction `ft_ft` peut modifier la valeur d'une variable définie dans une autre fonction, ce qui est une technique puissante et couramment utilisée en programmation en C.