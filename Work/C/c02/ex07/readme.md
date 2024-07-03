# Énoncé

| Exercice : 07                      |
| ---------------------------------- |
| ft_strupcase                       |
| Dossier de rendu : ex07/           |
| Fichiers à rendre : ft_strupcase.c |
| Fonctions Autorisées : Aucune      |
• Écrire une fonction qui met en majuscule chaque lettre.
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strupcase(char *str);
```
• Elle devra renvoyer str.
# Correction

```C
char	*ft_strupcase(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= 'a' && c <= 'z')
		{
			str[i] = c - 32;
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
	ret = ft_strupcase(str);
	ft_putstr(ret);
	write(1, "\n", 1);
}

int	main(void)
{
	char	str1[] = "__ super Test __";
	char	str2[] = "Un autre test 0123";

	test(str1);
	test(str2);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex07  (main) $ norminette -RCheckForbiddenSourceHeader ft_strupcase.c 
ft_strupcase.c: Error!
Error: INCLUDE_START_FILE   (line:  31, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  55, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  56, col:  20):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c02/ex07  (main) $ gcc -Wall -Wextra -Werror ft_strupcase.c 
Repo Git : Practice42/Work/C/c02/ex07  (main) $ ./a.out 
__ super Test __
__ SUPER TEST __
Un autre test 0123
UN AUTRE TEST 0123
Repo Git : Practice42/Work/C/c02/ex07  (main) $ 
```
# Explications

### Processus de la fonction

1. **Initialisation** :
   - **`int i`** : Variable utilisée comme index pour parcourir chaque caractère de la chaîne. Initialisée à 0.
   - **`char c`** : Variable temporaire pour stocker chaque caractère de la chaîne au fur et à mesure que la boucle progresse.

2. **Parcours de la chaîne** :
   - Une boucle `while` est utilisée pour itérer sur chaque caractère de la chaîne jusqu'à atteindre le caractère nul (`'\0'`), qui marque la fin de la chaîne.

3. **Conversion de caractères** :
   - Dans chaque itération de la boucle, le caractère courant est récupéré dans `c`.
   - Une condition `if` vérifie si ce caractère est une lettre minuscule (`c >= 'a' && c <= 'z'`). Cette vérification utilise les valeurs ASCII des caractères pour déterminer si un caractère est une minuscule.
   - Si le caractère est une minuscule, il est converti en majuscule en soustrayant 32 de sa valeur ASCII. En ASCII, la différence entre les valeurs des lettres majuscules et minuscules est de 32. Ainsi, `c - 32` transforme une lettre minuscule en sa correspondante majuscule.

4. **Incrémentation de l'index** :
   - `i++` : L'index `i` est incrémenté pour passer au caractère suivant dans la chaîne.

5. **Retour de la fonction** :
   - Après avoir terminé la boucle (c'est-à-dire après avoir atteint le caractère nul de fin de chaîne), la fonction retourne le pointeur `str`. Ce pointeur pointe vers la chaîne modifiée qui contient désormais des majuscules là où il y avait des minuscules.
