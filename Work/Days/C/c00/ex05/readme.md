# Énoncé

| Exercice : 05                       |
| ----------------------------------- |
| ft_print_comb                       |
| Dossier de rendu : ex05/            |
| Fichiers à rendre : ft_print_comb.c |
| Fonctions Autorisées : write        |
• Écrire une fonction qui affiche, dans l’ordre croissant, toutes les différentes combinaisons de trois chiffres différents dans l’ordre croissant - oui, la répétition est volontaire.
• Cela donne quelque chose comme ça :
```
$>./a.out | cat -e
012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789$>
```
• 987 n’est pas là car 789 est déjà présent
• 999 n’est pas là car ce nombre ne comporte pas exclusivement des chiffres différents
les uns des autres
• Elle devra être prototypée de la façon suivante :
```
void ft_print_comb(void);
```
# Correction
```C
#include <unistd.h>

void	print_combinaison(char i, char j, char k)
{
	char	s;
	char	e;

	s = ',';
	e = ' ';
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if ((i != '7') || (j != '8') || (k != '9'))
	{
		write(1, &s, 1);
		write(1, &e, 1);
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				print_combinaison(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
```
# Algorithme

L'algorithme de votre programme en C, qui génère toutes les combinaisons possibles de trois chiffres distincts en ordre croissant, peut être décrit de manière structurée comme suit :

### Algorithme `ft_print_comb`

**1. Déclaration des variables**
   - Déclarer trois variables de type `char`: `i`, `j`, `k`. Ces variables serviront à stocker les chiffres des combinaisons.

**2. Initialisation de la variable `i`**
   - Initialiser `i` à '0'. Ce sera le premier chiffre de la combinaison.

**3. Boucle principale sur `i`**
   - Commencer une boucle avec `i` allant de '0' à '7':
     - Pour chaque valeur de `i`, `i` représente le premier chiffre de la combinaison.

**4. Boucle secondaire sur `j`**
   - Pour chaque valeur de `i`, initialiser `j` à `i + 1`. `j` doit toujours être supérieur à `i`.
   - Commencer une boucle avec `j` allant de `i + 1` à '8' (soit '1' à '8'):
     - Pour chaque valeur de `j`, `j` représente le deuxième chiffre de la combinaison.

**5. Boucle interne sur `k`**
   - Pour chaque valeur de `j`, initialiser `k` à `j + 1`. `k` doit toujours être supérieur à `j`.
   - Commencer une boucle avec `k` allant de `j + 1` à '9' (soit '2' à '9'):
     - Pour chaque valeur de `k`, `k` représente le troisième chiffre de la combinaison.

**6. Affichage de la combinaison**
   - À l'intérieur de la boucle sur `k`, appeler la fonction `print_combinaison` avec les arguments `i`, `j`, et `k`.

**7. Fin de l'algorithme**
   - Les boucles se terminent naturellement lorsque les conditions de leur itération ne sont plus remplies (i.e., quand `i`, `j`, et `k` atteignent leurs valeurs maximales respectives).

### Fonction `print_combinaison`

**1. Affichage des chiffres**
   - Utiliser la fonction système `write` pour envoyer chaque chiffre (`i`, `j`, `k`) à la sortie standard.

**2. Gestion des séparateurs**
   - Vérifier si la combinaison courante n'est pas '789'. Si ce n'est pas '789', afficher une virgule suivie d'un espace pour séparer cette combinaison de la suivante.

# Démonstration

```
Repo Git : Practice42/Work/C/c00/ex05  (main *) $ norminette ft_print_comb.c 
ft_print_comb.c: OK!
Repo Git : Practice42/Work/C/c00/ex05  (main *) $ gcc ft_print_comb.c 
Repo Git : Practice42/Work/C/c00/ex05  (main *) $ ./a.out 
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789Repo Git : Practice42/Work/C/c00/ex05  (main *) $ 
```

# Explications

### Fonction `print_combinaison`

```c
void	print_combinaison(char i, char j, char k)
{
    char s = ',';
    char e = ' ';
```
Cette fonction déclare deux variables locales `s` et `e` pour stocker les caractères utilisés comme séparateurs (une virgule et un espace). Ces variables sont utilisées pour formater correctement la sortie.

```c
    write(1, &i, 1);
    write(1, &j, 1);
    write(1, &k, 1);
```
Ces trois appels à `write` affichent les chiffres représentés par `i`, `j`, et `k`. Chaque chiffre est envoyé individuellement à la sortie standard. Le `1` comme premier argument de `write` spécifie que la sortie doit être dirigée vers `stdout`.

```c
    if ((i != '7') || (j != '8') || (k != '9'))
    {
        write(1, &s, 1);
        write(1, &e, 1);
    }
}
```
Ce bloc conditionnel vérifie si la combinaison courante est '789'. Si ce n'est pas le cas, une virgule et un espace sont ajoutés comme séparateurs. Cela permet d'éviter d'ajouter une virgule et un espace après la dernière combinaison valide, gardant la sortie propre et conforme à la spécification.

### Fonction `ft_print_comb`

```c
void	ft_print_comb(void)
{
    char i, j, k;
```
La fonction déclare trois variables de type `char`, `i`, `j`, et `k`, qui seront utilisées pour stocker les chiffres des combinaisons.

```c
    i = '0';
    while (i <= '7')
    {
```
La boucle externe initialise `i` à '0' et itère jusqu'à '7'. La limite de '7' pour `i` assure que `j` et `k` peuvent prendre des valeurs allant jusqu'à '8' et '9', respectivement, sans dépasser la combinaison '789'.

```c
        j = i + 1;
        while (j <= '8')
        {
```
La boucle moyenne commence avec `j` à `i + 1`, garantissant que `j` est toujours plus grand que `i`. Elle continue jusqu'à '8'.

```c
            k = j + 1;
            while (k <= '9')
            {
                print_combinaison(i, j, k);
                k++;
            }
            j++;
        }
        i++;
    }
}
```
La boucle interne commence avec `k` à `j + 1`, ce qui garantit que `k` est toujours plus grand que `j`. Elle itère jusqu'à '9'. Chaque itération de cette boucle la plus interne génère une nouvelle combinaison, qui est passée à `print_combinaison` pour affichage. Les boucles garantissent que chaque chiffre dans la combinaison est unique et en ordre strictement croissant.

Ce code utilise des boucles imbriquées pour systématiquement générer et afficher toutes les combinaisons possibles de trois chiffres en respectant l'ordre croissant et l'unicité des chiffres dans chaque combinaison.