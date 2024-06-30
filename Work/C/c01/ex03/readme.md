# Énoncé

| ft_div_mod                    |
| ----------------------------- |
| Exercice : 03                 |
| ft_div_mod                    |
| Dossier de rendu : ex03/      |
| Fonctions Autorisées : Aucune |
• Écrire une fonction ft_div_mod qui a le prototypage suivant :
void
```
ft_div_mod(int a, int b, int *div, int *mod);
```
• Cette fonction divise les deux paramètres a et b et stocke le resultat dans l’int
pointé par div.
Elle stocke également le reste de la division de a et b dans l’int pointé par mod.
# Correction

```C
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a - *div * b;
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
	int	a;
	int	b;
	int	*div;
	int	*mod;

	a = 42;
	b = 8;
	ft_putnbr2(a);
	write(1, &"\n", 1);
	ft_putnbr2(b);
	write(1, &"\n", 1);
	ft_div_mod(a, b, div, mod);
	ft_putnbr2(*div);
	write(1, &"\n", 1);
	ft_putnbr2(*mod);
	write(1, &"\n", 1);
}
```

```
Repo Git : Practice42/Work/C/c01/ex03  (main) $ norminette -RCheckForbiddenSourceHeader ft_div_mod.c 
ft_div_mod.c: OK!
Repo Git : Practice42/Work/C/c01/ex03  (main) $ gcc ft_div_mod.c 
Repo Git : Practice42/Work/C/c01/ex03  (main) $ ./a.out
42
8
5
2
Repo Git : Practice42/Work/C/c01/ex03  (main) $ 
```
# Explications

#### Fonction `ft_div_mod`

La fonction `ft_div_mod` permet de calculer à la fois le quotient et le reste de la division de deux entiers et de stocker ces résultats dans des variables passées par adresse.

#### Code de la Fonction

```c
#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a - *div * b;
}
```

#### Explication

1. **Signature de la Fonction :**

    ```c
    void ft_div_mod(int a, int b, int *div, int *mod);
    ```

    - `void` : La fonction ne retourne rien.
    - `ft_div_mod` : Nom de la fonction.
    - `int a` : Premier paramètre, un entier à diviser.
    - `int b` : Deuxième paramètre, un entier diviseur.
    - `int *div` : Troisième paramètre, un pointeur vers un entier où le quotient sera stocké.
    - `int *mod` : Quatrième paramètre, un pointeur vers un entier où le reste sera stocké.

2. **Calcul et Stockage du Quotient :**

    ```c
    *div = a / b;
    ```

    - `a / b` : Effectue la division entière de `a` par `b`.
    - `*div` : Déréférence le pointeur `div` et stocke le quotient à l'adresse pointée par `div`.

3. **Calcul et Stockage du Reste (Modulo) :**

    ```c
    *mod = a - *div * b;
    ```

    - `*div * b` : Calcule le produit du quotient (`*div`) et du diviseur (`b`).
    - `a - *div * b` : Soustrait ce produit de `a` pour obtenir le reste.
    - `*mod` : Déréférence le pointeur `mod` et stocke le reste à l'adresse pointée par `mod`.
