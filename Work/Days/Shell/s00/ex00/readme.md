# Énoncé

| Exercise 00                    |
| ------------------------------ |
| Les vrais savent afficher un Z |
| Turn-in directory : ex00/      |
| Files to turn in : z           |
| Allowed functions : None       |
• Créez un fichier z qui, lorsque l’on fait un cat dessus, affiche "Z" suivi d’un retour
à la ligne.
```console
?>cat z
Z
?>
```

# Correction

Dans la console :
```sh
cd Practice42/Work/Shell/s00/ex00
echo "Z" > z
```

# Explications


echo "Z" génère une sortie  
`>>` écrit à la fin du fichier indiqué (et le créé s'il n'existe pas)  
`>` remplace le contenu du fichier

Rappel : 

```sh
echo "texte" >> fichier 
echo "autre texte" > fichier2  
```


