# Énoncé

| Exercice : 03                                                                     |
| --------------------------------------------------------------------------------- |
| hexdump                                                                           |
| Dossier de rendu : ex03/                                                          |
| Fichiers à rendre : Makefile, et les fichiers de votre programme                  |
| Fonctions Autorisées : close, open, read, write, malloc, free, strerror, basename |
• Écrire un programme appelé ft_hexdump qui réalise le même travail que la com-
mande hexdump du système sans redirection.
• Vous n’avez à gérer que l’option -C.
• Le répertoire de rendu aura un Makefile avec une règle all, une règle clean, et
une règle fclean.
• Vous pouvez utiliser la variable errno (voir le man de errno).
# Correction

main.c :
```C
#include "ft_hexdump.h"

void	print_hexstr(char *str, int bytes_read)
{
	int		i;
	int		size;
	char	c1;
	char	c2;

	i = 0;
	size = 16;
	while (i < bytes_read)
	{
		c1 = hex_digit((str[i] >> 4) & 0xF);
		c2 = hex_digit(str[i] & 0xF);
		write(1, &c1, 1);
		write(1, &c2, 1);
		write(1, " ", 1);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
	while (i++ < size)
	{
		if (i == 6)
			write(1, " ", 1);
		write(1, "   ", 3);
	}
	write(1, " ", 1);
}

int	print_line(char *buffer, int addr, int bytes_read)
{
	int		i;
	char	c;

	print_addr(addr, "  ");
	print_hexstr(buffer, bytes_read);
	i = 0;
	if (bytes_read > 0)
		write(1, "  |", 3);
	while (i < bytes_read)
	{
		c = buffer[i];
		if (c > 31 && c < 127)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
	if (bytes_read > 0)
		write(1, "|", 1);
	write(1, "\n", 1);
	return (0);
}

void	hexdump(int fd, char buffers[2][17], int bytes[2], int *same)
{
	int	i;

	i = 0;
	while (1)
	{
		copy_16(buffers[1], buffers[0]);
		bytes[1] = bytes[0];
		bytes[0] = read(fd, buffers[0], 16);
		if (bytes[0] <= 0)
			print_addr(16 * (i - (i > 0)) + bytes[1], "\n");
		if (bytes[0] <= 0)
			break ;
		buffers[0][bytes[0]] = '\0';
		if (is_equal_16(buffers[0], buffers[1]))
		{
			if (*same == 0)
				write(1, "*\n", 2);
			if (*same == 0)
				*same = 1;
		}
		else
			*same = print_line(buffers[0], 16 * i, bytes[0]);
		i++;
	}
}

int	read_file(char *filename)
{
	int		fd;
	int		same;
	int		bytes[2];
	char	buffers[2][17];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	bytes[0] = 0;
	bytes[1] = 0;
	same = 0;
	hexdump(fd, buffers, bytes, &same);
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*filename;

	filename = NULL;
	if (argc != 3)
	{
		putstr_err("Wrong number of arguments.\n");
		return (1);
	}
	if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == '\0')
		filename = argv[2];
	if (argv[2][0] == '-' && argv[2][1] == 'C' && argv[2][2] == '\0')
		filename = argv[1];
	if (filename == NULL)
	{
		putstr_err("Wrong option.\n");
		return (1);
	}
	if (read_file(filename))
	{
		putstr_err(basename(filename));
		putstr_err("error : ");
		putstr_err(strerror(errno));
		putstr_err("\n");
	}
	return (0);
}
```

suppl.c
```C
#include "ft_hexdump.h"

void	print_addr(int addr, char *next)
{
	int		i;
	char	hex;

	i = 8;
	while (i-- > 0)
	{
		hex = hex_digit((addr >> (4 * i)) & 0xF);
		write(1, &hex, 1);
	}
	while (*next)
	{
		write(1, next++, 1);
	}
}

char	hex_digit(char c)
{
	return (c + '0' + (c > 9) * 39);
}

void	putstr_err(char *str)
{
	while (*str)
	{
		write(2, str++, 1);
	}
}

void	copy_16(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		s1[i] = s2[i];
		i++;
	}
}

int	is_equal_16(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
```

ft_hexdump.h :
```h
#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <libgen.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>

void	print_addr(int addr, char *next);
char	hex_digit(char c);
void	putstr_err(char *str);
void	copy_16(char *s1, char *s2);
int		is_equal_16(char *s1, char *s2);
void	print_hexstr(char *str, int bytes_read);
int		print_line(char *buffer, int addr, int bytes_read);
void	hexdump(int fdn, char buffers[2][17], int bytes[2], int *same);
int		read_file(char *filename);

#endif
```

Makefile :
```make
SRCS = srcs/main.c srcs/suppl.c
OBJS = $(SRCS:.c=.o)
NAME = ft_hexdump
HEADERS = headers

all: $(NAME)

$(NAME): $(OBJS)
	gcc $^ -o $@ -Wall -Wextra -Werror -I $(HEADERS)

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror -I $(HEADERS)

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
Repo Git : Practice42/Work/C/c10/ex03  (main *) $ norminette -RCheckForbiddenSourceHeader -RCheckDefine srcs/main.c 
srcs/main.c: OK!
Repo Git : Practice42/Work/C/c10/ex03  (main *) $ norminette -RCheckForbiddenSourceHeader -RCheckDefine srcs/suppl.c
srcs/suppl.c: OK!
Repo Git : Practice42/Work/C/c10/ex03  (main *) $ norminette -RCheckForbiddenSourceHeader -RCheckDefine headers/ft_hexdump.h 
headers/ft_hexdump.h: OK!
Repo Git : Practice42/Work/C/c10/ex03  (main *) $ make fclean 
rm -f srcs/main.o srcs/suppl.o
rm -f ft_hexdump
Repo Git : Practice42/Work/C/c10/ex03  (main *) $ make
gcc -c srcs/main.c -o srcs/main.o -Wall -Wextra -Werror -I headers
gcc -c srcs/suppl.c -o srcs/suppl.o -Wall -Wextra -Werror -I headers
gcc srcs/main.o srcs/suppl.o -o ft_hexdump -Wall -Wextra -Werror -I headers
```

```
Repo Git : Practice42/Work/C/c10/ex03  (main *) $ ./ft_hexdump -C Makefile 
00000000  23 20 2a 2a 2a 2a 2a 2a  2a 2a 2a 2a 2a 2a 2a 2a    |# **************|
00000010  2a 2a 2a 2a 2a 2a 2a 2a  2a 2a 2a 2a 2a 2a 2a 2a    |****************|
*
00000040  2a 2a 2a 2a 2a 2a 2a 2a  2a 2a 2a 2a 2a 2a 20 23    |************** #|
00000050  0a 23 20 20 20 20 20 20  20 20 20 20 20 20 20 20    |.#              |
00000060  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 20    |                |
*
000000a0  23 0a 23 20 20 20 20 20  20 20 20 20 20 20 20 20    |#.#             |
000000b0  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 20    |                |
*
000000d0  20 20 20 20 20 20 20 20  20 20 20 20 3a 3a 3a 20    |            ::: |
000000e0  20 20 20 20 20 3a 3a 3a  3a 3a 3a 3a 3a 20 20 20    |     ::::::::   |
000000f0  20 23 0a 23 20 20 20 20  4d 61 6b 65 66 69 6c 65    | #.#    Makefile|
00000100  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 20    |                |
*
00000120  20 20 20 20 20 20 20 20  20 20 20 3a 2b 3a 20 20    |           :+:  |
00000130  20 20 20 20 3a 2b 3a 20  20 20 20 3a 2b 3a 20 20    |    :+:    :+:  |
00000140  20 20 23 0a 23 20 20 20  20 20 20 20 20 20 20 20    |  #.#           |
00000150  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 20    |                |
*
00000170  20 20 20 20 20 20 20 20  20 20 2b 3a 2b 20 2b 3a    |          +:+ +:|
00000180  2b 20 20 20 20 20 20 20  20 20 2b 3a 2b 20 20 20    |+         +:+   |
00000190  20 20 20 23 0a 23 20 20  20 20 42 79 3a 20 70 72    |   #.#    By: pr|
000001a0  6f 66 63 68 61 6f 73 20  3c 74 65 6d 70 40 74 65    |ofchaos <temp@te|
000001b0  6d 70 2e 63 6f 6d 3e 20  20 20 20 20 20 20 20 20    |mp.com>         |
000001c0  20 20 20 20 20 20 20 20  20 2b 23 2b 20 20 2b 3a    |         +#+  +:|
000001d0  2b 20 20 20 20 20 20 20  2b 23 2b 20 20 20 20 20    |+       +#+     |
000001e0  20 20 20 20 23 0a 23 20  20 20 20 20 20 20 20 20    |    #.#         |
000001f0  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 20    |                |
*
00000210  20 20 20 20 20 20 20 20  2b 23 2b 23 2b 23 2b 23    |        +#+#+#+#|
00000220  2b 23 2b 20 20 20 2b 23  2b 20 20 20 20 20 20 20    |+#+   +#+       |
00000230  20 20 20 20 20 23 0a 23  20 20 20 20 43 72 65 61    |     #.#    Crea|
00000240  74 65 64 3a 20 32 30 32  34 2f 30 37 2f 33 31 20    |ted: 2024/07/31 |
00000250  31 31 3a 30 37 3a 35 34  20 62 79 20 70 72 6f 66    |11:07:54 by prof|
00000260  63 68 61 6f 73 20 20 20  20 20 20 20 20 20 23 2b    |chaos         #+|
00000270  23 20 20 20 20 23 2b 23  20 20 20 20 20 20 20 20    |#    #+#        |
00000280  20 20 20 20 20 20 23 0a  23 20 20 20 20 55 70 64    |      #.#    Upd|
00000290  61 74 65 64 3a 20 32 30  32 34 2f 30 37 2f 33 31    |ated: 2024/07/31|
000002a0  20 32 30 3a 31 36 3a 30  36 20 62 79 20 6b 61 6f    | 20:16:06 by kao|
000002b0  73 20 20 20 20 20 20 20  20 20 20 20 20 20 23 23    |s             ##|
000002c0  23 20 20 20 23 23 23 23  23 23 23 23 2e 66 72 20    |#   ########.fr |
000002d0  20 20 20 20 20 20 20 23  0a 23 20 20 20 20 20 20    |       #.#      |
000002e0  20 20 20 20 20 20 20 20  20 20 20 20 20 20 20 20    |                |
*
00000320  20 20 20 20 20 20 20 20  23 0a 23 20 2a 2a 2a 2a    |        #.# ****|
00000330  2a 2a 2a 2a 2a 2a 2a 2a  2a 2a 2a 2a 2a 2a 2a 2a    |****************|
*
00000370  2a 2a 2a 2a 2a 2a 2a 2a  20 23 0a 0a 53 52 43 53    |******** #..SRCS|
00000380  20 3d 20 73 72 63 73 2f  6d 61 69 6e 2e 63 20 73    | = srcs/main.c s|
00000390  72 63 73 2f 73 75 70 70  6c 2e 63 0a 4f 42 4a 53    |rcs/suppl.c.OBJS|
000003a0  20 3d 20 24 28 53 52 43  53 3a 2e 63 3d 2e 6f 29    | = $(SRCS:.c=.o)|
000003b0  0a 4e 41 4d 45 20 3d 20  66 74 5f 68 65 78 64 75    |.NAME = ft_hexdu|
000003c0  6d 70 0a 48 45 41 44 45  52 53 20 3d 20 68 65 61    |mp.HEADERS = hea|
000003d0  64 65 72 73 0a 0a 61 6c  6c 3a 20 24 28 4e 41 4d    |ders..all: $(NAM|
000003e0  45 29 0a 0a 24 28 4e 41  4d 45 29 3a 20 24 28 4f    |E)..$(NAME): $(O|
000003f0  42 4a 53 29 0a 09 67 63  63 20 24 5e 20 2d 6f 20    |BJS)..gcc $^ -o |
00000400  24 40 20 2d 57 61 6c 6c  20 2d 57 65 78 74 72 61    |$@ -Wall -Wextra|
00000410  20 2d 57 65 72 72 6f 72  20 2d 49 20 24 28 48 45    | -Werror -I $(HE|
00000420  41 44 45 52 53 29 0a 0a  25 2e 6f 3a 20 25 2e 63    |ADERS)..%.o: %.c|
00000430  0a 09 67 63 63 20 2d 63  20 24 3c 20 2d 6f 20 24    |..gcc -c $< -o $|
00000440  40 20 2d 57 61 6c 6c 20  2d 57 65 78 74 72 61 20    |@ -Wall -Wextra |
00000450  2d 57 65 72 72 6f 72 20  2d 49 20 24 28 48 45 41    |-Werror -I $(HEA|
00000460  44 45 52 53 29 0a 0a 63  6c 65 61 6e 3a 0a 09 72    |DERS)..clean:..r|
00000470  6d 20 2d 66 20 24 28 4f  42 4a 53 29 0a 0a 66 63    |m -f $(OBJS)..fc|
00000480  6c 65 61 6e 3a 20 63 6c  65 61 6e 0a 09 72 6d 20    |lean: clean..rm |
00000490  2d 66 20 24 28 4e 41 4d  45 29 0a 0a 72 65 3a 20    |-f $(NAME)..re: |
000004a0  0a 09 24 28 4d 41 4b 45  29 20 66 63 6c 65 61 6e    |..$(MAKE) fclean|
000004b0  20 0a 09 24 28 4d 41 4b  45 29 20 61 6c 6c 0a 0a    | ..$(MAKE) all..|
000004c0  2e 50 48 4f 4e 59 3a 20  61 6c 6c 20 63 6c 65 61    |.PHONY: all clea|
000004d0  6e 20 66 63 6c 65 61 6e  20 72 65 0a                |n fclean re.|
000004dc
Repo Git : Practice42/Work/C/c10/ex03  (main *) $ 
```
# Explications

Le projet `ft_hexdump` consiste à développer un programme similaire à la commande Unix `hexdump`. Ce programme permet de visualiser le contenu binaire d'un fichier sous une forme hexadécimale et caractère lisible.

#### Structure du Projet
Le projet se divise en trois parties principales :

1. **main.c** : Le point d'entrée du programme qui gère la lecture des arguments et l'appel des fonctions principales.
2. **suppl.c** : Contient des fonctions utilitaires pour afficher les adresses, copier des données, comparer des blocs de données, et afficher des erreurs.
3. **ft_hexdump.h** : Un fichier d'en-tête qui déclare toutes les fonctions et inclut les bibliothèques nécessaires.

#### Fonctionnalités Clés
- **Affichage d'adresse** : Chaque ligne de sortie commence par l'adresse du premier octet de la ligne.
- **Affichage des données en hexadécimal** : Après l'adresse, les données sont affichées en hexadécimal.
- **Affichage ASCII** : Si les caractères sont lisibles, ils sont affichés en format ASCII à côté de leur représentation hexadécimale.
- **Gestion des fichiers** : Le programme lit les données du fichier spécifié et les traite par blocs.

#### Commandes Makefile
- **make all** : Compile le programme.
- **make clean** : Supprime les fichiers objets.
- **make fclean** : Supprime les fichiers objets et le fichier exécutable.
- **make re** : Exécute `fclean` suivi de `all`.

# Algorithme général

#### Initialisation
1. **Vérification des arguments** :
   - Le programme vérifie qu'il est lancé avec exactement trois arguments.
   - Il contrôle que l'un des arguments est `-C` pour activer le mode de visualisation canonique.

2. **Ouverture du fichier** :
   - Si les arguments sont valides, le programme tente d'ouvrir le fichier spécifié en mode lecture.

#### Traitement principal
3. **Lecture et traitement des données** :
   - **Boucle principale** :
     - Les données sont lues par blocs de 16 octets jusqu'à ce que la fin du fichier soit atteinte.
     - Pour chaque bloc lu, le programme vérifie s'il est identique au bloc précédent.
     - Si les blocs sont identiques et que c'est la première occurrence d'une série de blocs identiques, le programme affiche un astérisque (`*`).
     - Si le bloc est différent du précédent, il est affiché en format hexadécimal suivi de sa représentation ASCII.

4. **Affichage des données** :
   - **Affichage d'adresse** : Avant chaque ligne de données, l'adresse du premier octet du bloc est affichée.
   - **Conversion et affichage hexadécimal** : Chaque octet est converti en deux caractères hexadécimaux.
   - **Affichage ASCII** : Les caractères lisibles (entre 32 et 126) sont affichés à la fin de la ligne ; les autres sont remplacés par un point (`.`).

#### Terminaison
5. **Fin de la lecture** :
   - Après la dernière lecture, le programme affiche l'adresse de fin qui correspond au total des octets lus.
   - Le fichier est fermé et le programme termine.

6. **Gestion des erreurs** :
   - Si une erreur survient lors de l'ouverture du fichier ou de la lecture, un message d'erreur est affiché et le programme se termine avec un code d'erreur.
