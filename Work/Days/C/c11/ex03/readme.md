# Énoncé

| Exercice : 03                     |
| --------------------------------- |
| ft_count_if                       |
| Dossier de rendu : ex03/          |
| Fichiers à rendre : ft_count_if.c |
| Fonctions Autorisées : Aucune     |
• Écrire une fonction ft_count_if qui renverra le nombre d’éléments du tableau
qui, en les passant à la fonction f, ne renvoient pas 0.
• Cette fonction sera appliquée dans l’ordre du tableau.
• La fonction sera prototypée de la manière suivante :
```C
int ft_count_if(char **tab, int length, int(*f)(char*));
```
# Correction

```C
#include <unistd.h>

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
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
	char 	*strs1[] = {"hello", "world", "42", "a", "allo", NULL};
	char	*strs2[] = {"a", "b", "c", NULL};
	int			count;
	
	count = ft_count_if(strs1, &minlen_2);
	printf("Count : %d\n", count);
	count = ft_count_if(strs2, &minlen_2);
	printf("Count : %d\n", count);
}
```

```
le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer
ft_count_if.c: Error!
Error: INCLUDE_START_FILE   (line:  45, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  49, col:  22):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  50, col:  22):	Declaration and assignation on a single line

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer
Count : 3
Count : 0

Appuyez sur ENTRÉE ou tapez une commande pour continuer
```

