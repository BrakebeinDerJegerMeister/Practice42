# Énoncé

| Exercice : 08                        |
| ------------------------------------ |
| ft_print_combn                       |
| Dossier de rendu : ex08/             |
| Fichiers à rendre : ft_print_combn.c |
| Fonctions Autorisées : write         |
• Écrire une fonction qui affiche toutes les différentes combinaisons de n chiffres dans l’ordre croissant.
• n sera tel que : 0 < n < 10.
• Si n = 2, cela donne quelque chose comme ça :
```
$>./a.out | cat -e
01, 02, 03, ..., 09, 12, ..., 79, 89$>
```
• Elle devra être prototypée de la façon suivante :
```
void ft_print_combn(int n);
```
# Correction

```C
#include <unistd.h>

int	is_max_number(char *comb, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		if (comb[i] != ('0' + 10 - nb + i))
		{
			return (0);
		}
	}
	return (1);
}

void	loop(char *numbers, int *limits, int rank, int stop)
{
	int	i;
	int	new_limits[2];

	i = limits[0] - 1;
	while (++i <= limits[1])
	{
		numbers[rank] = '0' + i;
		if (rank == stop)
		{
			write(1, numbers, stop);
			if (! is_max_number(numbers, stop))
			{
				write(1, ", ", 2);
			}
			return ;
		}
		new_limits[0] = i + 1;
		new_limits[1] = limits[1] + 1;
		loop(numbers, new_limits, rank + 1, stop);
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	positions[10];
	int		limits[2];

	i = -1;
	while (++i < n)
	{
		positions[i] = '0' + i;
	}
	positions[n - 1]--;
	limits[0] = 0;
	limits[1] = 10 - n;
	loop(positions, limits, 0, n);
}

```
# Algorithme

### Description
Le code implémente une fonction pour générer toutes les combinaisons possibles de `n` chiffres, de manière croissante, sans répétition, à partir des chiffres de 0 à 9. Il utilise une approche récursive pour construire ces combinaisons et les affiche directement.

### Fonctions et leur Rôle

#### `is_max_number(char *comb, int nb)`
Cette fonction vérifie si la combinaison actuelle de chiffres stockée dans `comb` est la plus grande combinaison possible pour une longueur donnée `nb`. Elle parcourt chaque caractère de la chaîne `comb` et compare chaque chiffre à la valeur maximale qu'il pourrait prendre, en fonction de sa position. Si un chiffre ne correspond pas à sa valeur maximale attendue, la fonction retourne `0` (faux), sinon, si tous les chiffres sont maximaux, elle retourne `1` (vrai).

#### `loop(char *numbers, int *limits, int rank, int stop)`
Cette fonction est le cœur de l'algorithme récursif. Elle construit les combinaisons de chiffres une par une.

- `numbers` est la chaîne qui contient la combinaison actuelle.
- `limits` est un tableau de deux entiers qui détermine les valeurs minimales et maximales que le chiffre actuel (`numbers[rank]`) peut prendre.
- `rank` est l'index du chiffre actuel dans la chaîne `numbers`.
- `stop` est la longueur totale de la combinaison à générer (aussi utilisé pour déterminer si nous avons atteint la dernière position de la chaîne).

La fonction place un chiffre dans `numbers[rank]`, puis vérifie si c'est le dernier chiffre à placer (`rank == stop`). Si c'est le cas, elle affiche la combinaison. Sinon, elle appelle récursivement `loop` pour le chiffre suivant, en ajustant les limites pour ce nouveau chiffre.

#### `ft_print_combn(int n)`
Cette fonction initialise les conditions pour la récursion et appelle `loop` pour commencer le processus de génération des combinaisons. Elle prépare un tableau `positions` pour stocker les chiffres de la combinaison, et initialise `limits` pour contrôler les valeurs minimales et maximales que les chiffres peuvent prendre initialement.

### Déroulement de l'Algorithme
1. **Initialisation :** `ft_print_combn` prépare un tableau de caractères `positions` avec les `n` premiers chiffres en ordre croissant et ajuste le dernier chiffre.
2. **Définition des Limites :** Les valeurs de début et de fin pour les chiffres possibles sont définies.
3. **Appel Récursif :** La fonction `loop` est appelée avec les paramètres initiaux.
4. **Construction des Combinaisons :** `loop` construit récursivement chaque combinaison possible et affiche chacune d'elles directement, en ajoutant une virgule si la combinaison n'est pas la dernière.

# Démonstration

```C
int	main(void)
{
	ft_print_combn(3);
	write(1, "\n\n", 2);
	ft_print_combn(2);
	write(1, "\n\n", 2);
	ft_print_combn(5);
	write(1, "\n\n", 2);
	ft_print_combn(9);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c00/ex08  (main) $ norminette -RCheckForbiddenSourceHeader ft_print_combn.c 
ft_print_combn.c: OK!
Repo Git : Practice42/Work/C/c00/ex08  (main) $ gcc ft_print_combn.c
Repo Git : Practice42/Work/C/c00/ex08  (main) $ ./a.out
012, 013, 014, 015, 016, 017, 018, 019, 023, 024, 025, 026, 027, 028, 029, 034, 035, 036, 037, 038, 039, 045, 046, 047, 048, 049, 056, 057, 058, 059, 067, 068, 069, 078, 079, 089, 123, 124, 125, 126, 127, 128, 129, 134, 135, 136, 137, 138, 139, 145, 146, 147, 148, 149, 156, 157, 158, 159, 167, 168, 169, 178, 179, 189, 234, 235, 236, 237, 238, 239, 245, 246, 247, 248, 249, 256, 257, 258, 259, 267, 268, 269, 278, 279, 289, 345, 346, 347, 348, 349, 356, 357, 358, 359, 367, 368, 369, 378, 379, 389, 456, 457, 458, 459, 467, 468, 469, 478, 479, 489, 567, 568, 569, 578, 579, 589, 678, 679, 689, 789

01, 02, 03, 04, 05, 06, 07, 08, 09, 12, 13, 14, 15, 16, 17, 18, 19, 23, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39, 45, 46, 47, 48, 49, 56, 57, 58, 59, 67, 68, 69, 78, 79, 89

01234, 01235, 01236, 01237, 01238, 01239, 01245, 01246, 01247, 01248, 01249, 01256, 01257, 01258, 01259, 01267, 01268, 01269, 01278, 01279, 01289, 01345, 01346, 01347, 01348, 01349, 01356, 01357, 01358, 01359, 01367, 01368, 01369, 01378, 01379, 01389, 01456, 01457, 01458, 01459, 01467, 01468, 01469, 01478, 01479, 01489, 01567, 01568, 01569, 01578, 01579, 01589, 01678, 01679, 01689, 01789, 02345, 02346, 02347, 02348, 02349, 02356, 02357, 02358, 02359, 02367, 02368, 02369, 02378, 02379, 02389, 02456, 02457, 02458, 02459, 02467, 02468, 02469, 02478, 02479, 02489, 02567, 02568, 02569, 02578, 02579, 02589, 02678, 02679, 02689, 02789, 03456, 03457, 03458, 03459, 03467, 03468, 03469, 03478, 03479, 03489, 03567, 03568, 03569, 03578, 03579, 03589, 03678, 03679, 03689, 03789, 04567, 04568, 04569, 04578, 04579, 04589, 04678, 04679, 04689, 04789, 05678, 05679, 05689, 05789, 06789, 12345, 12346, 12347, 12348, 12349, 12356, 12357, 12358, 12359, 12367, 12368, 12369, 12378, 12379, 12389, 12456, 12457, 12458, 12459, 12467, 12468, 12469, 12478, 12479, 12489, 12567, 12568, 12569, 12578, 12579, 12589, 12678, 12679, 12689, 12789, 13456, 13457, 13458, 13459, 13467, 13468, 13469, 13478, 13479, 13489, 13567, 13568, 13569, 13578, 13579, 13589, 13678, 13679, 13689, 13789, 14567, 14568, 14569, 14578, 14579, 14589, 14678, 14679, 14689, 14789, 15678, 15679, 15689, 15789, 16789, 23456, 23457, 23458, 23459, 23467, 23468, 23469, 23478, 23479, 23489, 23567, 23568, 23569, 23578, 23579, 23589, 23678, 23679, 23689, 23789, 24567, 24568, 24569, 24578, 24579, 24589, 24678, 24679, 24689, 24789, 25678, 25679, 25689, 25789, 26789, 34567, 34568, 34569, 34578, 34579, 34589, 34678, 34679, 34689, 34789, 35678, 35679, 35689, 35789, 36789, 45678, 45679, 45689, 45789, 46789, 56789

012345678, 012345679, 012345689, 012345789, 012346789, 012356789, 012456789, 013456789, 023456789, 123456789Repo Git : Practice42/Work/C/c00/ex08  (main) $ 
```

# Explications

### Suggestions pour les débutants

Pour surmonter ces difficultés, les débutants pourraient :

- **Étudier les bases de la récursivité** : Commencer par des problèmes récursifs plus simples comme le calcul de la factorielle ou la série de Fibonacci peut aider.
- **Pratiquer avec des pointeurs et des tableaux** : Faire des exercices simples pour comprendre comment les pointeurs et les tableaux fonctionnent en C.
- **Se familiariser avec les opérations de caractères** : Expérimenter avec l'ASCII et comprendre comment les caractères sont gérés en C.
- **Décomposer les problèmes** : Essayer de réécrire ou de modifier des parties du code pour mieux comprendre comment chaque section contribue au résultat final.