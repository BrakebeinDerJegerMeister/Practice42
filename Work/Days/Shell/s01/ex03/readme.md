# Énoncé

| Exercice : 03                      |
| ---------------------------------- |
| count_files.sh                     |
| Dossier de rendu : ex03/           |
| Fichiers à rendre : count_files.sh |
| Fonctions Autorisées : Aucune      |
• Écrire une ligne de commande qui affiche le nombre de fichiers réguliers et de
répertoires dans le répertoire courant et tous ses sous-répertoires, y compris le "."
du répertoire de départ.
• Exemple de sortie :
```console
$>./count_files.sh | cat -e
42$
$>
```

# Correction

```sh
vim count_files.sh
```

```sh
find . | wc -l
```

```sh
chmod +x count_files.sh
```

# Démonstration

```console
Repo Git : Practice42/Work/Shell/s01  (main) $ find . | wc -l | cat -e
12$
Repo Git : Practice42/Work/Shell/s01  (main) $ find . -type f -o -type d | wc -l | cat -e
12$
Repo Git : Practice42/Work/Shell/s01  (main) $ 
```

# Explications

La commande `wc` est décrite selon `man` de cette façon : Print  newline,  word, and byte counts for each FILE, and a total line if more than one FILE is specified.  A word is a non-zero-length sequence of printable characters delimited by white space.

son option **`-l, --lines`** : print the newline counts,
Autrement dit, compte le nombre de caractères de fin de ligne, d'où l'on déduit finalement le nombre de lignes.

- **`find . -type f -o -type d | wc -l | cat -e`**:
    - Cette commande liste tous les fichiers (`-type f`) et répertoires (`-type d`) dans le répertoire courant et tous ses sous-répertoires. Le résultat est ensuite compté par `wc -l` qui compte le nombre total de lignes, c’est-à-dire le nombre total de fichiers et de répertoires. `cat -e` affiche ensuite ce nombre suivi d'un `$` pour montrer la fin de la ligne.
- **`find . | wc -l | cat -e`**:
    - Cette commande est plus générale car elle ne filtre pas les types d'éléments et liste donc tout ce qui se trouve dans le répertoire courant et ses sous-répertoires, y compris des liens symboliques ou d'autres types d'éléments spéciaux si présents. 