# Énoncé

| Exercice : 07                   |
| ------------------------------- |
| ft_putnbr                       |
| Dossier de rendu : ex07/        |
| Fichiers à rendre : ft_putnbr.c |
| Fonctions Autorisées : write    |
• Écrire une fonction qui affiche un nombre passé en paramètre. La fonction devra être capable d’afficher la totalité des valeurs possibles dans une variable de type int.
• Elle devra être prototypée de la façon suivante :
```
void ft_putnbr(int nb);
```
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
# Algorithme

1. **Fonction `ft_putnbr`**:
   - **Entrée**: Un entier `nb`.
   - **Processus**:
     - Si `nb` est négatif, le signe négatif (`-`) est écrit en premier à l'aide de la fonction `write`, et la valeur de `nb` est convertie en positif.
     - La fonction `nextnumber` est appelée avec la valeur absolue de `nb`.

2. **Fonction `nextnumber`**:
   - **Entrée**: Un entier `nb`.
   - **Processus**:
     - La dernière chiffre de `nb` est extraite en utilisant l'opération modulo 10.
     - Ce chiffre est converti en caractère.
     - Le nombre `nb` est ensuite divisé par 10 (en ignorant le reste précédemment extrait), réduisant ainsi `nb` à `nb/10`.
     - Si le résultat de cette division (nouveau `nb`) n'est pas zéro, `nextnumber` est appelée récursivement avec ce nouveau `nb`.
     - Après la sortie de la récursion (ou directement si `nb` était initialement zéro), le caractère correspondant au chiffre extrait est écrit à l'écran.
   - **Sortie**: Aucune sortie directe (c'est une fonction de type `void`), mais les chiffres de l'entier sont écrits sur la sortie standard un par un, à partir du chiffre le moins significatif jusqu'au plus significatif en raison de l'appel récursif.

L'algorithme fonctionne en décomposant le nombre entier en ses chiffres individuels de droite à gauche (des unités aux dizaines, centaines, etc.), les stocke sous forme de caractères, et les écrit dans l'ordre inverse, à l'aide de la récursivité pour gérer l'ordre d'affichage correct des chiffres sinon les chiffres apparaîtraient dans l'ordre inverse.
# Démonstration

```C
int	main(void)
{
	ft_putnbr(42);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(420);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(0);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(-4200);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(-42);
	write(1, &(char){'\n'}, 1);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c00/ex07  (main *) $ norminette -RCheckForbiddenSourceHeader ft_putnbr.c 
ft_putnbr.c: OK!
Repo Git : Practice42/Work/C/c00/ex07  (main *) $ gcc ft_putnbr.c 
Repo Git : Practice42/Work/C/c00/ex07  (main *) $ ./a.out 
42
420
0
-4200
-42
Repo Git : Practice42/Work/C/c00/ex07  (main *) $ 
```
# Explications

### 1. Modulo (`%`)
Le modulo est une opération qui donne le reste de la division d'un nombre par un autre. Dans le cas de `nb % 10`, cela permet de récupérer le dernier chiffre d'un nombre. Par exemple, pour `123`, `123 % 10` donne `3`.

### 2. Récursivité
La récursivité est une méthode où une fonction s'appelle elle-même pour résoudre une partie du problème jusqu'à ce qu'une condition finale soit atteinte, ici jusqu'à ce que `nb` soit zéro. Après avoir isolé le dernier chiffre avec le modulo, on réduit le nombre initial en enlevant le dernier chiffre (`(nb - next) / 10`), puis on rappelle la fonction avec ce nouveau nombre. Cela continue jusqu'à ce que tout le nombre soit traité, chiffre par chiffre.

### 3. Casts
Il y a trois moments où des conversions de type (cast) sont utilisées :
#### Cast pour convertir un int en long int

Pour prévenir le débordement lors de la conversion de l'entier minimal en son opposé positif, une approche consiste à effectuer un cast vers un type de donnée de capacité supérieure. En effet, dans le cas où l'entier minimal serait par exemple -2147483648 (pour un `int` sur des architectures 32 bits), et l'entier positif maximal serait 2147483647, convertir directement l'entier minimal en positif entraînerait un débordement, car 2147483648 ne peut pas être représenté par un `int`.

Pour contourner cette limitation, il est recommandé de convertir la valeur initiale en un type de donnée ayant une capacité supérieure. Voici un exemple de conversion explicite en C utilisant un cast pour transformer un `int` en `long int` :

```C
long int	nb;

nb = (long int)old_nb;
```

Cette opération garantit que même la valeur absolue de l'entier minimal pourra être représentée correctement, évitant ainsi le risque de débordement lors des opérations ultérieures. En utilisant `long int`, qui typiquement offre une plus grande plage de représentation numérique que `int`, la valeur -2147483648 peut être convertie en 2147483648 sans risque de dépasser les limites du type.
#### Cast pour convertir un chiffre en caractère
```c
disp = next + '0';
```
Ici, `next` est un chiffre entre 0 et 9 (obtenu par le modulo). Pour le convertir en caractère (par exemple, le chiffre `2` en caractère `'2'`), on ajoute `'0'` à `next`. En ASCII, `'0'` a une valeur de 48, donc ajouter `2` à 48 donne 50, qui est la valeur ASCII de `'2'`.

#### Cast pour écrire un caractère avec `write`
```c
write(1, &disp, 1);
```
Dans cette expression, `disp` est un `char` contenant un chiffre sous forme de caractère. L'opération `&disp` obtient l'adresse en mémoire de ce caractère, nécessaire pour la fonction `write`, qui attend une adresse mémoire et non directement la valeur. Le troisième argument `1` indique que `write` doit écrire un seul caractère.

Dans la fonction `ft_putnbr`, il y a également un cast implicite lors de l'écriture du signe négatif :
```c
write(1, &(char){'-'}, 1);
```
Ici, `&(char){'-'}` crée une instance temporaire du caractère `'-'` et en obtient l'adresse. Ce style permet de passer directement le caractère négatif à `write` sans avoir besoin de le stocker dans une variable.

Ces deux exemples montrent comment le cast est utilisé pour manipuler les types de données de manière appropriée pour des fonctions spécifiques, ici pour la conversion de types numériques en types caractères et pour s'adapter aux exigences d'une fonction d'entrée/sortie comme `write`.