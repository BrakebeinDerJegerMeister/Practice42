# Énoncé

| Exercice : 05                     |
| --------------------------------- |
| ft_show_tab                       |
| Dossier de rendu : ex05/          |
| Fichiers à rendre : ft_show_tab.c |
| Fonctions Autorisées : write      |
• Écrire une fonction qui affiche le contenu d’un tableau créé par la fonction précé-
dente.
• Elle devra être prototypée de la façon suivante :
```C
void ft_show_tab(struct s_stock_str *par);
```
• La structure est la même que l’éxercice précédent et sera dans le fichier ft_stock_str.h
que nous vous fournirons, :
• Pour chaque élément du tableau :
◦ la chaîne de caractères suivi d’un retour à la ligne
◦ la taille suivi d’un retour à la ligne
◦ la copie de la chaîne de caractères (qui aura pu être modifiée) suivi d’un retour
à la ligne
• Nous testons votre fonction avec notre ft_strs_to_tab (exercice précédent). Pre-
nez les mesures nécessaires pour que cela fonctionne !
# Correction

```C
#include "ft_stock_str.h"
#include <unistd.h>

void	nextnumber(long int nb)
{
	char		disp;
	long int	next;

	next = nb % 10;
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
	disp = next + '0';
	write(1, &disp, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		nextnumber(par[i].size);
		write(1, "\n", 1);
		par[i].copy[0] = 'Z';
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}
```

# Démonstration

```C
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (save);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	char		*cpy;
	t_stock_str	*stk;

	cpy = NULL;
	stk = (t_stock_str *)malloc(sizeof(t_stock_str) * (1 + ac));
	if (!stk)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stk[i].size = ft_strlen(av[i]);
		stk[i].str = av[i];
		free(cpy);
		stk[i].copy = malloc((stk[i].size + 1) * sizeof(char));
		if (!stk[i].copy)
			return (NULL);
		ft_strcpy(stk[i].copy, av[i]);
		i++;
	}
	stk[ac].str = 0;
	free(cpy);
	return (stk);
}

int	main(void)
{
	char		*av[] = {"Hello", "World", "Test", "Example"};
	t_stock_str	*stk;

	stk = ft_strs_to_tab(4, av);
	if (stk != NULL)
	{
		ft_show_tab(stk);
	}
	return (0);
}
```

```
Appuyez sur ENTRÉE ou tapez une commande pour continuer
ft_show_tab.c: Error!
Error: INCLUDE_START_FILE   (line:  58, col:   1):	Include must be at the start of file
Error: TOO_MANY_FUNCS       (line:  83, col:   1):	Too many functions in file
Error: TOO_MANY_FUNCS       (line: 110, col:   1):	Too many functions in file
Error: DECL_ASSIGN_LINE     (line: 112, col:  23):	Declaration and assignation on a single line

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer
Hello
5
Zello
World
5
Zorld
Test
4
Zest
Example
7
Zxample

Appuyez sur ENTRÉE ou tapez une commande pour continuer
```
# Explications

Tout à été dit dans l'exercice précédent !