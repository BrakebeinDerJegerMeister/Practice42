# Énoncé

| Exercice : 06                   |
| ------------------------------- |
| ft_strlen                       |
| Dossier de rendu : ex06/        |
| Fichiers à rendre : ft_strlen.c |
| Fonctions Autorisées : Aucune   |
• Écrire une fonction qui compte le nombre de caractères dans une chaîne de caractères et qui retourne le nombre trouvé.
• Elle devra être prototypée de la façon suivante :
```
int ft_strlen(char *str);
```
# Correction

```C
#include <unistd.h>

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

# Démonstration

```C
int	ft_putnbr2(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		ft_putnbr2(nb);
	}
	write(1, &disp, 1);
}

int	main(void)
{
	ft_putnbr2(ft_strlen("Hello"));
	write(1, "\n", 1);
	ft_putnbr2(ft_strlen("42"));
	write(1, "\n", 1);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c01/ex06  (main) $ norminette -RCheckForbiddenSourceHeader ft_strlen.c 
ft_strlen.c: OK!
Repo Git : Practice42/Work/C/c01/ex06  (main) $ gcc ft_strlen.c 
Repo Git : Practice42/Work/C/c01/ex06  (main) $ ./a.out 
5
2
Repo Git : Practice42/Work/C/c01/ex06  (main) $ 
```
# Explications

### Documentation du Corps de la Fonction `ft_strlen`

#### Fonction `ft_strlen`

La fonction `ft_strlen` retourne la longueur d'une chaîne de caractères, sans compter le caractère nul (`'\0') qui termine la chaîne.

#### Code de la Fonction

```c
#include <unistd.h>

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

#### Explication Détaillée

1. **Déclaration et Initialisation de la Variable `nb` :**

    ```c
    int nb;
    nb = 0;
    ```

    - **Accumulateur :** `nb` est une variable entière utilisée pour compter le nombre de caractères dans la chaîne.
    - **Initialisation :** `nb` est initialisé à 0 avant le début de la boucle, car au départ, aucun caractère n'a été compté.

2. **Boucle `while` pour Parcourir la Chaîne :**

    ```c
    while (*str)
    ```

    - **Condition de la Boucle :** La boucle continue tant que le caractère pointé par `str` n'est pas le caractère nul (`'\0'`).
    - **Déréférencement de `str` :** `*str` obtient le caractère courant pointé par `str`. En C, les chaînes de caractères sont terminées par un caractère nul (`'\0'`), qui est évalué à `false` dans une condition.

3. **Incrémentation du Compteur et du Pointeur :**

    ```c
    {
        nb++;
        str++;
    }
    ```

    - **Incrémentation de `nb` :** `nb++` augmente le compteur de caractères de 1 à chaque itération, indiquant que nous avons trouvé un autre caractère dans la chaîne.
    - **Avancement du Pointeur `str` :** `str++` avance le pointeur `str` d'un caractère, pointant ainsi vers le caractère suivant dans la chaîne. Cela permet à la boucle de vérifier chaque caractère de la chaîne successivement.

4. **Retour de la Longueur de la Chaîne :**

    ```c
    return (nb);
    ```

    - **Retour de la Valeur :** Après avoir parcouru toute la chaîne, la fonction retourne la valeur de `nb`, qui contient le nombre total de caractères dans la chaîne, excluant le caractère nul (`'\0'`).

### Fonctionnement Global

- **Initialisation** : La fonction initialise un compteur `nb` à 0.
- **Boucle `while`** : Parcourt chaque caractère de la chaîne jusqu'à atteindre le caractère nul (`'\0'`).
- **Incrémentation** : À chaque itération, incrémente le compteur `nb` et avance le pointeur `str`.
- **Retour** : Retourne le compteur `nb`, qui représente la longueur de la chaîne de caractères.