# Énoncé

| Exercice : 06                             |
| ----------------------------------------- |
| ft_str_is_printable                       |
| Dossier de rendu : ex06/                  |
| Fichiers à rendre : ft_str_is_printable.c |
| Fonctions Autorisées : Aucune             |
• Écrire une fonction qui renvoie 1 si la chaîne passée en paramètre ne contient que
des caractères affichables et renvoie 0 si la chaîne passée en paramètre contient
d’autres types de caractères.
• Elle devra être prototypée de la façon suivante :
```C
int ft_str_is_printable(char *str);
```
• Elle devra renvoyer 1 si str est une chaîne vide.
# Correction

```C
int	ft_str_is_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!(c > 31 && c < 127))
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

	ret = ft_str_is_printable(str);
	ft_putstr(str);
	if (ret)
		write(1, "\nOui\n", 5);
	else
		write(1, "\nNon\n", 5);
}

int	main(void)
{
	test("~~~ Bienvenue @ chez 42 ~~~");
	test("\x07Alerte système! \x02Gestion\x03.");
	test("Mise à jour \x1Brequise\x1C immédiatement!");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex06  (main) $ norminette -RCheckForbiddenSourceHeader ft_str_is_printable.c 
ft_str_is_printable.c: Error!
Error: INCLUDE_START_FILE   (line:  31, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c02/ex06  (main) $ gcc -Wall -Wextra -Werror ft_str_is_printable.c 
Repo Git : Practice42/Work/C/c02/ex06  (main) $ ./a.out 
~~~ Bienvenue @ chez 42 ~~~
Oui
zlerte système! Gestion.
Non
Mise à jour equise immédiatement!
Non
Repo Git : Practice42/Work/C/c02/ex06  (main) $ 
```
# Explications

La fonction `ft_str_is_printable` vérifie si tous les caractères d'une chaîne en C sont imprimables. Elle prend en argument un pointeur `str` vers une chaîne de caractères et retourne `1` si tous les caractères sont imprimables, sinon `0`.

Dans le corps de la fonction :

1. **Initialisation** : Une variable d'indice `i` est initialisée à 0 pour parcourir la chaîne caractère par caractère.
2. **Boucle** : Une boucle `while` continue tant que le caractère courant `str[i]` n'est pas le caractère nul (`'\0'`), qui marque la fin de la chaîne.
3. **Vérification** : À chaque itération, le caractère courant est stocké dans la variable `c`. La condition `if (!(c > 31 && c < 127))` vérifie si le caractère n'est pas dans la plage des caractères imprimables ASCII (codes 32 à 126 inclus). Si un caractère est trouvé hors de cette plage, la fonction retourne immédiatement `0`.
4. **Fin de boucle** : Si la boucle termine sans rencontrer de caractère non imprimable, la fonction retourne `1`, indiquant que la chaîne est entièrement composée de caractères imprimables.

Les caractères non imprimables dans ce contexte sont donc ceux ayant un code ASCII en dehors de l'intervalle [32, 126], incluant les caractères de contrôle (codes 0 à 31) et le caractère DEL (code 127). Ces caractères peuvent perturber l'affichage ou le traitement de textes, d'où l'utilité de cette fonction pour garantir que des chaînes contiennent uniquement des caractères adéquats pour l'affichage.