# Énoncé

| Exercice : 04                   |
| ------------------------------- |
| ft_strstrv                      |
| Dossier de rendu : ex04/        |
| Fichiers à rendre : ft_strstr.c |
| Fonctions Autorisées : Aucune   |
• Reproduire à l’identique le fonctionnement de la fonction strstr (man strstr).
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strstr(char *str, char *to_find);
```
# Correction

```C
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	is_good;

	if (*to_find == '\0')
		return (str);
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
			return (str + i);
		i++;
	}
	return ((void *)0);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(char *dest, char *to_find)
{
	printf("\ndest : %s\nto find : %s\n", dest, to_find);
	printf("ret : {%s}\n\n", ft_strstr(dest, to_find));
}

int	main(void)
{
	test("Ma phrase de test", "Ma super recherche trop grande");
	test("Ma phrase de test", "phrase");
	test("Ma phrase de test", "");
	test("Ma phrase de test", "recherche");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c03/ex04  (main) $ norminette -RCheckForbiddenSourceHeader ft_strstr.c 
ft_strstr.c: Error!
Error: INCLUDE_START_FILE   (line:  44, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c03/ex04  (main) $ gcc -Wall -Wextra -Werror ft_strstr.c 
Repo Git : Practice42/Work/C/c03/ex04  (main) $ ./a.out 

dest : Ma phrase de test
to find : Ma super recherche trop grande
ret : {(null)}


dest : Ma phrase de test
to find : phrase
ret : {phrase de test}


dest : Ma phrase de test
to find : 
ret : {Ma phrase de test}


dest : Ma phrase de test
to find : recherche
ret : {(null)}

Repo Git : Practice42/Work/C/c03/ex04  (main) $ 
```
# Explications

Points clés :

1. **Vérification de la chaîne vide** : Si `to_find` est vide, la fonction retourne directement le pointeur vers le début de `str`.
2. **Boucle principale** : Itère sur chaque caractère de `str`.
3. **Boucle interne** : Compare les caractères de `to_find` avec ceux de `str` à partir de la position actuelle.
4. **Initialisation de `is_good`** : Avant de commencer à comparer, `is_good` est mis à 1 et sera mis à 0 si une différence est trouvée.
5. **Retour du pointeur** : Si `is_good` reste 1 après la boucle interne, cela signifie que `to_find` a été trouvé, et la fonction retourne un pointeur vers le début de cette occurrence dans `str`.
6. **Retour NULL** : Si la sous-chaîne `to_find` n'est pas trouvée, la fonction retourne `NULL`.
