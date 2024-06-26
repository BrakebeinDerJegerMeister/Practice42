# Énoncé

| Exercice : 03                          |
| -------------------------------------- |
| ft_print_numbers                       |
| Dossier de rendu : ex03/               |
| Fichiers à rendre : ft_print_numbers.c |
| Fonctions Autorisées : write           |
• Écrire une fonction qui affiche tous les chiffres sur une seule ligne, dans l’ordre
croissant.
• Elle devra être prototypée de la façon suivante :
```
void ft_print_numbers(void);
```
# Correction

```C
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}

```

# Démonstration

```C
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}

int	main(void)
{
	ft_print_numbers();
}
```


```
Repo Git : Practice42/Work/C/c00/ex03  (main) $ norminette -RCheckForbiddenSourceHeader ft_print_numbers.c 
ft_print_numbers.c: OK!
Repo Git : Practice42/Work/C/c00/ex03  (main) $ gcc ft_print_numbers.c 
Repo Git : Practice42/Work/C/c00/ex03  (main) $ ./a.out 
0123456789Repo Git : Practice42/Work/C/c00/ex03  (main) $ 
```

# Explications

Cette fonction utilise une boucle pour itérer sur les chiffres de '0' à '9' et les affiche sur la sortie standard. Elle est implémentée en C et démontre l'utilisation de la boucle `while` et la fonction système `write` pour les opérations de sortie.
### Fonctionnement détaillé

#### Déclaration et Initialisation

- **`char c;`** : Déclaration d'une variable `c` de type `char`. Cette variable est utilisée pour stocker le caractère courant (chiffre) à afficher.

- **`c = '0';`** : Initialisation de la variable `c` à '0', qui est le premier chiffre à afficher.

#### Boucle while

- **`while (c <= '9')`** : La condition de la boucle spécifie que tant que `c` est inférieur ou égal à '9', la boucle doit continuer à s'exécuter. Cela garantit que tous les chiffres de '0' à '9' sont couverts.

#### Corps de la boucle

- **`write(1, &c, 1);`** : Appel à la fonction `write` pour écrire le caractère stocké dans `c` sur la sortie standard, qui est typiquement le terminal.
  - **`1`** : Le premier argument indique le descripteur de fichier pour la sortie standard. En C, `STDOUT_FILENO` est souvent utilisé pour améliorer la lisibilité.
  - **`&c`** : Le deuxième argument est l'adresse de la variable `c`, fournissant ainsi à `write` l'emplacement de la donnée à écrire.
  - **`1`** : Le troisième argument spécifie le nombre d'octets à écrire, qui est ici de 1 octet, car un `char` en C est généralement de taille 1 octet.

- **`c++;`** : Incrémentation de `c` pour passer au chiffre suivant dans l'ordre ASCII. Cela change `c` de '0' à '1', puis à '2', et ainsi de suite jusqu'à '9'.
