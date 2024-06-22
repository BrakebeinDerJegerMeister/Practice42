# Énoncé

| Exercise 05                      |
| -------------------------------- |
| GiT commit?                      |
| Turn-in directory : ex05/        |
| Files to turn in : git_commit.sh |
| Allowed functions : None         |
• Créez un script shell qui renvoie les id des 5 derniers commit de votre dépot git.
```console
%> bash git_commit.sh | cat -e
baa23b54f0adb7bf42623d6d0a6ed4587e11412a$
2f52d74b1387fa80eea844969e8dc5483b531ac1$
905f53d98656771334f53f59bb984fc29774701f$
5ddc8474f4f15b3fcb72d08fcb333e19c3a27078$
e94d0b448c03ec633f16d84d63beaef9ae7e7be8$
%>
```
Votre script sera teste dans notre environnement.

# Correction

```sh
vim git_commit.sh
```

> appuyer sur `i` (insertion avant le curseur)
```vim
git log -n 5 --pretty=format:"%H"
echo
```
> appuyer sur `ESC` (Passer en mode commande)
> écrire sur `:x` (enregistrer et quitter immédiatement)


# Démonstration

```console
Repo Git : Practice42/Work/Shell/s00/ex05  (main) $ bash git_commit.sh | cat -e
60e2650c59c14d958630abb453d564588c762b14$
c6daa121999d47bf730ebbd8f37c7a0e01706236$
9a6483b790bd8ed931c8ced946b06e2605cb69d7$
8ba0f7e3b568c5ddaf32c890f49f7d6020129748$
868d1614dc294f8d63875bc5533a4387e942a31b$
Repo Git : Practice42/Work/Shell/s00/ex05  (main) $ 
```

# Explications

Obtenir la liste des commits effectués dans le dépôt local
```
git log
```

Ne garder que les 5 derniers
```
-n 5
```

Améliorer l'affichage
```
--pretty=format:"%H"
```

Produire un saut de ligne supplémentaire sinon le prompt va être décalé
```
echo
```


# En savoir plus

## git log & --pretty

L'option `--pretty=format:"%H"` est utilisée avec la commande `git log` pour personnaliser l'affichage des informations relatives aux commits dans un dépôt Git. Elle permet de spécifier exactement quels détails du commit doivent être montrés et comment ils doivent être formatés.

### Explication de `--pretty=format:"%H"`

- **`%H`** : Spécifie que vous voulez afficher le hash complet du commit.

Quand vous utilisez cette option dans `git log`, par exemple :
```bash
git log --pretty=format:"%H"
```
Cela produit une liste des hashes complets de chaque commit dans la branche actuelle, un hash par ligne, sans aucune autre information comme le nom de l'auteur, la date, ou le message du commit.

### Autres options de formatage utiles

En plus de `%H` pour le hash complet, voici quelques spécificateurs de format utiles que vous pourriez vouloir utiliser avec `--pretty=format`:

- **`%h`** : Le hash abrégé du commit.
- **`%an`** : Le nom de l'auteur du commit.
- **`%ae`** : L'email de l'auteur du commit.
- **`%ad`** : La date du commit.
- **`%s`** : Le sujet (c'est-à-dire le message de titre) du commit.

### Exemples d'utilisation de formatage

Vous pouvez combiner plusieurs spécificateurs pour afficher différentes informations. Par exemple :

```bash
git log --pretty=format:"%h - %an (%ad) : %s"
```

Cela affichera le hash abrégé du commit, le nom de l'auteur, la date du commit entre parenthèses, et le message du commit, le tout dans une seule ligne pour chaque commit.

Cette approche est extrêmement flexible et vous permet de voir précisément les informations qui vous intéressent, formatées de manière à être facile à lire et à analyser, surtout dans les grands dépôts avec un historique de commit complexe.

## Hash

Le "hash" en informatique, et plus spécifiquement dans le contexte de systèmes de gestion de versions comme Git, est une chaîne de caractères générée par une fonction de hachage. Un hash est généralement utilisé pour identifier de manière unique des ensembles de données comme des fichiers ou des commits dans un dépôt Git. Voici quelques points pour mieux comprendre ce concept :

### Fonction de Hachage
- **Fonction de Hachage** : C’est une fonction mathématique qui prend une entrée (ou "message") et retourne une chaîne de caractères de longueur fixe, qui semble aléatoire. La chaîne de caractères est généralement une représentation hexadécimale et est appelée "hash". Par exemple, des fonctions de hachage courantes incluent SHA-256, SHA-1, MD5, entre autres.

### Propriétés d'une Fonction de Hachage
- **Déterminisme** : Une même entrée donnera toujours la même sortie (le même hash).
- **Diffusion** : Même un petit changement dans l'entrée entraîne un hash complètement différent.
- **Efficient** : Calculer le hash d'une entrée est rapide.
- **Sécurité** : Il est pratiquement impossible de retrouver l'entrée originale uniquement à partir du hash (irréversibilité). De plus, il est extrêmement difficile de trouver deux entrées différentes qui produiraient le même hash (résistance aux collisions).

### Utilisation dans Git
Dans Git, la fonction de hachage SHA-1 a traditionnellement été utilisée pour créer un identifiant unique pour chaque commit. Chaque commit, avec son ensemble de modifications, auteur, message de commit et horodatages, est passé à la fonction de hachage SHA-1, qui produit un hash de 40 caractères. Ce hash sert à identifier de manière unique le commit dans l'historique du dépôt. Voici ce que cela implique :

- **Intégrité** : Le hash permet de vérifier l'intégrité des données. Si les données sont altérées, le hash calculé sera différent.
- **Traçabilité** : Chaque commit peut être appelé ou examiné par son hash, permettant une navigation facile dans l'historique.

### Migration vers SHA-256
En raison de faiblesses découvertes dans SHA-1 et la possibilité théorique de collisions (deux données différentes produisant le même hash), Git a commencé à adopter SHA-256 dans les versions les plus récentes pour améliorer la sécurité et la robustesse du contrôle de version.

En résumé, dans le cadre de Git et d'autres applications informatiques, un hash est une empreinte digitale numérique qui permet de vérifier, identifier et gérer les données de manière efficace et sécurisée.