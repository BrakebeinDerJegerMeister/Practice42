# Énoncé

| Exercice : 05                             |
| ----------------------------------------- |
| ft_str_is_uppercase                       |
| Dossier de rendu : ex05/                  |
| Fichiers à rendre : ft_str_is_uppercase.c |
| Fonctions Autorisées : Aucune             |
• Écrire une fonction qui renvoie 1 si la chaîne passée en paramètre ne contient
que des caractères alphabétiques majuscules et renvoie 0 si la chaîne passée en
paramètre contient d’autres types de caractères.
• Elle devra être prototypée de la façon suivante :
```
int ft_str_is_uppercase(char *str);
```
• Elle devra renvoyer 1 si str est une chaîne vide.
# Correction

```C
int	ft_str_is_uppercase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c >= 'A' && c <= 'Z'))
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

	ret = ft_str_is_uppercase(str);
	ft_putstr(str);
	if (ret)
		write(1, "\nOui\n", 5);
	else
		write(1, "\nNon\n", 5);
}

int	main(void)
{
	test("aiZERTbrh");
	test("ABCEZ");
	test("EFGH_");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex05  (main +) $ norminette -RCheckForbiddenSourceHeader ft_str_is_upper_case.c 
ft_str_is_upper_case.c: Error!
Error: INCLUDE_START_FILE   (line:  31, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c02/ex05  (main +) $ gcc -Wall -Wextra -Werror ft_str_is_upper_case.c 
Repo Git : Practice42/Work/C/c02/ex05  (main +) $ ./a.out 
aiZERTbrh
Non
ABCEZ
Oui
EFGH_
Non
Repo Git : Practice42/Work/C/c02/ex05  (main +) $ 
```
# Explications

Voir exercice précédent, pas de difficulté particulière