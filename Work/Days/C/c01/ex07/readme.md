# Énoncé

| Exercice : 07                        |
| ------------------------------------ |
| ft_rev_int_tab                       |
| Dossier de rendu : ex07/             |
| Fichiers à rendre : ft_rev_int_tab.c |
| Fonctions Autorisées : Aucune        |
• Écrire une fonction qui inverse l’ordre des élements d’un tableau d’entiers.
• Les paramètres sont un pointeur sur entier et le nombre d’entiers dans le tableau.
• La fonction devra être prototypée de la façon suivante :
void
```
ft_rev_int_tab(int *tab, int size);
```
# Correction

```C
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	ex;

	i = size / 2;
	while (--i >= 0)
	{
		ex = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = ex;
	}
}
```

# Démonstration

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
	int	tab1[5];
	int	tab2[6];
	int	i;

	i = -1;
	while (++i < 5)
	{
		tab1[i] = (i + 1) * 2;
	}
	i = -1;
	while (++i < 6)
	{
		tab2[i] = (-3) * i;
	}
	print_tab(tab1, 5);
	ft_rev_int_tab(tab1, 5);
	print_tab(tab1, 5);
	print_tab(tab2, 6);
	ft_rev_int_tab(tab2, 6);
	print_tab(tab2, 6);
}

```

```
Repo Git : Practice42/Work/C/c01/ex07  (main *) $ norminette -RCheckForbiddenSourceHeader ft_rev_int_tab.c 
ft_rev_int_tab.c: OK!
Repo Git : Practice42/Work/C/c01/ex07  (main *) $ gcc ft_rev_int_tab.c 
Repo Git : Practice42/Work/C/c01/ex07  (main *) $ ./a.out 
2 4 6 8 10 
10 8 6 4 2 
0 -3 -6 -9 -12 -15 
-15 -12 -9 -6 -3 0 
Repo Git : Practice42/Work/C/c01/ex07  (main *) $ 

```
# Algorithme

### Inversion d'un Tableau d'Entiers

L'algorithme de la fonction `ft_rev_int_tab` permet d'inverser les éléments d'un tableau d'entiers :

#### But de l'Algorithme

L'algorithme prend un tableau d'entiers et sa taille en entrée et inverse les éléments de ce tableau en place, c'est-à-dire sans utiliser de mémoire supplémentaire pour un autre tableau.

#### Étapes de l'Algorithme

1. **Calcul du Point Milieu :**

    ```c
    i = size / 2;
    ```

    - La variable `i` est initialisée à la moitié de la taille du tableau (`size / 2`). Cette variable sert de compteur pour parcourir la première moitié du tableau.
    - En divisant la taille du tableau par 2, l'algorithme se limite à parcourir la moitié du tableau, car l'échange des éléments sera symétrique.

2. **Boucle de Parcours et d'Échange :**

    ```c
    while (--i >= 0)
    ```

    - La boucle `while` décrémente `i` à chaque itération (`--i`) et continue jusqu'à ce que `i` soit inférieur à 0.
    - À chaque itération, l'algorithme échange les éléments situés aux positions `i` et `size - i - 1`.

3. **Échange des Éléments :**

    ```c
    {
        ex = tab[size - i - 1];
        tab[size - i - 1] = tab[i];
        tab[i] = ex;
    }
    ```

    - **Sauvegarde de la Valeur :** `ex = tab[size - i - 1];`
        - La valeur de l'élément situé à la position symétrique `size - i - 1` (depuis la fin du tableau) est sauvegardée dans la variable `ex`.
    - **Échange de Valeurs :** `tab[size - i - 1] = tab[i];`
        - La valeur de l'élément situé à la position `i` est assignée à la position `size - i - 1`.
    - **Réaffectation :** `tab[i] = ex;`
        - La valeur sauvegardée dans `ex` (l'élément original de la position `size - i - 1`) est réaffectée à la position `i`.

#### Exemple de Fonctionnement

Supposons un tableau `tab` de taille `5` avec les éléments `[1, 2, 3, 4, 5]` :

1. **Initialisation :** `i = 5 / 2 = 2`
2. **Première Itération :** `i = 1`
    - Échange de `tab[0]` et `tab[4]` :
        - `ex = tab[4]` -> `ex = 5`
        - `tab[4] = tab[0]` -> `tab[4] = 1`
        - `tab[0] = ex` -> `tab[0] = 5`
    - Tableau après échange : `[5, 2, 3, 4, 1]`
3. **Deuxième Itération :** `i = 0`
    - Échange de `tab[1]` et `tab[3]` :
        - `ex = tab[3]` -> `ex = 4`
        - `tab[3] = tab[1]` -> `tab[3] = 2`
        - `tab[1] = ex` -> `tab[1] = 4`
    - Tableau après échange : `[5, 4, 3, 2, 1]`
4. **Fin de la Boucle :** `i` devient -1, la boucle s'arrête.

L'algorithme de la fonction `ft_rev_int_tab` est efficace pour inverser les éléments d'un tableau d'entiers en parcourant uniquement la moitié du tableau et en échangeant symétriquement les éléments des deux moitiés. Cette approche minimise le nombre d'opérations nécessaires et utilise une variable temporaire pour réaliser les échanges en place.
