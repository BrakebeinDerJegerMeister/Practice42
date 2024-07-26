# Énoncé

| Exercice : 04                        |
| ------------------------------------ |
| ft_strs_to_tab                       |
| Dossier de rendu : ex04/             |
| Fichiers à rendre : ft_strs_to_tab.c |
| Fonctions Autorisées : malloc, free  |
• Ecrire une fonction qui prend en parametre un tableau de chaîne de caractères
ainsi que la taille de ce tableau et renvoie un tableau de structure.
• Elle devra être prototypée de la façon suivante :
```C
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
```
• Elle doit transformer chaque element du tableau de chaîne de caractères en struc-
ture.
• La structure sera définie dans le fichier ft_stock_str.h comme suit :
```C
typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
}	t_stock_str;
```
◦ size étant la taille de la chaîne de caractères ;
◦ str étant la chaîne de caractères ;
◦ copy étant une copie de la chaîne de caractères ;
• Elle doit garder l’ordre des elements de av.
• Le tableau de structures devra être alloué et le dernièr element aura 0 pour valeur
de str, ceci afin de signifier la fin du tableau.
• Si une erreur d’allocation arrive elle doit renvoyer un pointeur NULL.
• Nous testons votre fonction avec notre ft_show_tab (exercice suivant). Prenez les
mesures nécessaires pour que cela fonctionne !
# Correction
#### ft_strs_to_tab.c
```C
#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (save);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	char		*cpy;
	t_stock_str	*stk;

	cpy = NULL;
	stk = (t_stock_str *)malloc(sizeof(t_stock_str) * (1 + ac));
	if (!stk)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stk[i].size = ft_strlen(av[i]);
		stk[i].str = av[i];
		free(cpy);
		stk[i].copy = malloc((stk[i].size + 1) * sizeof(char));
		if (!stk[i].copy)
			return (NULL);
		ft_strcpy(stk[i].copy, av[i]);
		i++;
	}
	stk[ac].str = 0;
	free(cpy);
	return (stk);
}
```

#### ft_stock_str.h
```C
#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
}	t_stock_str;

#endif
```

# Démonstration

```C
#include <stdio.h>

void	print_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		printf("\n------ Entrée %d ------\n", i);
		printf("size : {%d}\n", par[i].size);
		printf("str : {%s}\n", par[i].str);
		par[i].copy[0] = 'Z';
		printf("copy : {%s}\n", par[i].copy);
		i++;
	}
}

int	main(void)
{
	char		*av[] = {"Hello", "World", "Test", "Example"};
	t_stock_str	*stk;

	stk = ft_strs_to_tab(4, av);
	if (stk != NULL)
	{
		print_tab(stk);
	}
	return (0);
}
```

```
Appuyez sur ENTRÉE ou tapez une commande pour continuer
ft_strs_to_tab.c: Error!
Error: INCLUDE_START_FILE   (line:  66, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  86, col:  23):	Declaration and assignation on a single line

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer

------ Entrée 0 ------
size : {5}
str : {Hello}
copy : {Zello}

------ Entrée 1 ------
size : {5}
str : {World}
copy : {Zorld}

------ Entrée 2 ------
size : {4}
str : {Test}
copy : {Zest}

------ Entrée 3 ------
size : {7}
str : {Example}
copy : {Zxample}

Appuyez sur ENTRÉE ou tapez une commande pour continuer
```

# typedef

Les alias en C, souvent créés avec le mot-clé `typedef`, sont des outils puissants pour simplifier la gestion des types de données complexes et améliorer la lisibilité du code. 
### Qu'est-ce qu'un Alias en C?

Un alias est une façon de donner un autre nom à un type de données existant. En C, cela est couramment fait avec `typedef`, qui permet de redéfinir des types complexes (comme les structures ou les pointeurs sur fonctions) de manière plus simple et plus lisible.

### Syntaxe de Base

La syntaxe de base de `typedef` est la suivante :

```c
typedef type_existant nouvel_alias;
```

### Exemple d'Utilisation

1. **Alias pour les Types Primitifs**

   Il est possible de créer des alias pour les types primitifs, mais cela est moins courant car cela peut parfois rendre le code plus difficile à comprendre pour quelqu'un qui s'attend à voir les types primitifs standards.

   ```c
   typedef int entier;
   typedef double reel;
   ```

2. **Alias pour les Structures**

   C'est l'utilisation la plus courante de `typedef`, permettant de simplifier la déclaration de structures et de pointeurs vers des structures.

   ```c
   typedef struct s_point {
       int x, y;
   } Point;
   ```

   Après cette définition, `Point` peut être utilisé pour déclarer des variables de type `struct s_point`.

3. **Alias pour les Pointeurs**

   `typedef` est très utile pour simplifier les déclarations de pointeurs, particulièrement pour les pointeurs sur fonctions ou les structures.

   ```c
   typedef char *Chaine;

   typedef void (*FonctionCallback)(int, double);
   ```

   Ici, `Chaine` est un alias pour `char*` et `FonctionCallback` pour un pointeur sur une fonction prenant `int` et `double` comme paramètres et ne renvoyant rien.

### Avantages de l'Utilisation d'Alias

- **Clarté et Concision** : Les alias peuvent rendre le code plus clair et plus concis, en particulier quand on travaille avec des types complexes.
- **Facilité de Maintenance** : Modifier le type de base d'un alias (comme la structure d'un type défini) ne nécessite qu'une seule modification dans la déclaration `typedef`. Toutes les variables de cet alias dans le code utiliseront la nouvelle définition.
- **Portabilité** : Les alias peuvent aider à rendre le code plus portable entre différentes plateformes en isolant les spécificités des types de données dans les déclarations `typedef`.

### Bonnes Pratiques

- **Nommer les Alias de manière Significative** : Les noms des alias doivent clairement indiquer ce qu'ils représentent pour éviter toute confusion.
- **Utiliser `typedef` pour Complexifier, pas pour Simplifier les Types Primitifs** : Il est généralement conseillé d'éviter de redéfinir les types primitifs à moins qu'il n'y ait une raison spécifique, comme la nécessité de clarifier l'usage d'un type particulier pour des raisons de portabilité ou de spécification de domaine.
- **Documentation** : Comme les alias peuvent parfois masquer la complexité, assurez-vous que leur utilisation est bien documentée, surtout dans les projets de grande envergure ou les bibliothèques publiques.

# sizeof

`sizeof` est un opérateur en C, et non une fonction. C'est un opérateur compile-time qui est utilisé pour déterminer la taille en octets d'un type de données ou d'une variable. L'utilisation de `sizeof` ne nécessite pas d'inclure des parenthèses sauf lorsqu'il est utilisé avec un type de données. Voici quelques clarifications et exemples :

### Utilisation de `sizeof`

1. **Avec des types de données** : Lorsque vous utilisez `sizeof` avec un type de données, vous devez utiliser des parenthèses.
   ```c
   size_t size = sizeof(int);
   ```

2. **Avec des variables** : Lorsque vous utilisez `sizeof` avec des variables, les parenthèses sont optionnelles, sauf pour la clarté ou dans des expressions complexes.
   ```c
   int x;
   size_t size_x = sizeof x;  // Les parenthèses sont optionnelles
   size_t size_y = sizeof(x); // Les parenthèses ajoutent de la clarté
   ```

### Caractéristiques de `sizeof`

- **Évaluation à la Compilation** : Comme `sizeof` est évalué à la compilation, il ne peut pas être utilisé pour déterminer la taille de structures de données dont la taille n'est pas connue au moment de la compilation, comme les tableaux dynamiques ou les structures allouées dynamiquement dont la taille peut changer à l'exécution.

- **Résultat** : Le résultat de `sizeof` est de type `size_t`, qui est un type entier non signé utilisé pour représenter la taille d'un objet.

- **Utilisation Courante** : `sizeof` est couramment utilisé en conjonction avec `malloc` pour allouer de la mémoire pour des types de données ou des tableaux de manière sûre :
   ```c
   int *ptr = malloc(sizeof(int) * 10);  // Alloue de la mémoire pour un tableau de 10 entiers
   ```

### Avantages de l'opérateur `sizeof`

- **Portabilité** : Utiliser `sizeof` permet de rendre le code plus portable, car la taille des types de données peut varier selon les architectures. Par exemple, la taille d'un `int` peut être de 4 octets sur une architecture et de 2 octets sur une autre.

- **Sécurité** : Il aide à prévenir des erreurs telles que le dépassement de tampon en s'assurant que les opérations de mémoire prennent en compte la taille réelle des données.

En résumé, `sizeof` est un outil puissant en C qui aide à gérer la mémoire de manière efficace et sûre, en fournissant une méthode standardisée pour obtenir la taille des types de données au moment de la compilation.