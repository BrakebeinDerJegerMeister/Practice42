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

```C

```

```

```
# Explications
