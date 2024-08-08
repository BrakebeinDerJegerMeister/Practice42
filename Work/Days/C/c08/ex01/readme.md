# Énoncé

| Exercice : 01                    |
| -------------------------------- |
| ft_boolean.h                     |
| Dossier de rendu : ex01/         |
| Fichiers à rendre : ft_boolean.h |
| Fonctions Autorisées : Aucune    |
• Écrire un fichier ft_boolean.h qui fera compiler et fonctionner correctement le
main suivant :
```C
#include "ft_boolean.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}
```
• Ce programme devra afficher
```
I have an even number of arguments.
```
• ou
```
I have an odd number of arguments.
```
# Correction

```C
#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>
# define TRUE 1
# define FALSE 0
# define EVEN(n) !(n % 2)
# define EVEN_MSG "I have an even number of arguements.\n"
# define ODD_MSG "I have an odd number of arguements.\n"
# define SUCCESS 0

typedef int	t_bool;

#endif
```

# Démonstration

```
Repo Git : Practice42/Work/C/c08/ex01  (main) $ ./a.out 1 2 
I have an even number of arguments.
Repo Git : Practice42/Work/C/c08/ex01  (main) $ ./a.out 1 2 3
I have an odd number of arguments.
Repo Git : Practice42/Work/C/c08/ex01  (main) $ 
```
# Explications

Ce fichier est un exemple d'en-tête en C destiné à fournir une bibliothèque de facilités pour manipuler des booléens et tester la parité des nombres. Voici les différents types d'objets que l'on y rencontre :

1. **Directives de préprocesseur** :
   - `#ifndef`, `#define`, `#endif` : Ces directives vérifient si `FT_BOOLEAN_H` n'a pas déjà été défini pour prévenir les inclusions multiples du même fichier d'en-tête. Si `FT_BOOLEAN_H` n'est pas défini, il le définit et le contenu entre `#ifndef` et `#endif` est utilisé.
   - `#include <unistd.h>` : Inclut les déclarations pour les appels système et les constantes utilisées par le compilateur.

2. **Définitions de macros** :
   - `TRUE` et `FALSE` : Définies respectivement à 1 et 0 pour représenter les valeurs booléennes.
   - `EVEN(n)` : Macro qui retourne `1` (vrai) si `n` est pair, sinon `0` (faux). Elle utilise l'opérateur modulo pour vérifier si le reste de la division de `n` par 2 est zéro.
   - `EVEN_MSG` et `ODD_MSG` : Définissent des messages à afficher selon que le nombre d'arguments est pair ou impair.
   - `SUCCESS` : Défini à 0, utilisé typiquement pour indiquer qu'une fonction s'est exécutée sans erreur.

3. **Définition de type** :
   - `typedef int t_bool;` : Définit un nouveau type `t_bool` comme synonyme de `int`, probablement utilisé pour représenter un booléen dans le contexte de ce fichier d'en-tête.

Ce fichier d'en-tête encapsule donc des fonctionnalités liées à la manipulation de valeurs booléennes et la vérification de parité, tout en protégeant contre les inclusions multiples grâce aux directives du préprocesseur.