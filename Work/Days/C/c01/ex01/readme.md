# Énoncé

| Exercice : 01                        |
| ------------------------------------ |
| ft_ultimate_ft                       |
| Dossier de rendu : ex01/             |
| Fichiers à rendre : ft_ultimate_ft.c |
| Fonctions Autorisées : Aucune        |
• Écrire une fonction qui prend un pointeur sur pointeur sur pointeur sur poin-
teur sur pointeur sur pointeur sur pointeur sur pointeur sur pointeur sur int en
paramètre et donne à l’int la valeur de 42.
• Elle devra être prototypée de la façon suivante :
void
```
ft_ultimate_ft(int *********nbr);
```
# Correction

```C
#include <unistd.h>

void	ft_ft(int *********nbr)
{
	*********nbr = 42;
}

```

# Démonstration

```C
int	ft_putnbr2(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		ft_putnbr2(nb);
	}
	write(1, &disp, 1);
}

int	main(void)
{
	int	n;
	int	*ptr1;
	int	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;
	int	*********ptr9;

	ptr1 = &n;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	ft_ultimate_ft(ptr9);
	ft_putnbr2(n);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c01/ex01  (main) $ norminette -RCheckForbiddenSourceHeader ft_ultimate_ft.c 
ft_ultimate_ft.c: Error!
Error: TOO_MANY_VARS_FUNC   (line:  42, col:   1):	Too many variables declarations in a function
Error: TOO_MANY_VARS_FUNC   (line:  43, col:   1):	Too many variables declarations in a function
Error: TOO_MANY_VARS_FUNC   (line:  44, col:   1):	Too many variables declarations in a function
Error: TOO_MANY_VARS_FUNC   (line:  45, col:   1):	Too many variables declarations in a function
Error: TOO_MANY_VARS_FUNC   (line:  46, col:   1):	Too many variables declarations in a function
Repo Git : Practice42/Work/C/c01/ex01  (main) $ gcc ft_ultimate_ft.c 
Repo Git : Practice42/Work/C/c01/ex01  (main) $ ./a.out
42Repo Git : Practice42/Work/C/c01/ex01  (main) $ 

```
# Explications

Bien évidemment `Norminette` ne passe pas mais cela importe peu car main() est une fonction à ne pas rendre et sera donc à supprimer plus tard. Cependant elle est nécessaire pour la démonstration.

### Documentation sur les Pointeurs Multiples en C

#### Déclarations et Initialisations

Le programme suivant déclare et initialise des pointeurs de plusieurs niveaux, allant d'un pointeur simple à un pointeur de neuf niveaux.

```c
int	main(void)
{
	int	n;
	int	*ptr1;
	int	**ptr2;
	int	***ptr3;
	int	****ptr4;
	int	*****ptr5;
	int	******ptr6;
	int	*******ptr7;
	int	********ptr8;
	int	*********ptr9;

	ptr1 = &n;
	ptr2 = &ptr1;
	ptr3 = &ptr2;
	ptr4 = &ptr3;
	ptr5 = &ptr4;
	ptr6 = &ptr5;
	ptr7 = &ptr6;
	ptr8 = &ptr7;
	ptr9 = &ptr8;
	ft_ultimate_ft(ptr9);
	ft_putnbr2(n);
	return (0);
}
```

1. **Déclaration des Pointeurs :**
    - `int n;`: Déclare une variable entière `n`.
    - `int *ptr1;`: Déclare un pointeur `ptr1` qui pointe vers un entier.
    - `int **ptr2;`: Déclare un pointeur `ptr2` qui pointe vers `ptr1`.
    - `int ***ptr3;`: Déclare un pointeur `ptr3` qui pointe vers `ptr2`.
    - `int ****ptr4;`: Déclare un pointeur `ptr4` qui pointe vers `ptr3`.
    - `int *****ptr5;`: Déclare un pointeur `ptr5` qui pointe vers `ptr4`.
    - `int ******ptr6;`: Déclare un pointeur `ptr6` qui pointe vers `ptr5`.
    - `int *******ptr7;`: Déclare un pointeur `ptr7` qui pointe vers `ptr6`.
    - `int ********ptr8;`: Déclare un pointeur `ptr8` qui pointe vers `ptr7`.
    - `int *********ptr9;`: Déclare un pointeur `ptr9` qui pointe vers `ptr8`.

2. **Initialisation des Pointeurs :**
    - `ptr1 = &n;`: Affecte à `ptr1` l'adresse de `n`.
    - `ptr2 = &ptr1;`: Affecte à `ptr2` l'adresse de `ptr1`.
    - `ptr3 = &ptr2;`: Affecte à `ptr3` l'adresse de `ptr2`.
    - `ptr4 = &ptr3;`: Affecte à `ptr4` l'adresse de `ptr3`.
    - `ptr5 = &ptr4;`: Affecte à `ptr5` l'adresse de `ptr4`.
    - `ptr6 = &ptr5;`: Affecte à `ptr6` l'adresse de `ptr5`.
    - `ptr7 = &ptr6;`: Affecte à `ptr7` l'adresse de `ptr6`.
    - `ptr8 = &ptr7;`: Affecte à `ptr8` l'adresse de `ptr7`.
    - `ptr9 = &ptr8;`: Affecte à `ptr9` l'adresse de `ptr8`.

#### Utilisation dans une Fonction

La fonction `ft_ultimate_ft` modifie la valeur de `n` via un pointeur de neuf niveaux :

```c
void ft_ultimate_ft(int *********nbr) {
    *********nbr = 42;
}
```

1. **Signature de la Fonction :**
    - `void ft_ultimate_ft(int *********nbr)`: Cette fonction prend un pointeur à neuf niveaux de déréférencement vers un entier.

2. **Modification de la Valeur :**
    - `*********nbr = 42;`: Cette ligne déréférence le pointeur à neuf niveaux pour accéder à la variable entière d'origine et lui affecte la valeur 42.

### Explication Générale

L'utilisation de multiples niveaux de pointeurs permet de créer une chaîne de références qui peuvent être manipulées pour accéder à une variable de manière indirecte. Cela est particulièrement utile dans les situations où vous avez besoin de passer des références multiples dans des fonctions ou manipuler des structures de données complexes.

- **Déclaration et Initialisation :** Chaque niveau de pointeur est déclaré et initialisé séparément, formant une chaîne de références de plus en plus éloignées de la variable d'origine.
- **Passage et Déréférencement :** En passant le pointeur le plus éloigné (`ptr9`) à la fonction, celle-ci peut accéder à la variable d'origine (`n`) après plusieurs niveaux de déréférencement.
- **Modification de Valeur :** La fonction `ft_ultimate_ft` démontre comment modifier la valeur d'une variable située au bout d'une chaîne de pointeurs multiples.

Cette approche, bien que rarement nécessaire dans des situations pratiques simples, montre la flexibilité et la puissance de la gestion des pointeurs en C, particulièrement utile dans les environnements systèmes et bas niveau où une manipulation fine de la mémoire est requise.

