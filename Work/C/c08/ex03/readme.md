# Énoncé

| Exercice : 03                  |
| ------------------------------ |
| ft_point.h                     |
| Dossier de rendu : ex03/       |
| Fichiers à rendre : ft_point.h |
| Fonctions Autorisées : Aucune  |
• Écrire un fichier ft_point.h qui fera compiler le main suivant :
```C
#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;
	set_point(&point);
	return (0);
}
```

# Correction

```C
#ifndef FT_POINT_H
# define FT_POINT_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

#endif
```

# Explications

En premier choix j'aurais écrit :

```C
#ifndef FT_POINT_H
# define FT_POINT_H

struct t_point
{
	int	x;
	int	y;
};

#endif
```

Mais selon Norminette une structure doit avoir un nom et celui-ci doit commencer par s_ donc nous n'avons pas le choix que d'utiliser l'écriture avec typedef.

L'instruction `typedef struct` en C est utilisée pour définir un nouveau type de données à partir d'une structure, permettant de créer des instances de cette structure plus simplement et plus clairement.

### Syntaxe de Base

La syntaxe de base pour définir une structure avec `typedef` est la suivante :

```c
typedef struct name1 {
    // déclaration des membres de la structure
} name2;
```

### Composantes de la Déclaration

1. **`struct name1`** : `name1` est le nom de la structure. Ce nom est optionnel et peut être omis. S'il est présent, il sert principalement dans des situations où la structure doit être capable de se référencer elle-même, par exemple pour des pointeurs dans des structures liées comme des listes chaînées.

2. **Déclaration des Membres** : Entre les accolades `{}` vous déclarez les membres de la structure. Ces membres peuvent être de n'importe quel type, y compris d'autres structures, des unions, des types de base (comme `int`, `float`, etc.), ou des pointeurs.

3. **`name2`** : C'est le nom du nouveau type que vous créez avec `typedef`. Une fois cette déclaration effectuée, `name2` peut être utilisé comme n'importe quel autre type de données dans votre programme. Par exemple, vous pouvez déclarer des variables de type `name2` sans avoir à utiliser le mot-clé `struct` à chaque fois.

### Exemple Pratique

Voici un exemple concret d'utilisation de `typedef` avec une structure :

```c
typedef struct {
    int id;
    float salary;
    char name[100];
} Employee;
```

Dans cet exemple :
- Nous avons défini un type `Employee`.
- Ce type a trois champs : `id` (un entier), `salary` (un flottant) et `name` (un tableau de caractères).
- Après cette déclaration, vous pouvez créer des instances de `Employee` simplement en déclarant :

```c
Employee emp1, emp2;
emp1.id = 1;
emp1.salary = 50000.0;
strcpy(emp1.name, "John Doe");
```

### Avantages de `typedef` avec `struct`

- **Clarté** : L'utilisation de `typedef` rend le code plus clair et plus facile à lire, car vous n'avez plus besoin de préfixer chaque déclaration de variable structurelle avec le mot-clé `struct`.
- **Facilité d'Utilisation** : Cela simplifie la déclaration de variables et de paramètres de fonctions, en particulier pour des types complexes comme les structures.
- **Maintenance** : Modifier la structure de base ne nécessite pas de changer le type dans toutes les parties du programme où elle est utilisée, puisque le `typedef` gère cela de manière transparente.

Utiliser `typedef` avec des structures est donc une pratique courante en C pour améliorer la lisibilité et la gestion du code, tout en permettant une abstraction et une encapsulation plus efficaces des données dans votre programme.

