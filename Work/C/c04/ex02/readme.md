# Énoncé

| Exercice : 02                   |
| ------------------------------- |
| ft_putnbr                       |
| Dossier de rendu : ex02/        |
| Fichiers à rendre : ft_putnbr.c |
| Fonctions Autorisées : write    |
• Écrire une fonction qui affiche un nombre passé en paramètre. La fonction devra
être capable d’afficher la totalité des valeurs possibles dans une variable de type
int.
• Elle devra être prototypée de la façon suivante :
```C
void ft_putnbr(int nb);
```
• Par exemple :
◦ ft_putnbr(42) affiche "42".
# Correction

```C
#include <unistd.h>

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

# Déja réalisé en c00 ex07