# Énoncé

| Exercice : 05                    |
| -------------------------------- |
| ft_strlcat                       |
| Dossier de rendu : ex05/         |
| Fichiers à rendre : ft_strlcat.c |
| Fonctions Autorisées : Aucune    |
• Reproduire à l’identique le fonctionnement de la fonction strlcat (man strlcat).
• Elle devra être prototypée de la façon suivante :
```C
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
```
# Correction

```C
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && dest_len + i < size -1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + src_len);
}
```
# Démonstration

```C
#include <stdio.h>
#include <string.h>

void	test(char *dest, char *src, unsigned int size)
{
	printf("\nTaille du tampon : {%u}\n", size);
	printf("dest : {%s} - %lu\n", dest, strlen(dest));
	printf("src : {%s} - %lu\n", src, strlen(src));
	printf("Résultat : {%u}\n", ft_strlcat(dest, src, size));
	printf("dest : {%s} - %lu\n", dest, strlen(dest));
}

int	main(void)
{
	char	s1[50] = "Ceci est un ";
	char	s2[13] = "Voici";
	char	s3[50] = "Encore un test";
	char	s4[50] = "";

	test(s1, "test", 16);
	test(s2, " un autre test", 9);
	test(s3, "", 6);
	test(s4, "Test final", 0);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c03/ex05  (main) $ norminette -RCheckForbiddenSourceHeader ft_strlcat.c 
ft_strlcat.c: Error!
Error: INCLUDE_START_FILE   (line:  37, col:   1):	Include must be at the start of file
Error: INCLUDE_START_FILE   (line:  38, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  51, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  52, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  53, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  54, col:  20):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c03/ex05  (main) $ gcc -Wall -Wextra -Werror ft_strlcat.c 
Repo Git : Practice42/Work/C/c03/ex05  (main) $ ./a.out 

Taille du tampon : {16}
dest : {Ceci est un } - 12
src : {test} - 4
Résultat : {16}
dest : {Ceci est un tes} - 15

Taille du tampon : {9}
dest : {Voici} - 5
src : { un autre test} - 14
Résultat : {19}
dest : {Voici un} - 8

Taille du tampon : {6}
dest : {Encore un test} - 14
src : {} - 0
Résultat : {6}
dest : {Encore un test} - 14

Taille du tampon : {0}
dest : {} - 0
src : {Test final} - 10
Résultat : {10}
dest : {} - 0
Repo Git : Practice42/Work/C/c03/ex05  (main) $ 
```
# Explications
La fonction `ft_strlcat`, est conçue pour concaténer des chaînes de caractères de manière sécurisée. Cette fonction fait partie de la librairie C et est souvent utilisée pour éviter les débordements de tampon, un problème commun en C lorsque l'on manipule des chaînes de caractères. Voici une explication détaillée de chaque partie du code :

1. **Déclaration de la fonction** :
   ```c
   unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
   ```
   La fonction prend en paramètres deux chaînes de caractères `dest` (destination) et `src` (source), ainsi qu'un entier non signé `size` qui représente la taille totale du tampon `dest` (y compris le caractère nul de fin).

2. **Initialisation des variables** :
   ```c
   unsigned int	i;
   unsigned int	dest_len;
   unsigned int	src_len;
   ```
   Trois variables sont déclarées pour stocker les indices et les longueurs des chaînes.

3. **Calcul de la longueur de `dest`** :
   ```c
   dest_len = 0;
   while (dest[dest_len] != '\0')
       dest_len++;
   ```
   Cette boucle calcule la longueur de la chaîne `dest`, excluant le caractère nul final.

4. **Calcul de la longueur de `src`** :
   ```c
   src_len = 0;
   while (src[src_len] != '\0')
       src_len++;
   ```
   De manière similaire, cette boucle calcule la longueur de `src`.

5. **Vérification de la taille du tampon `dest`** :
   ```c
   if (size <= dest_len)
       return (size + src_len);
   ```
   Si la taille donnée `size` est inférieure ou égale à la longueur de `dest`, la fonction retourne immédiatement la somme de `size` et de la longueur de `src`. Cela indique qu'aucune concaténation n'est possible car le tampon `dest` ne dispose pas d'espace suffisant même pour ajouter un seul caractère de `src`.

6. **Concaténation des chaînes** :
   ```c
   i = 0;
   while (src[i] != '\0' && dest_len + i < size - 1)
   {
       dest[dest_len + i] = src[i];
       i++;
   }
   ```
   Cette boucle concatène `src` à la fin de `dest`. Elle s'arrête soit lorsque tous les caractères de `src` ont été parcourus, soit lorsque l'espace restant dans `dest` est épuisé (en laissant de la place pour le caractère nul final).

7. **Terminaison de la chaîne `dest`** :
   ```c
   dest[i + dest_len] = '\0';
   ```
   Un caractère nul est ajouté à la fin de la chaîne `dest` pour s'assurer qu'elle soit correctement terminée.

8. **Retour de la nouvelle longueur de `dest`** :
   ```c
   return (dest_len + src_len);
   ```
   La fonction retourne la somme des longueurs de `dest` et `src`, ce qui représente la longueur totale que `dest` aurait si il y avait suffisamment d'espace pour concaténer `src` en entier.
