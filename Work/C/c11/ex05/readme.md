# Énoncé

| Exercice : 05                                                       |
| ------------------------------------------------------------------- |
| do-op                                                               |
| Dossier de rendu : ex05/                                            |
| Fichiers à rendre : Tous les fichiers nécessaires a votre programme |
| Fonctions Autorisées : write                                        |
• Écrire un programme qui s’appelle do-op.
• Le programme devra être lancé avec trois arguments : do-op valeur1 operateur
valeur2
• Exemple :
```
$>./do-op 42 "+" 21
63
$>
```
• Vous devriez utilisé un tableau de pointeur sur fonction afin d’appeler la fonction correspondant à un operateur.
• En cas d’opérateur inconnu votre programme doit afficher 0.
• Si le nombre d’arguments n’est pas correct, do-op n’affiche rien.
• Votre programme doit accepter et afficher le résultat avec les opérateurs suivant :
```
’+’ ’-’ ’/’ ’*’ et ’%’
```
• En cas de division par 0 votre programme doit afficher :
```
Stop : division by zero
```
• En cas de modulo par 0 votre programme doit afficher :
```
Stop : modulo by zero
```
• Voici un exemple de tests de la Moulinette :
```
$> make clean
$> make
$> ./do-op
$> ./do-op 1 + 1
2
$> ./do-op 42amis - --+-20toto12
62
$> ./do-op 1 p 1
0
$> ./do-op 1 + toto3
1
$>
$> ./do-op toto3 + 4
4
$> ./do-op foo plus bar
0
$> ./do-op 25 / 0
Stop : division by zero
$> ./do-op 25 % 0
Stop : modulo by zero
$>
```
# Correction

do_op.h :
```C
#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		add(int a, int b, int *err);
int		sub(int a, int b, int *err);
int		mul(int a, int b, int *err);
int		div(int a, int b, int *err);
int		mod(int a, int b, int *err);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int old_nb);
void	do_op(int a, int b, char *op);

#endif
```

do-op.c :
```C
#include "do_op.h"

void	init(int (**op_fcts)(int, int, int *), char *ops)
{
	op_fcts[0] = add;
	op_fcts[1] = sub;
	op_fcts[2] = mul;
	op_fcts[3] = div;
	op_fcts[4] = mod;
	ops[0] = '+';
	ops[1] = '-';
	ops[2] = '*';
	ops[3] = '/';
	ops[4] = '%';
}

void	do_op(int a, int b, char *op)
{
	int		(*op_fcts[5])(int, int, int *);
	int		i;
	int		result;
	int		error;
	char	ops[5];

	init(op_fcts, ops);
	i = 0;
	while (i < 5)
	{
		if (ops[i] == op[0])
		{
			error = -1;
			result = op_fcts[i](a, b, &error);
			if (! error)
			{
				ft_putnbr(result);
				ft_putstr("\n");
			}
			return ;
		}
		i++;
	}
}
```

main.c :
```C
#include "do_op.h"

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) != 1)
	{
		ft_putstr("0\n");
		return (1);
	}
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	do_op(a, b, argv[2]);
	return (0);
}
```

Makefile :
```make
SRCS = main.c $(wildcard srcs/*.c)
OBJS = $(SRCS:.c=.o)
NAME = do-op
HEADERS = headers

all: $(NAME)

$(NAME): $(OBJS)
	gcc $^ -o $@ -Wall -Wextra -Werror -I $(HEADERS)

%.o: %.c
	gcc -c $< -o $@ -Wall -Wextra -Werror -I $(HEADERS)

clean:
	rm -f $(OBJS) $(NAME)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re
```

ft_srclen.c
```C
#include "do_op.h"

int	ft_strlen(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		nb++;
		str++;
	}
	return (nb);
}
```

ft_putnbr.c
```C
#include "do_op.h"

void	nextnumber(long int nb)
{
	char		disp;
	long int	next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
	write(1, &disp, 1);
}

void	ft_putnbr(int old_nb)
{
	long int	nb;

	nb = (long int)old_nb;
	if (nb < 0)
	{
		nb = -nb;
		write(1, &(char){'-'}, 1);
	}
	nextnumber(nb);
}
```

ft_putstr.c :
```C
#include "do_op.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
```

ft_atoi.c :
```C
#include "do_op.h"

int	is_whitespace(char chr)
{
	if (chr == 32 || (chr > 8 && chr < 14))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		factor;
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	factor = 1;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			factor = -factor;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (int)str[i] - 48 + nb * 10;
		i++;
	}
	return (factor * nb);
}
```
# Démonstration

```
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ make
gcc -c srcs/do-op.c -o srcs/do-op.o -Wall -Wextra -Werror -I headers
gcc main.o srcs/do-op.o srcs/ft_atoi.o srcs/ft_putnbr.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/operations.o -o do-op -Wall -Wextra -Werror -I headers
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op 1 + 1
2
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op 42amis - --+-20toto12
62
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op 1 p 1
0
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op 1 + toto3
1
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op toto3 + 4
4
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op foo plus bar
0
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op 25 / 0
Stop : division by zero
Repo Git : Practice42/Work/C/c11/ex05  (main *) $ ./do-op 25 % 0
Stop : modulo by zero
Repo Git : Practice42/Work/C/c11/ex05  (main *) $
```
# Explications

Voir tout ce que vous avez déjà fait auparavant, rien de nouveau.