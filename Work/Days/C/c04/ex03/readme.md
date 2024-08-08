# Énoncé

| Exercice : 03                 |
| ----------------------------- |
| ft_atoi                       |
| Dossier de rendu : ex03/      |
| Fichiers à rendre : ft_atoi.c |
| Fonctions Autorisées : Aucune |
• Ecrire une fonction qui convertit le début de la chaîne pointée par str en entier de type
int
• str peut commencer par un nombre arbitraire de ‘white space‘ (comme defini par isspace(3))
• str peut ensuite être suivi par un nombre arbitraire de signe + et de signe -. Le signe -
fera changer le signe de l’entier retourné en fonction du nombre de signe - et si celui ci
est pair ou impair.
• Pour finir str devra être composée de chiffre de la base 10
• Votre fonction devra lire str tant que celle ci suit les règles au dessus et elle doit retourner
le nombre trouvé jusque là.
• Vous ne devriez pas prendre en compte les overflows et les underflows, le résultat est
considérer comme indéfini dans ces cas.
• Vous pouvez comparer votre fonction avec la vrai fonction atoi à part la partie sur les
signes ainsi que l’overflow.
• Voici l’exemple d’un programme qui affiche la valeur de retour de atoi :
```
$>./a.out "   ---+--+1234ab567"
-1234
```
• Elle devra être prototypée de la façon suivante :
```C
int ft_atoi(char *str);
```
# Correction

```C
int	is_whitespace(char chr)
{
	if (chr == 32 || (chr > 8 && chr < 14))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		factor;
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	factor = 1;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			factor = -factor;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (int)str[i] - 48 + nb * 10;
		i++;
	}
	return (factor * nb);
}
```
# Démonstration

```C
#include <stdlib.h>
#include <stdio.h>

void	test(char *str)
{
	int	res;

	res = ft_atoi(str);
	printf("\nStr : {%s}\n", str);
	printf("ft_atoi : {%d}\n", res);
	printf("atoi : {%d}\n", atoi(str));
}

int	main(void)
{
	test("  ---+--+1234ab567");
	test("-1234ab567");
	test("-12-5");
	test("+45");
	test("-42");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c04/ex03  (main *) $ norminette -RCheckForbiddenSourceHeader ft_atoi.c 
ft_atoi.c: Error!
Error: INCLUDE_START_FILE   (line:  55, col:   1):	Include must be at the start of file
Error: INCLUDE_START_FILE   (line:  56, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c04/ex03  (main *) $ gcc -Wall -Wextra -Werror ft_atoi.c 
Repo Git : Practice42/Work/C/c04/ex03  (main *) $ ./a.out 

Str : {  ---+--+1234ab567}
ft_atoi : {-1234}
atoi : {0}

Str : {-1234ab567}
ft_atoi : {-1234}
atoi : {-1234}

Str : {-12-5}
ft_atoi : {-12}
atoi : {-12}

Str : {+45}
ft_atoi : {45}
atoi : {45}

Str : {-42}
ft_atoi : {-42}
atoi : {-42}
Repo Git : Practice42/Work/C/c04/ex03  (main *) $ 
```
# Algorithme

### Documentation Algorithme de `ft_atoi`

#### Description Générale

Le programme `ft_atoi` est une implémentation personnalisée de la fonction `atoi` (ASCII to Integer) en langage C. Cette fonction convertit une chaîne de caractères représentant un nombre en un entier. La fonction gère également les espaces blancs initiaux, les signes '+' et '-', et effectue la conversion des caractères numériques en un entier.

#### Détails des Fonctions

1. **Fonction `is_whitespace`**
   - **Entrée :** Un caractère (`char chr`).
   - **Sortie :** Un entier (`int`), 1 si le caractère est un espace blanc, sinon 0.
   - **Algorithme :**
     - Vérifie si le caractère est un espace (`chr == 32`).
     - Vérifie si le caractère est une tabulation verticale, une nouvelle ligne, un retour chariot ou une tabulation horizontale (`chr > 10 && chr < 14`).
     - Retourne 1 si une des conditions est vraie, sinon retourne 0.

2. **Fonction `ft_atoi`**
   - **Entrée :** Un pointeur vers une chaîne de caractères (`char *str`).
   - **Sortie :** Un entier (`int`), la représentation numérique de la chaîne de caractères.
   - **Algorithme :**
     - Initialise les variables :
       - `nb` (le nombre à retourner) à 0.
       - `i` (l'index de la chaîne) à 0.
       - `factor` (le facteur de signe) à 1.
     - **Élimination des espaces blancs initiaux :**
       - Utilise une boucle `while` pour ignorer tous les caractères d'espacement en utilisant la fonction `is_whitespace`.
     - **Gestion des signes :**
       - Vérifie les caractères '+' ou '-'.
       - Si un '-' est rencontré, inverse la valeur de `factor`.
       - Incrémente `i` pour passer au caractère suivant.
     - **Conversion des caractères numériques :**
       - Utilise une boucle `while` pour traiter chaque caractère numérique de la chaîne.
       - Convertit chaque caractère en son équivalent numérique (`(int)str[i] - 48`).
       - Met à jour la valeur de `nb` en multipliant l'ancienne valeur par 10 et en ajoutant la nouvelle valeur.
       - Incrémente `i` pour passer au caractère suivant.
     - Retourne le produit de `factor` et `nb`, fournissant ainsi la valeur entière correspondant à la chaîne d'entrée.
