# Énoncé

| Exercice : 08                              |
| ------------------------------------------ |
| Les dix dames                              |
| Dossier de rendu : ex08/                   |
| Fichiers à rendre : ft_ten_queens_puzzle.c |
| Fonctions Autorisées : write               |
• Écrire une fonction qui affiche toutes les possibilités de placer dix dames sur un
échiquier de 10x10 sans qu’elles ne puissent s’atteindre en un seul coup.
• La recursivité devra être utilisée.
• La valeur de retour de votre fonction devra être le nombre de solutions affichées
• Elle devra être prototypée de la façon suivante :
```C
int ft_ten_queens_puzzle(void);
```
• L’affichage se fera de la façon suivante :
```
$>./a.out | cat -e
0257948136$
0258693147$
...
4605713829$
4609582731$
...
9742051863$
$>
```
• La suite se lit de gauche à droite. Le premier chiffre correspond à la position de
la première dame dans la première colonne (l’index commençant à 0). Le énième
chiffre correspond à la position de la énième dame dans la énième colonne.
# Correction

```C
#include <unistd.h>

void	display_queens(int *queens)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = queens[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	no_conflict(int *queens, int col)
{
	int	i;
	int	delta;

	i = 0;
	while (col > 0 && i < col)
	{
		delta = col - i;
		if (queens[i] == queens[col])
			return (0);
		if (queens[i] + delta == queens[col])
			return (0);
		if (queens[i] - delta == queens[col])
			return (0);
		i++;
	}
	return (1);
}

void	seek_solutions(int *queens, int col, int row, int *nb)
{
	if (row == 10)
		return ;
	if (col == 10)
	{
		*nb += 1;
		display_queens(queens);
		return ;
	}
	queens[col] = row;
	if (no_conflict(queens, col))
	{
		seek_solutions(queens, col + 1, 0, nb);
	}
	seek_solutions(queens, col, row + 1, nb);
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	nb;

	nb = 0;
	seek_solutions(queens, 0, 0, &nb);
	return (nb);
}
```
# Démonstration

```C
#include <stdio.h>

int	main(void)
{
	printf("\nsolutions : {%d}\n", ft_ten_queens_puzzle());
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c05/ex08  (main) $ norminette -RCheckForbiddenSourceHeader ft_ten_queens_puzzle.c 
ft_ten_queens_puzzle.c: Error!
Error: INCLUDE_START_FILE   (line:  78, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c05/ex08  (main) $ gcc -Wall -Wextra -Werror ft_ten_queens_puzzle.c 
Repo Git : Practice42/Work/C/c05/ex08  (main) $ ./a.out | cat -e
0257948136$
0258693147$
0258693174$
0286931475$
0358297146$
0369184275$
...
9713068524$
9741306825$
9741306852$
9742051863$
$
solutions : {724}$
Repo Git : Practice42/Work/C/c05/ex08  (main) $
```

