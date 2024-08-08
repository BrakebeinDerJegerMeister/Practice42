# Énoncé

| Exercice : 00                    |
| -------------------------------- |
| ft_putchar                       |
| Dossier de rendu : ex00/         |
| Fichiers à rendre : ft_putchar.c |
| Fonctions Autorisées : write     |
• Écrire une fonction qui affiche le caractère passé en paramètre.
• Elle devra être prototypée de la façon suivante :
```C
void ft_putchar(char c);
```
Pour afficher le caractère, vous devez utiliser la fonction write de la manière
suivante.
```C
write(1, &c, 1);
```

# Correction

```C
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```
# Démonstration

```C
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	ft_putchar('a');
	ft_putchar('b');
	ft_putchar('\n');
	return (0);
}
```


```
Repo Git : Practice42/Work/C/c00/ex00  (main) $ norminette -RCheckForbiddenSourceHeader ft_putchar.c 
ft_putchar.c: OK!
Repo Git : Practice42/Work/C/c00/ex00  (main) $ gcc ft_putchar.c 
Repo Git : Practice42/Work/C/c00/ex00  (main) $ ./a.out 
ab
Repo Git : Practice42/Work/C/c00/ex00  (main) $ 
```
# Explications

### Prototype de la fonction

```c
void ft_putchar(char c);
```

- **`void`**: Ce mot clé indique que la fonction ne renvoie aucune valeur.
- **`ft_putchar`**: Nom de la fonction, typique des conventions de nommage dans certains projets C, où `ft_` est souvent préfixe pour indiquer "fonction". Cela aide à éviter les conflits de noms avec les fonctions standard de la bibliothèque C.
- **`(char c)`**: Liste des paramètres de la fonction. `char c` signifie que la fonction prend un seul paramètre nommé `c` de type `char`, qui est un type de données utilisé pour stocker un caractère unique.

### Corps de la fonction

```c
{
    write(1, &c, 1);
}
```

- **`write`**: Il s'agit d'une fonction système définie dans la bibliothèque `<unistd.h>`. Elle est utilisée pour écrire des données dans des fichiers ou des descripteurs de fichiers. La fonction `write` a trois paramètres :
  - **`1`**: Le premier paramètre de `write` est le descripteur de fichier où écrire. Ici, `1` représente la sortie standard (stdout), qui est typiquement la console ou le terminal. En C, `0` est l'entrée standard (stdin), `1` est la sortie standard, et `2` est la sortie d'erreur standard (stderr).
  - **`&c`**: Le deuxième paramètre est un pointeur vers les données à écrire. Ici, `&c` est l'adresse de `c`, ce qui signifie que `write` écrit le caractère stocké à cette adresse. Le `&` est un opérateur qui obtient l'adresse d'une variable, donc `&c` donne l'adresse de la variable `c`.
  - **`1`**: Le troisième paramètre spécifie le nombre d'octets à écrire. Comme `char` est typiquement de taille 1 octet, passer `1` indique que `write` doit écrire un octet à partir de l'adresse fournie, qui est le contenu de `c`.