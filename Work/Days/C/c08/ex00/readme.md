# Énoncé

| Exercice : 00                 |
| ----------------------------- |
| ft.h                          |
| Dossier de rendu : ex00/      |
| Fichiers à rendre : ft.h      |
| Fonctions Autorisées : Aucune |
• Écrire votre fichier ft.h
• Il contient tous les prototypages des fonctions :
```C
void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
```

# Correction

# Explications

J'ai été obligé de regarder un peu ailleurs pour comprendre en quoi consistait cet exercice...

De plus, selon GPT :

Dans cet exercice, on vous demande de créer un fichier d'en-tête en C, nommé `ft.h`, qui contiendra les prototypes des fonctions spécifiées. Un prototype de fonction en C est une déclaration qui fournit des informations essentielles sur la fonction : le type de retour, le nom de la fonction, et les types de ses paramètres. Cela permet à d'autres fichiers C dans votre projet d'appeler ces fonctions, même si leurs définitions sont dans d'autres fichiers. C'est une pratique courante pour organiser les programmes en C, permettant une compilation séparée et une meilleure gestion du code.

Voici ce que vous devez faire:

1. **Créer le fichier `ft.h`**: Ce fichier sera placé dans le dossier `ex00/` comme spécifié. Vous devez créer ce fichier d'en-tête et y écrire les prototypes de fonctions.

2. **Écrire les prototypes des fonctions**: Dans votre fichier `ft.h`, vous déclarerez les fonctions suivantes:
   - `void ft_putchar(char c);`
   - `void ft_swap(int *a, int *b);`
   - `void ft_putstr(char *str);`
   - `int ft_strlen(char *str);`
   - `int ft_strcmp(char *s1, char *s2);`

Chacun de ces prototypes informe le compilateur sur la manière d'utiliser ces fonctions. Le type `void` indique qu'une fonction ne retourne aucune valeur, tandis que `int` indique un retour de type entier. Les paramètres entre parenthèses indiquent les arguments que la fonction attend.

3. **Pourquoi c'est nécessaire**: Les prototypes sont essentiels pour assurer que les fonctions sont utilisées correctement à travers différents fichiers dans un projet. Ils aident également à éviter des erreurs communes en type-checking lors de la compilation. Cela permet de maintenir votre code propre, organisé, et facilement modifiable ou extensible.

Voici un exemple de ce à quoi votre fichier `ft.h` pourrait ressembler :

```c
#ifndef FT_H
#define FT_H

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

#endif
```

La directive `#ifndef` au début et `#endif` à la fin est utilisée pour éviter les inclusions multiples du même fichier d'en-tête, ce qui pourrait causer des erreurs de compilation.

## Directives

La ligne `#define FT_H` dans le fichier d'en-tête `ft.h` fait partie d'un mécanisme de prévention des inclusions multiples, souvent utilisé en C et C++. Cela sert à éviter les problèmes et erreurs qui peuvent survenir si le même fichier d'en-tête est inclus plusieurs fois dans un ou plusieurs fichiers source. Ce mécanisme utilise des directives de préprocesseur : `#ifndef`, `#define`, et `#endif`.

Voici comment cela fonctionne et pourquoi c'est important :

### 1. **`#ifndef` et `#define`**
   - **`#ifndef`** (if not defined) vérifie si un certain identifiant (dans ce cas, `FT_H`) n'a pas déjà été défini.
   - **`#define`** définit cet identifiant. Cela se produit seulement si l'identifiant n'était pas déjà défini, grâce à la condition posée par `#ifndef`.

### 2. **Prévention des inclusions multiples**
   - Si vous incluez `ft.h` dans plusieurs fichiers source, ou indirectement via d'autres fichiers d'en-tête qui incluent `ft.h`, le préprocesseur vérifie à chaque fois si `FT_H` a été défini.
   - Lors de la première inclusion, `FT_H` n'est pas défini, donc le préprocesseur passe au-delà de la directive `#ifndef`, définit `FT_H`, et inclut le contenu de `ft.h`.
   - Pour toute inclusion subséquente du même fichier d'en-tête, `FT_H` sera déjà défini. La condition `#ifndef FT_H` sera donc fausse, et le préprocesseur sautera tout le contenu de `ft.h`, évitant ainsi de le traiter à nouveau.

### 3. **Exemple complet**

Voici à quoi ressemblerait typiquement l'utilisation de ce mécanisme dans un fichier d'en-tête :

```c
#ifndef FT_H   // Si FT_H n'est pas déjà défini
#define FT_H   // Définir FT_H

// Prototypes de fonctions et autres déclarations

#endif  // Fin de la condition #ifndef
```

### 4. **Importance**
   - Cette approche évite les problèmes tels que les définitions de types multiples, la rédéclaration de variables globales, ou les conflits de définition qui peuvent causer des erreurs de compilation ou des comportements erratiques du programme.
   - Elle rend le code plus sûr et plus robuste en garantissant que chaque bloc d'en-tête est inclus une seule fois, même dans des projets complexes avec de nombreuses dépendances entre fichiers.

C'est donc une bonne pratique standard en développement C/C++ pour maintenir la qualité et la maintenabilité du code.


## A savoir

Norminette à besoin que l'on écrive :

```C
# define FT_H
```

Au lieu de :

```C
#define FT_H
```

~~#define FT_H~~

Sinon elle n'est pas contente :

```
ft.h: Error!
Error: PREPROC_BAD_INDENT   (line:  14, col:   1):	Bad preprocessor indentation
```

