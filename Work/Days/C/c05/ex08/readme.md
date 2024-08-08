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

# Algorithme

Solution au problème des dix reines sur un échiquier de 10x10. Ce problème consiste à placer dix reines sur un échiquier de telle sorte qu'aucune reine ne puisse en attaquer une autre, ni sur les rangées, ni sur les colonnes, ni sur les diagonales. Le code utilise la récursivité pour explorer toutes les configurations possibles et affiche les solutions valides. Voici une explication détaillée de chaque fonction et des décisions algorithmiques prises :

### Fonction `display_queens(int *queens)`
Cette fonction prend un tableau d'entiers où chaque position représente une colonne de l'échiquier et la valeur à cette position représente la rangée où la reine est placée. La fonction itère sur ce tableau et affiche la position de chaque reine transformée en caractère, suivie par un saut de ligne pour séparer les solutions. L'usage de la fonction système `write` pour un affichage direct est une approche bas niveau, choisie pour sa rapidité et son efficacité, évitant le buffering des sorties standard en C.

### Fonction `no_conflict(int *queens, int col)`
Elle vérifie s'il y a un conflit avec la reine placée dans la colonne spécifiée (`col`). Pour chaque reine déjà placée (de la colonne 0 à `col-1`), elle vérifie si deux reines sont sur la même rangée (`queens[i] == queens[col]`) ou sur les diagonales (`queens[i] + delta == queens[col]` pour la diagonale montante et `queens[i] - delta == queens[col]` pour la diagonale descendante). Le calcul de la différence `delta` pour chaque reine permet de vérifier simultanément les conflits en rangée et en diagonale, optimisant les performances par un seul passage.

### Fonction `seek_solutions(int *queens, int col, int row, int *nb)`
Cette fonction est la clé de voûte de l'algorithme, utilisant la récursivité pour explorer toutes les configurations possibles. Si `col` atteint 10, une configuration valide a été trouvée. La fonction procède alors par récursivité: si la reine placée ne cause pas de conflit, elle appelle `seek_solutions` pour la colonne suivante, débutant à la rangée 0. Si un conflit est détecté, elle essaie la rangée suivante dans la même colonne. Le paramètre `nb` est utilisé pour compter les solutions, et il est passé par référence pour maintenir l'état à travers les appels récursifs.

### Fonction `ft_ten_queens_puzzle`
Fonction principale qui initialise le tableau `queens` et déclenche la recherche des solutions à partir de la première colonne et de la première rangée. L'initialisation à zéro des compteurs et du tableau garantit un état propre avant de commencer la recherche de solutions.

En conclusion, ce code illustre l'application efficace de la récursion pour résoudre un problème complexe de backtracking, où chaque décision est soigneusement conçue pour optimiser la recherche de solutions tout en gérant efficacement l'état à travers des appels récursifs.