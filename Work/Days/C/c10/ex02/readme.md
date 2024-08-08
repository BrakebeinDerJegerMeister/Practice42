# Énoncé

| Exercice : 02                                                                     |
| --------------------------------------------------------------------------------- |
| tail                                                                              |
| Dossier de rendu : ex02/                                                          |
| Fichiers à rendre : Makefile, et les fichiers de votre programme                  |
| Fonctions Autorisées : close, open, read, write, malloc, free, strerror, basename |
• Écrire un programme appelé ft_tail qui réalise le même travail que la commande
tail.
• Vous avez à gérer uniquement l’option -c, mais vous n’avez pas à gérer le ’+’ et
le ’-’.
• Tous les tests seront effectué avec l’option -c
• Le répertoire de rendu aura un Makefile avec une règle all, une règle clean, et
une règle fclean.
• Vous pouvez utiliser la variable errno
# Correction

```C
#include <unistd.h>
#include <libgen.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

int	get_option_c(char *str, char *nbr, int *num)
{
	int		nb;
	int		i;
	char	*conv;

	if (str[0] == '-' && str[1] == 'c')
	{
		if (str[2] == '\0')
			conv = nbr;
		else
		{
			str = str + 2;
			conv = str;
		}
		nb = 0;
		i = 0;
		while (conv[i] >= '0' && conv[i] <= '9')
		{
			nb = (int)conv[i] - 48 + nb * 10;
			i++;
		}
		*num = nb;
		return (1);
	}
	return (0);
}

int	get_filesize(char *filename)
{
	int		fd;
	char	buffer[1024];
	int		size;
	int		bytes_read;

	size = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		bytes_read = read(fd, buffer, 1024);
		size = size + bytes_read;
		if (bytes_read <= 0)
			break ;
	}
	close(fd);
	return (size);
}

void	ft_putstr_ex(int std, char *str)
{
	while (*str)
	{
		write(std, str, 1);
		str++;
	}
}

int	tail(char *filename, int limit)
{
	int		fd;
	char	buffer[1];
	int		bytes_read;
	int		size;
	int		current;

	size = get_filesize(filename);
	fd = open(filename, O_RDONLY);
	if (size == -1)
	{
		return (1);
	}
	current = 0;
	while (1)
	{
		bytes_read = read(fd, buffer, 1);
		current = current + bytes_read;
		if ((current + limit) >= size)
			write(1, buffer, 1);
		if (bytes_read <= 0)
			break ;
	}
	close(fd);
	return (0);
}

int	main(int argc, char *argv[])
{
	int		num;
	char	*filename;

	if (argc < 4)
		ft_putstr_ex(2, "Too few arguments.\n");
	if (argc > 4)
		ft_putstr_ex(2, "Too many arguments.\n");
	if (argc != 4)
		return (1);
	if (get_option_c(argv[1], argv[2], &num))
		filename = argv[3];
	else if (get_option_c(argv[2], argv[3], &num))
		filename = argv[1];
	else
		return (1);
	if (tail(filename, num))
	{
		ft_putstr_ex(2, "File error : ");
		ft_putstr_ex(2, basename(filename));
		ft_putstr_ex(2, ", ");
		ft_putstr_ex(2, strerror(errno));
		ft_putstr_ex(2, "\n");
	}
	return (0);
}
```

```make
SRCS = srcs/main.c
OBJS = $(SRCS:.c=.o)
NAME = ft_tail

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
Repo Git : Practice42/Work/C/c10/ex02  (main *) $ make
gcc -c srcs/main.c -o srcs/main.o -Wall -Wextra -Werror
gcc srcs/main.o -o ft_tail -Wall -Wextra -Werror
Repo Git : Practice42/Work/C/c10/ex02  (main *) $ ./ft_tail -c Makefile -c 25
Too many arguments.
Repo Git : Practice42/Work/C/c10/ex02  (main *) $ ./ft_tail Makefile -c 25
HONY: all clean fclean re

Repo Git : Practice42/Work/C/c10/ex02  (main *) $ ./ft_tail -c Makefile 
Too few arguments.
Repo Git : Practice42/Work/C/c10/ex02  (main *) $ ./ft_tail -c Makefile 70
File error : 70, No such file or directory
Repo Git : Practice42/Work/C/c10/ex02  (main *) $ ./ft_tail -c 70 Makefile
NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re

Repo Git : Practice42/Work/C/c10/ex02  (main *) $ 
```
# Explications

Rien de particulier, se référer à l'exercice précédent.