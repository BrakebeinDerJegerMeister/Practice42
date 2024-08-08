# Énoncé

| Exercice : 03                           |
| --------------------------------------- |
| ft_str_is_numeric                       |
| Dossier de rendu : ex03/                |
| Fichiers à rendre : ft_str_is_numeric.c |
| Fonctions Autorisées : Aucune           |
• Écrire une fonction qui renvoie 1 si la chaîne passée en paramètre ne contient que
des chiffres et renvoie 0 si la chaîne passée en paramètre contient d’autres types
de caractères.
• Elle devra être prototypée de la façon suivante :
```
int ft_str_is_numeric(char *str);
```
• Elle devra renvoyer 1 si str est une chaîne vide.
# Correction

```C
int	ft_str_is_numeric(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c >= '0' && c <= '9'))
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

int	main(void)
{
	int	is1;
	int	is2;

	is1 = ft_str_is_numeric("9011110");
	is2 = ft_str_is_numeric("12309a");
	if (is1)
		write(1, "Oui\n", 4);
	else
		write(1, "Non\n", 4);
	if (is2)
		write(1, "Oui\n", 4);
	else
		write(1, "Non\n", 4);
}
```

```
Repo Git : Practice42/Work/C/c02/ex03  (main) $ norminette -RCheckForbiddenSourceHeader ft_str_is_numeric.c 
ft_str_is_numeric.c: Error!
Error: INCLUDE_START_FILE   (line:  31, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c02/ex03  (main) $ gcc -Wall -Wextra -Werror ft_str_is_numeric.c 
Repo Git : Practice42/Work/C/c02/ex03  (main) $ ./a.out 
Oui
Non
Repo Git : Practice42/Work/C/c02/ex03  (main) $ 
```
# Explications

Pas d'explications particulières, voir ex02 (c02) c'est le même principe.