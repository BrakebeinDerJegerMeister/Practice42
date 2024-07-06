# Énoncé

| Exercice : 00                   |
| ------------------------------- |
| ft_strcmp                       |
| Dossier de rendu : ex00/        |
| Fichiers à rendre : ft_strcmp.c |
| Fonctions Autorisées : Aucune   |
• Reproduire à l’identique le fonctionnement de la fonction strcmp (man strcmp).
• Elle devra être prototypée de la façon suivante :
```C
int ft_strcmp(char *s1, char *s2);
```
# Correction

```C
int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (1)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 < c2)
			return (-1);
		if (c1 > c2)
			return (1);
		if (c1 == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
}
```
# Démonstration

```C
#include <stdio.h>

void	test(char *s1, char *s2)
{
	int	res;

	res = ft_strcmp(s1, s2);
	printf("%s\n%s\n", s1, s2);
	if (res == 0)
	{
		printf("Chaîne 1 = Chaîne 2");
	}
	else if (res > 0)
	{
		printf("Chaîne 1 > Chaîne 2");
	}
	else
	{
		printf("Chaîne 1 < Chaîne 2");
	}
	printf("\n");
}

int	main(void)
{
	test("Super test 1", "Super test 2");
	test("Super test 3", "Super test");
	test("Super test", "Super test");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c03/ex00  (main) $ norminette -RCheckForbiddenSourceHeader ft_strcmp.c 
ft_strcmp.c: Error!
Error: INCLUDE_START_FILE   (line:  34, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c03/ex00  (main) $ gcc -Wall -Wextra -Werror ft_strcmp.c 
Repo Git : Practice42/Work/C/c03/ex00  (main) $ ./a.out 
Super test 1
Super test 2
Chaîne 1 < Chaîne 2
Super test 3
Super test
Chaîne 1 > Chaîne 2
Super test
Super test
Chaîne 1 = Chaîne 2
Repo Git : Practice42/Work/C/c03/ex00  (main) $ 
```
# Explications

### Fonction `ft_strcmp`

#### Prototype
```c
int ft_strcmp(char *s1, char *s2);
```

#### Description
La fonction `ft_strcmp` compare deux chaînes de caractères `s1` et `s2` et retourne un entier selon le résultat de la comparaison lexicographique :

- Retourne `-1` si `s1` est inférieure à `s2`.
- Retourne `1` si `s1` est supérieure à `s2`.
- Retourne `0` si les deux chaînes sont égales.

#### Paramètres
- `char *s1` : Pointeur vers la première chaîne de caractères.
- `char *s2` : Pointeur vers la deuxième chaîne de caractères.

#### Valeurs de Retour
- `-1` : La première chaîne est lexicographiquement inférieure à la deuxième.
- `1` : La première chaîne est lexicographiquement supérieure à la deuxième.
- `0` : Les deux chaînes sont identiques.

#### Implémentation
```c
int	ft_strcmp(char *s1, char *s2)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (1)
	{
		c1 = s1[i];
		c2 = s2[i];
		if (c1 < c2)
			return (-1);
		if (c1 > c2)
			return (1);
		if (c1 == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
}
```

#### Explication du Code

1. **Initialisation des Variables** :
   - `int i = 0` : Initialisation de l'index à 0 pour parcourir les caractères des chaînes.
   - `char c1` et `char c2` : Variables pour stocker les caractères actuels des chaînes `s1` et `s2`.

2. **Boucle Infinie** :
   - La boucle `while (1)` est une boucle infinie qui sera interrompue par les instructions `return`.

3. **Comparaison des Caractères** :
   - `c1 = s1[i];` et `c2 = s2[i];` : Récupération des caractères actuels de `s1` et `s2` respectivement.
   - `if (c1 < c2)` : Si le caractère de `s1` est inférieur à celui de `s2`, la fonction retourne `-1`.
   - `if (c1 > c2)` : Si le caractère de `s1` est supérieur à celui de `s2`, la fonction retourne `1`.
   - `if (c1 == '\0' && s2[i] == '\0')` : Si les deux caractères sont le caractère nul (`'\0'`), cela signifie que les deux chaînes sont égales et la fonction retourne `0`.

4. **Incrémentation de l'Index** :
   - `i++` : Passage au caractère suivant des chaînes.

#### Remarques
- La fonction compare les chaînes de caractères caractère par caractère jusqu'à trouver une différence ou jusqu'à ce que les deux chaînes se terminent par le caractère nul (`'\0'`).
- Cette implémentation est similaire à la fonction standard `strcmp` de la bibliothèque C standard, mais elle utilise une boucle infinie avec des retours explicites pour chaque cas de comparaison.
