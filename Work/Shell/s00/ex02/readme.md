# Énoncé

| Exercise 02                 |
| --------------------------- |
| Owi, encore...              |
| Turn-in directory : ex02/   |
| Files to turn in : exo2.tar |
| Allowed functions : None    |
• Créer tous ces fichiers et répertoires. Faire le nécessaire pour que l’affichage d’un
ls -l dans votre répertoire ressemble à cela :
```console
%> ls -l
total XX
drwx--xr-x 2 XX XX XX Jun 1 20:47 test0
-rwx--xr-- 1 XX XX 4 Jun 1 21:46 test1
dr-x---r-- 2 XX XX XX Jun 1 22:45 test2
-r-----r-- 2 XX XX 1 Jun 1 23:44 test3
-rw-r----x 1 XX XX 2 Jun 1 23:43 test4
-r-----r-- 2 XX XX 1 Jun 1 23:44 test5
lrwxr-xr-x 1 XX XX 5 Jun 1 22:20 test6 -> test0
%>
```
Pour les heures, il sera toléré que ce soit l’année qui s’affiche si la date de l’exercice
(1 juin) est dépassée de six mois ou plus.
• Une fois l’exercice résolu, vous exécuterez la commande tar -cf exo2.tar * pour
créer le fichier à rendre.

# Correction

> [!ATTENTION] Remarque
> Je ne parviens pas à afficher 
> 
> lrwxrwxrwx 1 kaos kaos    5 juin   1 22:20 test6 -> test0
> 
> comme il a été demandé dans l'exercice
> je ne peux le faire qu'au moyen de la commande ls -lL


```shell
mkdir test0
chmod 715 test0/
touch -t 202406012047 test0

truncate -s 4 test1
chmod 714 test1
touch -t 202406012146 test1

mkdir test2
chmod 504 test2
touch -t 202406012245 test2

truncate -s 1 test3
chmod 404 test3
touch -t 202406012344 test3

truncate -s 2 test4
chmod 641 test4
touch -t 202406012343 test4

ln test3 test5
chmod 404 test5
touch -t 202406012344 test5

ln -s test0 test6
chmod -h 755 test6
touch -h -t 202406012220 test6
```

# Explications

## Résultats de `ls -l`

```terminal
drwxr-xr-x 2 kaos kaos 4096 juin  21 21:10 test0  
-rwx--xr-- 1 kaos kaos    4 juin  21 21:10 test1  
dr-x---r-- 2 kaos kaos 4096 juin  21 21:10 test2  
-r-----r-- 2 kaos kaos    1 juin  21 21:10 test3  
-rw-r----x 1 kaos kaos    2 juin  21 21:10 test4  
-r-----r-- 2 kaos kaos    1 juin  21 21:10 test5  
lrwxrwxrwx 1 kaos kaos    5 juin  21 21:10 test6 -> test0  
tar -cf exo2.tar *  
```


```
1 ère colonne :
-rw-r----x : Ceci est la représentation des permissions du fichier appelé par exemple `test4`. Chaque caractère a une signification précise :
- Le premier caractère `-` indique qu'il s'agit d'un fichier régulier. D'autres symboles pourraient être `d` pour un répertoire, `l` pour un lien symbolique, etc.
lrw-r----x: Lien symbolique (l comme link)
dr-x---r-- : Dossier (d comme directory)
--r-----r- : Fichier (rien comme fichier)
- Les trois caractères suivants : permissions du propriétaire.
- Les trois caractères suivants : permissions du groupe.
- Les trois derniers caractères : permissions des autres utilisateurs (tout le monde en dehors du propriétaire et du groupe)

2ème colonne :
2 : Ceci indique le nombre de liens physiques vers ce fichier. Pour un fichier ordinaire, ce nombre est typiquement `1`. S'il s'agit d'un répertoire, ce nombre indiquerait le nombre de sous-répertoires qu'il contient (sans compter `.` et `..`).

3ème et 4ème colonnes :
kaos kaos : Le premier `kaos` représente l'utilisateur propriétaire du fichier. Le second `kaos` représente le groupe auquel appartient le fichier. Cela signifie que l'utilisateur `kaos` et les membres du groupe `kaos` sont les principaux concernés par les permissions définies.

5ème colonne :
2 : Ceci indique la taille du fichier en octets. par exemple `test4` a donc une taille de 2 octets.

```



## commande `ln test3 test5`

Permet de passer de 1 à 2 le nombre de liens physiques pour `test3` et `test5`.

## touch

Dans la commande `touch`, les options `-mt` et `-t` servent toutes deux à modifier les horodatages des fichiers, mais elles acceptent des formats de date et d'heure différents et ont des utilisations légèrement variées.

### Option `-t`
L'option `-t` est standard et utilisée pour définir explicitement l'horodatage d'accès et de modification d'un fichier à une valeur spécifique. Elle accepte une valeur de date et d'heure sous la forme `[[CC]YY]MMDDhhmm[.ss]`, où chaque partie représente :

- **CC** : Les deux premiers chiffres de l'année (le siècle, facultatif).
- **YY** : Les deux derniers chiffres de l'année (facultatif si le siècle est spécifié).
- **MM** : Le mois (01 à 12).
- **DD** : Le jour du mois (01 à 31).
- **hh** : L'heure (00 à 23).
- **mm** : Les minutes (00 à 59).
- **.ss** : Les secondes (00 à 59, facultatif).

Exemple :
```bash
touch -t 202106012220.30 testfile
```
Cette commande définit l'horodatage de modification du fichier `testfile` au 1er juin 2021 à 22h20 et 30 secondes.

### Utilisation
L'option `-t` est largement prise en charge et devrait être utilisée pour la configuration précise des horodatages de fichiers dans les scripts et les processus automatisés sur n'importe quelle plate-forme Unix/Linux standard. Si `-mt` est disponible dans votre environnement, assurez-vous de consulter la documentation spécifique de votre système pour comprendre son usage et sa syntaxe exacts, car elle pourrait différer des conventions standards.

### Option `-h`

Normalement, `touch -h -t` sur un lien symbolique ne fonctionne pas sur toutes les distributions Linux car les liens symboliques ne conservent pas d'horodatages indépendants.