# Énoncé

| Exercise 07               |
| ------------------------- |
|                           |
| Turn-in directory : ex07/ |
| Files to turn in : b      |
| Allowed functions : None  |
• Créer le fichier b tel que :
```console
%>cat -e a
STARWARS$
Episode IV, A NEW HOPE It is a period of civil war.$
$
Rebel spaceships, striking from a hidden base, have won their first victory against the evil
Galactic Empire.$
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the
DEATH STAR,$
an armored space station with enough power to destroy an entire planet.$
$
Pursued by the Empire's sinister agents, Princess Leia races home aboard her starship, custodian of
the stolen plans that can save her people and restore freedom to the galaxy...$
$
%>diff a b > sw.diff
```

# Correction

Je n'ai pas très bien compris en quoi l'exercice consiste donc en regardant à droite et à gauche j'ai l'impression que le but est de créer un patch....

Pour la prise en main et comprendre ce que je fais je créé un fichier `a` qui contient donc le texte original.

Copier a dans b puis éditer le fichier avec vim en changeant des mots
```sh
cp a b
vim b
```
Effectuer les changements
Puis créer un fichier de différences
```sh
diff a b > sw.diff
```

Observer le fichier
```console
Repo Git : Practice42/Work/Shell/s00/ex07  (main) $ cat -e sw.diff 
6c6$
< During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the$
---$
> During the battle, Rebel spies managed to steal public plans to the Empire's ultimate weapon, the$
8c8$
< an armored space station with enough power to destroy an entire planet.$$
---$
> an armored space station with enough power to destroy an entire city.$$
10,11c10,11$
< Pursued by the Empire's sinister agents, Princess Leia races home aboard her starship, custodian of$
< the stolen plans that can save her people and restore freedom to the galaxy...$
---$
> Pursued by the Empire's sinister agents, agent Leia races home aboard her starship, custodian of$
> the stolen plans that can burn her people and restore servitude to the galaxy...$

```

# Explications

Pour utiliser la commande `patch` afin de modifier du texte dans un fichier en changeant spécifiquement des mots, vous devez d'abord créer un fichier de différences (souvent appelé "patch") qui décrit comment les fichiers doivent être modifiés. Voici les étapes détaillées pour effectuer cette opération :

### 1. Créer un fichier original et un fichier modifié
D'abord, vous devez avoir deux versions du fichier : l'originale (`fichier_a`) et une version modifiée où les mots ont été changés (`fichier_b`).

### 2. Générer le fichier de patch
Ensuite, vous devez créer un fichier de différences qui décrit les changements entre les deux versions. Cela se fait généralement avec la commande `diff`. Exécutez la commande suivante dans un terminal :

```bash
diff -u fichier_a fichier_b > mon_patch.patch
```

- `diff` : la commande utilisée pour trouver les différences entre les fichiers.
- `-u` : une option qui spécifie que le format du patch doit être unifié, ce qui est utile pour la lisibilité et est communément utilisé avec `patch`.
- `fichier_a` : le fichier original.
- `fichier_b` : le fichier modifié.
- `mon_patch.patch` : le fichier qui sera créé et qui contient les différences.

### 3. Appliquer le patch
Pour appliquer le patch au fichier original et effectuer les modifications, utilisez la commande `patch` :

```bash
patch fichier_a mon_patch.patch
```

- `patch` : la commande pour appliquer les modifications.
- `fichier_a` : le fichier original qui sera modifié.
- `mon_patch.patch` : le fichier de patch contenant les changements.

Après l'exécution de cette commande, `fichier_a` sera modifié selon les différences décrites dans `mon_patch.patch`.

### 4. Vérification
Vous pouvez vérifier que les modifications ont été appliquées correctement en affichant ou en comparant le contenu du fichier `fichier_a` avec le contenu attendu.

Cette méthode est très utilisée pour appliquer des modifications ou des correctifs dans des fichiers, particulièrement dans le contexte du développement logiciel où des modifications doivent être distribuées et appliquées de manière contrôlée.