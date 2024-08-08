# Énoncé

| Exercice : 00                                      |
| -------------------------------------------------- |
| rush0X                                             |
| Dossier de rendu : ex00/                           |
| Fichiers à rendre : main.c, ft_putchar.c, rush0X.c |
| Fonctions Autorisées : write                       |
• Les fichiers à rendre seront le main.c, un ft_putchar.c et votre rush0X.c, où 0X correspondra au numéro du rush. Par exemple, rush00.c.
• Exemple de main.c :
```C
int main()
{
rush(5, 5);
return (0);
}
```
• Vous devrez donc écrire la fonction rush prenant en paramètre deux variables de type entier nommées respectivement x et y.
• Votre fonction rush devra afficher à l’écran un rectangle de x caractères de largeur, et y caractères de hauteur.
• Votre main sera modifié en soutenance pour pouvoir changer les paramètres de l’appel à la fonction rush. Par exemple, ce genre de chose sera testé :
```C
int main()
{
rush(123, 42);
return (0);
}
```

# Commun

main.c :
```C
void	rush(int x, int y);

int	main(void)
{
	rush(5, 3);
	return (0);
}
```

ft_putchar.c :
```C
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```
# Rush 00

### rush(5, 3) affichera ceci :
```
$>./a.out
o---o
|   |
o---o
$>
```
### Correction

rush00.c
```C
void	ft_putchar(char c);

void	print_corner(int cx, int cy, int x, int y)
{
	if ((cx == 1 && cy == 1) || (cx == x && cy == y)
		|| (cx == 1 && cy == y) || (cx == x && cy == 1))
		ft_putchar('o');
}

void	print_other(int cx, int cy, int x, int y)
{
	if ((cx == 1 || cx == x) && (cy > 1 && cy < y))
		ft_putchar('|');
	if ((cx > 1 && cx < x) && (cy == 1 || cy == y))
		ft_putchar('-');
	else if (cx > 1 && cx < x && cy > 1 && cy < y)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	while (++cy <= y)
	{
		while (++cx <= x)
		{
			print_corner(cx, cy, x, y);
			print_other(cx, cy, x, y);
			if (cx == x)
				ft_putchar('\n');
		}
		cx = 0;
	}
}
```
### Démonstration

```
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out
o---o
|   |
o---o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out
o---o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out
o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out
o
|
|
|
o
```




# Rush 01
### rush(5, 3) affichera ceci :
```
$>./a.out
/***\
*   *
\***/
$>
```
### Correction

rush01.c :
```C
void	ft_putchar(char c);

void	print_corner(int cx, int cy, int x, int y)
{
	if (cx == 1 && cy == 1)
		ft_putchar('/');
	else if (cx == 1 && cy == y && cy > 1)
		ft_putchar('\\');
	else if (cx == x && cy == y && cy > 1)
		ft_putchar('/');
	else if (cx == x && cy == 1)
		ft_putchar('\\');
}

void	print_other(int cx, int cy, int x, int y)
{
	if (((cx == 1 || cx == x) && (cy > 1 && cy < y))
		|| ((cx > 1 && cx < x) && (cy == 1 || cy == y)))
		ft_putchar('*');
	else if (cx > 1 && cx < x && cy > 1 && cy < y)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	while (++cy <= y)
	{
		while (++cx <= x)
		{
			print_corner(cx, cy, x, y);
			print_other(cx, cy, x, y);
			if (cx == x)
				ft_putchar('\n');
		}
		cx = 0;
	}
}
```
### Démonstration

```
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush01.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
/***\
*   *
\***/
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush01.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
/***\
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush01.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
/
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush01.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
/
*
*
*
\
Repo Git : Practice42/Work/Rush/ex00  (main *) $ 
```




# Rush 02

### rush(5, 3) affichera ceci :
```
$>./a.out
ABBBA
B   B
CBBBC
$>
```
### Correction

rush02.c :
```C
void	ft_putchar(char c);

void	print_corner(int cx, int cy, int x, int y)
{
	if (cy == 1 && (cx == 1 || cx == x))
		ft_putchar('A');
	if (cy > 1 && cy == y && (cx == 1 || cx == x))
		ft_putchar('C');
}

void	print_other(int cx, int cy, int x, int y)
{
	if (((cx == 1 || cx == x) && (cy > 1 && cy < y))
		|| ((cx > 1 && cx < x) && (cy == 1 || cy == y)))
		ft_putchar('B');
	else if (cx > 1 && cx < x && cy > 1 && cy < y)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	while (++cy <= y)
	{
		while (++cx <= x)
		{
			print_corner(cx, cy, x, y);
			print_other(cx, cy, x, y);
			if (cx == x)
				ft_putchar('\n');
		}
		cx = 0;
	}
}
```
### Démonstration

```
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush02.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
ABBBA
B   B
CBBBC
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush02.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
ABBBA
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush02.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
A
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush02.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
A
B
B
B
C
Repo Git : Practice42/Work/Rush/ex00  (main *) $ 
```





# Rush 03

### rush(5, 3) affichera ceci :
```
ABBBC
B   B
ABBBC
```
### Correction

rush03.c
```C
void	ft_putchar(char c);

void	print_corner(int cx, int cy, int x, int y)
{
	if (cx == 1 && (cy == 1 || cy == y))
		ft_putchar('A');
	if (cx > 1 && cx == x && (cy == 1 || cy == y))
		ft_putchar('C');
}

void	print_other(int cx, int cy, int x, int y)
{
	if (((cx == 1 || cx == x) && (cy > 1 && cy < y))
		|| ((cx > 1 && cx < x) && (cy == 1 || cy == y)))
		ft_putchar('B');
	else if (cx > 1 && cx < x && cy > 1 && cy < y)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	while (++cy <= y)
	{
		while (++cx <= x)
		{
			print_corner(cx, cy, x, y);
			print_other(cx, cy, x, y);
			if (cx == x)
				ft_putchar('\n');
		}
		cx = 0;
	}
}
```
### Démonstration

```
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush03.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
ABBBC
B   B
ABBBC
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush03.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
ABBBC
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush03.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
A
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush03.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
A
B
B
B
A
Repo Git : Practice42/Work/Rush/ex00  (main *) $ 
```






# Rush 04

### rush(5, 3) affichera ceci :
```
$>./a.out

$>
```
### Correction

rush04.c
```C
void	ft_putchar(char c);

void	print_corner(int cx, int cy, int x, int y)
{
	if ((cx == 1 && cy == 1) || (cx == x && cy == y && cy > 1 && cx > 1))
		ft_putchar('A');
	else if ((cx == x && cy == 1) || (cx == 1 && cy == y))
		ft_putchar('C');
}

void	print_other(int cx, int cy, int x, int y)
{
	if (((cx == 1 || cx == x) && (cy > 1 && cy < y))
		|| ((cx > 1 && cx < x) && (cy == 1 || cy == y)))
		ft_putchar('B');
	else if (cx > 1 && cx < x && cy > 1 && cy < y)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	while (++cy <= y)
	{
		while (++cx <= x)
		{
			print_corner(cx, cy, x, y);
			print_other(cx, cy, x, y);
			if (cx == x)
				ft_putchar('\n');
		}
		cx = 0;
	}
}
```
### Démonstration

```
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush04.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
ABBBC
B   B
CBBBA
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush04.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
ABBBC
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush04.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
A
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror ft_putchar.c rush04.c main.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
A
B
B
B
C
Repo Git : Practice42/Work/Rush/ex00  (main *) $ 
```




