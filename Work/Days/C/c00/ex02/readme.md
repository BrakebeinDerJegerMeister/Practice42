# Énoncé

| Exercice : 02                                   |
| ----------------------------------------------- |
| ft_print_reverse_alphabet                       |
| Dossier de rendu : ex02/                        |
| Fichiers à rendre : ft_print_reverse_alphabet.c |
| Fonctions Autorisées : write                    |
• Écrire une fonction qui affiche l’alphabet en minuscule sur une seule ligne, dans
l’ordre décroissant, à partir de la lettre ’z’.
• Elle devra être prototypée de la façon suivante :
```
void ft_print_reverse_alphabet(void);
```
# Correction

```C
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}
```

# Démonstration

```C
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}

int	main(void)
{
	ft_print_reverse_alphabet();
}

```


```
Repo Git : Practice42/Work/C/c00/ex02  (main) $ norminette -RCheckForbiddenSourceHeader ft_print_reverse_alphabet.c 
ft_print_reverse_alphabet.c: OK!
Repo Git : Practice42/Work/C/c00/ex02  (main) $ gcc ft_print_reverse_alphabet.c 
Repo Git : Practice42/Work/C/c00/ex02  (main) $ ./a.out 
zyxwvutsrqponmlkjihgfedcbaRepo Git : Practice42/Work/C/c00/ex02  (main) $ 
```

# Explications

La fonction `ft_print_reverse_alphabet`illustre une implémentation pour afficher l'alphabet anglais en ordre décroissant (de 'z' à 'a') en utilisant des opérations bas niveau avec la fonction système `write` :

### Inclusion de la bibliothèque

```c
#include <unistd.h>
```
Cette directive préprocesseur inclut l'en-tête `unistd.h`, qui est essentiel pour l'accès à la déclaration de la fonction `write`. Cette fonction est fréquemment utilisée dans des contextes où les performances sont critiques et où un contrôle granulaire sur les E/S du fichier est nécessaire.

### Définition de la fonction

```c
void ft_print_reverse_alphabet(void);
```
La fonction est définie avec le type de retour `void`, signifiant qu'elle ne renvoie aucune valeur. Elle ne prend également aucun paramètre, comme indiqué par la liste de paramètres vide `void`.

### Corps de la fonction

```c
char c;

c = 'z';
while (c >= 'a')
{
    write(1, &c, 1);
    c--;
}
```

#### Déclaration et Initialisation
- **`char c;`** : Déclaration d'une variable locale `c` de type `char`, qui sera utilisée pour stocker les caractères de l'alphabet.
- **`c = 'z';`** : Initialisation de `c` avec 'z', le point de départ pour l'itération décroissante à travers l'alphabet.

#### Boucle while
- **`while (c >= 'a')`** : La boucle continue tant que `c` est supérieur ou égal à 'a', assurant ainsi que tous les caractères de 'z' à 'a' sont traités. Cette condition démontre l'utilisation d'une comparaison directe de caractères ASCII, exploitant le fait que les lettres minuscules sont séquentiellement ordonnées dans la table ASCII.

#### Corps de la boucle
- **`write(1, &c, 1);`** : Appel à la fonction `write` avec trois arguments :
  - **`1`** : Le descripteur de fichier pour la sortie standard. En C, `STDOUT_FILENO` pourrait être utilisé à la place du littéral `1` pour une meilleure lisibilité.
  - **`&c`** : Adresse de la variable `c`, passée à `write` pour indiquer où les données doivent être lues.
  - **`1`** : Nombre d'octets à écrire, qui est ici un seul octet, correspondant à la taille d'un caractère.
- **`c--;`** : Décrémentation de `c` pour passer au caractère précédent dans l'ordre ASCII. Cela modifie la valeur de `c` à chaque itération de la boucle, déplaçant progressivement l'affichage de 'z' à 'a'.

### Usage
La fonction est typiquement appelée dans un contexte où il est nécessaire de démontrer ou de tester des flux de caractères inverses, souvent utilisée dans des contextes éducatifs ou de débogage pour visualiser des comportements spécifiques des caractères ASCII.
