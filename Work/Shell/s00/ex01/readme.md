# Correction

Dans la console :
```sh
cd Practice42/Work/Shell/s00/ex01
truncate -s 40 testShell00
chmod 455 testShell00
tar -cf testShell00.tar testShell00
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


r: Read, w : Write, x : eXecute  
  
-rwxrwxrwx : -(prorpiétaire : rwx )(groupe : rwx )(autres : rwx)  
-421421421 : -(prorpiétaire : 421 )(groupe : 421 )(autres : 421)  
  
donc  
  
-r--r-xr-x : -(prorpiétaire : r-- )(groupe : r-x )(autres : r-x)  
-4--4-14-1 : -(prorpiétaire : 400 )(groupe : 401 )(autres : 401)  
donc (4+0+0 = 4)(4+0+1 = 5)(4+0+1 = 5) donc 455  



