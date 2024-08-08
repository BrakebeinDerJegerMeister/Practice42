# Énoncé

| Exercice : 00                                                                                        |
| ---------------------------------------------------------------------------------------------------- |
| libft                                                                                                |
| Dossier de rendu : ex00/                                                                             |
| Fichiers à rendre : libft_creator.sh, ft_putchar.c, ft_swap.c, ft_putstr.c, ft_strlen.c, ft_strcmp.c |
| Fonctions Autorisées : write                                                                         |
• Créer votre bibliothèque ft. Elle s’appellera libft.a.
• Un shell script appelé libft_creator.sh compilera comme il le faut les fichiers
sources et créera votre bibliothèque.
• Cette bibliothèque doit contenir toutes les fonctions suivantes :
```C
void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
```
• Nous lancerons la commande suivante :
```sh
sh libft_creator.sh
```

# Correction

```sh
gcc -c -Wall -Wextra -Werror *.c
ar -r libtf.a *.o
ranlib libft.a
```

# Explications


## gcc

La commande `gcc -c -Wall -Wextra -Werror *.c` utilise le compilateur GCC pour compiler des fichiers source C (`*.c`) en fichiers objets (`*.o`) sans générer d'exécutable final. Voici une brève explication de chaque composant de cette commande :

- **`gcc`** : C'est le compilateur GNU pour le langage C.

- **`-c`** : Cette option indique au compilateur de ne pas linker les fichiers objets en un exécutable final. Au lieu de cela, GCC se limite à la compilation des fichiers source en fichiers objets.

- **`-Wall`** : Active un ensemble de messages d'avertissement pour signaler des constructions de code potentiellement problématiques.

- **`-Wextra`** : Active des messages d'avertissement supplémentaires qui ne sont pas inclus dans `-Wall`. Cela permet de détecter encore plus de problèmes potentiels.

- **`-Werror`** : Traite tous les avertissements comme des erreurs. Cela signifie que si GCC rencontre un avertissement lors de la compilation, il arrêtera le processus de compilation, refusant de produire les fichiers objets jusqu'à ce que le problème soit résolu.

- **`*.c`** : Cette partie indique de compiler tous les fichiers source C dans le répertoire courant. Le `*` est un joker qui représente tous les fichiers ayant l'extension `.c`.

Cette commande est souvent utilisée dans le développement pour s'assurer que le code est propre et exempt d'avertissements potentiels, ce qui peut aider à éviter des bugs subtils ou des comportements inattendus.

## Librairie

Une bibliothèque (ou librairie) en informatique est un ensemble de fonctions et de routines pré-écrites, organisées sous forme de fichiers, qui peuvent être utilisées par des programmes pour accomplir des tâches spécifiques. Les bibliothèques sont conçues pour réutiliser du code, réduire le temps de développement, et promouvoir la modularité et la maintenabilité du logiciel.

### Types de bibliothèques

1. **Bibliothèques statiques** :
   - Ce sont des collections de fichiers objets (`.o` ou `.obj`) rassemblés dans un seul fichier archive (`.a` sur Unix/Linux, `.lib` sur Windows).
   - Les fonctions des bibliothèques statiques sont copiées directement dans l'exécutable lors de la phase de linkage. Cela signifie que chaque exécutable qui utilise la bibliothèque a sa propre copie des fonctions de la bibliothèque.
   - Avantage : Pas de dépendance aux fichiers de la bibliothèque lors de l'exécution.
   - Inconvénient : Taille accrue de l'exécutable, mise à jour de la bibliothèque nécessitant une recompilation des programmes l'utilisant.

2. **Bibliothèques dynamiques** :
   - Également connues sous le nom de bibliothèques partagées (`.so` sur Unix/Linux, `.dll` sur Windows).
   - Les fonctions ne sont pas copiées dans l'exécutable mais sont chargées en mémoire au moment de l'exécution.
   - Avantage : Réduction de la taille des exécutables et possibilité de partager une seule instance de la bibliothèque entre plusieurs programmes en mémoire.
   - Inconvénient : Les fichiers de la bibliothèque doivent être présents sur le système lors de l'exécution.

### Utilisation des bibliothèques

Les bibliothèques sont utilisées pour encapsuler des fonctionnalités communes ou spécifiques afin de :

1. **Réduire la duplication de code** : Les fonctions couramment utilisées (comme la gestion des chaînes de caractères, des fichiers, des mathématiques avancées) sont centralisées dans des bibliothèques. Cela évite de réécrire le même code dans chaque projet.

2. **Faciliter la maintenance** : Les erreurs ou les améliorations peuvent être effectuées dans un seul endroit (la bibliothèque), et tous les programmes qui l'utilisent en bénéficient après une mise à jour.

3. **Promouvoir la modularité** : En séparant les fonctionnalités en bibliothèques, les programmes deviennent plus modulaires et plus faciles à gérer.

4. **Encapsulation de la complexité** : Les bibliothèques peuvent encapsuler des tâches complexes (comme le traitement graphique, l'accès aux bases de données, les protocoles réseau) derrière des interfaces simples, permettant aux développeurs de se concentrer sur la logique de leur application sans se soucier des détails internes.

### Exemple d'utilisation

Lors de la création d'un programme en C, un développeur peut utiliser la bibliothèque standard C pour des tâches courantes. Par exemple, `printf` pour l'affichage, `malloc` pour la gestion de la mémoire dynamique, etc. Ces fonctions sont définies dans des bibliothèques comme `libc`. Lors de la compilation, le compilateur lie le code du programme avec cette bibliothèque pour produire l'exécutable final.
## ar

La commande `ar` est un utilitaire Unix utilisé pour créer, modifier et extraire des fichiers à partir d'archives. Les archives créées avec `ar` sont souvent utilisées pour regrouper plusieurs fichiers objets en une seule bibliothèque statique, généralement avec l'extension `.a`. Ces bibliothèques sont ensuite utilisées lors de l'étape de linkage pour assembler des programmes.

L'option `r` est suffisante. L'utilisation de `ar -r libft.a *.o` ajoutera ou remplacera les fichiers objets dans la bibliothèque `libft.a`. L'option `c` est superflue car `r` crée déjà la bibliothèque si elle n'existe pas.

Voici quelques-unes des options et fonctionnalités les plus courantes de `ar` :

1. **Création et modification d'archives** :
    
    - `ar r [archive] [fichiers]` : Remplace ou ajoute les fichiers spécifiés dans l'archive. Si l'archive n'existe pas, elle est créée.
    - `ar c [archive]` : Signifie "create", crée une nouvelle archive sans afficher de message si elle existe déjà (généralement utilisé en combinaison avec d'autres options comme `r`).
    - `ar d [archive] [fichiers]` : Supprime les fichiers spécifiés de l'archive.
    - `ar q [archive] [fichiers]` : Ajoute rapidement les fichiers à la fin de l'archive sans remplacer les fichiers existants (peut être plus rapide que `r`).
    - `ar s [archive]` : Crée un index (table des symboles) pour l'archive, permettant une recherche plus rapide des symboles par le linker. Cette opération est souvent équivalente à l'utilisation de `ranlib`.
2. **Extraction de fichiers** :
    
    - `ar x [archive] [fichiers]` : Extrait les fichiers spécifiés de l'archive. Si aucun fichier n'est spécifié, tous les fichiers de l'archive sont extraits.
3. **Affichage des informations d'une archive** :
    
    - `ar t [archive]` : Affiche une liste des fichiers contenus dans l'archive.
    - `ar p [archive] [fichier]` : Affiche le contenu d'un fichier spécifique à partir de l'archive.
    - `ar v` : Option verbale pour afficher des informations supplémentaires sur les actions entreprises par `ar`.

Les archives créées par `ar` ne sont pas compressées par défaut et sont souvent utilisées pour la création de bibliothèques statiques dans les environnements de développement de logiciels.

## ranlib

`ranlib` est un utilitaire utilisé pour générer un index (ou "table des symboles") pour les bibliothèques statiques (fichiers `.a`) dans les systèmes Unix et Linux. Cet index permet aux liens ultérieurs d'accéder plus rapidement aux symboles contenus dans la bibliothèque.

En pratique, après avoir créé une bibliothèque statique avec des fichiers objets, on utilise `ranlib` pour optimiser l'accès aux symboles lors de la liaison. Cela est particulièrement important si la bibliothèque contient des fichiers objets qui dépendent les uns des autres. Sans l'index généré par `ranlib`, l'éditeur de liens pourrait avoir des difficultés à résoudre les symboles correctement, surtout si l'ordre des objets dans la bibliothèque n'est pas optimal.