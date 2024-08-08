# Énoncé

| Exercice : 04                                             |
| --------------------------------------------------------- |
| ft_convert_base                                           |
| Dossier de rendu : ex04/                                  |
| Fichiers à rendre : ft_convert_base.c, ft_convert_base2.c |
| Fonctions Autorisées : malloc, free                       |
• Écrire une fonction qui renvoie le résultat de la conversion de la chaîne nbr expri-
mée en une base base_from dans une base base_to.
• nbr, base_from, base_to ne seront pas forcement modifiable.
• nbr suivra les mêmes règles que ft_atoi_base. Attention donc au ’+’, ’-’ et aux
whitespaces.
• Le nombre representé par nbr tient dans un int.
• Si une base est incorrecte, la fonction renverra NULL.
• Le nombre retourné doit être préfixé seulement par un seul et unique ’-’ si c’est
nécessaire, pas de whitespaces ou de ’+’.
• Elle devra être prototypée de la façon suivante :
```C
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
```
# Correction

```C
#include <stdlib.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 1)
		return (0);
	return (i);
}

long	atoi_positive_base(char *str, char *base, int ibase)
{
	int		i;
	long	nb;
	int		val;
	int		j;

	i = 0;
	nb = 0;
	while (str[i] != '\0')
	{
		val = -1;
		j = -1;
		while (++j < ibase)
		{
			if (base[j] == str[i])
			{
				val = j;
				break ;
			}
		}
		if (val == -1)
			return (0);
		nb = val + nb * ibase;
		i++;
	}
	return (nb);
}

char	*my_strcat(char *str1, char *str2)
{
	char	*new;
	char	*save;
	int		i;

	i = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[i] != '\0')
		i++;
	new = (char *)malloc(i + 1);
	save = new;
	while (*str1)
		*new++ = *str1++;
	while (*str2)
		*new++ = *str2++;
	*new = '\0';
	return (save);
}

char	*get_positive_nbrbase(long nb, char *base, int ibase)
{
	long	current;
	char	*str1;
	char	*str2;

	current = nb % ibase;
	nb = (nb - current) / ibase;
	if (nb != 0)
		str1 = get_positive_nbrbase(nb, base, ibase);
	else
		str1 = "";
	str2 = my_strcat(str1, (char []){base[current], '\0'});
	return (str2);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		factor;
	int		ibase_from;
	int		ibase_to;
	long	nb1;
	char	*nb2;

	factor = 1;
	ibase_from = check_base(base_from);
	ibase_to = check_base(base_to);
	if (ibase_from == 0 || ibase_to == 0)
		return (NULL);
	while (nbr[0] == 32 || (nbr[0] > 8 && nbr[0] < 14))
		nbr++;
	while (nbr[0] == '-' || nbr[0] == '+')
	{
		if (nbr[0] == '-')
			factor = -factor;
		nbr++;
	}
	nb1 = atoi_positive_base(nbr, base_from, ibase_from);
	nb2 = get_positive_nbrbase(nb1, base_to, ibase_to);
	if (factor == -1)
		nb2 = my_strcat("-", nb2);
	return (nb2);
}
```
# Démonstration

```C
#include <stdio.h>

void	test(char *str, char *base_from, char *base_to)
{
	char	*nb = ft_convert_base(str, base_from, base_to);
	printf("\nstr : {%s}", str);
	printf("\nbase from : {%s}", base_from);
	printf("\nbase to : {%s}", base_to);
	printf("\nnb : {%s}\n", nb);
	free(nb);
}

int	main(void)
{
	test("adadaadadaadada", "ad", "ok");
	test("adadaadadaadada", "da", "ok");
	test("adadaadadaadada", "mn", "prout");
	test("aaaaaa", "a", "bk");
	test("    +---+215", "0123456789", "0123456789ABCDEF");
	test("-eyfpnvofoy", "poneyvif", "foin");
	return (0);
}
```

```
ft_convert_base.c: Error!
Error: INCLUDE_START_FILE   (line: 133, col:   1):	Include must be at the start of file
Error: TOO_MANY_FUNCS       (line: 135, col:   1):	Too many functions in file
Error: DECL_ASSIGN_LINE     (line: 137, col:  17):	Declaration and assignation on a single line
Error: NL_AFTER_VAR_DECL    (line: 138, col:   1):	Variable declarations must be followed by a newline
Error: TOO_MANY_FUNCS       (line: 145, col:   1):	Too many functions in file

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer

str : {adadaadadaadada}
base from : {ad}
base to : {ok}
nb : {kokookokookoko}

str : {adadaadadaadada}
base from : {da}
base to : {ok}
nb : {kokokkokokkokok}

str : {adadaadadaadada}
base from : {mn}
base to : {prout}
nb : {p}

str : {aaaaaa}
base from : {a}
base to : {bk}
nb : {(null)}

str : {    +---+215}
base from : {0123456789}
base to : {0123456789ABCDEF}
nb : {-D7}

str : {-eyfpnvofoy}
base from : {poneyvif}
base to : {foin}
nb : {-onfnifooofnnfnf}

Appuyez sur ENTRÉE ou tapez une commande pour continuer
```
# Explications

Que du déjà vu...