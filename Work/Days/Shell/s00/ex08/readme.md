# Énoncé

| Exercise 08               |
| ------------------------- |
|                           |
| Turn-in directory : ex08/ |
| Files to turn in : clean  |
| Allowed functions : None  |
• Placez dans un fichier clean une ligne de commande qui va rechercher, à partir
du répertoire courant et dans tous ses sous-répertoires, les fichiers dont le nom se
termine par ~, ou commence et se termine par #.
• La ligne de commande affichera et effacera les fichiers trouvés.
• Une seule commande est autorisée : pas de ’;’ ou de ’&&’ ou autre.

# Correction

```shell
find . \( -name '*~' -o -name '#*#' \) -print -delete
```

# Explications

## La commande :

```shell
find . \( -name '*~' -o -name '#*#' \) -print -delete
```

Explication de la commande :

- `find .` : Cette commande initie une recherche dans le répertoire courant (représenté par `.`) et dans tous ses sous-répertoires.
- `\( -name '*~' -o -name '#*#' \)` : Cela spécifie les motifs de noms de fichiers à rechercher. `-name '*~'` cherche tous les fichiers dont les noms se terminent par `~`. `-name '#*#'` cherche tous les fichiers dont les noms commencent et se terminent par `#`. 
- `-print` : Affiche le chemin des fichiers trouvés. Cela vous permet de voir quels fichiers sont affectés avant qu'ils ne soient supprimés.
- `-delete` : Supprime les fichiers qui correspondent aux critères. Cette action est exécutée après que le fichier a été affiché grâce à `-print`.

## Le caractère `*`

Dans le contexte des commandes Unix comme `find` ou lorsque vous utilisez des motifs glob (globbing patterns) dans le shell, les caractères `*` et `?` ont des significations spécifiques pour la correspondance de noms de fichiers :

### Le Caractère `*`
- **`*`** représente zéro ou plusieurs caractères dans un nom de fichier ou un chemin. Par exemple, `*.txt` correspond à tous les fichiers ayant l'extension `.txt`, peu importe le nom du fichier avant `.txt`.

### Le Caractère `?`
- **`?`** représente un seul caractère. Par exemple, `?.txt` correspond à tous les fichiers dont les noms se composent d'un seul caractère suivi de `.txt`, comme `a.txt`, `b.txt`, mais pas `ab.txt`.

Ces caractères permettent de spécifier des modèles flexibles pour identifier les fichiers et les répertoires dans diverses commandes et scripts, simplifiant la gestion des fichiers par correspondance de motifs.

---
## Les parenthèses

Les parenthèses dans la commande `find`  sont utilisées pour grouper les conditions de recherche et contrôler l'ordre d'évaluation des expressions. En absence de parenthèses, les opérations logiques pourraient ne pas s'exécuter comme prévu, car la commande `find` évalue les expressions de gauche à droite et l'opérateur `-o` (qui signifie "or") a une priorité basse. 

### Sans Parenthèses
Si vous écrivez la commande sans parenthèses :
```bash
find . -name '*~' -o -name '#*#' -print -delete
```
Cette commande ne fonctionnera pas comme prévu pour les deux motifs, car l'opérateur `-o` divise la commande en deux parties :
1. `-name '*~'`
2. `-name '#*#' -print -delete`

Cela signifie que :
- Pour les fichiers se terminant par `~`, la commande ne les affiche pas et ne les supprime pas non plus, car `-print` et `-delete` ne sont appliqués qu'à la seconde partie de l'expression après le `-o`.
- Seuls les fichiers commençant et se terminant par `#` seront imprimés et supprimés.

### Avec Parenthèses
Quand vous ajoutez des parenthèses :
```bash
find . \( -name '*~' -o -name '#*#' \) -print -delete
```
Les parenthèses forcent `find` à évaluer `-name '*~' -o -name '#*#'` comme une seule expression groupée avant d'appliquer les actions `-print` et `-delete`. Cela garantit que :
- Tous les fichiers qui se terminent par `~` ou qui commencent et se terminent par `#` sont à la fois affichés et supprimés, car `-print` et `-delete` s'appliquent à tous les fichiers correspondant à l'une ou l'autre des conditions à l'intérieur des parenthèses.

---
## Les antislashs `\`

Dans les commandes shell sur les systèmes Unix-like, les caractères comme les parenthèses `(` et `)` sont interprétés par le shell comme des opérateurs de contrôle utilisés pour grouper des commandes. Cependant, lorsque vous utilisez la commande `find` et que vous voulez que les parenthèses soient interprétées littéralement par `find` lui-même et non par le shell, vous devez les échapper avec des antislashs `\`.

Voici pourquoi les antislashs `\` sont nécessaires dans ce contexte :

### Préservation de la signification spéciale pour `find`
- Les antislashs `\` devant les parenthèses, comme dans `\(` et `\)`, indiquent au shell de passer les parenthèses à la commande `find` sans interprétation. Cela permet à `find` de les utiliser pour grouper les expressions de manière logique, comme discuté précédemment.

### Exemple pratique
Si vous ne mettez pas d'antislashs, le shell pourrait essayer d'interpréter les parenthèses pour lui-même, ce qui entraînerait des erreurs ou des comportements non souhaités. Par exemple, considérons cette commande sans échappement :
```bash
find . ( -name '*~' -o -name '#*#' ) -print
```
Cela générerait une erreur de syntaxe dans le shell parce que le shell essaie de traiter `( -name '*~' -o -name '#*#' )` comme une instruction groupée et isolée, ce qui n'est pas ce que vous voulez.

### Utilisation correcte avec antislash
En ajoutant des antislashs :
```bash
find . \( -name '*~' -o -name '#*#' \) -print
```
Vous dites explicitement au shell de ne pas traiter les parenthèses, permettant ainsi à `find` de les utiliser pour grouper correctement les conditions.

En somme, l’utilisation des antislashs `\` devant des caractères spéciaux comme les parenthèses assure que ces caractères sont passés littéralement aux commandes comme `find`, permettant ainsi l'usage correct de leurs fonctionnalités avancées.

---
## Pourquoi des guillemets simples ?

Dans le contexte des commandes Unix et Linux, l'utilisation des guillemets simples (`'`) et des guillemets doubles (`"`) affecte la manière dont le shell interprète les caractères spéciaux à l'intérieur des chaînes de caractères. Choisir l'un ou l'autre type de guillemet dépend de l'effet désiré sur l'interprétation des expressions et variables au sein de la commande.

### Guillemets simples `'`
- **Préservation littérale** : Tout caractère placé entre guillemets simples est préservé littéralement, sans aucune interprétation ou expansion par le shell. Cela signifie que les variables, les caractères d'échappement, et les caractères spéciaux ne sont pas traités ou expansés.
- **Usage courant** : Utiliser des guillemets simples est très pratique quand votre chaîne de caractères contient des éléments qui pourraient être interprétés par le shell, comme des caractères spéciaux (`$`, `*`, `&`, etc.) ou des espaces. Cela évite que le shell ne traite ces éléments autrement que comme de simples textes.

### Guillemets doubles `"`
- **Interprétation et expansion** : Les guillemets doubles permettent l'expansion des variables (par exemple, `$HOME` ou `$PATH`) et l'interprétation de certains caractères spéciaux (comme le caractère de nouvelle ligne `\n`, ou le caractère de tabulation `\t`). Cependant, certains caractères, comme le dollar (`$`), les guillemets simples eux-mêmes, et le backslash (`\`), conservent une signification spéciale et peuvent influencer le comportement de la chaîne.
- **Usage courant** : On utilise les guillemets doubles quand on souhaite incorporer des variables ou des expressions dont les valeurs doivent être évaluées et incorporées dans la chaîne de caractères.

### Pourquoi choisir `'` dans les commandes `find`
Dans les commandes comme `find`, où vous spécifiez des motifs de nom de fichier ou des expressions qui ne doivent pas être altérées ou expansées par le shell, il est souvent préférable d'utiliser des guillemets simples. Cela garantit que les motifs sont passés exactement tels quels à la commande `find`, sans risque d'interférence ou de modification par le shell.

Par exemple, pour la commande :
```bash
find . -name '*.txt'
```
- Si vous utilisez des guillemets simples autour de `*.txt`, le shell passe le motif `*.txt` directement à `find`, qui l'utilisera pour faire correspondre les noms de fichiers.
- Si vous utilisez des guillemets doubles, tout fichier correspondant à des expansions déjà effectuées dans le répertoire courant serait transmis à `find`, ce qui pourrait ne pas correspondre à l'intention initiale si des fichiers `.txt` existent déjà dans votre répertoire courant.

En conclusion, l'utilisation de guillemets simples ou doubles doit être choisie en fonction du besoin de littéralité ou d'expansion dans le contexte de la commande exécutée. Pour des commandes comme `find`, où la précision des motifs est cruciale, les guillemets simples sont souvent préférés.