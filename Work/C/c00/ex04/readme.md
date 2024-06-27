# Énoncé

| Exercice : 04                        |
| ------------------------------------ |
| ft_is_negative                       |
| Dossier de rendu : ex04/             |
| Fichiers à rendre : ft_is_negative.c |
| Fonctions Autorisées : write         |
• Écrire une fonction qui affiche ’N’ ou ’P’ suivant le signe de l’entier passé en
paramètre. Si n est négatif alors afficher ’N’. Si n est positif ou nul alors afficher
’P’.
• Elle devra être prototypée de la façon suivante :
```
void ft_is_negative(int n);
```
# Correction

```C
#include <unistd.h>

void	print_me(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	char	c;

	if (n < 0)
	{
		c = 'N';
	}
	else
	{
		c = 'P';
	}
	print_me(c);
}
```

# Démonstration
```C
#include <unistd.h>

void	print_me(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	char	c;

	if (n < 0)
	{
		c = 'N';
	}
	else
	{
		c = 'P';
	}
	print_me(c);
}

int	main(void)
{
	ft_is_negative(3);
	ft_is_negative(-3);
	ft_is_negative(0);
	ft_is_negative(100);
	ft_is_negative(90);
	ft_is_negative(-50);
	return (0);
}
```


```
Repo Git : Practice42/Work/C/c00/ex04  (main *) $ norminette ft_is_negative.c 
ft_is_negative.c: OK!
Repo Git : Practice42/Work/C/c00/ex04  (main *) $ gcc ft_is_negative.c 
Repo Git : Practice42/Work/C/c00/ex04  (main *) $ ./a.out 
PNPPPNRepo Git : Practice42/Work/C/c00/ex04  (main *) $ 
```

# Explications

V### Structure du Code

1. **Fonction `print_me`** : 
   - Cette fonction prend un caractère `c` en argument.
   - Elle utilise `write` pour afficher ce caractère sur la sortie standard, souvent le terminal ou la console.
   - `write(1, &c, 1)` : 
     - `1` indique qu'on écrit sur la sortie standard.
     - `&c` est l'adresse de la variable `c` (car `write` a besoin d'une adresse mémoire pour lire les données).
     - `1` spécifie qu'on écrit un seul caractère.

2. **Fonction `ft_is_negative`** :
   - Cette fonction prend un entier `n` en argument pour vérifier si cet entier est négatif ou non.
   - Elle déclare une variable locale `c` de type `char` pour stocker le résultat.
   - Utilise une structure conditionnelle `if` pour tester la valeur de `n` :
     - Si `n` est inférieur à zéro (`n < 0`), `c` est assigné à 'N', indiquant que le nombre est négatif.
     - Sinon, `c` est assigné à 'P', indiquant que le nombre est positif ou zéro.
   - Appelle `print_me(c)` pour afficher 'N' si `n` est négatif, ou 'P' sinon.

### Exécution du Code

- Lorsque `ft_is_negative` est appelée avec une valeur spécifique pour `n`, elle détermine si cette valeur est négative ou non et utilise `print_me` pour afficher le résultat.
- Par exemple, si `ft_is_negative(-1)` est appelée, elle affichera 'N'. Si `ft_is_negative(0)` est appelée, elle affichera 'P'.

