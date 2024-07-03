# Énoncé

| Exercice : 04                             |
| ----------------------------------------- |
| ft_str_is_lowercase                       |
| Dossier de rendu : ex04/                  |
| Fichiers à rendre : ft_str_is_lowercase.c |
| Fonctions Autorisées : Aucune             |
• Écrire une fonction qui renvoie 1 si la chaîne passée en paramètre ne contient
que des caractères alphabétiques minuscules et renvoie 0 si la chaîne passée en
paramètre contient d’autres types de caractères.
• Elle devra être prototypée de la façon suivante :
```
int ft_str_is_lowercase(char *str);
```
• Elle devra renvoyer 1 si str est une chaîne vide.
# Correction

```C
int	ft_str_is_lowercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c >= 'a' && c <= 'z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
```
# Démonstration

```C
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	test(char *str)
{
	int	ret;

	ret = ft_str_is_lowercase(str);
	ft_putstr(str);
	if (ret)
		write(1, "\nOui\n", 5);
	else
		write(1, "\nNon\n", 5);
}

int	main(void)
{
	test("aabghrh");
	test("eseggH");
	test("0qzqfq");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex04  (main *+) $ norminette -RCheckForbiddenSourceHeader ft_str_is_lowercase.c 
ft_str_is_lowercase.c: Error!
Error: INCLUDE_START_FILE   (line:  31, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c02/ex04  (main *+) $ gcc -Wall -Wextra -Werror ft_str_is_lowercase.c 
Repo Git : Practice42/Work/C/c02/ex04  (main *+) $ ./a.out 
aabghrh
Oui
eseggH
Non
0qzqfq
Repo Git : Practice42/Work/C/c02/ex04  (main *+) $
```
# Explications

Le code définit une fonction `ft_str_is_lowercase` qui prend en paramètre un pointeur vers une chaîne de caractères `str` et retourne un entier. Cette fonction vérifie si tous les caractères de la chaîne sont des lettres minuscules. Si la chaîne contient uniquement des minuscules, la fonction retourne 1, sinon elle retourne 0.

La fonction utilise une boucle `while` pour parcourir chaque caractère de la chaîne jusqu'au caractère nul (`'\0'`), qui marque la fin de la chaîne. Pour chaque caractère, la fonction vérifie s'il est compris entre 'a' et 'z'. Si un caractère ne respecte pas cette condition, la fonction retourne immédiatement 0, indiquant la présence d'un caractère non minuscule. Si la boucle se termine sans trouver de caractère non minuscule, la fonction retourne 1, confirmant que tous les caractères sont minuscules.

(Idem que les exercices précédents)