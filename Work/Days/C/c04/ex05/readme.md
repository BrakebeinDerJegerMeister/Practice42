# Énoncé

| Exercice : 05                      |
| ---------------------------------- |
| ft_atoi_base                       |
| Dossier de rendu : ex05/           |
| Fichiers à rendre : ft_atoi_base.c |
| Fonctions Autorisées : Aucune      |
• Ecrire une fonction qui convertit le début de la chaîne pointée par str en entier de
type int.
• str est dans une base specifique passée en second argument de la fonction.
• A part le système de base, cette fonction doit reproduire le comportement de
ft_atoi.
• Si un paramètre contient une erreur la fonction renvoie 0. Une erreur peut être :
◦ la base est vide ou est de taille 1 ;
◦ la base contient deux fois le même caractère ;
◦ la base contient les caractères + ou - ou des whitespaces ;
• Elle devra être prototypée de la façon suivante :
```C
int ft_atoi_base(char *str, char *base);
```
# Correction

```C
int	get_rank(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	check_base_error(char *base, int ibase)
{
	int	i;
	int	j;

	if (ibase == 0 || ibase == 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_val(char *str, char *base, int ibase)
{
	int	i;
	int	val;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		val = get_rank(str[i], base);
		if (val == -1)
			return (0);
		nb = val + nb * ibase;
		i++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	factor;
	int	ibase;

	factor = 1;
	ibase = 0;
	while (base[ibase] != '\0')
		ibase++;
	if (check_base_error(base, ibase))
		return (0);
	while (str[0] == 32 || (str[0] > 8 && str[0] < 14))
		str++;
	while (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			factor = -factor;
		str++;
	}
	return (get_val(str, base, ibase) * factor);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(char *str, char *base)
{
	int	nb = ft_atoi_base(str, base);
	printf("\nstr : {%s}", str);
	printf("\nbase : {%s}", base);
	printf("\nnb : {%d}\n", nb);
}

int	main(void)
{
	test("adadaadadaadada", "ad");
	test("adadaadadaadada", "da");
	test("adadaadadaadada", "mn");
	test("aaaaaa", "a");
	test("    +---+215", "0123456789");
	test("-eyfpnvofoy", "poneyvif");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c04/ex05  (main *) $ norminette -RCheckForbiddenSourceHeader ft_atoi_base.c 
ft_atoi_base.c: Error!
Error: INCLUDE_START_FILE   (line:  92, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  96, col:  12):	Declaration and assignation on a single line
Error: NL_AFTER_VAR_DECL    (line:  97, col:   1):	Variable declarations must be followed by a newline
Error: TOO_MANY_FUNCS       (line: 102, col:   1):	Too many functions in file
Repo Git : Practice42/Work/C/c04/ex05  (main *) $ gcc -Wall -Wextra -Werror ft_atoi_base.c 
Repo Git : Practice42/Work/C/c04/ex05  (main *) $ ./a.out 

str : {adadaadadaadada}
base : {ad}
nb : {10570}

str : {adadaadadaadada}
base : {da}
nb : {22197}

str : {adadaadadaadada}
base : {mn}
nb : {0}

str : {aaaaaa}
base : {a}
nb : {0}

str : {    +---+215}
base : {0123456789}
nb : {-215}

str : {-eyfpnvofoy}
base : {poneyvif}
nb : {-484529100}
Repo Git : Practice42/Work/C/c04/ex05  (main *) $ 

```
# Explications

#### Objectif
Convertir une chaîne de caractères `str`, qui représente un nombre dans une base arbitraire définie par la chaîne `base`, en un entier décimal. La fonction principale `ft_atoi_base` utilise plusieurs fonctions auxiliaires pour valider la base, trouver la position d'un caractère dans la base, et calculer la valeur numérique de la chaîne de caractères complète.

#### Fonctions et Méthodes

1. **get_rank(char c, char *base)**
   - **Entrée :** Un caractère `c` et une chaîne `base` qui définit les symboles utilisables dans la numération.
   - **Processus :** Parcourt `base` pour trouver l'indice de `c`.
   - **Sortie :** Renvoie l'indice de `c` dans `base` ou `-1` si `c` n'est pas trouvé.

2. **check_base_error(char *base, int ibase)**
   - **Entrée :** Une chaîne `base` représentant les symboles valides de la base et `ibase`, la longueur de `base`.
   - **Processus :**
     - Vérifie si la longueur de la base est 0 ou 1.
     - Vérifie la présence de caractères non valides (`+`, `-`).
     - Vérifie les doublons dans `base`.
   - **Sortie :** Renvoie `1` (erreur) si une condition d'erreur est remplie, sinon `0`.

3. **get_val(char *str, char *base, int ibase)**
   - **Entrée :** La chaîne `str` à convertir, la chaîne `base` et sa longueur `ibase`.
   - **Processus :**
     - Convertit chaque caractère de `str` en sa valeur numérique selon `base`.
     - Accumule la valeur totale en multipliant l'accumulation précédente par `ibase` et en ajoutant la valeur du caractère courant.
   - **Sortie :** La valeur entière représentant `str` dans la base décimale.

4. **ft_atoi_base(char *str, char *base)**
   - **Entrée :** La chaîne `str` à convertir et la chaîne `base`.
   - **Processus :**
     - Calcule la longueur de `base` et vérifie les erreurs.
     - Ignore les espaces blancs initiaux dans `str`.
     - Gère les signes `+` et `-` pour déterminer le signe du nombre.
     - Utilise `get_val` pour convertir le nombre.
   - **Sortie :** Le nombre entier converti, ajusté par le facteur de signe.

#### Description Algorithmique

1. **Validation de la Base :**
   - La base est validée pour s'assurer qu'elle contient au moins deux caractères distincts et aucun caractère n'est `+` ou `-`.
   - Les doublons dans la base sont également vérifiés pour garantir que chaque caractère peut représenter une valeur unique.

2. **Prétraitement de la Chaîne :**
   - Les espaces blancs et les caractères de contrôle au début de `str` sont ignorés.
   - Les signes sont traités pour déterminer si le nombre final doit être positif ou négatif.

3. **Conversion :**
   - La chaîne est parcourue caractère par caractère.
   - Chaque caractère est converti en sa valeur numérique correspondante dans la base.
   - La valeur numérique totale est calculée en utilisant un système de numération de position, où chaque chiffre contribue à la valeur totale en fonction de sa position dans le nombre.

#### Utilisation

Ce code est utile pour des applications nécessitant la conversion de données entre différentes bases, comme les calculatrices, les convertisseurs de base, ou dans des contextes où les données sont représentées dans une base non décimale.