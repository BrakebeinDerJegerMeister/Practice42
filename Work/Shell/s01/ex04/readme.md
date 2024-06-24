# Énoncé

| Exercice : 04                 |
| ----------------------------- |
| MAC.sh                        |
| Dossier de rendu : ex04/      |
| Fichiers à rendre : MAC.sh    |
| Fonctions Autorisées : Aucune |
• Écrire une ligne de commande qui affiche les adresses MAC de votre machine.
Chaque adresse sera suivi d’un retour à la ligne.
# Correction

```sh
ifconfig | grep 'ether' | tr -s ' ' | cut -d ' ' -f 3
```

# Démonstration

```console
Repo Git : Practice42/Work/Shell/s01/ex04  (main *) $ ./MAC.sh | cat -e
e8:9c:25:dd:72:ca$
c8:5e:a9:a3:8e:e1$
Repo Git : Practice42/Work/Shell/s01/ex04  (main *) $ 
```

# Explications

### Solution utilisant `tr` avec `cut`

Une façon d'aborder ce problème consiste à normaliser l'espacement avant d'utiliser `cut`. Vous pouvez utiliser `tr` pour remplacer tous les espaces séquentiels par un seul espace, ce qui permettra à `cut` de travailler de manière plus fiable :

```sh
ifconfig | grep 'ether' | tr -s ' ' | cut -d ' ' -f 3
```

Explication de la commande :
- `ifconfig` : affiche toutes les informations des interfaces réseau.
- `grep 'ether'` : filtre la sortie pour inclure uniquement les lignes contenant "ether".
- `tr -s ' '` : compresse les séquences d'espaces en un seul espace, rendant la séparation de champs plus cohérente.
- `cut -d ' ' -f 3` : divise la ligne en utilisant l'espace comme délimiteur et sélectionne le troisième champ, car après la normalisation des espaces, l'adresse MAC devrait se trouver en troisième position.