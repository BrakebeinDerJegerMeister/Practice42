# Énoncé

| Exercice : 00                   |
| ------------------------------- |
| ft_strdup                       |
| Dossier de rendu : ex00/        |
| Fichiers à rendre : ft_strdup.c |
| Fonctions Autorisées : malloc   |
• Reproduire à l’identique le fonctionnement de la fonction strdup (man strdup).
• Elle devra être prototypée de la façon suivante :
```C
char *ft_strdup(char *src);
```
# Correction

```C
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	new = (char *)malloc(i + 1);
	i = 0;
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
```

# Démonstration

```C
#include <stdio.h>

void	test(char *str)
{
	char	*res;

	printf("\nsrc : {%s}", str);
	res = ft_strdup(str);
	printf("\nres : {%s}\n", res);
}

int	main(void)
{
	test("Coucou");
	test("C'est le masupilami : Houba houba");
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c07/ex00  (main) $ norminette -RCheckForbiddenSourceHeader ft_strdup.c 
ft_strdup.c: Error!
Error: INCLUDE_START_FILE   (line:  34, col:   1):	Include must be at the start of file
Repo Git : Practice42/Work/C/c07/ex00  (main) $ gcc -Wall -Wextra -Werror ft_strdup.c 
Repo Git : Practice42/Work/C/c07/ex00  (main) $ ./a.out 

src : {Coucou}
res : {Coucou}

src : {C'est le masupilami : Houba houba}
res : {C'est le masupilami : Houba houba}
Repo Git : Practice42/Work/C/c07/ex00  (main) $ 
```
# Explications

## `malloc`

`malloc` est une fonction essentielle en C, utilisée pour allouer dynamiquement de la mémoire pendant l'exécution d'un programme. Le nom `malloc` provient de l'anglais *memory allocation*. Voici un aperçu de son utilisation, ses caractéristiques, et quelques points d'attention lors de son emploi.

### Fonctionnement

`malloc` permet de réserver un bloc de mémoire d'une taille spécifiée en octets et renvoie un pointeur vers le début de ce bloc. La signature de la fonction est la suivante :

```c
void* malloc(size_t size);
```

- `size` : le nombre d'octets à allouer.
- La fonction renvoie un pointeur de type `void*` qui peut être converti en n'importe quel autre type de pointeur.

### Utilisation

Pour utiliser `malloc`, vous devez inclure l'en-tête `<stdlib.h>`. Voici un exemple simple d'utilisation de `malloc` pour allouer de la mémoire pour un tableau de 10 entiers :

```c
#include <stdlib.h>

int* array = (int*) malloc(10 * sizeof(int));
if (array == NULL) {
    // Échec de l'allocation, gestion de l'erreur
}
```

### Gestion de la mémoire

Une fois que la mémoire n'est plus nécessaire, il est crucial de la libérer en utilisant `free()` pour éviter les fuites de mémoire. Par exemple :

```c
free(array);
```

### Points d'attention

- **Initialisation :** La mémoire allouée par `malloc` n'est pas initialisée. Les données présentes à cette adresse mémoire sont indéterminées. Si vous avez besoin de mémoire initialisée à zéro, vous pouvez utiliser `calloc` à la place.
- **Gestion des erreurs :** `malloc` renvoie `NULL` si l'allocation échoue (par exemple, si le système n'a plus de mémoire disponible). Il est important de vérifier si le résultat de `malloc` est `NULL` avant d'utiliser le pointeur retourné.
- **Sécurité :** Utiliser des pointeurs non initialisés ou après qu'ils aient été libérés peut conduire à des vulnérabilités et des erreurs de segmentation. Assurez-vous toujours que vos pointeurs sont valides.
- **Portabilité :** L'allocation dynamique peut se comporter différemment sur différentes plateformes en termes de gestion de la mémoire. Il est bon de connaître l'environnement cible pour optimiser l'utilisation de la mémoire.

### Conclusion

`malloc` est un outil puissant pour la gestion de la mémoire en C, permettant une flexibilité significative dans la construction de programmes complexes. Toutefois, il requiert une utilisation prudente et une bonne compréhension de ses implications pour éviter des erreurs coûteuses en termes de performance et de sécurité.