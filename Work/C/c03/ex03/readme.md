# Énoncé

| Exercice : 03                    |
| -------------------------------- |
| ft_strncat                       |
| Dossier de rendu : ex03/         |
| Fichiers à rendre : ft_strncat.c |
| Fonctions Autorisées : Aucune    |
• Reproduire à l’identique le fonctionnement de la fonction strncat (man strncat).
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strncat(char *dest, char *src, unsigned int nb);
```
# Correction

```C
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*save;

	save = dest;
	while (*dest)
		dest++;
	while (*src && nb)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (save);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(char *dest, char *src, unsigned int nb)
{
	printf("dest : %s\nsrc : %s\n", dest, src);
	printf("res : {%s}\n", ft_strncat(dest, src, nb));
}

int	main(void)
{
	char	s1[50] = "Ceci est un ";
	char	s2[50] = "Voici";
	char	s3[50] = "Encore un test";
	char	s4[50] = "";

	test(s1, "test", 8);
	test(s2, " un autre test", 9);
	test(s3, "",6);
	test(s4, "Test final",0);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c03/ex03  (main) $ norminette -RCheckForbiddenSourceHeader ft_strnncat.c 
ft_strncat.c: Error!
Error: INCLUDE_START_FILE   (line:  29, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  39, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  40, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  41, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  42, col:  20):	Declaration and assignation on a single line
Error: SPC_AFTER_OPERATOR   (line:  46, col:  16):	missing space after operator
Error: SPC_AFTER_OPERATOR   (line:  47, col:  26):	missing space after operator
Repo Git : Practice42/Work/C/c03/ex03  (main) $ gcc -Wall -Wextra -Werror ft_strncat.c 
Repo Git : Practice42/Work/C/c03/ex03  (main) $ ./a.out 
dest : Ceci est un 
src : test
res : {Ceci est un test}
dest : Voici
src :  un autre test
res : {Voici un autre}
dest : Encore un test
src : 
res : {Encore un test}
dest : 
src : Test final
res : {}
Repo Git : Practice42/Work/C/c03/ex03  (main) $ 
```
# Explications

### Fonction `ft_strncat`

#### Prototype
```c
char *ft_strncat(char *dest, char *src, unsigned int nb);
```

#### Description
La fonction `ft_strncat` concatène au maximum `nb` caractères de la chaîne `src` à la fin de la chaîne `dest`. La chaîne de destination `dest` doit être suffisamment grande pour contenir le résultat final, y compris le caractère nul (`'\0'`).

#### Paramètres
- **`char *dest`** : Pointeur vers la chaîne de destination, où `src` sera ajoutée.
- **`char *src`** : Pointeur vers la chaîne source qui sera ajoutée à la fin de `dest`.
- **`unsigned int nb`** : Nombre maximal de caractères à copier de `src`.

#### Valeur de Retour
- Retourne un pointeur vers la chaîne de destination `dest`.

#### Implémentation

```c
char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    char *save;

    save = dest;
    while (*dest)
        dest++;
    while (*src && nb)
    {
        *dest++ = *src++;
        nb--;
    }
    *dest = '\0';
    return (save);
}
```

### Explication du Code

1. **Déclaration et Initialisation de `save`** :
   - `char *save;` : Déclare un pointeur `save` pour conserver l'adresse de début de la chaîne `dest`.
   - `save = dest;` : Initialise `save` avec l'adresse de `dest`.

2. **Avancer jusqu'à la Fin de `dest`** :
   - `while (*dest) dest++;` : Cette boucle parcourt `dest` jusqu'à atteindre le caractère nul (`'\0') qui marque la fin de la chaîne. À ce point, `dest` pointe sur le caractère nul à la fin de la chaîne.

3. **Copier les Caractères de `src` à `dest` avec Limitation de `nb`** :
   - `while (*src && nb)` : Cette boucle continue tant qu'il y a des caractères dans `src` et que `nb` n'est pas nul.
   - `*dest++ = *src++;` : Copie le caractère actuel de `src` à `dest`, puis avance les deux pointeurs.
   - `nb--;` : Décrémente le compteur `nb` à chaque itération.

4. **Ajouter le Caractère Nul de Fin** :
   - `*dest = '\0';` : Après la copie des caractères de `src`, un caractère nul (`'\0') est ajouté à la fin de la chaîne résultante pour marquer la fin de la chaîne.

5. **Retourner le Pointeur Initial de `dest`** :
   - `return (save);` : La fonction retourne le pointeur `save`, qui pointe toujours vers le début de la chaîne de destination `dest`.
