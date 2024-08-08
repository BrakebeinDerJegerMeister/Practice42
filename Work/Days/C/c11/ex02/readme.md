# Énoncé

| Exercice : 02                 |
| ----------------------------- |
| ft_any                        |
| Dossier de rendu : ex02/      |
| Fichiers à rendre : ft_any.c  |
| Fonctions Autorisées : Aucune |
• Écrire une fonction ft_any qui renverra 1 si, en le passant à la fonction f, au
moins un élément du tableau renvoie autre chose que 0, sinon elle renverra 0.
• Cette fonction sera appliquée dans l’ordre du tableau.
• La fonction sera prototypée de la manière suivante :
```C
int ft_any(char **tab, int(*f)(char*));
```
• Le tableau sera terminé par un pointeur nul.
# Correction

```C
#include <unistd.h>

int	ft_any(char **tab, int (*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
```
# Démonstration

```C
#include <stdio.h>

int	minlen_2(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
		if (i > 2)
			return (1);
	}
	return (0);
}

int	main(void)
{
	char	*strs1[] = {"hello", "world", "42", "a", "allo", NULL};
	char	*strs2[] = {"a", "b", "c", NULL};
	int			has_any;
	
	has_any = ft_any(strs1, &minlen_2);
	printf("%s\n", has_any ? "oui" : "non");
	has_any = ft_any(strs2, &minlen_2);
	printf("%s\n", has_any ? "oui" : "non");
}
```

```
le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer
ft_any.c: Error!
Error: INCLUDE_START_FILE   (line:  43, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  47, col:  22):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  48, col:  22):	Declaration and assignation on a single line
Error: TERNARY_FBIDDEN      (line:  52, col:  28):	Ternaries are forbidden
Error: TERNARY_FBIDDEN      (line:  54, col:  28):	Ternaries are forbidden

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer
oui
non

Appuyez sur ENTRÉE ou tapez une commande pour continuer

