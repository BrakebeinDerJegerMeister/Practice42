# Énoncé

| Exercice : 03                    |
| -------------------------------- |
| ft_strjoin                       |
| Dossier de rendu : ex03/         |
| Fichiers à rendre : ft_strjoin.c |
| Fonctions Autorisées : malloc    |
• Écrire une fonction qui va concatener l’ensemble des chaîne de caractères pointées par strs en les séparants à l’aide de sep.
• size représente la taille de strs.
• Si size vaut 0, il faut retourner une chaîne de caractères vide que l’on peut free().
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strjoin(int size, char **strs, char *sep);
```
# Correction

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

int	get_full_size(int size, char **strs, char *sep)
{
	int	i;
	int	sz;

	sz = 0;
	i = 0;
	while (i < size)
	{
		sz += ft_strlen(strs[i]);
		if (i > 0)
			sz += ft_strlen(sep);
		i++;
	}
	return (sz);
}

void	fast_strcpy(char **dest, char *src)
{
	while (*src)
	{
		**dest = *src;
		(*dest)++;
		src++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*tmp;
	int		sz;
	int		i;

	sz = 0;
	if (size > 0)
		sz = get_full_size(size, strs, sep);
	res = (char *)malloc(sz + 1);
	tmp = res;
	if (size > 0)
	{
		i = -1;
		while (++i < size)
		{
			fast_strcpy(&res, strs[i]);
			if (i < size - 1)
				fast_strcpy(&res, sep);
		}
	}
	*res = '\0';
	return (tmp);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int size, char **strs, char *sep)
{
	char	*res;

	res = ft_strjoin(size, strs, sep);
	printf("\nres : {%s}\n", res);
	free(res);
}

int	main(void)
{
	char *t1[] = {"aaa", "b", "cccc", "dd", "e"};
	char *t2[] = {"Miaou"};

	test(5, t1, "--");
	test(0, t1, "_");
	test(1, t2, " ");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c07/ex03  (main *) $ norminette -RCheckForbiddenSourceHeader ft_strjoin.c 
ft_strjoin.c: Error!
Error: INCLUDE_START_FILE   (line:  78, col:   1):	Include must be at the start of file
Error: TOO_MANY_FUNCS       (line:  89, col:   1):	Too many functions in file
Error: SPACE_REPLACE_TAB    (line:  91, col:   9):	Found space when expecting tab
Error: DECL_ASSIGN_LINE     (line:  91, col:  16):	Declaration and assignation on a single line
Error: SPACE_REPLACE_TAB    (line:  92, col:   9):	Found space when expecting tab
Error: DECL_ASSIGN_LINE     (line:  92, col:  16):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c07/ex03  (main *) $ gcc -Wall -Wextra -Werror ft_strjoin.c 
Repo Git : Practice42/Work/C/c07/ex03  (main *) $ ./a.out 

res : {aaa--b--cccc--dd--e}

res : {}

res : {Miaou}
Repo Git : Practice42/Work/C/c07/ex03  (main *) $ 
```
# Explications

### Fonctionnement Général
Le programme est conçu pour concaténer un ensemble de chaînes de caractères, stockées dans un tableau, en une seule chaîne, en les séparant par un séparateur spécifique. Ce processus nécessite le calcul de la taille totale nécessaire pour stocker la chaîne résultante, l'allocation de cette mémoire, la copie des chaînes individuelles dans ce nouvel espace, suivie de l'insertion du séparateur entre les chaînes.

### Utilisation des Pointeurs
Les pointeurs jouent un rôle crucial dans ce programme, notamment dans la manière dont ils sont manipulés pour copier des chaînes et avancer dans la mémoire allouée.

1. **Pointeurs pour Accéder aux Chaînes** :
   - Chaque chaîne du tableau est accédée via un pointeur. Chaque élément du tableau `strs` est un pointeur vers une chaîne de caractères (`char*`).

2. **Pointeur `res` pour Stocker le Résultat** :
   - Un pointeur `res` est utilisé pour référencer le début de la zone de mémoire allouée pour stocker la chaîne finale. Ce pointeur est crucial car il représente l'adresse initiale de la mémoire où la concaténation des chaînes va être stockée.

3. **Avancement du Pointeur `res`** :
   - Un aspect intéressant du programme est la façon dont le pointeur `res` est avancé à mesure que les chaînes sont copiées. Chaque fois qu'une chaîne est copiée dans la mémoire allouée, le pointeur `res` est déplacé pour pointer à l'endroit juste après le dernier caractère inséré.
   - Cela est essentiel pour éviter d'écraser les données déjà copiées et pour s'assurer que le prochain segment de texte (la prochaine chaîne ou le séparateur) est ajouté au bon endroit.

4. **Pointeur Temporaire `tmp`** :
   - Un pointeur temporaire `tmp` est utilisé pour garder une trace du début de la mémoire allouée. Comme `res` est modifié (déplacé vers l'avant) pendant la copie des chaînes, `tmp` sert à retenir l'adresse originale de la mémoire allouée pour pouvoir retourner cette adresse à la fin de la fonction et pour la gestion de la mémoire (par exemple, pour libérer la mémoire).

### Rappel sur les Pointeurs
Les pointeurs permettent de manipuler directement les adresses mémoire, ce qui est crucial pour des opérations de bas niveau comme la manipulation de chaînes en C. Avancer un pointeur tout en conservant une référence à son adresse originale est une technique couramment utilisée pour construire efficacement des chaînes de caractères en évitant la surcharge associée à des opérations plus complexes ou redondantes.