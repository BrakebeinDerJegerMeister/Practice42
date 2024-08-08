# Énoncé

| Exercise 01                        |
| ---------------------------------- |
| C’est quoi des attributs ?         |
| Turn-in directory : ex01/          |
| Files to turn in : testShell00.tar |
| Allowed functions : None           |
• Créer le fichier testShell00 dans votre répertoire de rendu.
• Vous devrez faire en sorte que:
```console
%> ls -l
total XX
-r--r-xr-x 1 XX XX 40 Jun 1 23:42 testShell00
%>
```
Pour les heures, il sera toléré que ce soit l’année qui s’affiche si la date de l’exercice
(1 juin) est dépassée de six mois ou plus.
• Une fois l’exercice résolu, vous exécuterez la commande tar -cf testShell00.tar
testShell00 pour créer le fichier à rendre.
# Correction

Dans la console :
```sh
cd Practice42/Work/Shell/s00/ex01
truncate -s 40 testShell00
chmod 455 testShell00
tar -cf testShell00.tar testShell00
```

on aurait pu faire :

```sh
chmod u=r,g=rx,o=rx fichier.txt
```


# Explications

Plusieurs façons de créer un fichier de 40 octets :

```shell
echo -n "01234567890123456789012345678901234567890000" | head -c 40 > testShell00
```

ou

```shell
truncate -s 40 testShell00
```

-s : définir la taille, soit en insérant des caractère s'il en manque soit en supprimant s'il y en a trop

```shell
chmod 455 testShell00
```

Pourquoi 455 ?

r: Read, w : Write, x : eXecute  = 1 paquet de 3 bits
  et globalement : r = 4, w = 2, x = 1, rien = 0
  
```
-rwxrwxrwx : -(prorpiétaire : rwx )(groupe : rwx )(autres : rwx)  
-421421421 : -(prorpiétaire : 421 )(groupe : 421 )(autres : 421)  
```
  
donc  on applique et on fait la somme par partie :
  
```
-r--r-xr-x : -(prorpiétaire : r-- )(groupe : r-x )(autres : r-x)  
-4--4-14-1 : -(prorpiétaire : 400 )(groupe : 401 )(autres : 401)  
on additionne (4+0+0 = 4)(4+0+1 = 5)(4+0+1 = 5)
on obtient finalement 455  
```



