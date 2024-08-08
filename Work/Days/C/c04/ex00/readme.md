# Énoncé

| Exercice : 00                   |
| ------------------------------- |
| ft_strlen                       |
| Dossier de rendu : ex00/        |
| Fichiers à rendre : ft_strlen.c |
| Fonctions Autorisées : Aucune   |
• Écrire une fonction qui compte le nombre de caractères dans une chaîne de carac-
tères et qui retourne le nombre trouvé.
• Elle devra être prototypée de la façon suivante :
```C
int ft_strlen(char *str);
```
# Correction

```C
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(char *str)
{
	printf("\nStr : {%s}\nSize : {%d}\n", str, ft_strlen(str));
}

int	main(void)
{
	test("Coucou");
	test("");
	test("42");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c04/ex00  (main) $ norminette -RCheckForbiddenSourceHeader ft_strlen.c 
ft_strlen.c: Error!
Error: INCLUDE_START_FILE   (line:  23, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c04/ex00  (main) $ gcc -Wall -Wextra -Werror ft_strlen.c 
Repo Git : Practice42/Work/C/c04/ex00  (main) $ ./a.out 

Str : {Coucou}
Size : {6}

Str : {}
Size : {0}

Str : {42}
Size : {2}
Repo Git : Practice42/Work/C/c04/ex00  (main) $ 
```
# Explications

### Spécifications
- **Entrée :** `char *str` représente un pointeur vers le premier caractère d'une chaîne de caractères terminée par un caractère nul (`\0`).
- **Sortie :** La fonction retourne un entier (`int`), qui est la longueur de la chaîne, c'est-à-dire le nombre de caractères précédant le caractère nul.

### Algorithmique
1. **Initialisation :** 
   - Une variable entière `i` est initialisée à zéro. Elle sert de compteur pour le nombre de caractères dans la chaîne.

2. **Traitement :**
   - La boucle `while` vérifie la condition `*str++`. Cette condition effectue deux opérations :
     - Elle évalue le caractère actuel pointé par `str`.
     - Elle incrémente le pointeur `str` pour pointer vers le caractère suivant après chaque évaluation.
   - La condition de la boucle continue tant que le caractère évalué est différent de `\0` (le caractère de fin de chaîne). À chaque itération valide (c'est-à-dire chaque fois que le caractère n'est pas `\0`), le compteur `i` est incrémenté de 1.

3. **Terminaison :**
   - Dès que le caractère nul (`\0`) est rencontré, la condition de la boucle devient fausse, ce qui met fin à la boucle.
   - La fonction renvoie la valeur de `i`, qui représente maintenant le nombre total de caractères dans la chaîne sans inclure le caractère nul.

Cet algorithme est efficace car il parcourt la chaîne une seule fois, caractère par caractère, jusqu'à atteindre le caractère nul, et utilise un simple compteur pour déterminer la longueur de la chaîne.