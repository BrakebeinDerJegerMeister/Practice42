# Énoncé

| Exercice : 04                                       |
| --------------------------------------------------- |
| btree_insert_data                                   |
| Dossier de rendu : ex04/                            |
| Fichiers à rendre : btree_insert_data.c, ft_btree.h |
| Fonctions Autorisées : btree_create_node            |
• Écrire la fonction btree_insert_data qui insère l’élément item dans un arbre.
L’arbre passé en paramètre sera trié : pour chaque node tous les élements inférieurs se situent dans la partie gauche et tous les éléments supérieurs ou égaux à droite. On enverra en paramètre une fonction de comparaison ayant le même
comportement que strcmp.
• Le paramètre root pointe sur le noeud racine de l’arbre. Lors du premier appel, il pointe sur NULL.
• Elle devra être prototypée de la façon suivante :
```C
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));
```
# Correction

ft_btree.h :
```C
#ifndef FT_BTREE_H
# define FT_BTREE_H

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}	t_btree;

t_btree	*btree_create_node(void *item);

#endif
```

btree_insert_data.c :
```C

```
# Algorithme

# Démonstration

```C

```

```

```
# Explications

Exemple où un nouvel élément "E" doit être inséré dans l'arbre binaire de recherche (ABR) suivant :

```
      D
     / \
    C   F
```

### Principe de l'Insertion

1. **Navigation vers le Point d'Insertion** :
   - Lorsque vous insérez "E" et que vous arrivez au nœud "D", vous comparez "E" avec "D".
   - Si "E" est supérieur ou égal à "D", vous allez vers le sous-arbre droit de "D".
   - Supposons que "D" a déjà un sous-arbre droit "F", vous comparez ensuite "E" à "F".

2. **Placement Correct de "E"** :
   - Si "E" est inférieur à "F", "E" doit être placé dans le sous-arbre gauche de "F" (à condition que cette position soit disponible, c’est-à-dire `NULL`).
   - S'il n'y a pas de sous-arbre gauche à "F" (i.e., `F->left` est `NULL`), alors "E" peut être inséré directement à cette position.
   - Si "F" avait déjà un sous-arbre gauche "G" et que "E" est inférieur à "F" mais supérieur à "G", alors "E" s'insérerait entre "F" et "G", respectant toujours l'ordre des ABR.

### Illustration avec l'Exemple de D, C, F, E

Reprenons l'arbre avant insertion de "E" :

```
      D
     / \
    C   F
```

**Processus d'insertion de "E"** :

- Comparez "E" avec "D" : "E" >= "D", donc allez à droite vers "F".
- Comparez "E" avec "F" : "E" < "F", donc le placement est à gauche de "F".

Si `F->left` est `NULL` :

```
      D
     / \
    C   F
       /
      E
```

Dans cet exemple, "E" est inséré comme le sous-arbre gauche de "F", et "F" ne doit pas être déplacé ou remplacé. "E" devient simplement une nouvelle feuille dans l'arbre, et l'arbre reste un ABR valide.

### Résumé

- **Insertions** : Les insertions dans un ABR ne requièrent jamais de remplacer un nœud existant ni de réarranger l'arbre de manière complexe. Elles nécessitent simplement de trouver le bon point `NULL` où insérer le nouveau nœud.
- **Maintien de l'ordre** : Chaque insertion respecte l'ordre strict des valeurs dans l'ABR, et les nœuds sont ajoutés en tant que nouvelles feuilles pour maintenir cet ordre sans perturber la structure existante.

En suivant cette méthode, l'ABR garantit une efficacité optimale des opérations de recherche, d'insertion et de suppression, et maintient une complexité en O(log n) pour ces opérations dans le cas moyen.


### Un détail à revoir :

```C
	if ((*cmpf)(*root->item, item) > 0)
		btree_insert_data(&(*root)->left, item, cmpf);
	else
		btree_insert_data(&(*root)->right, item, cmpf);
```
Se lit ainsi :
Si l'item actuel est plus grand que l'item à insérer, aller à gauche
Si l'item actuel est égal ou plus petit que l'item à insérer, aller à droite