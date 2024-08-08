# Énoncé (GIT)

| Exercise 06                      |
| -------------------------------- |
| GiT                              |
| Turn-in directory : ex06/        |
| Files to turn in : git_ignore.sh |
| Allowed functions : None         |
• Écrivez un court script shell qui renverra la liste des fichiers existants ignorés par
votre dépot git actuellement présents dans votre dépot local. Exemple:
```console
%> bash git_ignore.sh | cat -e
.DS_Store$
mywork.c~$
%>
```
Votre script sera teste dans notre environnement.


# Correction

```
# se placer évidemment dans le dossier
vim git_ignore.sh
```

> appuyer sur `i` (insertion avant le curseur)
```vim
cat .gitignore
```
> appuyer sur `ESC` (Passer en mode commande)
> écrire sur `:x` (enregistrer et quitter immédiatement)


# Démonstration

```
Repo Git : Practice42/  (main *) $ cat .gitignore | cat -e
.obsidian/$
Repo Git : Practice42/  (main *) $
```


# Explications

## Qu'avons nous fait ?

Nous nous sommes contentés de simplement afficher la sortie de fichier .gitignore qui sera redirigée vers cat avec un pipe `|`

## .gitignore

Le fichier `.gitignore` est utilisé dans les projets gérés avec le système de contrôle de version Git. Son rôle est d'indiquer à Git quelles fichiers ou dossiers doivent être ignorés et non suivis. Cela permet de prévenir l'inclusion de fichiers non essentiels ou sensibles dans un dépôt Git, tels que des fichiers temporaires, des logs, des fichiers de configuration spécifiques à un environnement ou des dépendances installées localement.

Voici comment fonctionne un fichier `.gitignore` :

1. **Placement** : Le fichier `.gitignore` se place à la racine du dépôt Git ou dans des sous-dossiers pour appliquer des règles spécifiques à ces répertoires.
2. **Syntaxe** :
   - Les lignes vides servent de séparateurs pour améliorer la lisibilité.
   - Les commentaires sont précédés par un signe dièse (`#`).
   - Les chemins relatifs définis dans le fichier sont relatifs à l'emplacement du fichier `.gitignore`.
   - Les motifs glob peuvent être utilisés pour spécifier des règles, comme `*.log` pour ignorer tous les fichiers `.log`.
   - L'exclusion peut être précédée par un point d'exclamation (`!`) pour ré-inclure des fichiers qui seraient autrement ignorés par les règles précédentes.

3. **Exemples de règles courantes** :
   - Ignorer tous les fichiers `.log` : `*.log`
   - Ignorer un dossier spécifique : `build/`
   - Ignorer tous les fichiers sauf ceux avec une extension spécifique (par exemple, garder tous les fichiers `.c`) : `*.*` suivi de `!*.c`

En pratique, utiliser un fichier `.gitignore` approprié est crucial pour maintenir la propreté du dépôt et éviter que des fichiers intermédiaires ou personnels ne soient exposés involontairement. Chaque projet peut nécessiter un ensemble spécifique de règles dans `.gitignore` selon les outils, les langages de programmation, et les pratiques spécifiques utilisés.