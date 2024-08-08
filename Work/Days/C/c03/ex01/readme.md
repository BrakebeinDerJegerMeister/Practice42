# Énoncé

| Exercice : 01                    |
| -------------------------------- |
| ft_strncmp                       |
| Dossier de rendu : ex01/         |
| Fichiers à rendre : ft_strncmp.c |
| Fonctions Autorisées : Aucune    |
• Reproduire à l’identique le fonctionnement de la fonction strncmp (man strncmp).
• Elle devra être prototypée de la façon suivante :
```C
int ft_strncmp(char *s1, char *s2, unsigned int n);
```
# Correction

```C
int	ft_strcmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	char			c1;
	char			c2;

	i = 0;
	while (i < n)
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
	return (0);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(char *s1, char *s2, unsigned int n)
{
	int	res;

	res = ft_strcmp(s1, s2, n);
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
	test("Super test 1", "Super test 2", 10);
	test("Super test 3", "Super test", 11);
	test("Super test", "Super test", 30);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c03/ex01  (main) $ norminette -RCheckForbiddenSourceHeader ft_strncmp.c 
ft_strncmp.c: Error!
Error: INCLUDE_START_FILE   (line:  35, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c03/ex01  (main) $ gcc -Wall -Wextra -Werror ft_strncmp.c 
Repo Git : Practice42/Work/C/c03/ex01  (main) $ ./a.out 
Super test 1
Super test 2
Chaîne 1 = Chaîne 2
Super test 3
Super test
Chaîne 1 > Chaîne 2
Super test
Super test
Chaîne 1 = Chaîne 2
Repo Git : Practice42/Work/C/c03/ex01  (main) $ 
```
# Explications

### Fonction `ft_strncmp`

#### Prototype
```c
int ft_strncmp(char *s1, char *s2, unsigned int n);
```

#### Description
La fonction `ft_strncmp` compare les `n` premiers caractères de deux chaînes de caractères `s1` et `s2`. Elle retourne un entier selon le résultat de la comparaison lexicographique :

- Retourne `-1` si `s1` est lexicographiquement inférieure à `s2` dans les `n` premiers caractères.
- Retourne `1` si `s1` est lexicographiquement supérieure à `s2` dans les `n` premiers caractères.
- Retourne `0` si les `n` premiers caractères des deux chaînes sont identiques.

#### Paramètres
- `char *s1` : Pointeur vers la première chaîne de caractères.
- `char *s2` : Pointeur vers la deuxième chaîne de caractères.
- `unsigned int n` : Nombre maximal de caractères à comparer.

#### Valeurs de Retour
- `-1` : La première chaîne est lexicographiquement inférieure à la deuxième dans les `n` premiers caractères.
- `1` : La première chaîne est lexicographiquement supérieure à la deuxième dans les `n` premiers caractères.
- `0` : Les `n` premiers caractères des deux chaînes sont identiques.

#### Implémentation
```c
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int i;
    char c1;
    char c2;

    i = 0;
    while (i < n)
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
    return (0);
}
```

#### Explication du Code

1. **Initialisation des Variables** :
   - `unsigned int i = 0` : Initialisation de l'index à 0 pour parcourir les caractères des chaînes.
   - `char c1` et `char c2` : Variables pour stocker les caractères actuels des chaînes `s1` et `s2`.

2. **Boucle de Comparaison** :
   - La boucle continue tant que `i` est inférieur à `n`.
   - `c1 = s1[i]` et `c2 = s2[i]` : Récupération des caractères actuels de `s1` et `s2` respectivement.
   - `if (c1 < c2)` : Si le caractère de `s1` est inférieur à celui de `s2`, la fonction retourne `-1`.
   - `if (c1 > c2)` : Si le caractère de `s1` est supérieur à celui de `s2`, la fonction retourne `1`.
   - `if (c1 == '\0' && s2[i] == '\0')` : Si les deux caractères sont le caractère nul (`'\0'`), cela signifie que les deux chaînes sont égales jusqu'à ce point et la fonction retourne `0`.

3. **Incrémentation de l'Index** :
   - `i++` : Passage au caractère suivant des chaînes.

4. **Retour par Défaut** :
   - Si aucune différence n'est trouvée dans les `n` premiers caractères, retourne `0`.

#### Cas Spécifique : `n` plus grand que les chaînes
Si `n` est plus grand que la longueur des deux chaînes, la comparaison s'arrêtera lorsque le caractère nul (`'\0'`) sera atteint dans l'une des chaînes.
