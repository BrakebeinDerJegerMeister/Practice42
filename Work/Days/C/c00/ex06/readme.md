# Énoncé

| Exercice : 06                        |
| ------------------------------------ |
| ft_print_comb2                       |
| Dossier de rendu : ex06/             |
| Fichiers à rendre : ft_print_comb2.c |
| Fonctions Autorisées : write         |
• Écrire une fonction qui affiche toutes les différentes combinaisons de deux nombres
entre 0 et 99, dans l’ordre croissant.
• Cela donne quelque chose comme ça :
```
$>./a.out | cat -e
00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99$>
```
• Elle devra être prototypée de la façon suivante :
```
void ft_print_comb2(void);
```
# Correction

```C
#include <unistd.h>

void	print_combinaison(char n2d, char n2u, char n1d, char n1u)
{
	char	s;
	char	e;

	s = ',';
	e = ' ';
	write(1, &n2d, 1);
	write(1, &n2u, 1);
	write(1, &e, 1);
	write(1, &n1d, 1);
	write(1, &n1u, 1);
	if ((n2d != '9') || (n2u != '8') || (n1d != '9') || (n1u != '9'))
	{
		write(1, &s, 1);
		write(1, &e, 1);
	}
}

void	compute(char n2d, char n2u, char n1d, char n1u)
{
	while ((n2d < '9') || (n2u <= '8'))
	{
		if (n2u > '9')
		{
			n2u = '0';
			n2d++;
		}
		n1d = n2d;
		n1u = n2u + 1;
		while ((n1d < '9') || (n1u <= '9'))
		{
			if (n1u > '9')
			{
				n1u = '0';
				n1d++;
			}
			print_combinaison(n2d, n2u, n1d, n1u);
			n1u++;
		}
		n2u++;
	}
}

void	ft_print_comb2(void)
{
	char	n2d;
	char	n2u;
	char	n1d;
	char	n1u;

	n2d = '0';
	n2u = '0';
	compute(n2d, n2u, n1d, n1u);
}
```
# Algorithme

### Fonction `print_combinaison`
Cette fonction prend quatre caractères (`n2d`, `n2u`, `n1d`, `n1u`) représentant deux paires de chiffres. Elle les écrit sur la sortie standard (stdout), avec une espace entre les deux paires, suivie d'une virgule et d'un espace si la combinaison n'est pas "98 99".

- **Paramètres** :
  - `n2d` : Dizaine de la première paire.
  - `n2u` : Unité de la première paire.
  - `n1d` : Dizaine de la deuxième paire.
  - `n1u` : Unité de la deuxième paire.
- **Traitement** :
  - Affiche la première paire de chiffres.
  - Affiche un espace.
  - Affiche la deuxième paire de chiffres.
  - Si ce n'est pas la dernière paire (98 99), affiche une virgule suivie d'un espace.

### Fonction `compute`
Cette fonction génère toutes les combinaisons possibles de deux paires de chiffres et les passe à la fonction `print_combinaison`.

- **Paramètres initiaux** :
  - `n2d`, `n2u` : Commencent à '0', représentent la première paire.
  - `n1d`, `n1u` : Calculés à partir de `n2d` et `n2u` pour assurer que la deuxième paire est toujours après la première.
- **Boucles imbriquées** :
  - La boucle externe contrôle `n2d` et `n2u`.
  - À chaque itération de `n2u`, la boucle interne génère `n1d` et `n1u` de sorte que `n1d n1u` soit toujours plus grand que `n2d n2u`.
  - Les chiffres sont incrémentés, et si `n1u` ou `n2u` dépasse '9', ils sont réinitialisés à '0' et le chiffre des dizaines (`n1d` ou `n2d`) est incrémenté.

### Fonction `ft_print_comb2`
Cette fonction initialise les quatre variables de caractères pour les chiffres (deux pour chaque paire) et appelle `compute` pour générer et afficher toutes les combinaisons.

- **Initialisation** :
  - `n2d` et `n2u` sont initialisés à '0'.
- **Appel de la fonction** :
  - Appelle `compute` avec les variables initialisées pour générer et imprimer toutes les combinaisons.

### Résumé
Le programme utilise des boucles et des conditions pour générer systématiquement toutes les paires possibles de deux chiffres (00 à 99) où la deuxième paire est toujours supérieure à la première. Les paires sont affichées avec les formats appropriés, utilisant des opérations de bas niveau (`write`) pour un affichage direct sur la sortie standard. C'est une méthode efficace pour explorer toutes les combinaisons possibles dans un espace défini tout en s'assurant que l'ordre est respecté.

# Démonstration

```C
int	main(void)
{
	ft_print_comb2();
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c00/ex06  (main) $ norminette -RCheckForbiddenSourceHeader ft_print_comb2.c 
ft_print_comb2.c: OK!
Repo Git : Practice42/Work/C/c00/ex06  (main) $ gcc ft_print_comb2.c 
Repo Git : Practice42/Work/C/c00/ex06  (main) $ ./a.out 
00 01, 00 02, 00 03, 00 04, 00 05, 00 06, 00 07, 00 08, 00 09, 00 10, 00 11, 00 12, 00 13, 00 14, 00 15, 00 16, 00 17, 00 18, 00 19, 00 20, 00 21, 00 22, 00 23, 00 24, ..., 00 88, 00 89, 00 90, 00 91, 00 92, 00 93, 00 94, 00 95, 00 96, 00 97, 00 98, 00 99, 01 02, 01 03, 01 04, 01 05, 01 06, 01 07, 01 08, 01 09, 01 10, 01 11, 01 12, 01 13, 01 14, 01 15, 01 16, 01 17, 01 18, 01 19, 01 20, 01 21, 01 22, 01 23, 01 24, 01 25, 01 26, 01 27, ..., 54 87, 54 88, 54 89, 54 90, 54 91, 54 92, 54 93, 54 94, 54 95, 54 96, 54 97, 54 98, 54 99, 55 56, 55 57, 55 58, 55 59, 55 60, 55 61, 55 62, 55 63, 55 64, 55 65, 55 66, 55 67, 55 68, 55 69, 55 70, 55 71, 55 72, 55 73, 55 74, 55 75, 55 76, 55 77, 55 78, 55 79, 55 80, 55 81, 55 82, 55 83, 55 84, 55 85, 55 86, 55 87, 55 88, 55 89, 55 90, 55 91, 55 92, 55 93, 55 94, 55 95, 55 96, 55 97, 55 98, 55 99, 56 57, 56 58, 56 59, 56 60, 56 61, 56 62, 56 63, 56 64, 56 65, 56 66, 56 67, ..., 87 95, 87 96, 87 97, 87 98, 87 99, 88 89, 88 90, 88 91, 88 92, 88 93, 88 94, 88 95, 88 96, 88 97, 88 98, 88 99, 89 90, 89 91, 89 92, 89 93, 89 94, 89 95, 89 96, 89 97, 89 98, 89 99, 90 91, 90 92, 90 93, 90 94, 90 95, 90 96, 90 97, 90 98, 90 99, 91 92, 91 93, 91 94, 91 95, 91 96, 91 97, 91 98, 91 99, 92 93, 92 94, 92 95, 92 96, 92 97, 92 98, 92 99, 93 94, 93 95, 93 96, 93 97, 93 98, 93 99, 94 95, 94 96, 94 97, 94 98, 94 99, 95 96, 95 97, 95 98, 95 99, 96 97, 96 98, 96 99, 97 98, 97 99, 98 99Repo Git : Practice42/Work/C/c00/ex06  (main) $ 
```
# Explications

Rien de particulier de ce code qui est une extension du précédent.