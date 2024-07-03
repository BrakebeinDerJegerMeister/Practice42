# Énoncé

| Exercice : 08                       |
| ----------------------------------- |
| ft_strlowcase                       |
| Dossier de rendu : ex08/            |
| Fichiers à rendre : ft_strlowcase.c |
| Fonctions Autorisées : Aucune       |
• Écrire une fonction qui met en minuscule chaque lettre.
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strlowcase(char *str);
```
• Elle devra renvoyer str.
# Correction

```C
char	*ft_strlowcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
		{
			str[i] = c + 32;
		}
		i++;
	}
	return (str);
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
	char	*ret;

	ft_putstr(str);
	write(1, "\n", 1);
	ret = ft_strlowcase(str);
	ft_putstr(ret);
	write(1, "\n", 1);
}

int	main(void)
{
	char	str1[] = "__ SUpeR TesT __";
	char	str2[] = "Un autre TEST ** 0123";

	test(str1);
	test(str2);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex08  (main) $ norminette -RCheckForbiddenSourceHeader ft_strlowcase.c 
ft_strlowcase.c: Error!
Error: INCLUDE_START_FILE   (line:  31, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  55, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  56, col:  20):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c02/ex08  (main) $ gcc -Wall -Wextra -Werror ft_strlowcase.c 
Repo Git : Practice42/Work/C/c02/ex08  (main) $ ./a.out 
__ SUpeR TesT __
__ super test __
Un autre TEST ** 0123
un autre test ** 0123
Repo Git : Practice42/Work/C/c02/ex08  (main) $ 
```
# Explications

En ASCII, la différence entre une lettre majuscule (A-Z) et la lettre minuscule correspondante (a-z) est de 32. Pour chaque lettre de l'alphabet anglais, vous pouvez convertir une majuscule en minuscule en ajoutant 32 à son code ASCII, et vous pouvez convertir une minuscule en majuscule en soustrayant 32 de son code ASCII.

Par exemple :
- Le code ASCII de 'A' est 65 et celui de 'a' est 97.
- Le code ASCII de 'Z' est 90 et celui de 'z' est 122.

La formule pour convertir une majuscule en minuscule est donc `char minuscule = majuscule + 32;` et pour convertir une minuscule en majuscule, `char majuscule = minuscule - 32;`.