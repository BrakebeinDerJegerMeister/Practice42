# Énoncé

| Exercise 09                       |
| --------------------------------- |
| Illusions, not tricks, Michael... |
| Turn-in directory : ex09/         |
| Files to turn in : ft_magic       |
| Allowed functions : None          |
• Créer un fichier magique nommé ft_magic qui devra être correctement formaté
pour détecter les fichiers de type 42 file et constitués de la chaîne "42" àu 42ème
octet.

# Correction

Il s'agit de construire un fichier de format pour être utilisé par file qui se chargera d'effectuer la détection de fichiers à tester en se basant sur ce fichier format appelé `ft_magic`

- Dans un premier temps on construit un fichier de test pour voir si notre commande et notre fichier magique fonctionnent ensemble :

```sh
echo -n $(python3 -c 'print("x"*41 + "42")') > test
```

On aurait très bien pu faire un fichier texte contenant directement :
```sh
vim test
```
Puis saisir la chaîne :
```plaintext
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx42
```

Dans un second temps on créé le fichier magique :

```sh
echo "41 string 42 42 file" > ft_magic
```

La ligne `41 string 42 42 file` dans un fichier magique indique à l'outil `file` de vérifier si la chaîne "42" commence exactement à l'octet 42 d'un fichier et, si c'est le cas, de classer ce fichier comme "42 file".

# Démonstration

Ici on voit que le fichier `test` est reconnu comme étant du type `42 file` :
```console
Repo Git : Practice42/Work/Shell/s00/ex09  (main) $ file -m ft_magic test 
test: 42 file
```

Alors qu'ici `readme.md` n'est pas un fichier `42 file`
```console
Repo Git : Practice42/Work/Shell/s00/ex09  (main) $ file -m ft_magic readme.md 
readme.md: Unicode text, UTF-8 text, with very long lines (450)
```

# Explications

Lorsqu'on dit que la chaîne "42" doit se trouver au 42ème octet, cela signifie que la séquence de caractères commence à l'octet numéro 42. En termes de positionnement dans un fichier, cela signifie que le caractère '4' est à l'octet 42 et le caractère '2' est à l'octet 43. 

Donc, pour être plus clair:
- Octet 42: '4'
- Octet 43: '2'

Ainsi, dans le contexte des fichiers magiques utilisés par l'outil `file`, si vous configurez pour détecter la chaîne "42" à partir de l'octet 42, vous devez en effet vérifier que l'octet 42 est '4' et l'octet 43 est '2'. La syntaxe dans le fichier magique devrait alors commencer la vérification à partir de l'octet 41 (puisque l'indexation commence à 0) pour la chaîne "42". Voici comment vous devriez configurer cela dans votre fichier `ft_magic`:

```plaintext
41 string 42 42 file
```

Cette ligne dans le fichier `ft_magic` instruit l'outil `file` à rechercher la séquence de caractères "42" en commençant à lire à partir de l'octet 41. Si cette séquence est trouvée, le fichier en question sera identifié comme "42 file".

