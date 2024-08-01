# Énoncé

| Exercice : 00                    |
| -------------------------------- |
| ft_foreach                       |
| Dossier de rendu : ex00/         |
| Fichiers à rendre : ft_foreach.c |
| Fonctions Autorisées : Aucune    |
• Écrire une fonction ft_foreach qui, pour un tableau d’entiers donné, appliquera
une fonction sur tous les éléments de ce tableau. Cette fonction sera appliquée
dans l’ordre du tableau.
• La fonction sera prototypée de la manière suivante :
```C
void ft_foreach(int *tab, int length, void(*f)(int));
```
• Par exemple, la fonction ft_foreach pourra être appelée de la façon suivante pour
afficher l’ensemble des entiers du tableau :
```h
ft_foreach(tab, 1337, &ft_putnbr);
```
# Correction

```C
void	ft_foreach(int *tab, int length, void (*f)(int))
{
	void	(*f)(int);
	int		i;

	i = 0;
	while (i < length)
	{
		f(tab[i++]);
	}
}
```
# Démonstration

```C
#include <unistd.h>

void	nextnumber(long int nb)
{
	char		disp;
	long int	next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
	write(1, &disp, 1);
}

void	ft_putnbr(int old_nb)
{
	long int	nb;

	nb = (long int)old_nb;
	if (nb < 0)
	{
		nb = -nb;
		write(1, &(char){'-'}, 1);
	}
	nextnumber(nb);
}

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	void	(*f)(int);
	int		i;

	i = 0;
	while (i < length)
	{
		f(tab[i++]);
	}
}

int	main(void)
{
	int	tab[5] = {5, 22, -5, 67, 9};

	ft_foreach(tab, 5, &ft_putnbr);
}
```

```
Repo Git : Practice42/Work/C/c11/ex00  (main) $ norminette -RCheckForbiddenSourceHeader -RCheckDefine ft_foreach.c 
ft_foreach.c: Error!
Error: DECL_ASSIGN_LINE     (line:  56, col:  16):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c11/ex00  (main) $ gcc -Wall -Wextra -Werror ft_foreach.c 
Repo Git : Practice42/Work/C/c11/ex00  (main) $ ./a.out 
522-5679Repo Git : Practice42/Work/C/c11/ex00  (main) $
```
# Explications
Attention, contrairement à ce qui est indiqué dans le PDF :
```C
void ft_foreach(int *tab, int length, void(*f)(int));
```
Si il n'y a pas d'espace entre void et (*f) norminette refuse même si le compilateur fonctionne :
```
Error: MISSING_IDENTIFIER   (line:  43, col:  41):	missing type qualifier or identifier in function arguments
```
Il faut donc écrire comme cela :
```C
void	ft_foreach(int *tab, int length, void (*f)(int))
```



La fonction `ft_foreach` est un exemple de code en C démontrant comment une fonction peut être passée en tant qu'argument à une autre fonction, permettant ainsi de manipuler des données de manière flexible. Cette approche est couramment utilisée pour appliquer une opération spécifique à chaque élément d'un tableau sans réécrire de code pour chaque nouvelle opération.

### Prototype de la fonction

```c
void ft_foreach(int *tab, int length, void (*f)(int));
```

- **`int *tab`**: Un pointeur vers un tableau d'entiers sur lequel les opérations seront appliquées.
- **`int length`**: La taille du tableau.
- **`void (*f)(int)`**: Un pointeur vers la fonction qui sera appliquée à chaque élément du tableau. Cette fonction doit accepter un entier comme argument et retourner `void`.

### Détails de l'implémentation

1. **Déclaration de la fonction pointeur**:
   La fonction `ft_foreach` accepte un pointeur vers une fonction, `f`, qui elle-même prend un int en paramètre et retourne void. Cela permet à `ft_foreach` d'appliquer n'importe quelle fonction correspondant à cette signature sur les éléments du tableau.

2. **Boucle principale**:
   La fonction utilise une boucle `while` pour parcourir tous les éléments du tableau. La variable `i` sert d'indice pour le tableau et est initialisée à 0.

3. **Application de la fonction**:
   Dans chaque itération de la boucle, la fonction pointée par `f` est appelée avec l'élément courant du tableau comme argument (`tab[i]`). L'indice `i` est ensuite incrémenté.