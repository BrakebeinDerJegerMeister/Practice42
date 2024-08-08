# Énoncé

| Exercice : 05                          |
| -------------------------------------- |
| Can you create it ?                    |
| Dossier de rendu : ex05/               |
| Fichiers à rendre : "\?$*’MaRViN’*$?\" |
| Fonctions Autorisées : Aucune          |
• Créer un fichier contenant uniquement "42" et RIEN d’autre.
• Il se nommera :
```plaintext
"\?$*'MaRViN'*$?\"
```
• Exemple :
```console
$>ls -lRa *MaRV* | cat -e
-rw---xr-- 1 75355 32015 2 Oct 2 12:21 "\?$*'MaRViN'*$?\"$
$>
```

# Correction

```sh
echo "42"> \"\\\?\$\*\'MaRViN\'\*\$\?\\\"
```

# Démonstration

```console
Repo Git : Practice42/Work/Shell/s01/ex05  (main) $ ls -lRa *MaRV* | cat -e
-rw-rw-r-- 1 kaos kaos 3 juin  24 20:44 "\?$*'MaRViN'*$?\"$
Repo Git : Practice42/Work/Shell/s01/ex05  (main) $
```

Par curiosité :

```console
Repo Git : Practice42/Work/Shell/s01/ex05  (main) $ ls -l
total 8
-rw-rw-r-- 1 kaos kaos    3 juin  24 20:44 '"\?$*'\''MaRViN'\''*$?\"'
-rw-rw-r-- 1 kaos kaos 1094 juin  24 20:45  readme.md
Repo Git : Practice42/Work/Shell/s01/ex05  (main) $ 
```
# Explications

La commande mentionnée, `echo "42"> \"\\\?\$\*\'MaRViN\'\*\$\?\\\"`, est un exemple de comment écrire dans un fichier avec un nom très complexe contenant plusieurs caractères qui doivent être échappés pour être interprétés littéralement par le shell. Voici une explication détaillée des éléments de cette commande et pourquoi les antislashs (`\`) sont utilisés :

### La commande `echo`

- `echo "42"` : Cela indique au shell de sortir le texte `42`. `echo` est souvent utilisé pour envoyer du texte à la sortie standard ou dans un fichier.

### Redirection `>`

- `>` : Ceci est un opérateur de redirection qui prend la sortie de la commande à sa gauche (ici, `echo "42"`) et l'écrit dans le fichier spécifié à sa droite. Si le fichier existe déjà, son contenu sera écrasé.

### Nom de fichier avec caractères spéciaux

- Le nom de fichier ici est `"\"\\\?\$\*\'MaRViN\'\*\$\?\\\""` et comprend une complexe série de caractères spéciaux et d'antislashs pour l'échappement. Expliquons pourquoi chaque antislash est nécessaire :

  - **`\"`** : Échappe les guillemets doubles. Les guillemets sont utilisés pour définir les limites d'une chaîne de caractères en shell, donc si vous voulez que les guillemets fassent partie du nom de fichier, vous devez les échapper avec `\`.
  
  - **`\\\?`** : Le point d'interrogation (`?`) est un caractère spécial en shell qui correspond à n'importe quel caractère unique. Pour l'utiliser littéralement (comme partie du nom de fichier), vous devez l'échapper avec deux antislashs. Un antislash est utilisé pour échapper l'antislash lui-même, et un autre pour échapper le point d'interrogation.
  
  - **`\$`** : Le dollar (`$`) est utilisé en shell pour signifier une variable. Pour l'utiliser comme un caractère littéral, il doit être échappé avec `\`.
  
  - **`\*`** : L'astérisque (`*`) est un caractère spécial en shell utilisé pour la correspondance de motifs (globbing), représentant zéro ou plusieurs caractères. Pour l'utiliser comme un simple caractère dans un nom de fichier, il doit être échappé.
  
  - **`\'`** : Les guillemets simples sont utilisés pour délimiter des chaînes qui sont prises littéralement par le shell, sans interprétation des caractères spéciaux. Échapper un guillemet simple permet de l'inclure dans une chaîne délimitée par des guillemets simples.

Chaque caractère spécial ou qui pourrait être interprété par le shell (comme un indicateur pour une variable, une expansion de commande, ou une correspondance de motif) doit être échappé pour être utilisé littéralement. Cette commande montre comment échapper correctement une série complexe de ces caractères pour s'assurer que le nom de fichier est traité comme une chaîne littérale et non comme une instruction ou un motif par le shell.