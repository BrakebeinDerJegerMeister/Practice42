# Énoncé

| Exercice : 02                 |
| ----------------------------- |
| ft_swap                       |
| Dossier de rendu : ex02/      |
| Fichiers à rendre : ft_swap.c |
| Fonctions Autorisées : Aucune |
• Écrire une fonction qui échange le contenu de deux entiers dont les adresses sont
données en paramètres.
• Elle devra être prototypée de la façon suivante :
void
```
ft_swap(int *a, int *b);
```
# Correction

```C
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
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
	int	*a;
	int	*b;

	*a = 42;
	*b = 41;
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
	ft_swap(a, b);
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
}
```

```
Repo Git : Practice42/Work/C/c01/ex02  (main) $ norminette -RCheckForbiddenSourceHeader ft_swap.c 
ft_swap.c: OK!
Repo Git : Practice42/Work/C/c01/ex02  (main) $ gcc ft_swap.c 
Repo Git : Practice42/Work/C/c01/ex02  (main) $ ./a.out
42
41
41
42
Repo Git : Practice42/Work/C/c01/ex02  (main) $ 
```
# Explications


### Fonction `ft_swap`

La fonction `ft_swap` permet d'échanger les valeurs de deux entiers en utilisant des pointeurs.

#### Code de la Fonction

```c
#include <unistd.h>

void ft_swap(int *a, int *b) {
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
```

#### Explication

1. **Signature de la Fonction :**

    ```c
    void ft_swap(int *a, int *b);
    ```

    - `void` : La fonction ne retourne rien.
    - `ft_swap` : Nom de la fonction.
    - `int *a` : Premier paramètre, un pointeur vers un entier.
    - `int *b` : Deuxième paramètre, un pointeur vers un entier.

2. **Déclaration d'une Variable Temporaire :**

    ```c
    int c;
    ```

    - `c` : Déclare une variable temporaire de type entier pour stocker temporairement la valeur pointée par `a`.

3. **Échange des Valeurs :**

    ```c
    c = *a;
    *a = *b;
    *b = c;
    ```

    - `c = *a` : Stocke la valeur pointée par `a` dans la variable `c`.
    - `*a = *b` : Affecte la valeur pointée par `b` à la position pointée par `a`.
    - `*b = c` : Affecte la valeur temporairement stockée dans `c` à la position pointée par `b`.

