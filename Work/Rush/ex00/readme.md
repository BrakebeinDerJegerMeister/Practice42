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
int	main(void)
{
	rush(5, 1);
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
	if (((cx == 1 || cx == x) && (cy > 1 && cy < y))
		|| ((cx > 1 && cx < x) && (cy == 1 || cy == y)))
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
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
o---o
--
--
--
o---o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
o---o
-   -
-   -
-   -
o---o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
o---o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
o
-
-
-
o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ cc -Wall -Wextra -Werror main.c ft_putchar.c rush00.c -o a.out
Repo Git : Practice42/Work/Rush/ex00  (main *) $ ./a.out 
o
Repo Git : Practice42/Work/Rush/ex00  (main *) $ 
```
### Explications


# Rush 00
### Correction

rush01.c :
```C

```
### Démonstration

```

```
### Explications

# Rush 00
### Correction

rush02.c :
```C

```
### Démonstration

```

```
### Explications

# Rush 00
### Correction

rush03.c
```C

```
### Démonstration

```

```
### Explications