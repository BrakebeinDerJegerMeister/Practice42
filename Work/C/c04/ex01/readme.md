# Énoncé

| Exercice : 01                   |
| ------------------------------- |
| ft_putstr                       |
| Dossier de rendu : ex01/        |
| Fichiers à rendre : ft_putstr.c |
| Fonctions Autorisées : write    |
• Écrire une fonction qui affiche un à un les caractères d’une chaîne à l’écran.
• L’adresse du premier caractère de la chaîne est contenue dans le pointeur passé en
paramètre à la fonction.
• Elle devra être prototypée de la façon suivante :
```C
void ft_putstr(char *str);
```
# Correction

```C
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
```

Exercice déjà réalisé, pas la peine de s'attarder dessus.