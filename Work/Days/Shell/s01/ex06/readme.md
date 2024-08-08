# Énoncé

| Exercice : 06                 |
| ----------------------------- |
| skip.sh                       |
| Dossier de rendu : ex06/      |
| Fichiers à rendre : skip.sh   |
| Fonctions Autorisées : Aucune |
• Écrire une ligne de commande et qui affiche un ls -l une ligne sur deux, à partir de la première.

# Correction

```sh
ls -l | sed -n 'p;n'
```

# Démonstration

```console
Repo Git : Practice42/Work/Shell/s00  (main) $ ls -l | sed -n 'p;n'
total 1392
drwxrwxr-x 2 profchaos profchaos    4096 juin  25 09:32 ex01
drwxrwxr-x 2 profchaos profchaos    4096 juin  25 09:32 ex03
drwxrwxr-x 2 profchaos profchaos    4096 juin  25 09:32 ex05
drwxrwxr-x 2 profchaos profchaos    4096 juin  25 09:32 ex07
drwxrwxr-x 2 profchaos profchaos    4096 juin  25 09:32 ex09
```

# Complément (vu sur stack overflow)

Quelqu'un dit qu'il faut inverser n et p, cependant cette personne n'a pas connaissance que notre énoncé était à partir de la première ligne mais l'exemple est très intéressant :

(Puisque ici il s'agit d'éviter la première ligne) 
https://stackoverflow.com/questions/71047727/how-to-skip-a-line-every-two-lines-starting-by-skipping-the-first-line

You have to invert your `sed` command: it should be `n;p` instead of `p;n`:

Your code:

```bash
for x in {1..20}; do echo $x ; done | sed -n 'p;n'
```

```bash
1
3
5
7
9
11
13
15
17
19
```

The version with `sed` inverted:

```bash
for x in {1..20}; do echo $x ; done | sed -n 'n;p'
```

Output:

```bash
2
4
6
8
10
12
14
16
18
20
```
# Explications

La commande `ls -l | sed -n 'p;n'` est utilisée pour lister les fichiers et répertoires dans le format long, mais n'affiche qu'une ligne sur deux de la sortie. 

1. **`ls -l`** :
   - `ls` est une commande Unix/Linux utilisée pour lister les fichiers et les répertoires.
   - L'option `-l` spécifie que la liste doit être affichée en format long, ce qui inclut des informations détaillées telles que les permissions, le nombre de liens, le propriétaire, le groupe, la taille des fichiers, et la date de dernière modification pour chaque fichier ou répertoire.

2. **`|` (pipe)** :
   - Le pipe prend la sortie de la commande à sa gauche (`ls -l`) et la transmet à l'entrée de la commande à sa droite (`sed -n 'p;n'`).
   - Cela permet de traiter la sortie de `ls -l` avec la commande `sed`.

3. **`sed -n 'p;n'`** :
   - `sed` est un éditeur de flux pour le filtrage et la transformation de texte.
   - L'option `-n` est utilisée pour supprimer l'impression automatique de chaque ligne de texte. Sans cette option, `sed` imprimerait chaque ligne par défaut avant d'appliquer les commandes spécifiées.
   - `'p;n'` est une suite de commandes `sed` :
     - `p` (print) indique à `sed` d'imprimer la ligne courante. Avec l'option `-n`, cela signifie que seules les lignes explicitement demandées par `p` seront imprimées.
     - `n` (next) indique à `sed` de passer à la ligne suivante sans la traiter. Cela signifie que cette ligne ne sera pas imprimée, car l'impression automatique est désactivée par `-n`.

En utilisant cette combinaison de commandes, `ls -l | sed -n 'p;n'` affiche donc une ligne sur deux de la liste complète des fichiers et répertoires. Ce comportement est utile pour examiner des échantillons de données dans un répertoire très peuplé ou pour simplifier l'affichage dans un contexte où trop d'informations peuvent être encombrantes.