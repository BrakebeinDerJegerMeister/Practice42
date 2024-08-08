# Énoncé

| Exercice : 08                     |
| --------------------------------- |
| add_chelou.sh                     |
| Dossier de rendu : ex08/          |
| Fichiers à rendre : add_chelou.sh |
| Fonctions Autorisées : Aucune     |
• Écrire une ligne de commande qui prend les nombres contenus dans les variables
FT_NBR1 en base 
```
’\"?!
```
et FT_NBR2 en base `mrdoc` et qui affiche la somme des deux
en base `gtaio luSnemf`
◦ Exemple 1 :
```
FT_NBR1=\'?"\"'\
FT_NBR2=rcrdmddd
```
◦ La somme est :
```
Salut
```
◦ Exemple 2 :
```
FT_NBR1=\"\"!\"\"!\"\"!\"\"!\"\"!\"\"
FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo
```
◦ La somme est :
```
Segmentation fault
```

# Correction

On peut en déduire les valeurs symboliques pour commencer :
```
mot1  |  mot2  |  valeur  |  code octal (mot1)
____________________________________________
 '    |   m    |   0      |       \047
 \    |   r    |   1      |       \134
 "    |   d    |   2      |       \042
 ?    |   o    |   3      |       \077
 !    |   c    |   4      |       \041
```

L'idée est d'utiliser le code octal pour esquiver les échappements compliqués et difficiles à gérer, par ailleurs même dans mon fichier md les antislashs posent quelsques problèmes :

```sh
echo "$FT_NBR1 + $FT_NBR2" | tr "mrdoc" "01234" | tr '\047\134\042\077\041' '01234' | xargs echo "ibase=5; obase=23;" | bc | tr "0123456789ABC" "gtaio luSnemf"
```



# Démonstration

exemple 1
```
export FT_NBR1=$(printf '\134\047\077\042\134\042\047\134')
export FT_NBR2="rcrdmddd"
kaos@omega:~$ echo "$FT_NBR1 + $FT_NBR2" | tr "mrdoc" "01234" | tr '\047\134\042\077\041' '01234' | xargs echo "ibase=5; obase=23;" | bc | tr "0123456789ABC" "gtaio luSnemf"
Salut
```

exemple 2
```
export FT_NBR1=$(printf '\134\042\134\042\041\134\042\134\042\041\134\042\134\042\041\134\042\134\042\041\134\042\134\042\041\134\042\134\042')
export FT_NBR2="dcrcmcmooododmrrrmorcmcrmomo"
kaos@omega:~$ echo "$FT_NBR1 + $FT_NBR2" | tr "mrdoc" "01234" | tr '\047\134\042\077\041' '01234' | xargs echo "ibase=5; obase=23;" | bc | tr "0123456789ABC" "gtaio luSnemf"
Segmentation fault
kaos@omega:~$ 
```

# Explications

### Détails des Composants

1. **`echo "$FT_NBR1 + $FT_NBR2"`**
   - **Fonction :** Cette commande concatène les valeurs des variables `FT_NBR1` et `FT_NBR2` avec un signe `+` entre elles. Cela prépare l'expression pour une addition dans la calculatrice `bc`.
   - **Output :** Un string qui ressemble à quelque chose comme `'xyz + abc'`, où `xyz` et `abc` sont les valeurs de `FT_NBR1` et `FT_NBR2`.

2. **`tr "mrdoc" "01234"`**
   - **Fonction :** Transforme les caractères `m`, `r`, `d`, `o`, `c` en `0`, `1`, `2`, `3`, `4` respectivement. Ceci est utilisé pour convertir `FT_NBR2` de sa base spécifique (`mrdoc`) en base numérique.
   - **Output :** Transforme les chaînes de caractères de `FT_NBR2` pour les représenter en chiffres selon la table de mapping fournie.

3. **`tr '\047\134\042\077\041' '01234'`**
   - **Fonction :** Transforme les caractères spéciaux et les guillemets en chiffres basés sur leur code ASCII octal. Ici, le guillemet simple (`'`), le backslash (`\`), le guillemet double (`"`), le point d'interrogation (`?`), et le point d'exclamation (`!`) sont transformés en `0`, `1`, `2`, `3`, `4` respectivement.
   - **Output :** Transforme les chaînes de caractères de `FT_NBR1` pour les représenter en chiffres selon la table de mapping fournie.

4. **`xargs echo "ibase=5; obase=23;"`**
   - **Fonction :** `xargs` prend la sortie de la commande précédente et l'utilise comme argument pour la commande `echo` qui suit. Cette commande `echo` ajoute les paramètres de base pour `bc`, spécifiant que l'entrée est en base 5 et que la sortie doit être en base 23.
   - **Output :** Produit une chaîne qui prépare l'environnement pour `bc`, intégrant l'expression d'addition reçue comme entrée.

5. **`bc`**
   - **Fonction :** Effectue des calculs précis avec des nombres arbitrairement grands. Ici, `bc` calcule l'expression générée, interprétant l'entrée en base 5 et convertissant le résultat en base 23.
   - **Output :** Donne le résultat de l'addition en base 23 sous forme de chiffres.

6. **`tr "0123456789ABC" "gtaio luSnemf"`**
   - **Fonction :** Transforme le résultat numérique de `bc` en une chaîne basée sur un mapping personnalisé, convertissant les chiffres et les lettres de base 23 (`0123456789ABC`) en une suite de caractères spécifiques (`gtaio luSnemf`).
   - **Output :** Fournit la sortie finale en une chaîne personnalisée qui représente le résultat de l'opération dans une "base" spécifique et ludique.

### Utilisation Pratique
Cette commande est idéale pour effectuer des calculs en bases non-standard et pour afficher le résultat dans un format tout aussi non-standard, permettant des manipulations complexes et spécifiques adaptées à des besoins particuliers ou à des fins d'encodage spécifique.