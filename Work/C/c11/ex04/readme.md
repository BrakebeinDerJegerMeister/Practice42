# Énoncé

| Exercice : 04                    |
| -------------------------------- |
| ft_is_sort                       |
| Dossier de rendu : ex04/         |
| Fichiers à rendre : ft_is_sort.c |
| Fonctions Autorisées : Aucune    |
• Écrire une fonction ft_is_sort qui renverra 1 si le tableau est trié et 0 dans le
cas contraire.
• La fonction passée en paramètre renverra un entier négatif si le premier argument
est inférieur au deuxième, 0 s’ils sont égaux et un entier positif autrement.
• La fonction sera prototypée de la manière suivante :
```C
int ft_is_sort(int *tab, int length, int(*f)(int, int));
```
# Correction

```C
int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
```
# Démonstration

```C
int	desc(int a, int b)
{
	return (b - a);
}

#include <stdio.h>

int	main(void)
{
	int	t1[5] = {10, -5, 3, 9, 100};
	int	t2[5] = {0, 1, 2, 3, 4};
	int	r;

	r = ft_is_sort(t1, 5, desc);
	printf("%s\n", r ? "oui" : "non");
	r = ft_is_sort(t2, 5, desc);
	printf("%s\n", r ? "oui" : "non");
	return (0);
}
```

```
Appuyez sur ENTRÉE ou tapez une commande pour continuer
ft_is_sort.c: Error!
Error: INCLUDE_START_FILE   (line:  32, col:   1):	Include must be at the start of file
Error: DECL_ASSIGN_LINE     (line:  36, col:  15):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  37, col:  15):	Declaration and assignation on a single line
Error: TERNARY_FBIDDEN      (line:  41, col:  22):	Ternaries are forbidden
Error: TERNARY_FBIDDEN      (line:  43, col:  22):	Ternaries are forbidden

le shell a retourné 1

Appuyez sur ENTRÉE ou tapez une commande pour continuer

Appuyez sur ENTRÉE ou tapez une commande pour continuer
non
oui

Appuyez sur ENTRÉE ou tapez une commande pour continuer
```
# Explications

Revoir exercice c11 ex00 tout commence là bas.