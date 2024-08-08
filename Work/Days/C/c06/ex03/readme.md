# Énoncé

| Exercice : 03                        |
| ------------------------------------ |
| ft_sort_params                       |
| Dossier de rendu : ex03/             |
| Fichiers à rendre : ft_sort_params.c |
| Fonctions Autorisées : write         |
• Il s’agit ici d’un programme, vous devrez donc avoir une fonction main dans votre
fichier.c.
• Écrire un programme qui affiche les arguments reçus en ligne de commande triés
par ordre ascii.
• Vous devez afficher tous les arguments, sauf argv[0].
• Un argument par ligne.
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	sort_me_asc(int nb, char **strings)
{
	int		i;
	int		j;
	char	*str;

	i = 2;
	while (i < nb)
	{
		str = strings[i];
		j = i - 1;
		while (j >= 1 && (ft_strcmp(strings[j], str) > 0))
		{
			strings[j + 1] = strings[j];
			j--;
		}
		strings[j + 1] = str;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	sort_me_asc(argc, argv);
	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
```

# Démonstration

```
Repo Git : Practice42/Work/C/c06/ex03  (main) $ ./a.out t4 t5 t2 t0 test1 test2 test3
t0
t2
t4
t5
test1
test2
test3
Repo Git : Practice42/Work/C/c06/ex03  (main) $ 
```

# Algorithme

L'algorithme de tri par insertion, tel qu'implémenté ci-dessus, opère en parcourant un tableau de chaînes de caractères. Il commence à partir du deuxième élément du tableau, en considérant que le segment avant l'élément actuel est déjà trié, et cherche à insérer l'élément actuel à sa position correcte parmi les éléments précédents pour maintenir l'ordre croissant.

À chaque itération, l'élément actuel est stocké temporairement et un pointeur se déplace à partir de cet indice vers le début du tableau, comparant l'élément actuel avec chaque précédent. Si un élément précédent est plus grand que l'élément actuel, il est déplacé vers la droite, faisant ainsi de la place pour l'élément actuel. Ce processus se poursuit jusqu'à ce que le pointeur atteigne le début du tableau ou un élément inférieur à l'élément actuel. L'élément actuel est ensuite inséré à cette position.

Ce procédé est répété pour chaque élément du tableau jusqu'à ce que le tableau entier soit trié. La complexité temporelle de cet algorithme est généralement de l'ordre de \(O(n^2)\), ce qui le rend peu efficace pour de grands ensembles de données par rapport à des algorithmes de tri plus rapides comme le tri fusion ou le tri rapide. Cependant, pour des ensembles de données petits ou presque triés, il peut être très performant et facile à implémenter.


# Exemple

Prenons le tableau suivant :

```
["E", "C", "F", "A", "D", "B"]
```

Nous allons détailler le processus de tri pas à pas :

**Étape initiale**:
```
["E", "C", "F", "A", "D", "B"]
```

**Étape 1** : Insertion de "C"

- "C" est comparé avec "E", et "E" est déplacé à droite car "E" > "C".

```
|---- Déplacement ----|
["E", "E", "F", "A", "D", "B"]
  ↑
["C", "E", "F", "A", "D", "B"]
```

**Étape 2** : Insertion de "F"

- "F" est comparé avec "E", et aucun déplacement n'est nécessaire car "E" < "F".

```
["C", "E", "F", "A", "D", "B"]
```

**Étape 3** : Insertion de "A"

- "A" est comparé avec "F", "F" est déplacé à droite.
- "A" est ensuite comparé avec "E", "E" est déplacé à droite.
- "A" est finalement comparé avec "C", "C" est déplacé à droite.

```
|---- Déplacements ----|
["C", "E", "F", "F", "D", "B"]
            ↑
["C", "E", "E", "F", "D", "B"]
      ↑
["C", "C", "E", "F", "D", "B"]
  ↑
["A", "C", "E", "F", "D", "B"]
```

**Étape 4** : Insertion de "D"

- "D" est comparé avec "F", "F" est déplacé à droite.
- "D" est ensuite comparé avec "E", "E" est déplacé à droite.

```
|---- Déplacements ----|
["A", "C", "E", "F", "F", "B"]
            ↑
["A", "C", "E", "E", "F", "B"]
      ↑
["A", "C", "D", "E", "F", "B"]
```

**Étape 5** : Insertion de "B"

- "B" est comparé avec "F", "F" est déplacé à droite.
- "B" est ensuite comparé avec "E", "E" est déplacé à droite.
- "B" est ensuite comparé avec "D", "D" est déplacé à droite.
- "B" est ensuite comparé avec "C", "C" est déplacé à droite.

```
|---- Déplacements ----|
["A", "C", "D", "E", "F", "F"]
            ↑
["A", "C", "D", "E", "E", "F"]
      ↑
["A", "C", "D", "D", "E", "F"]
  ↑
["A", "C", "C", "D", "E", "F"]
  ↑
["A", "B", "C", "D", "E", "F"]
```

**Tableau final trié**:
```
["A", "B", "C", "D", "E", "F"]
```
