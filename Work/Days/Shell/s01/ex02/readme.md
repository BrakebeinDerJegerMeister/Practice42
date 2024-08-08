# Énoncé

| Exercice : 02                  |
| ------------------------------ |
| find_sh.sh                     |
| Dossier de rendu : ex02/       |
| Fichiers à rendre : find_sh.sh |
| Fonctions Autorisées : Aucune  |
• Écrire une ligne de commande qui cherche dans le répertoire courant et dans tous
ses sous-répertoires tous les fichiers dont le nom se termine par ".sh" (sans les
guillemets) et n’affiche que leurs noms, sans le .sh.
• Exemple de sortie :
```console
$>./find_sh.sh | cat -e
find_sh$
file1$
file2$
file3$
$>
```

# Correction

```sh
find . -name '*.sh' -exec basename {} .sh \;
```

# Démonstration

```console
Repo Git : Practice42/Work/Shell/s01/ex02  (main *) $ ./find_sh.sh | cat -e
find_sh$
Repo Git : Practice42/Work/Shell/s01/ex02  (main *) $ 

```

# Explications

Cette commande est utilisée dans les systèmes Unix et Linux pour trouver des fichiers avec une extension spécifique et en extraire seulement les noms, sans les extensions ni les chemins. Voici une explication détaillée de chaque élément de la commande :

1. **`find . -name '*.sh'`** : 
   - **`find`** : C'est la commande utilisée pour rechercher des fichiers et des répertoires dans une hiérarchie de répertoires.
   - **`.`** : Spécifie le répertoire de départ pour la recherche, ici `.` représente le répertoire courant.
   - **`-name '*.sh'`** : C'est un critère de recherche qui indique à `find` de lister tous les fichiers dont les noms se terminent par `.sh`. Le `*` est un joker qui correspond à n'importe quelle chaîne de caractères.

2. **`-exec basename {} .sh \;`** :
   - **`-exec`** : C'est une action de la commande `find` qui permet d'exécuter une commande sur chaque fichier trouvé qui correspond aux critères de recherche. L'action est exécutée pour chaque fichier trouvé avant de passer au suivant.
   - **`basename {} .sh`** : `basename` est une commande qui extrait le nom de base d'un chemin complet. Ici, `{}` est un substitut utilisé par `find` pour représenter le chemin complet du fichier trouvé. L'argument `.sh` indique à `basename` de supprimer l'extension `.sh` du nom de fichier.
   - <code>\;</code> : Le point-virgule indique la fin de la commande à exécuter. Il doit être précédé d'un backslash (`\`) pour être interprété littéralement comme un caractère et non comme un spécial par le shell.

