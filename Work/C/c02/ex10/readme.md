# Énoncé

| Exercice : 10                    |
| -------------------------------- |
| ft_strlcpy                       |
| Dossier de rendu : ex10/         |
| Fichiers à rendre : ft_strlcpy.c |
| Fonctions Autorisées : Aucune    |
• Reproduire à l’identique le fonctionnement de la fonction strlcpy (man strlcpy).
• Elle devra être prototypée de la façon suivante :
```C
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
```
# Correction

```C
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		if (i < (size - 1))
			dest[i] = src[i];
		i++;
	}
	dest[size - 1] = '\0';
	return (i);
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

void	nextnumber(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
	write(1, &disp, 1);
}

int	main(void)
{
	char	str1[] = "Exemple vraiment parfait";
	char	dst1[30];
	int		res1;
	char	str2[] = "Autre";
	char	dst2[30];
	int		res2;

	ft_putstr(str1);
	write(1, "\n", 1);
	res1 = ft_strlcpy(dst1, str1, 10);
	ft_putstr(dst1);
	write(1, "\n", 1);
	nextnumber(res1);
	write(1, "\n", 1);

	ft_putstr(str2);
	write(1, "\n", 1);
	res2 = ft_strlcpy(dst2, str2, 10);
	ft_putstr(dst2);
	write(1, "\n", 1);
	nextnumber(res2);
	write(1, "\n", 1);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex10  (main *) $ norminette -RCheckForbiddenSourceHeader ft_strlcpy.c 
ft_strlcpy.c: Error!
Error: INCLUDE_START_FILE   (line:  30, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  58, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  61, col:  20):	Declaration and assignation on a single line
Error: TOO_MANY_VARS_FUNC   (line:  63, col:   1):	Too many variables declarations in a function
Error: EMPTY_LINE_FUNCTION  (line:  72, col:   1):	Empty line in function
Repo Git : Practice42/Work/C/c02/ex10  (main *) $ gcc -Wall -Wextra -Werror ft_strlcpy.c 
Repo Git : Practice42/Work/C/c02/ex10  (main *) $ ./a.out 
Exemple vraiment parfait
Exemple v
24
Autre
Autre
5
Repo Git : Practice42/Work/C/c02/ex10  (main *) $ 
```
# Explications

La fonction `ft_strlcpy` est une implémentation personnalisée de la fonction standard `strlcpy` utilisée pour copier une chaîne de caractères d'une source (`src`) vers une destination (`dest`) en respectant une limite spécifiée par `size`. 

### Objectif
`ft_strlcpy` vise à copier une chaîne de la source vers la destination de manière sécurisée, en évitant les débordements de tampon et en garantissant que la chaîne de destination est toujours terminée par un caractère nul, même si la chaîne source est plus longue que la taille allouée pour la destination.

### Fonctionnement

1. **Vérification de la taille nulle** :
   - Avant de commencer la copie, la fonction vérifie si `size` est égal à 0. Si c'est le cas, cela signifie qu'aucun espace n'est disponible pour la copie, et la fonction retourne immédiatement 0. Cela prévient toute modification de la chaîne de destination qui pourrait mener à des erreurs si l'espace alloué est insuffisant.

2. **Initialisation et copie conditionnelle** :
   - La fonction initialise un compteur `i` à 0 pour suivre le nombre de caractères copiés.
   - Elle entre ensuite dans une boucle qui parcourt chaque caractère de `src` jusqu'à ce qu'elle rencontre le caractère nul, marquant la fin de la chaîne source.
   - À chaque itération, elle vérifie si `i` est inférieur à `size - 1`. Cette condition permet de s'assurer qu'il y a suffisamment d'espace dans `dest` pour inclure le caractère courant et le caractère nul final.
   - Si la condition est vraie, le caractère à l'index `i` de `src` est copié à l'index `i` de `dest`.

3. **Terminaison de la chaîne de destination** :
   - Indépendamment du résultat de la boucle, la fonction s'assure que le dernier caractère dans `dest`, à l'index `size - 1`, est mis à `\0`. Cela garantit que même si la chaîne source est tronquée, la chaîne de destination ne présentera pas de risques de débordement de tampon lorsqu'elle est utilisée ultérieurement.

4. **Retour de la fonction** :
   - La fonction retourne la valeur de `i`, qui représente le nombre total de caractères parcourus dans `src`. Cela peut être utile pour déterminer si la chaîne a été entièrement copiée ou non.

### Conclusion

`ft_strlcpy` est une fonction de copie de chaînes conçue pour la sécurité et la robustesse. Elle évite les erreurs communes liées à la manipulation de chaînes en C, telles que les débordements de tampon, en garantissant que la chaîne de destination est toujours correctement terminée. Cette approche est particulièrement importante dans les environnements où la validité et l'intégrité des données sont critiques.