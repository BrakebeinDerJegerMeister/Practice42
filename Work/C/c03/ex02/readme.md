# Énoncé

| Exercice : 02                   |
| ------------------------------- |
| ft_strcat                       |
| Dossier de rendu : ex02/        |
| Fichiers à rendre : ft_strcat.c |
| Fonctions Autorisées : Aucune   |
• Reproduire à l’identique le fonctionnement de la fonction strcat (man strcat).
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strcat(char *dest, char *src);
```
# Correction

```C
char	*ft_strcat(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (save);
}

```
# Démonstration

```C
#include <stdio.h>

void	test(char *dest, char *src)
{
	printf("dest : %s\nsrc : %s\n", dest, src);
	printf("%s\n", ft_strcat(dest, src));
}

int	main(void)
{
	char	s1[50] = "Ceci est un ";
	char	s2[50] = "Voici";
	char	s3[50] = "Encore un test";
	char	s4[50] = "";

	test(s1, "test");
	test(s2, " un autre test");
	test(s3, "");
	test(s4, "Test final");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c03/ex02  (main) $ norminette -RCheckForbiddenSourceHeader ft_strcat.c 
ft_strcat.c: Error!
Error: INCLUDE_START_FILE   (line:  26, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  36, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  37, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  38, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  39, col:  20):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c03/ex02  (main) $ gcc -Wall -Wextra -Werror ft_strcat.c 
Repo Git : Practice42/Work/C/c03/ex02  (main) $ ./a.out 
dest : Ceci est un 
src : test
Ceci est un test
dest : Voici
src :  un autre test
Voici un autre test
dest : Encore un test
src : 
Encore un test
dest : 
src : Test final
Test final
Repo Git : Practice42/Work/C/c03/ex02  (main) $ 
```
# Explications

### Fonction `ft_strcat`

#### Prototype
```c
char *ft_strcat(char *dest, char *src);
```

#### Description
La fonction `ft_strcat` concatène la chaîne `src` à la fin de la chaîne `dest`. La chaîne de destination `dest` doit être suffisamment grande pour contenir le résultat final, y compris le caractère nul (`'\0').

#### Paramètres
- **`char *dest`** : Pointeur vers la chaîne de destination, où `src` sera ajoutée.
- **`char *src`** : Pointeur vers la chaîne source qui sera ajoutée à la fin de `dest`.

#### Valeur de Retour
- Retourne un pointeur vers la chaîne de destination `dest`.

#### Implémentation

```c
char *ft_strcat(char *dest, char *src)
{
    char *save;

    save = dest;
    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = '\0';
    return (save);
}
```

### Explication du Code

1. **Déclaration de la Variable `save`** :
   - `char *save;` : Déclare un pointeur `save` pour conserver l'adresse de début de la chaîne `dest`.
   - `save = dest;` : Initialise `save` avec l'adresse de `dest`.

2. **Avancer jusqu'à la Fin de `dest`** :
   - `while (*dest) dest++;` : Cette boucle parcourt `dest` jusqu'à atteindre le caractère nul (`'\0') qui marque la fin de la chaîne. À ce point, `dest` pointe sur le caractère nul à la fin de la chaîne.

3. **Copier les Caractères de `src` à `dest`** :
   - `while (*src) *dest++ = *src++;` : Cette boucle copie les caractères de `src` à `dest`. Chaque caractère de `src` est assigné à la position actuelle de `dest`, puis les pointeurs `dest` et `src` sont incrémentés.

4. **Ajouter le Caractère Nul de Fin** :
   - `*dest = '\0';` : Après la copie des caractères de `src`, un caractère nul (`'\0') est ajouté à la fin de la chaîne résultante pour marquer la fin de la chaîne.

5. **Retourner le Pointeur Initial de `dest`** :
   - `return (save);` : La fonction retourne le pointeur `save`, qui pointe toujours vers le début de la chaîne `dest`.

### Points Clés
- **Précondition** : La chaîne de destination `dest` doit avoir assez d'espace pour contenir la chaîne `src` après la concaténation.
- **Postcondition** : La chaîne de destination `dest` contient la chaîne source `src` ajoutée à sa fin, et la chaîne résultante est terminée par un caractère nul (`'\0').