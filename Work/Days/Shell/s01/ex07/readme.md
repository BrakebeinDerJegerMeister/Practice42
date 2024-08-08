# Énoncé

| Exercice : 07                   |
| ------------------------------- |
| r_dwssap.sh                     |
| Dossier de rendu : ex07/        |
| Fichiers à rendre : r_dwssap.sh |
| Fonctions Autorisées : Aucune   |
• Écrire une ligne de commande qui affiche la sortie d’un cat /etc/passwd, en
retirant les commentaires, une ligne sur deux en partant de la seconde en inversant
chaque login et en triant par ordre alphabétique inversé, en ne conservant que les
logins compris entre FT_LINE1 et FT_LINE2 inclus, séparés par des ", " (sans
les guillemets), et terminés par un ".".
• Exemple : Entre les lignes 7 et 15, le résultat sera quelque chose du genre :
```console
$> ./r_dwssap.sh
sstq_, sorebrek_brk_, soibten_, sergtsop_, scodved_, rlaxcm_, rgmecived_, revreswodniw_, revressta_.$>
```

# Correction

```sh
cat /etc/passwd | cut -d ':' -f 1 | sed -n 'n;p' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd ',' - | sed 's/,/, /g' | tr '\n' '.'
```

# Démonstration

Définir des variables avant de tester bien sur :

```console
Repo Git : Practice42/Work/Shell/s01/ex07  (main) $ export FT_LINE1=5
Repo Git : Practice42/Work/Shell/s01/ex07  (main) $ export FT_LINE2=9
Repo Git : Practice42/Work/Shell/s01/ex07  (main) $ ./r_dwssap.sh
tiktr, sys, swen, subegassem, spoonrek.Repo Git : Practice42/Work/Shell/s01/ex07  (main) $
```

ligne 5 à 9 incluse donc 5 logins

# Explications

Détails entre chaque pipe :

1. **`cat /etc/passwd`** : Cette commande lit le contenu du fichier `/etc/passwd`. Ce fichier contient des informations sur chaque compte utilisateur sur le système, généralement organisé en plusieurs champs séparés par des deux-points (`:`).

2. **`cut -d ':' -f 1`** : Utilise `cut` pour extraire uniquement le premier champ de chaque ligne, c’est-à-dire le nom d’utilisateur (login). Le délimiteur spécifié ici est `:`.

3. **`sed -n 'n;p'`** : Ce filtre `sed` permet d’imprimer une ligne sur deux, en commençant par la seconde ligne. `n` saute une ligne et `p` imprime la suivante, ce qui permet de sauter les lignes impaires et d’imprimer les paires.

4. **`rev`** : Inverse les chaînes de caractères de chaque ligne. Cela signifie que les logins sont retournés caractère par caractère.

5. **`sort -r`** : Trie les lignes (les noms d'utilisateur inversés) par ordre alphabétique inversé, du plus grand au plus petit.

6. **`sed -n "${FT_LINE1},${FT_LINE2}p"`** : Sélectionne un sous-ensemble des lignes selon les valeurs de `FT_LINE1` et `FT_LINE2`, qui doivent être définies en amont ou directement dans l'appel de commande. Cette commande `sed` imprime seulement les lignes entre ces deux indices inclus.

7. **`paste -sd ',' -`** : Concatène toutes les lignes en une seule ligne, en utilisant `,` comme séparateur. Cela transforme la sortie multiligne en une seule ligne continue.

8. **`sed 's/,/, /g'`** : Modifie la sortie de `paste` en ajoutant un espace après chaque virgule pour faire en sorte que les éléments soient séparés par `, ` plutôt que simplement par `,`.

9. **`tr '\n' '.'`** : Remplace le saut de ligne final par un point. Cela est utile pour s'assurer que la sortie finale est sur une seule ligne et terminée par un point, conformément aux exigences de formatage.
