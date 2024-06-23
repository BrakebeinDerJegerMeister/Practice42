# Énoncé


| Exercice : 01                       |
| ----------------------------------- |
| print_groups.sh                     |
| Dossier de rendu : ex01/            |
| Fichiers à rendre : print_groups.sh |
| Fonctions Autorisées : Aucune       |
• Écrire une ligne de commande qui détermine et affiche la liste des groupes dans
lesquels est membre le login spécifié dans la variable d’environnement FT_USER,
séparés par des virgules sans espaces.
• Exemples :
◦ avec FT_USER=nours, le résultat est "god,root,admin,master,nours,bocal"
(sans les guillemets)
```console
$>./print_groups.sh
god,root,admin,master,nours,bocal$>
```
◦ avec FT_USER=daemon, le résultat est "daemon,bin" (sans les guillemets)
```console
$>./print_groups.sh
daemon,bin$>
```

# Correction

```vim
id -nG $FT_USER | tr ' ' ',' | tr -d '\n'
```

Ne pas oublier :
```sh
chmod +x print_groups.sh
```
# Démonstration

```console
Repo Git : Practice42/Work/Shell/s01/ex00  (main) $ ./print_groups.sh 
kaos,adm,cdrom,sudo,dip,plugdev,users,lpadmin,sambashare,vboxusers,wiresharkRepo Git : Practice42/Work/Shell/s01/ex00  (main) $ 
```

# Explications

La commande  <code>id -nG $FT_USER | tr ' ' ',' | tr -d '\n'</code>, est utilisée pour récupérer et formater une liste de groupes auxquels un utilisateur appartient. Voici une explication détaillée de chaque partie de cette commande :

1. **`id -nG $FT_USER`** :
   - `id` : C'est une commande Unix/Linux qui est utilisée pour obtenir les identifiants utilisateur et groupe.
   - `-nG` : Cette option spécifie à `id` de retourner les noms (`-n`) de tous les groupes (`-G`) auxquels l'utilisateur appartient. Si `$FT_USER` est défini, il sera utilisé comme l'utilisateur cible; sinon, elle retourne les groupes de l'utilisateur courant.
   - `$FT_USER` : Il s'agit d'une variable d'environnement qui contient le nom de l'utilisateur pour lequel vous souhaitez obtenir la liste des groupes.

2. <code>tr ' ' ','</code> :
   - `tr` : C'est une commande (translate or delete : voir `man tr`) qui est utilisée pour remplacer ou supprimer des caractères.
   - `' ' ','` : Ces paramètres demandent à `tr` de remplacer chaque espace (' ') par une virgule (','). Les espaces séparent les noms de groupes dans la sortie de la commande `id`, donc cette opération transforme cette sortie en une liste de noms séparés par des virgules, ce qui est utile pour des formats où les noms de groupe doivent être listés en une seule ligne sans espaces.

3. <code>tr -d '\n'</code> :
   - `-d` : Cette option (delete) de `tr` sert à supprimer des caractères plutôt que les remplacer.
   - <code>'\n'</code> : Spécifie le caractère de nouvelle ligne (saut de ligne). Le but ici est de supprimer le saut de ligne que la commande `id` ajoute automatiquement à la fin de sa sortie. Cela garantit que la liste finale des groupes ne terminera pas par une nouvelle ligne, ce qui peut être nécessaire si cette sortie doit être utilisée comme partie d'une commande ou intégrée dans un fichier sans saut de ligne à la fin.

En résumé, cette chaîne de commandes génère une liste des noms de groupes auxquels l'utilisateur défini par `FT_USER` appartient, formate cette liste avec des virgules sans espaces ni ligne finale, prête à être utilisée ou affichée selon les besoins.