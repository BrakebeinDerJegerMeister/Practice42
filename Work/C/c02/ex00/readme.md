# Énoncé

| Exercice : 00                   |
| ------------------------------- |
| ft_strcpy                       |
| Dossier de rendu : ex00/        |
| Fichiers à rendre : ft_strcpy.c |
| Fonctions Autorisées : Aucune   |
• Reproduire à l’identique le fonctionnement de la fonction strcpy (man strcpy).
• Elle devra être prototypée de la façon suivante :
char
```
*ft_strcpy(char *dest, char *src);
```
# Correction

```C
char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (save);
}

```
# Démonstration

```C
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (save);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	main(void)
{
	char	src[] = "Hello 42";
	char	dest[9];
	char	*res;

	ft_putstr(src);
	write(1, "\n", 1);
	res = ft_strcpy(dest, src);
	ft_putstr(dest);
	write(1, "\n", 1);
	ft_putstr(res);
	write(1, "\n", 1);
}
```

```
Repo Git : Practice42/Work/C/c02/ex00  (main) $ norminette -RCheckForbiddenSourceHeader ft_strcpy.c 
ft_strcpy.c: Error!
Error: DECL_ASSIGN_LINE     (line:  39, col:  19):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c02/ex00  (main) $ gcc -Wall -Wextra -Werror ft_strcpy.c 
Repo Git : Practice42/Work/C/c02/ex00  (main) $ ./a.out 
Hello 42
Hello 42
Hello 42
Repo Git : Practice42/Work/C/c02/ex00  (main) $ 
```
# Explications
La fonction `ft_strcpy` est une implémentation personnalisée de la fonction standard `strcpy` en C, utilisée pour copier la chaîne de caractères source `src` vers la destination `dest`. Cette fonction assure que la chaîne de caractères `src` est entièrement copiée dans `dest`, incluant le caractère de terminaison nul (`'\0'`), qui marque la fin d'une chaîne en C. 
### Signature de la fonction
```c
char	*ft_strcpy(char *dest, char *src)
```
- **char \*dest** : Pointeur vers le tableau de caractères (chaîne) où `src` doit être copiée.
- **char \*src** : Pointeur vers la chaîne de caractères source à copier dans `dest`.
- **Retour** : Renvoie un pointeur vers la chaîne de destination (`dest`).

### Corps de la fonction
```c
char	*save;
```
- **save** : Variable de type pointeur `char` utilisée pour sauvegarder l'adresse initiale de `dest`. Cela permet de retourner le début de la chaîne de destination après la copie.

```c
save = dest;
```
- Cette ligne assigne l'adresse initiale de `dest` à `save`. Cela est nécessaire pour que, après la modification de `dest` pendant la copie, vous puissiez toujours retourner l'adresse originale de la chaîne destination.

```c
while (*src)
{
	*dest++ = *src++;
}
```
- **Boucle while** : Continue tant que le caractère pointé par `src` n'est pas le caractère nul (`'\0'`).
- **\*dest++ = \*src++** : Copie le caractère actuellement pointé par `src` dans la position actuelle pointée par `dest`, puis incrémente les deux pointeurs (`dest` et `src`). Cela déplace les pointeurs vers le prochain caractère dans leurs chaînes respectives. La boucle s'arrête quand elle atteint le caractère nul de `src`, qui n'est pas copié par cette portion de la boucle.

```c
*dest = '\0';
```
- Cette ligne ajoute manuellement le caractère nul à la fin de la chaîne `dest` pour s'assurer qu'elle est correctement terminée comme une chaîne C valide. Ceci est crucial car les chaînes en C doivent être terminées par un caractère nul pour que d'autres fonctions standard travaillant sur des chaînes puissent identifier leur fin.

```c
return (save);
```
- **return (save)** : Retourne le pointeur sauvegardé qui pointe vers le début de la chaîne de destination. Cela permet aux fonctions appelantes d'utiliser le résultat de `ft_strcpy` pour accéder à la chaîne complètement copiée.