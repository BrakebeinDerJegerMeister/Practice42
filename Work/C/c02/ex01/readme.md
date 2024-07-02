# Énoncé

| Exercice : 01                    |
| -------------------------------- |
| ft_strncpy                       |
| Dossier de rendu : ex01/         |
| Fichiers à rendre : ft_strncpy.c |
| Fonctions Autorisées : Aucune    |
• Reproduire à l’identique le fonctionnement de la fonction strncpy (man strncpy).
• Elle devra être prototypée de la façon suivante :
char
```
*ft_strncpy(char *dest, char *src, unsigned int n);
```
# Correction

```C
char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	char	*save;

	save = dest;
	while (n-- && *src)
	{
		*dest++ = *src++;
	}
	n++;
	while (n--)
	{
		*dest++ = '\0';
	}
	return (save);
}
```

# Démonstration

```C
#include <unistd.h>

char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	char	*save;

	save = dest;
	while (n-- && *src)
	{
		*dest++ = *src++;
		write(1, "~", 1);
	}
	n++;
	while (n--)
	{
		*dest++ = '\0';
		write(1, ".", 1);
	}
	write(1, "\n", 1);
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
	char	src1[] = "Hello 42";
	char	dest1[15];
	char	*res1;
	char	src2[] = "Hello 42";
	char	dest2[15];
	char	*res2;

	ft_putstr(src1);
	write(1, "\n", 1);
	res1 = ft_strncpy(dest1, src1, 12);
	ft_putstr(dest1);
	write(1, "\n", 1);
	ft_putstr(res1);
	write(1, "\n", 1);

	ft_putstr(src2);
	write(1, "\n", 1);
	res2 = ft_strncpy(dest2, src2, 5);
	dest2[5] = '\0';
	ft_putstr(dest2);
	write(1, "\n", 1);
	ft_putstr(res2);
	write(1, "\n", 1);
}
```

```
Repo Git : Practice42/Work/C/c02/ex01  (main *) $ norminette -RCheckForbiddenSourceHeader ft_strncpy.c 
ft_strncpy.c: Error!
Error: DECL_ASSIGN_LINE     (line:  46, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  49, col:  20):	Declaration and assignation on a single line
Error: TOO_MANY_VARS_FUNC   (line:  51, col:   1):	Too many variables declarations in a function
Error: EMPTY_LINE_FUNCTION  (line:  60, col:   1):	Empty line in function
Repo Git : Practice42/Work/C/c02/ex01  (main *) $ gcc -Wall -Wextra -Werror ft_strncpy.c 
Repo Git : Practice42/Work/C/c02/ex01  (main *) $ ./a.out 
Hello 42
~~~~~~~~....
Hello 42
Hello 42
Hello 42
~~~~~
Hello
Hello
Repo Git : Practice42/Work/C/c02/ex01  (main *) $ 
```
# Explications

#### Description
La fonction `ft_strncpy` copie jusqu'à `n` caractères de la chaîne source (`src`) vers la chaîne destination (`dest`). Si la longueur de la chaîne source est inférieure à `n`, les caractères restants dans la chaîne destination sont remplis avec des zéros (`\0`). Cette fonction est une version personnalisée de la fonction standard `strncpy`.

#### Paramètres
- `char *dest` : Un pointeur vers la chaîne de destination où les caractères de la source seront copiés.
- `const char *src` : Un pointeur vers la chaîne source qui sera copiée.
- `unsigned int n` : Le nombre maximum de caractères à copier de la source à la destination.

#### Valeur de Retour
- Retourne un pointeur vers la chaîne de destination (`dest`).

#### Fonctionnement
1. **Sauvegarde de l'adresse de destination :**
   ```c
   char *save
   save = dest;
   ```
   - Un pointeur (`save`) est utilisé pour sauvegarder l'adresse de départ de la chaîne de destination. Cela permet de retourner l'adresse de départ à la fin de la fonction.

2. **Copie des caractères de la source vers la destination :**
   ```c
   while (n-- && *src)
   {
       *dest++ = *src++;
   }
   ```
   - Cette boucle copie les caractères de `src` à `dest` jusqu'à ce que `n` atteigne zéro ou que la fin de `src` soit atteinte (`*src` devient nul).

3. **Réinitialisation de `n` pour le remplissage avec des caractères nuls :**
   ```c
   n++;
   ```
   - Cette ligne ajuste `n` pour compenser la décrémentation finale de la boucle précédente.

4. **Remplissage avec des caractères nuls :**
   ```c
   while (n--)
   {
       *dest++ = '\0';
   }
   ```
   - Si `src` est plus courte que `n`, les caractères restants dans `dest` sont remplis avec des zéros (`\0`). Cela garantit que la chaîne destination est toujours correctement terminée.

5. **Retour de l'adresse de départ de `dest` :**
   ```c
   return save;
   ```
   - La fonction retourne l'adresse initiale de `dest`, permettant à l'appelant de manipuler facilement la chaîne copiée.

#### Précautions et Conseils
- **Prévoir un caractère de plus :**
  - Lorsque vous utilisez `ft_strncpy`, assurez-vous que le tableau de destination a suffisamment d'espace pour contenir `n` caractères plus le caractère de terminaison nul (`\0`). Par exemple, si vous souhaitez copier une chaîne de longueur 5, allouez un tableau de 6 caractères.

  ```c
  char src[] = "Hello";
  char dest[6]; // 5 caractères pour "Hello" + 1 pour '\0'

  ft_strncpy(dest, src, 5);
  ```

  - Si le tableau de destination ne prévoit pas ce caractère supplémentaire, il pourrait en résulter des erreurs de chaîne non terminée, entraînant des comportements indéterminés lors de la manipulation de la chaîne.

En suivant ces explications et précautions, vous pouvez utiliser `ft_strncpy` de manière sécurisée et efficace, garantissant que vos chaînes de caractères sont correctement copiées et terminées.