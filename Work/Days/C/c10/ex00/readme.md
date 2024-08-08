# Énoncé

| Exercice : 00                                                    |
| ---------------------------------------------------------------- |
| display_file                                                     |
| Dossier de rendu : ex00/                                         |
| Fichiers à rendre : Makefile, et les fichiers de votre programme |
| Fonctions Autorisées : close, open, read, write                  |
• Écrire un programme appelé ft_display_file qui affiche sur la sortie standard
uniquement le contenu du fichier passé en argument.
• Le répertoire de rendu aura un Makefile avec une règle all, une règle clean, et
une règle fclean. Le binaire s’appellera ft_display_file.
• La fonction malloc est interdite. Vous pouvez faire l’exercice uniquement en dé-
clarant un tableau de taille fixe.
• Tous les fichiers passés en paramètre seront valides.
• Les messages d’erreurs devront être affichés sur la sortie leur étant réservée et en
étant suivi d’un retour à la ligne.
• Si il n’y aucun argument, votre programme doit afficher
```
File name missing.
```
• Si il y a trop d’argument, votre programme doit afficher
```
Too many arguments.
```
• Si le fichier n’est pas lisible, votre programme doit afficher
```
Cannot read file.
```
# Correction

```C
#include <unistd.h>
#include <fcntl.h>

int	disp_file(char *filename)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		bytes_read = read(fd, buffer, 1023);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		write(1, buffer, bytes_read);
	}
	close(fd);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ret;

	ret = 0;
	if (argc < 2)
		write(2, "File name missing.\n", 19);
	if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	if (argc != 2)
		return (1);
	ret = disp_file(argv[1]);
	if (ret)
	{
		write(2, "Cannot read file.\n", 18);
		return (1);
	}
	return (0);
}
```

```make
SRCS = srcs/ft_display_file.c
OBJS = $(SRCS:.c=.o)
NAME = ft_display_file

all: $(NAME)

$(NAME): $(OBJS)
	gcc $^ -o $@ -Wall -Wextra -Werror

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re
```
# Démonstration

```
Repo Git : Practice42/Work/C/c10/ex00  (main) $ make 
all              clean            fclean           ft_display_file  re
Repo Git : Practice42/Work/C/c10/ex00  (main) $ make
gcc -c srcs/ft_display_file.c -o srcs/ft_display_file.o -Wall -Wextra -Werror
gcc srcs/ft_display_file.o -o ft_display_file -Wall -Wextra -Werror
Repo Git : Practice42/Work/C/c10/ex00  (main) $ ./
ft_display_file  srcs/            
Repo Git : Practice42/Work/C/c10/ex00  (main) $ ./ft_display_file 
File name missing.
Repo Git : Practice42/Work/C/c10/ex00  (main) $ ./ft_display_file Makefile 
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: profchaos <temp@temp.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 12:01:58 by profchaos         #+#    #+#              #
#    Updated: 2024/07/29 12:51:48 by profchaos        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_display_file.c
OBJS = $(SRCS:.c=.o)
NAME = ft_display_file

all: $(NAME)

$(NAME): $(OBJS)
	gcc $^ -o $@ -Wall -Wextra -Werror

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re
Repo Git : Practice42/Work/C/c10/ex00  (main) $ 
```
# Explications


La fonction `disp_file` est conçue pour afficher le contenu d'un fichier spécifié par son nom, `filename`. Elle utilise les appels système bas niveau pour ouvrir, lire, et écrire le contenu du fichier à l'écran.

### Analyse du code

```c
int	disp_file(char *filename)
{
	int		fd;           // File descriptor for the opened file
	char	buffer[1024]; // Buffer to store the data read from the file
	int		bytes_read;   // Number of bytes actually read by read()

	fd = open(filename, O_RDONLY); // Open the file in read-only mode
	if (fd == -1)
		return (1);               // Return 1 if the file cannot be opened
```

- **Ouverture du fichier** : La fonction commence par tenter d'ouvrir le fichier spécifié en utilisant `open()`. Elle passe le nom du fichier et le flag `O_RDONLY`, indiquant qu'elle veut ouvrir le fichier en mode lecture seule.
- **Gestion d'erreur** : Si `open()` renvoie `-1`, cela signifie que l'ouverture du fichier a échoué (peut-être parce que le fichier n'existe pas ou l'utilisateur n'a pas les droits nécessaires pour y accéder). Dans ce cas, la fonction retourne `1` pour indiquer une erreur.

```c
	while (1)
	{
		bytes_read = read(fd, buffer, 1023); // Read up to 1023 bytes from the file
		if (bytes_read <= 0)
			break;                          // Break the loop if the end of the file is reached or an error occurs
		buffer[bytes_read] = '\0';          // Null-terminate the string
		write(1, buffer, bytes_read);       // Write the read content to stdout
	}
	return (0);
}
```

- **Lecture du fichier** : La fonction entre dans une boucle infinie où elle lit jusqu'à 1023 octets du fichier à la fois. La valeur 1023 est utilisée pour laisser de la place pour le caractère nul de fin de chaîne, ce qui est important pour utiliser des fonctions qui manipulent des chaînes de caractères.
- **Condition d'arrêt** : Si `read()` renvoie `0`, cela signifie que la fin du fichier a été atteinte. Si `read()` renvoie une valeur négative, une erreur de lecture s'est produite. Dans les deux cas, la boucle est interrompue.
- **Écriture sur la sortie standard** : Les données lues sont écrites sur la sortie standard (`stdout`, représenté par le descripteur de fichier `1`). Cela permet d'afficher le contenu du fichier à l'écran.
- **Terminaison de la chaîne** : `buffer[bytes_read] = '\0';` garantit que le buffer est bien terminé par un caractère nul, ce qui est utile si les données lues incluent du texte pour éviter d'afficher des caractères aléatoires à la fin.

### Retour de la fonction

- La fonction retourne `0` pour indiquer que le fichier a été lu et affiché avec succès sans erreurs.

### Points à considérer

- **Gestion des erreurs** : Bien que la fonction gère l'erreur d'ouverture du fichier, elle ne gère pas explicitement les erreurs de lecture. En cas d'erreur de lecture, elle interrompt simplement la lecture et termine.
- **Utilisation de la mémoire** : Utiliser un buffer statique de taille fixe limite la quantité de données lues à la fois, mais simplifie la gestion de la mémoire.
- **Sécurité** : L'utilisation d'un buffer statique et la terminaison manuelle par un caractère nul sont sûres dans ce contexte, mais il est essentiel de s'assurer que `bytes_read` ne dépasse jamais la taille du buffer moins un pour éviter les débordements de buffer.




### Structure du Makefile

Le Makefile est divisé en plusieurs sections principales, chacune définissant une partie spécifique du processus de build :

1. **Déclaration des variables**
2. **Règles de build**
3. **Règles de nettoyage**
4. **Cibles spéciales**
5. **Variables automatiques**

### Déclaration des Variables

```makefile
SRCS = srcs/ft_display_file.c
OBJS = $(SRCS:.c=.o)
NAME = ft_display_file
```

- **`SRCS`** : Liste des fichiers sources. Ici, il contient un seul fichier source qui se trouve dans le dossier `srcs/`.
- **`OBJS`** : Liste des fichiers objets. Cette variable utilise une substitution de suffixe pour convertir les noms de fichiers de `.c` en `.o`, indiquant les fichiers intermédiaires générés pendant la compilation.
- **`NAME`** : Nom du fichier exécutable final. C'est le nom du programme que vous allez générer.

### Règles de Build

```makefile
all: $(NAME)

$(NAME): $(OBJS)
	gcc $^ -o $@ -Wall -Wextra -Werror

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror
```

- **`all`** : Cible par défaut du Makefile. En exécutant simplement `make`, cette règle est ciblée, ce qui conduit à la création de l'exécutable `$(NAME)`.

- **`$(NAME)`** : Dépend des fichiers objets (`$(OBJS)`). Cette règle spécifie comment lier les fichiers objets en un exécutable. Les options `-Wall -Wextra -Werror` activent des avertissements supplémentaires et traitent tous les avertissements comme des erreurs pour encourager un code propre.

- **`%.o: %.c`** : Règle générique pour convertir un fichier `.c` en `.o`. Ceci est essentiel pour la compilation séparée, permettant à `make` de recompiler uniquement les fichiers qui ont changé.

### Règles de Nettoyage

```makefile
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
```

- **`clean`** : Supprime tous les fichiers objets, nettoyant le répertoire de tous les fichiers intermédiaires.
- **`fclean`** : Effectue un nettoyage complet en exécutant d'abord `clean` puis en supprimant l'exécutable, laissant le répertoire dans un état "propre".

### Reconstruire Tout

```makefile
re: 
	$(MAKE) fclean 
	$(MAKE) all
```

- **`re`** : Cible pour "rebuild", qui est utile pour reconstruire le projet entier depuis zéro. Elle assure que tout est recompilé proprement.

### Cibles Spéciales

```makefile
.PHONY: all clean fclean re
```

- **`.PHONY`** : Indique que les cibles listées ne sont pas des fichiers. Ceci prévient `make` de chercher des fichiers nommés `all`, `clean`, etc., et garantit que ces règles soient exécutées même si un fichier du même nom existe.

### Utilité des Variables Automatiques

- **`$^`** : La liste des dépendances de la règle, utile pour la liaison ou la compilation.
- **`$@`** : Le nom de la cible de la règle, utilisé ici pour spécifier le fichier de sortie de la compilation.
- **`$<`** : Le premier prérequis de la règle, utilisé pour compiler chaque fichier source en fichier objet.

Cette documentation devrait aider à comprendre la structure et le fonctionnement de votre Makefile, facilitant sa gestion et son adaptation à mesure que le projet évolue ou que de nouveaux fichiers sources sont ajoutés.