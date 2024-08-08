# Énoncé

| Exercice : 04                        |
| ------------------------------------ |
| ft_putnbr_base                       |
| Dossier de rendu : ex04/             |
| Fichiers à rendre : ft_putnbr_base.c |
| Fonctions Autorisées : write         |
• Écrire une fonction qui affiche un nombre dans le terminal dans une base donnée.
• Ce nombre est fourni sous la forme d’un int et la base sous la forme d’une chaîne
de caractères.
• La base contient tous les symboles utilisables pour afficher le nombre :
◦ 0123456789 est la base couramment utilisée pour représenter nos nombres
décimaux ;
◦ 01 est une base binaire ;
◦ 0123456789ABCDEF est une base hexadecimale ;
◦ poneyvif est une base octale.
• La fonction doit gérer les nombres négatifs.
• Si un paramètre contient une erreur la fonction n’affiche rien. Une erreur peut
être :
◦ base est vide ou est de taille 1 ;
◦ base contient deux fois le même caractère ;
◦ base contient les caractères + ou -.
• Elle devra être prototypée de la façon suivante :
```C
void ft_putnbr_base(int nbr, char *base);
```
# Correction

```C
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	put_positive_nbrbase(long nb, int ibase, char *base)
{
	long	current;

	current = nb % ibase;
	nb = (nb - current) / ibase;
	if (nb != 0)
	{
		put_positive_nbrbase(nb, ibase, base);
	}
	write(1, &base[current], 1);
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

void	ft_putnbr_base(int nbr, char *base)
{
	int		ibase;
	long	new_nbr;

	ibase = ft_strlen(base);
	new_nbr = nbr;
	if (check_base_error(base, ibase))
		return ;
	if (new_nbr < 0)
	{
		new_nbr = -new_nbr;
		write(1, &(char){'-'}, 1);
	}
	put_positive_nbrbase(new_nbr, ibase, base);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(int nbr, char *base)
{
	printf("\nnbr : {%d}", nbr);
	printf("\nbase : {%s}\n", base);
	ft_putnbr_base(nbr, base);
	printf("\n");
}

int	main(void)
{	
	test(581499, "0123456789");
	test(581499, "0123456789ABCDEF");
	test(581499, "01");
	test(581499, "");
	test(581499, "coucou");
	test(-484529100, "poneyvif");
	test(-484529100, "foin");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c04/ex04  (main *) $ norminette -RCheckForbiddenSourceHeader ft_putnbr_base.c 
ft_putnbr_base.c: Error!
Error: INCLUDE_START_FILE   (line:  79, col:   1):	Include must be at the start of file
Error: TOO_MANY_FUNCS       (line:  89, col:   1):	Too many functions in file
Error: SPC_BEFORE_NL        (line:  90, col:   2):	Space before newline
Repo Git : Practice42/Work/C/c04/ex04  (main *) $ gcc -Wall -Wextra -Werror ft_putnbr_base.c 
Repo Git : Practice42/Work/C/c04/ex04  (main *) $ ./a.out 

nbr : {581499}
base : {0123456789}
581499

nbr : {581499}
base : {0123456789ABCDEF}
8DF7B

nbr : {581499}
base : {01}
10001101111101111011

nbr : {581499}
base : {}


nbr : {581499}
base : {coucou}


nbr : {-484529100}
base : {poneyvif}
-eyfpnvofoy

nbr : {-484529100}
base : {foin}
-onfnifooofnnfnf
Repo Git : Practice42/Work/C/c04/ex04  (main *) $ 
```
# Explications


1. **Fonction `ft_strlen`** :
   Cette fonction calcule la longueur d'une chaîne de caractères en incrémentant un compteur jusqu'à ce qu'elle atteigne le caractère nul qui termine la chaîne.

2. **Fonction `put_positive_nbrbase`** :
   - Cette fonction est une fonction récursive destinée à afficher un nombre positif dans la base spécifiée.
   - Elle divise le nombre (`nb`) par la base (`ibase`) pour obtenir le quotient et le reste. Le reste correspond à l'indice du caractère dans la chaîne `base` qui doit être affiché pour représenter ce chiffre du nombre.
   - La fonction se rappelle elle-même avec le quotient jusqu'à ce que ce quotient soit nul, point auquel elle commence à afficher les caractères de la base accumulés pendant les appels récursifs, en commençant par le chiffre le plus significatif.

3. **Fonction `check_base_error`** :
   - Cette fonction vérifie plusieurs conditions d'erreur sur la chaîne de base:
     - La base doit contenir au moins 2 caractères (sinon, on ne peut pas représenter des nombres en base `n`).
     - La base ne doit contenir ni le signe plus ('+') ni le signe moins ('-'), car ces caractères sont généralement réservés pour indiquer le signe d'un nombre.
     - La base ne doit pas contenir de caractères en double, car chaque chiffre d'une base doit être unique pour éviter la confusion dans la représentation des nombres.
   - Si une de ces conditions n'est pas respectée, la fonction retourne `1` pour indiquer une erreur.

4. **Fonction `ft_putnbr_base`** :
   - Cette fonction est la fonction principale utilisée pour convertir et afficher un nombre (`nbr`) dans une base donnée (`base`).
   - Elle commence par déterminer la longueur de la chaîne de base en utilisant `ft_strlen`.
   - Elle vérifie ensuite s'il y a une erreur avec la base en utilisant `check_base_error`.
   - Si le nombre est négatif, elle affiche le signe moins ('-') et convertit le nombre en sa valeur absolue.
   - Finalement, elle appelle `put_positive_nbrbase` pour afficher le nombre dans la base spécifiée.