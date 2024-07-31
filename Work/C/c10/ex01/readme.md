# Énoncé

| Exercice : 01                                                       |
| ------------------------------------------------------------------- |
| cat                                                                 |
| Dossier de rendu : ex01/                                            |
| Fichiers à rendre : Makefile, et les fichiers de votre programme    |
| Fonctions Autorisées : close, open, read, write, strerror, basename |
• Écrire un programme appelé ft_cat qui réalise le même travail que la commande
cat du système.
• Vous n’avez pas à gérer les options.
• Le répertoire de rendu aura un Makefile avec une règle all, une règle clean, et
une règle fclean.
• Vous pouvez utiliser la variable errno (voir le man de Errno).
• Vous devriez aller lire les man de toutes les fonctions authorisées
• Vous pouvez faire l’exercice uniquement en déclarant un tableau de taille fixe. Ce
tableau aura une taille limitée à un peu moins d’environ 30 ko. Pour que vous
puissiez tester cette limitation, utilisez la commande ulimit dans votre shell.
# Correction

```C
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_putstr_ex(int std, char *str)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

int	disp_file(char *filename)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_ex(2, "Problème avec le fichier ");
		ft_putstr_ex(2, basename(filename));
		ft_putstr_ex(2, ", ");
		ft_putstr_ex(2, strerror(errno));
		ft_putstr_ex(2, "\n");
		return (1);
	}
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
	int	i;

	ret = 0;
	if (argc < 2)
	{
		ft_putstr_ex(2, "Filename missing.\n");
		return (1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ret = disp_file(argv[i]);
			if (ret)
				return (1);
			i++;
		}
	}
	return (0);
}
```

```make
SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)
NAME = ft_cat

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
# Algorithme

# Démonstration

```
Repo Git : Practice42/Work/C/c10/ex01  (main) $ make
gcc -c srcs/main.c -o srcs/main.o -Wall -Wextra -Werror
gcc srcs/main.o -o ft_cat -Wall -Wextra -Werror
Repo Git : Practice42/Work/C/c10/ex01  (main) $ make f
fclean  ft_cat  
Repo Git : Practice42/Work/C/c10/ex01  (main) $ make fclean 
rm -f srcs/main.o
rm -f ft_cat
Repo Git : Practice42/Work/C/c10/ex01  (main) $ 


Repo Git : Practice42/Work/C/c10/ex01/srcs  (main) $ ./a.out main.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
...
...
...
	return (0);
}
Repo Git : Practice42/Work/C/c10/ex01/srcs  (main) $ ./a.out main.c existepas.c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
...
...
...
	return (0);
}
Problème avec le fichier existepas.c, No such file or directory
Repo Git : Practice42/Work/C/c10/ex01/srcs  (main) $ 
```
# Explications

Voici une documentation détaillée sur les fonctions `strerror`, `basename` et l'utilisation de la variable `errno` en programmation C, particulièrement utiles pour la gestion des erreurs et le traitement des chemins de fichiers.

### 1. `strerror` et `errno`

**Fonctionnalité :**
`strerror` est une fonction de la bibliothèque standard C qui convertit un code d'erreur (stocké dans la variable `errno`) en un message d'erreur humainement lisible. La variable `errno` est définie dans `<errno.h>` et est automatiquement définie par le système à un code d'erreur pertinent lorsque les appels système échouent.

**Usage :**

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *file = fopen("nonexistentfile.txt", "r");
    if (file == NULL) {
        printf("Erreur : %s\n", strerror(errno));
    }
    return 0;
}
```

**Explication :**
- Dans cet exemple, si `fopen` échoue à ouvrir le fichier (parce qu'il n'existe pas, par exemple), `errno` est mis à une valeur telle que `ENOENT`. La fonction `strerror(errno)` retournera alors une chaîne de caractères telle que "No such file or directory".
- `strerror` est particulièrement utile pour le débogage et les logs, fournissant des détails sur la nature des erreurs d'exécution.

### 2. `basename`

**Fonctionnalité :**
`basename` est une fonction définie dans `<libgen.h>` qui extrait le nom de fichier de base à partir d'un chemin complet. C'est utile pour des opérations où vous souhaitez afficher ou loguer uniquement le nom de fichier, indépendamment du chemin d'accès complet.

**Usage :**

```c
#include <libgen.h>
#include <stdio.h>

int main() {
    char path[] = "/usr/local/bin/nano";
    char *file = basename(path);
    printf("Nom de fichier : %s\n", file);
    return 0;
}
```

**Explication :**
- `basename(path)` extrait "nano" du chemin fourni. Notez que `basename` peut modifier la chaîne originale, donc si vous avez besoin de conserver le chemin original, faites une copie de la chaîne avant d'appeler `basename`.
- Il est aussi important de noter que le comportement de `basename` peut varier entre différents systèmes UNIX, donc sa sortie doit être traitée avec prudence.

### 3. Variable `errno`

**Fonctionnalité :**
`errno` est une macro qui renvoie un pointeur vers le code d'erreur pour le thread courant. Elle est utilisée pour déterminer pourquoi les appels système échouent sans avoir à retourner de multiples valeurs.

**Usage :**
```c
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    if (close(-1) == -1) {
        fprintf(stderr, "Erreur lors de la fermeture du fichier : %s\n", strerror(errno));
    }
    return 0;
}
```

**Explication :**
- L'exemple tente de fermer un descripteur de fichier non valide (`-1`), ce qui échoue et définit `errno` à `EBADF` ("Bad file descriptor").
- Utiliser `errno` est crucial pour comprendre les erreurs spécifiques retournées par les appels système et les fonctions de la bibliothèque standard qui ne retournent pas de messages d'erreur détaillés directement.