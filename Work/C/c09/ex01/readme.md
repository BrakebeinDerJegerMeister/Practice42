# Énoncé

| Exercice : 01                 |
| ----------------------------- |
| Makefile                      |
| Dossier de rendu : ex01/      |
| Fichiers à rendre : Makefile  |
| Fonctions Autorisées : Aucune |
• Écrire le Makefile qui compile une librairie libft.a.
• Votre makefile doit afficher chaque commande qu’il effectue sans aucune fioriture.
• Votre makefile ne doit pas effectuer de commande inutile.
• Le Makefile ira chercher les fichiers sources dans le dossier srcs.
• Ces fichiers sources seront : ft_putchar.c, ft_swap.c, ft_putstr.c, ft_strlen.c, ft_strcmp.c
• Le Makefile ira chercher les fichiers headers dans le dossier includes.
• Ces fichiers headers seront : ft.h
• Il devra compiler vos fichiers c en utilisant gcc et les options -Wall -Wextra -Werror
flags dans cet ordre.
• La lib sera à la racine de l’exercice.
• Les fichiers .o devront être à coté de leur fichier .c respectif.
• Le Makefile devra également implémenter des règles clean, fclean, re, la règle
all et bien sur libft.a.
• Lancer juste make doit être équivalent à make all.
• La règle all devra faire comme make libft.a.
• la règle clean devra retirer tous les fichiers temporaires générés.
• La règle fclean fait l’équivalent d’un make clean et éfface aussi le binaire créé lors du make all.
• La règle re fait l’équivalent d’un make fclean puis un make all.
• Votre makefile ne doit pas recompiler les fichiers inutilement.
• Nous ne ramasserons que votre Makefile et testerons avec nos fichiers.
# Correction

```Makefile
SOURCES = $(wildcard srcs/*.c)
OBJECTS = $(SOURCES:.c=.o)

all: libft.a

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I includes
	
libft.a: $(OBJECTS)
	ar -r libft.a $(OBJECTS)
	ranlib libft.a

clean:
	rm -f $(OBJECTS)

fclean: 
	$(MAKE) clean
	rm -f libft.a

re: 
	$(MAKE) fclean
	$(MAKE) all
```

# Démonstration

```
Repo Git : Practice42/Work/C/c09/ex01  (main) $ make
gcc -Wall -Wextra -Werror -c srcs/ft_putchar.c -o srcs/ft_putchar.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_putstr.c -o srcs/ft_putstr.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_strlen.c -o srcs/ft_strlen.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_swap.c -o srcs/ft_swap.o -I includes
ar -r libft.a srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
ar: création de libft.a
ranlib libft.a
Repo Git : Practice42/Work/C/c09/ex01  (main) $ make re
make fclean
make[1] : on entre dans le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
make clean
make[2] : on entre dans le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
rm -f srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
make[2] : on quitte le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
rm -f libft.a
make[1] : on quitte le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
make all
make[1] : on entre dans le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
gcc -Wall -Wextra -Werror -c srcs/ft_putchar.c -o srcs/ft_putchar.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_putstr.c -o srcs/ft_putstr.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_strcmp.c -o srcs/ft_strcmp.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_strlen.c -o srcs/ft_strlen.o -I includes
gcc -Wall -Wextra -Werror -c srcs/ft_swap.c -o srcs/ft_swap.o -I includes
ar -r libft.a srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
ar: création de libft.a
ranlib libft.a
make[1] : on quitte le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
Repo Git : Practice42/Work/C/c09/ex01  (main) $ make fclean
make clean
make[1] : on entre dans le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
rm -f srcs/ft_putchar.o srcs/ft_putstr.o srcs/ft_strcmp.o srcs/ft_strlen.o srcs/ft_swap.o
make[1] : on quitte le répertoire « /home/profchaos/Desktop/Practice42/Work/C/c09/ex01 »
rm -f libft.a
Repo Git : Practice42/Work/C/c09/ex01  (main) $ 
```
# Explications

Un fichier Makefile est utilisé pour automatiser le processus de compilation et de gestion des dépendances dans un projet de programmation. Il contient des règles et des instructions pour compiler le code source, générer des exécutables, et effectuer d'autres tâches comme le nettoyage des fichiers temporaires ou l'exécution de tests.

### Définition des variables
```makefile
SOURCES = $(wildcard srcs/*.c)
OBJECTS = $(SOURCES:.c=.o)
```
- **`SOURCES` :** Utilise la fonction `wildcard` de Make pour capturer tous les fichiers `.c` dans le répertoire `srcs/`. Cela permet d'automatiser la récupération des fichiers sources sans les lister manuellement.
- **`OBJECTS` :** Transforme chaque fichier source listé dans `SOURCES` de `.c` en `.o`. Cette substitution assure que chaque fichier source a un fichier objet correspondant qui sera compilé.

### Cible principale
```makefile
all: libft.a
```
- **Description :** Définit `all` comme la cible principale qui, par convention, est ce que `make` exécutera par défaut s'il n'est pas donné de cible spécifique. `all` dépend de `libft.a`, indiquant à `make` de construire `libft.a`.

### Règles de compilation
```makefile
%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I includes
```
- **`%.o: %.c` :** C'est une règle pattern. Le `%` sert de placeholder, permettant à cette règle d'être appliquée à tout fichier `.c` pour créer un fichier `.o` correspondant.
- **`gcc ...` :** La commande de compilation. 
  - **`-Wall -Wextra -Werror` :** Active tous les avertissements principaux (`-Wall`), les avertissements supplémentaires (`-Wextra`), et traite tous les avertissements comme des erreurs (`-Werror`).
  - **`-c` :** Indique à GCC de compiler le fichier source en fichier objet sans lier.
  - **`$<` :** Variable automatique représentant la première dépendance de la règle, ici le fichier source `.c`.
  - **`-o $@` :** Spécifie le nom du fichier de sortie (`$@` est la cible de la règle, le fichier `.o`).
  - **`-I includes` :** Ajoute `includes` au chemin de recherche pour les fichiers d'en-tête.

### Création de la bibliothèque
```makefile
libft.a: $(OBJECTS)
	ar -r libft.a $(OBJECTS)
```
- **`libft.a: $(OBJECTS)` :** Spécifie que `libft.a` doit être recompilé si un des fichiers dans `$(OBJECTS)` est plus récent que `libft.a`.
- **`ar -r` :** Utilise l'archiver pour créer ou mettre à jour `libft.a` avec les fichiers objets listés.

### Nettoyage
```makefile
clean:
	rm -f $(OBJECTS)
```
- **`clean` :** Une cible phony pour supprimer tous les fichiers objets, facilitant un nouveau départ propre.

```makefile
fclean: 
	$(MAKE) clean
	rm -f libft.a
```
- **`fclean` :** Étend `clean` pour inclure également la suppression de `libft.a`.

```makefile
re: 
	$(MAKE) fclean
	$(MAKE) all
```
- **`re` :** Une règle pour "recompiler" tout. Elle nettoie tout d'abord le projet avec `fclean`, puis reconstruit tout avec `all`.

### Notes sur les symboles et méthodologies

- **`$@`, `$<` :** Ces variables automatiques simplifient la gestion des noms de fichiers et réduisent les erreurs en automatisant les parties répétitives des commandes.
- **`$(MAKE)` vs `make` :** Utiliser `$(MAKE)` pour invoquer `make` dans les sous-appels garantit que les mêmes options sont passées au sous-make, telles que les variables d'environnement ou d'autres options de ligne de commande.