# Énoncé

| Exercice : 08                         |
| ------------------------------------- |
| ft_sort_int_tab                       |
| Dossier de rendu : ex08/              |
| Fichiers à rendre : ft_sort_int_tab.c |
| Fonctions Autorisées : Aucune         |
• Écrire une fonction qui trie un tableau d’entiers par ordre croissant.
• Les paramètres sont un pointeur sur entier et le nombre d’entiers dans le tableau.
• La fonction devra être prototypée de la façon suivante :
```C
void    ft_sort_int_tab(int *tab, int size);
```

# Correction

```C
#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	ex;

	i = size;
	while (--i > 0)
	{
		if (tab[i] < tab[i - 1])
		{
			ex = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = ex;
			ft_sort_int_tab(tab, i + 1);
		}
	}
}
```

# Démonstration

```
Repo Git : Practice42/Work/C/c01/ex08  (main) $ norminette -RCheckForbiddenSourceHeader ft_sort_int_tab.c 
ft_sort_int_tab.c: OK!
Repo Git : Practice42/Work/C/c01/ex08  (main) $ gcc -Wall -Wextra -Werror ft_sort_int_tab.c 
Repo Git : Practice42/Work/C/c01/ex08  (main) $ ./a.out 
27 0 42 43 -9 
-9 0 27 42 43 
Repo Git : Practice42/Work/C/c01/ex08  (main) $
```


```C
void	nextnumber(int nb)
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

void	print_tab(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		ft_putnbr(tab[i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int	tab[5];

	tab[0] = 27;
	tab[1] = 0;
	tab[2] = 42;
	tab[3] = 43;
	tab[4] = -9;
	print_tab(tab, 5);
	ft_sort_int_tab(tab, 5);
	print_tab(tab, 5);
}
```
