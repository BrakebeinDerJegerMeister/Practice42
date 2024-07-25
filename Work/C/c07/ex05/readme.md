# Énoncé

| Exercice : 05                  |
| ------------------------------ |
| ft_split                       |
| Dossier de rendu : ex05/       |
| Fichiers à rendre : ft_split.c |
| Fonctions Autorisées : malloc  |
• Écrire une fonction qui découpe une chaîne de caractères en fonction d’une autre
chaîne de caractères.
• Il faudra utiliser chaque caractère de la chaine charset comme séparateur.
• La fonction renvoie un tableau où chaque élément de celui ci contient l’adresse
d’une chaîne de caractères comprise entre deux séparateur. Le dernier élement du
tableau devra être égal à 0 pour marquer la fin du tableau.
• Il ne doit pas y avoir de chaîne vide dans votre tableau. Tirez-en les conclusions
qui s’imposent.
• La chaîne qui sera transmise ne sera pas modifiable.
• Elle devra être prototypée de la façon suivante :
```C
char **ft_split(char *str, char *charset);
```
# Correction

```C
#include <stdlib.h>

int	get_strpos(char *str, char *to_find)
{
	int	i;
	int	j;
	int	is_good;

	if (*to_find == '\0')
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (to_find[j] != '\0')
		{
			is_good = 1;
			if (str[i + j] == '\0' || str[i + j] != to_find[j])
			{
				is_good = 0;
				break ;
			}
			j++;
		}
		if (is_good)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	mystrcpy(char **str, char *from, int len)
{
	int	i;

	*str = (char *)malloc(len + 1);
	(*str)[len] = '\0';
	i = 0;
	while (i < len)
	{
		(*str)[i] = from[i];
		i++;
	}
}

void	next(char *str, char *charset, int count, char ***array)
{
	int	cpos;
	int	clen;
	int	slen;

	cpos = get_strpos(str, charset);
	clen = ft_strlen(charset);
	if (cpos == 0)
		next(str + clen, charset, count, array);
	else if (cpos > 0)
	{
		next(str + cpos + clen, charset, count + 1, array);
		mystrcpy(&(*array)[count], str, cpos);
	}
	else if (*str && cpos == -1)
	{
		slen = ft_strlen(str);
		next(str + slen, charset, count + 1, array);
		mystrcpy(&(*array)[count], str, slen);
	}
	if (*str == '\0' && cpos == -1)
	{
		*array = (char **)malloc((count + 1) * 8);
		(*array)[count] = NULL;
	}
	return ;
}

char	**ft_split(char *str, char *charset)
{
	char	**array;

	next(str, charset, 0, &array);
	return (array);
}
```
# Algorithme

# Démonstration

```C
#include <stdio.h>

void	test(char *str, char *charset)
{
	char	**tab;
	int		i;

	tab = ft_split(str, charset);
	if (!tab)
		return ;
	i = 0;
	printf("====================\n");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("====================\n\n");
}

int	main(void)
{
	test("aaa--456f----hheh--tjjjjjm--oyyyyo", "--");
	test("012301456045600789f0ffzt0hrtjj00jrj000", "0");
	return (0);
}
```

```
ft_split.c: Error!
Error: INCLUDE_START_FILE   (line: 105, col:   1):	Include must be at the start of file
Error: TOO_MANY_FUNCS       (line: 107, col:   1):	Too many functions in file
Error: TOO_MANY_FUNCS       (line: 127, col:   1):	Too many functions in file

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer
====================
aaa
456f
hheh
tjjjjjm
oyyyyo
====================

====================
123
1456
456
789f
ffzt
hrtjj
jrj
====================


Appuyez sur ENTRÉE ou tapez une commande pour continuer
```
# Explications

Le code implémente une fonction `ft_split` qui divise une chaîne de caractères en un tableau de sous-chaînes, en utilisant une autre chaîne spécifiée comme séparateur. Voici une explication de haut niveau de l'algorithme utilisé :

### Algorithme de la fonction `ft_split`

1. **Initialisation** :
   - La fonction `ft_split` est appelée avec deux arguments : `str` (la chaîne à diviser) et `charset` (la chaîne utilisée comme séparateur).
   - La fonction commence par appeler `next` pour traiter la chaîne.

2. **Fonction `next`** :
   - `next` est une fonction récursive qui divise la chaîne `str` en utilisant le séparateur `charset`.
   - Elle prend en entrée la chaîne à traiter, le séparateur, un compteur `count` qui garde la trace du nombre de sous-chaînes trouvées, et un pointeur vers le tableau de chaînes.

3. **Traitement récursif** :
   - La position du séparateur dans la chaîne actuelle est trouvée en utilisant `get_strpos`.
   - Si le séparateur est trouvé au début de la chaîne, la fonction saute ce séparateur et rappelle `next` sur la sous-chaîne restante.
   - Si le séparateur est trouvé ailleurs que au début, la sous-chaîne avant le séparateur est copiée dans le tableau (utilisant `mystrcpy`), et `next` est rappelée sur le reste de la chaîne après le séparateur.
   - Si le séparateur n'est pas trouvé (`cpos == -1`) et que la chaîne n'est pas vide, la totalité de la chaîne restante est considérée comme une sous-chaîne finale et copiée dans le tableau.

4. **Terminaison de la récursivité** :
   - Lorsque la chaîne d'entrée est vide (`*str == '\0'`), la fonction `next` alloue de la mémoire pour le tableau de pointeurs basé sur le nombre de sous-chaînes trouvées (`count`).
   - Un pointeur `NULL` est ajouté à la fin du tableau pour marquer la fin du tableau de chaînes.

5. **Retour du résultat** :
   - Une fois la récursivité complète et le tableau de chaînes correctement peuplé, `ft_split` renvoie le tableau.

### Remarques

- L'algorithme emploie une récursivité pour parcourir la chaîne d'entrée et identifier les sous-chaînes, en s'appuyant sur des fonctions auxiliaires pour trouver la position du séparateur et copier des sous-chaînes.
- La gestion de la mémoire est critique ici, notamment l'allocation dynamique pour chaque sous-chaîne et pour le tableau de pointeurs lui-même. Cette gestion doit être effectuée avec précaution pour éviter les fuites de mémoire ou les erreurs d'accès.