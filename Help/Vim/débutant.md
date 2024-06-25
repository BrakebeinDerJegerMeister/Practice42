### Guide Vim pour Ultra Débutants

Vim est un éditeur de texte puissant utilisé dans les environnements Unix et Linux. Il peut sembler complexe au début, mais quelques commandes de base suffisent pour démarrer. Voici un guide simple pour vous aider à créer et modifier des fichiers textes avec Vim.

#### 1. Ouvrir ou Créer un Fichier

Pour ouvrir un fichier existant ou en créer un nouveau avec Vim, utilisez la commande suivante dans votre terminal :

```bash
vim nom_du_fichier
```

Remplacez `nom_du_fichier` par le nom du fichier que vous souhaitez ouvrir ou créer. Si le fichier n'existe pas, Vim en créera un nouveau.

#### 2. Mode Normal et Mode Insertion

Vim a plusieurs modes, mais les deux principaux que vous utiliserez sont le **mode Normal** et le **mode Insertion**.

- **Mode Normal** : C'est le mode par défaut au démarrage de Vim. Dans ce mode, vous pouvez exécuter des commandes.
- **Mode Insertion** : Dans ce mode, vous pouvez taper et modifier le texte comme dans un éditeur de texte classique.

Pour passer du mode Normal au mode Insertion, tapez `i`. Vous verrez "INSERT" s'afficher en bas de l'écran, ce qui signifie que vous pouvez commencer à taper votre texte.

#### 3. Écrire du Texte

Une fois en mode Insertion, tapez simplement votre texte. Vous pouvez utiliser les touches fléchées pour vous déplacer dans le texte que vous écrivez.

#### 4. Sauvegarder le Fichier

Pour sauvegarder vos modifications, vous devez d'abord revenir au mode Normal. Appuyez sur `Esc` pour quitter le mode Insertion.

Ensuite, tapez `:w` suivi de `Entrée` pour sauvegarder le fichier.

#### 5. Quitter Vim

Pour quitter Vim, vous devez être en mode Normal. Tapez `:q` et appuyez sur `Entrée`. Si vous avez fait des modifications et que vous souhaitez les sauvegarder avant de quitter, tapez `:wq` et appuyez sur `Entrée`.

#### 6. Sauvegarder et Quitter en une étape

Si vous voulez à la fois sauvegarder vos modifications et quitter l'éditeur, tapez `:wq` en mode Normal, puis appuyez sur `Entrée`.

#### Conseil Bonus : Annuler les Modifications

Si vous faites une erreur et souhaitez annuler la dernière modification, tapez `u` en mode Normal. Cela annulera la dernière action effectuée.

### Résumé des Commandes de Base

- `i` : Passer en mode Insertion pour éditer le texte.
- `Esc` : Revenir au mode Normal pour exécuter des commandes.
- `:w` : Sauvegarder le fichier.
- `:q` : Quitter Vim.
- `:wq` ou `ZZ` (en mode Normal) : Sauvegarder et quitter.
- `u` : Annuler la dernière modification en mode Normal.

Ce guide vous donne les outils essentiels pour commencer à utiliser Vim sans vous perdre dans sa complexité. Bonne édition avec Vim!
