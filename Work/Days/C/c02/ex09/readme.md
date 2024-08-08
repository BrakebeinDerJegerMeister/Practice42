# Énoncé

| Exercice : 09                          |
| -------------------------------------- |
| ft_strcapitalize                       |
| Dossier de rendu : ex09/               |
| Fichiers à rendre : ft_strcapitalize.c |
| Fonctions Autorisées : Aucune          |
• Écrire une fonction qui met en majuscule la première lettre de chaque mot et le
reste du mot en minuscule.
• Un mot est une suite de caractères alphanumériques.
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strcapitalize(char *str);
```
• Elle devra renvoyer str.
• Par exemple :
```
salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
```
• Doit donner :
```
Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
```
# Correction

```C
char	*ft_strcapitalize(char *str)
{
	int		i;
	char	c;
	char	b;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (i > 0)
			b = str[i - 1];
		else
			b = ' ';
		if (b == ' ' || b == '+' || b == '-')
			if (c >= 'a' && c <= 'z')
				str[i] = c - 32;
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
	ret = ft_strcapitalize(str);
	ft_putstr(ret);
	write(1, "\n", 1);
}

int	main(void)
{
	char	str1[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	char	str2[] = "ceci est un autre essai";

	test(str1);
	test(str2);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex09  (main) $ norminette -RCheckForbiddenSourceHeader ft_strcapitalize.c 
ft_strcapitalize.c: Error!
Error: INCLUDE_START_FILE   (line:  35, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  59, col:  20):	Declaration and assignation on a single line
Error: LINE_TOO_LONG        (line:  59, col:  85):	line too long
Error: DECL_ASSIGN_LINE     (line:  60, col:  20):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c02/ex09  (main) $ gcc -Wall -Wextra -Werror ft_strcapitalize.c 
Repo Git : Practice42/Work/C/c02/ex09  (main) $ ./a.out 
salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un
Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un
ceci est un autre essai
Ceci Est Un Autre Essai
Repo Git : Practice42/Work/C/c02/ex09  (main) $
```
# Explications

La fonction `ft_strcapitalize` est conçue pour parcourir une chaîne de caractères donnée et transformer en majuscules la première lettre de chaque mot, tout en laissant les autres lettres inchangées. Voici une explication détaillée du raisonnement et du fonctionnement de cette fonction :

### Déclaration des Variables
- **`int i`** : Utilisée pour indexer et parcourir chaque caractère de la chaîne `str`.
- **`char c`** : Stocke le caractère courant de la chaîne lors de chaque itération de la boucle.
- **`char b`** : Stocke le caractère précédent dans la chaîne ou un espace `' '` si `i` est 0. Ceci est utilisé pour déterminer si le caractère courant `c` est le début d'un nouveau mot.

### Parcours de la Chaîne
- La boucle **`while`** continue tant que le caractère courant `str[i]` n'est pas le caractère nul (`'\0'`), ce qui marque la fin de la chaîne.

### Logique de Capitalisation
- À l'intérieur de la boucle, le caractère courant `c` est affecté à partir de `str[i]`.
- La variable `b` est définie en fonction de la position du caractère :
  - Si `i > 0`, cela signifie qu'il y a un caractère avant `c`, donc `b` prend la valeur de `str[i - 1]`.
  - Si `i == 0`, cela signifie que `c` est le premier caractère de la chaîne, donc `b` est défini à `' '` pour forcer la vérification si `c` est une lettre minuscule qui doit être convertie en majuscule.
  
### Conditions pour la Conversion en Majuscule
- La condition **`if (b == ' ' || b == '+' || b == '-')`** vérifie si le caractère précédent `b` est un espace, un plus `'+'`, ou un tiret `'-'`. Ces caractères sont considérés comme des délimiteurs de mots.
  - Si l'une de ces conditions est vraie, cela indique que le caractère courant `c` est le début d'un mot.
  - La condition imbriquée **`if (c >= 'a' && c <= 'z')`** vérifie ensuite si ce caractère courant est une lettre minuscule.
    - Si c'est le cas, le caractère est converti en majuscule en soustrayant 32 de sa valeur ASCII, ce qui est l'équivalent de `c - 32`.

### Incrémentation de l'Index
- **`i++`** : À la fin de chaque itération, l'index `i` est incrémenté pour passer au caractère suivant dans la chaîne.

### Retour de la Fonction
- Après avoir terminé la boucle, la fonction retourne le pointeur vers la chaîne originale `str`, qui a maintenant été modifiée pour que chaque mot commence par une majuscule, conformément aux règles définies.