# Énoncé

| Exercice : 04                             |
| ----------------------------------------- |
| ft_ultimate_div_mod                       |
| Dossier de rendu : ex04/                  |
| Fichiers à rendre : ft_ultimate_div_mod.c |
| Fonctions Autorisées : Aucune             |
• Écrire une fonction ft_ultimate_div_mod qui a le prototypage suivant :
void
```
ft_ultimate_div_mod(int *a, int *b);
```
• Cette fonction divise les int pointés par a et b.
Le résultat de la division est stocké dans l’int pointé par a.
Le résultat du reste de la division est stocké dans l’int pointé par b.
# Correction

```C
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a - div * *b;
	*a = div;
	*b = mod;
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
	*b = 8;
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
	ft_ultimate_div_mod(a, b);
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
}
```

```
Repo Git : Practice42/Work/C/c01/ex04  (main) $ norminette -RCheckForbiddenSourceHeader ft_ultimate_div_mod.c 
ft_ultimate_div_mod.c: OK!
Repo Git : Practice42/Work/C/c01/ex04  (main) $ gcc ft_ultimate_div_mod.c 
Repo Git : Practice42/Work/C/c01/ex04  (main) $ ./a.out
42
8
5
2
Repo Git : Practice42/Work/C/c01/ex04  (main) $
```
# Explications

### Documentation du Code : Division et Modulo avec Mise à Jour des Valeurs en C

Utilisation des pointeurs pour calculer et mettre à jour simultanément le quotient et le reste (modulo) de deux entiers en C, destiné à des programmeurs ayant une compréhension intermédiaire des pointeurs et de la manipulation des valeurs en mémoire.

#### Fonction `ft_ultimate_div_mod`

La fonction `ft_ultimate_div_mod` permet de calculer le quotient et le reste de la division de deux entiers, puis met à jour les valeurs originales des entiers avec le quotient et le reste respectivement.

#### Code de la Fonction

```c
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a - div * *b;
	*a = div;
	*b = mod;
}
```

#### Explication

1. **Déclaration de Variables Locales :**

    ```c
    int div;
    int mod;
    ```

    - `div` : Variable locale pour stocker le quotient de la division.
    - `mod` : Variable locale pour stocker le reste (modulo) de la division.

2. **Calcul du Quotient :**

    ```c
    div = *a / *b;
    ```

    Cette ligne effectue la division entière des valeurs pointées par `a` et `b`, et stocke le résultat (quotient) dans `div`. L'opérateur de division `/` en C entre deux entiers renvoie le quotient de la division, tronquant toute partie décimale.

3. **Calcul du Reste (Modulo) :**

    ```c
    mod = *a - div * *b;
    ```

    Cette ligne calcule le reste de la division. Elle utilise le quotient `div` pour déterminer combien de fois `b` s'inscrit complètement dans `a`, puis soustrait ce produit de la valeur originale de `a`. Le résultat est stocké dans `mod`.

4. **Mise à Jour des Valeurs Pointées :**

    ```c
    *a = div;
    *b = mod;
    ```

    - `*a = div` : Met à jour la valeur pointée par `a` avec le quotient (`div`).
    - `*b = mod` : Met à jour la valeur pointée par `b` avec le reste (`mod`).

    En utilisant les pointeurs `a` et `b`, la fonction modifie directement les valeurs originales des variables passées par référence. Cette technique est couramment utilisée pour retourner plusieurs valeurs depuis une fonction.

### Conclusion

La fonction `ft_ultimate_div_mod` utilise des pointeurs pour permettre la modification directe des variables passées en argument, ce qui permet de retourner simultanément le quotient et le reste de la division de deux entiers. Cette approche est efficace pour des calculs qui nécessitent la mise à jour de multiples valeurs sans recourir à des structures de retour complexes.