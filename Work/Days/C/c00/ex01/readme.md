# Énoncé

| Exercice : 01                           |
| --------------------------------------- |
| ft_print_alphabet                       |
| Dossier de rendu : ex01/                |
| Fichiers à rendre : ft_print_alphabet.c |
| Fonctions Autorisées : write            |
• Écrire une fonction qui affiche l’alphabet en minuscule sur une seule ligne, dans
l’ordre croissant, à partir de la lettre ’a’.
• Elle devra être prototypée de la façon suivante :
```
void ft_print_alphabet(void);
```
# Correction

```C
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}
```

# Démonstration

```C
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}

int	main(void)
{
	ft_print_alphabet();
}
```


```
Repo Git : Practice42/Work/C/c00/ex01  (main) $ norminette -RCheckForbiddenSourceHeader ft_print_alphabet.c 
ft_print_alphabet.c: OK!
Repo Git : Practice42/Work/C/c00/ex01  (main) $ gcc ft_print_alphabet.c 
Repo Git : Practice42/Work/C/c00/ex01  (main) $ ./a.out 
abcdefghijklmnopqrstuvwxyzRepo Git : Practice42/Work/C/c00/ex01  (main) $ 
```

# Explications

Cette fonction affiche les lettres de l'alphabet en minuscules, de 'a' à 'z'. Elle ne prend aucun paramètre et ne renvoie aucune valeur (type `void`).

### Comportement de la fonction

La fonction `ft_print_alphabet` initialise une variable `char` nommée `c` à 'a', qui est la première lettre de l'alphabet en minuscules. Elle utilise ensuite une boucle `while` pour parcourir toutes les lettres jusqu'à 'z' inclusivement.

Dans chaque itération de la boucle :

- La lettre courante stockée dans `c` est écrite sur la sortie standard (stdout), ce qui correspond généralement au terminal. Cela est accompli par l'appel à la fonction `write`.
- Après avoir écrit la lettre, `c` est incrémentée (`c++`) pour passer à la lettre suivante dans l'alphabet ASCII.

La fonction `write` est utilisée avec les paramètres suivants :

- `1` indique que le texte doit être écrit sur la sortie standard.
- `&c` est l'adresse de la variable `c`, permettant à `write` d'accéder à la lettre à afficher.
- `1` spécifie la taille de l'écriture, qui est de 1 octet, correspondant à la taille d'un `char`.

### Remarques

Cette fonction démontre l'utilisation des boucles, des types de données de base en C, et comment interagir avec la sortie standard à l'aide de `write`. Elle est idéale pour comprendre les opérations de base de manipulation de caractères et de flux de contrôle dans le langage C.