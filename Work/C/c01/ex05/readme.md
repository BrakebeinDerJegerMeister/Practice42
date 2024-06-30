# Énoncé

| Exercice : 05                   |
| ------------------------------- |
| ft_putstr                       |
| Dossier de rendu : ex05/        |
| Fichiers à rendre : ft_putstr.c |
| Fonctions Autorisées : write    |
• Écrire une fonction qui affiche une chaine de caractères à l’écran.
• Elle devra être prototypée de la façon suivante :
void
```
ft_putstr(char *str);
```
# Correction

```C
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
```
# Démonstration

```C
int	main(void)
{
	ft_putstr("42");
	ft_putstr("\n");
	ft_putstr("Bla bla bla");
	ft_putstr("\n");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c01/ex05  (main) $ norminette -RCheckForbiddenSourceHeader ft_putstr.c 
ft_putstr.c: OK!
Repo Git : Practice42/Work/C/c01/ex05  (main) $ gcc ft_putstr.c 
Repo Git : Practice42/Work/C/c01/ex05  (main) $ ./a.out 
42
Bla bla bla
Repo Git : Practice42/Work/C/c01/ex05  (main) $ 

```
# Explications

#### Fonction `ft_putstr`

La fonction `ft_putstr` affiche une chaîne de caractères sur la sortie standard (le terminal) en parcourant la chaîne caractère par caractère.

#### Code de la Fonction

```c
#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}
```

#### Explication Détaillée

1. **Boucle `while` pour Parcourir la Chaîne :**

    ```c
    while (*str)
    ```

    - **Condition de la Boucle :** La boucle `while` continue de s'exécuter tant que le caractère pointé par `str` n'est pas le caractère nul (`'\0'`).
    - **Pointeur `str` :** `*str` déréférence le pointeur `str`, obtenant ainsi le caractère courant de la chaîne. En C, une chaîne de caractères se termine par un caractère nul (`'\0'`), qui est évalué à `false` dans une condition.

2. **Écriture du Caractère sur la Sortie Standard :**

    ```c
    write(1, str, 1);
    ```

    - **Fonction `write` :** Cette fonction système est utilisée pour écrire des données sur un descripteur de fichier. Ici, elle écrit sur la sortie standard (`stdout`), représentée par le descripteur de fichier `1`.
    - **Paramètres de `write` :**
        - `1` : Descripteur de fichier pour la sortie standard.
        - `str` : Pointeur vers le caractère à écrire.
        - `1` : Nombre d'octets à écrire (un seul caractère à la fois).

3. **Avancement du Pointeur :**

    ```c
    str++;
    ```

    - **Incrémentation du Pointeur :** `str++` avance le pointeur `str` d'un caractère dans la chaîne.
    - **Parcours de la Chaîne :** En incrémentant le pointeur, la boucle `while` passe au caractère suivant de la chaîne à chaque itération.

### Fonctionnement Global

La fonction `ft_putstr` utilise une boucle `while` pour parcourir chaque caractère d'une chaîne de caractères jusqu'à ce qu'elle atteigne le caractère nul (`'\0'`). À chaque itération, elle écrit le caractère courant sur la sortie standard en utilisant `write`, puis avance le pointeur pour traiter le caractère suivant.

Cette méthode permet d'afficher chaque caractère de la chaîne séquentiellement, ce qui est une approche efficace et directe pour gérer les chaînes de caractères en C.