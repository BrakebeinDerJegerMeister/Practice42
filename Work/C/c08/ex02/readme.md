# Énoncé

| Exercice : 02                 |
| ----------------------------- |
| ft_abs.h                      |
| Dossier de rendu : ex02/      |
| Fichiers à rendre : ft_abs.h  |
| Fonctions Autorisées : Aucune |
• Écrire une macro ABS qui remplace son paramètre par sa valeur absolue :
```C
#define ABS(Value)
```
# Correction

```C
#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(value) ((value) ^ ((value) >> 31)) - ((value) >> 31)

#endif

```

# Démonstration

```C
#include "ft_abs.h"
#include <stdio.h>

void	test(int x)
{
	printf("Nombre : {%d}\n", x);
	printf("Valeur absolue : {%d}\n\n", ABS(x));
}

int	main(void)
{
	test(50);
	test(-2500);
	test(-0);
	test(-1);
	return (0);
}
```

```
Nombre : {50}
Valeur absolue : {50}

Nombre : {-2500}
Valeur absolue : {2500}

Nombre : {0}
Valeur absolue : {0}

Nombre : {-1}
Valeur absolue : {1}


Appuyez sur ENTRÉE ou tapez une commande pour continuer
```
# Explications

### Comprendre les composantes de la macro

1. **Décalage à Droite (`>>`)** :
   - `value >> 31` : Cette opération décale tous les bits de `value` de 31 positions vers la droite. En C, les entiers sont typiquement stockés sur 32 bits en complément à deux, où le bit le plus à gauche (bit de signe) détermine si le nombre est positif (0) ou négatif (1). En décalant `value` de 31 bits à droite, on ne garde que le bit de signe. Ainsi, si `value` est positif, le résultat est 0 (tous les bits sont 0); si `value` est négatif, le résultat est -1 (tous les bits sont 1).

2. **Opération XOR (`^`)** :
   - `value ^ (value >> 31)` : L'opérateur XOR compare les bits correspondants de `value` et de `value >> 31`. Si les bits comparés sont différents, le résultat est 1; s'ils sont identiques, le résultat est 0. Cela signifie que si `value` est négatif (et donc `value >> 31` est -1 ou, en binaire, tous les bits sont 1), cette opération inverse tous les bits de `value`. Si `value` est positif, les bits ne changent pas car XOR avec 0 laisse les bits inchangés.

3. **Soustraction (`-`)** :
   - `((value) ^ ((value) >> 31)) - ((value) >> 31)` : Cette partie finalise le calcul. Si `value` était négatif, rappelons-nous que les bits de `value` ont été inversés, donc l'opération a converti `value` en son complément (le pas vers sa valeur absolue). La soustraction de -1 (car `value >> 31` donne -1 pour un négatif) ajuste ce résultat en ajoutant 1, ce qui est nécessaire pour compléter la conversion de la représentation en complément à deux du nombre négatif en sa valeur absolue positive. Si `value` était déjà positif, cette soustraction n'a pas d'effet (0 - 0 = 0).

### Exemple Simplifié

Pour rendre cela plus clair, prenons un exemple avec un petit nombre binaire.

Supposons que `value` soit `-3`. En binaire, `-3` se représente comme `11111101` en complément à deux (sur 8 bits pour simplifier) :
- `value >> 31` devient `11111111` (tous les bits sont 1 car -3 est négatif).
- `value ^ (value >> 31)` convertit `11111101` en `00000010` (inversion de tous les bits).
- Soustraire `(value >> 31)` (qui est -1) à `00000010` donne `00000011`, qui est `3` en décimal.

Ainsi, la macro ABS calcule la valeur absolue de -3 comme +3, en utilisant uniquement des opérations binaires, sans aucun test conditionnel.

## Pourquoi mettre des parenthèses ?

La différence entre utiliser des parenthèses autour de `value` et ne pas les utiliser dans la définition de la macro ABS pourrait ne pas être immédiatement apparente dans des cas simples, mais elle devient critique lorsque la macro est utilisée avec des expressions plus complexes.

Voici un exemple pour illustrer cela :

Imaginons que vous utilisez la macro `ABS` avec l'expression `a + b` :

```c
int a = 5, b = -10;
int result = ABS(a + b); // Si on remplace par ABS sans parenthèses
```

Avec la définition **sans parenthèses** :

```c
#define ABS(x) (x ^ (x >> 31)) - (x >> 31)
```

L'expansion de la macro donne :

```c
(a + b ^ (a + b >> 31)) - (a + b >> 31)
```

Ici, selon les règles de priorité des opérateurs en C, le décalage à droite (`>>`) est évalué avant l'addition (`+`) et la soustraction (`-`), mais l'opérateur XOR (`^`) a la même priorité que `+` et `-`. Donc, l'expression serait traitée comme suit, ce qui n'est pas correct :

1. `(a + b >> 31)` est évalué en premier (le décalage est effectué avant l'addition, ce qui est incorrect sans parenthèses supplémentaires).
2. Ensuite, l'addition `a +` le résultat de `b ^ quelque chose` est faite, ce qui n'est pas l'intention originale.

Avec la définition **avec parenthèses** :

```c
#define ABS(x) ((x) ^ ((x) >> 31)) - ((x) >> 31)
```

L'expansion donne :

```c
((a + b) ^ ((a + b) >> 31)) - ((a + b) >> 31)
```

Ici, chaque `(a + b)` est correctement traité comme une unité distincte, garantissant que toutes les opérations (addition, décalage, XOR) sont appliquées à la totalité de l'expression `a + b`, et dans le bon ordre. Cela maintient la cohérence et la justesse de la valeur calculée.

Ainsi, les parenthèses assurent que peu importe la complexité de l'expression passée à la macro, elle sera traitée correctement comme une seule entité logique, évitant des erreurs subtiles liées à la priorité des opérations.