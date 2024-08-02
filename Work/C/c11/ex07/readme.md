# Énoncé

| Exercice : 07                                     |
| ------------------------------------------------- |
| ft_advanced_sort_string_tab                       |
| Dossier de rendu : ex07/                          |
| Fichiers à rendre : ft_advanced_sort_string_tab.c |
| Fonctions Autorisées : Aucune                     |
• Écrire la fonction ft_advanced_sort_string_tab qui trie, en fonction du retour
de la fonction passée en paramètre
• Le tri s’effectuera en échangeant les pointeurs du tableau.
• tab sera terminé par un pointeur nul
• Elle devra être prototypée de la façon suivante :
```C
void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));
```
# Correction

```C
void	ft_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		j;
	char	*comp;

	i = 1;
	while (tab[i - 1] && tab[i])
	{
		comp = tab[i];
		j = i - 1;
		while (j >= 0 && cmp(comp, tab[j]) < 0)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		if (j < i - 1)
			tab[j + 1] = comp;
		i++;
	}
}
```
# Démonstration

```C
#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	print_tab(char **tab)
{
	printf("Tab :\n");
	while (*tab)
	{
		printf("- %s\n", *tab++);
	}
	printf("\n");
}

int	main(void)
{
	char	*tab[5] = {"Lion", "Chaton", "Chat", "Kangourou", NULL};

	print_tab(tab);
	ft_sort_string_tab(tab, ft_strcmp);
	print_tab(tab);
}
```

```
ft_advanced_sort_string_tab.c: Error!
Error: INCLUDE_START_FILE   (line:  35, col:   1):	Include must be at the start of file
Error: INCLUDE_START_FILE   (line:  36, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  62, col:  21):	Declaration and assignation on a single line

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer
Tab :
- Lion
- Chaton
- Chat
- Kangourou

Tab :
- Chat
- Chaton
- Kangourou
- Lion


Appuyez sur ENTRÉE ou tapez une commande pour continuer
```
# Explications

Franchement si vous êtes arrivé à ce niveau il n'y a pas besoin d'explications....
