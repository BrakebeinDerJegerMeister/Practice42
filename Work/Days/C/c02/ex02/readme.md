# Énoncé

| Exercice : 02                         |
| ------------------------------------- |
| ft_str_is_alpha                       |
| Dossier de rendu : ex02/              |
| Fichiers à rendre : ft_str_is_alpha.c |
| Fonctions Autorisées : Aucune         |
• Écrire une fonction qui renvoie 1 si la chaîne passée en paramètre ne contient que
des caractères alphabétiques et renvoie 0 si la chaîne passée en paramètre contient
d’autres types de caractères.
• Elle devra être prototypée de la façon suivante :
```
int ft_str_is_alpha(char *str);
```
• Elle devra renvoyer 1 si str est une chaîne vide.
# Correction

```C
int	ft_str_is_alpha(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
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

	is1 = ft_str_is_alpha("BlaBla");
	is2 = ft_str_is_alpha("aaaabbaA_");
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
Repo Git : Practice42/Work/C/c02/ex02  (main *) $ norminette -RCheckForbiddenSourceHeader ft_str_is_alpha.c 
ft_str_is_alpha.c: Error!
Error: INCLUDE_START_FILE   (line:  31, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c02/ex02  (main *) $ gcc -Wall -Wextra -Werror ft_str_is_alpha.c
Repo Git : Practice42/Work/C/c02/ex02  (main *) $ ./a.out 
Oui
Non
Repo Git : Practice42/Work/C/c02/ex02  (main *) $ 
```
# Explications

**But :**
La fonction `ft_str_is_alpha` vérifie si tous les caractères d'une chaîne de caractères (`str`) sont des lettres alphabétiques (a-z, A-Z). Si c'est le cas, elle renvoie `1`, sinon elle renvoie `0`.

**Fonctionnement :**
1. **Boucle de Parcours :**
   - La fonction utilise une boucle `while` pour parcourir chaque caractère de la chaîne jusqu'à rencontrer le caractère nul (`'\0'`), qui marque la fin de la chaîne.
   ```c
   while (str[i] != '\0')
   ```

2. **Vérification du Caractère :**
   - Pour chaque caractère, il est stocké dans la variable `c`.
   - La fonction vérifie ensuite si `c` est une lettre alphabétique :
     - `(c >= 'a' && c <= 'z')` pour vérifier si `c` est une lettre minuscule.
     - `(c >= 'A' && c <= 'Z')` pour vérifier si `c` est une lettre majuscule.
   - L'opérateur logique `||` (OU) est utilisé pour indiquer que `c` peut être soit une lettre majuscule, soit une lettre minuscule.
   - Si `c` n'est pas une lettre alphabétique, la fonction renvoie immédiatement `0`, il est inutile de tester les caractères suivants.
   ```c
   c = str[i];
   if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
   {
       return (0);
   }
   ```

3. **Incrémentation de l'Index :**
   - Si le caractère est alphabétique, l'index est incrémenté pour passer au caractère suivant.
   ```c
   i++;
   ```

4. **Retour du Résultat :**
   - Si tous les caractères de la chaîne sont alphabétiques, la fonction retourne `1` après la boucle.
   ```c
   return (1);
   ```
