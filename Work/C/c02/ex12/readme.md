# Énoncé

| Exercice : 12                         |
| ------------------------------------- |
| ft_print_memory                       |
| Dossier de rendu : ex12/              |
| Fichiers à rendre : ft_print_memory.c |
| Fonctions Autorisées : write          |
• Écrire une fonction qui affiche une zone mémoire à l’écran.
• L’affichage de la zone mémoire est séparée en trois "colonnes" séparées par un
espace :
◦ L’adresse en hexadécimal du premier caractère de la ligne suivi d’un ’ :’.
◦ Le contenu en hexadécimal avec un espace tous les deux caractères et doit etre
complété avec des espaces si nécessaire (voir l’exemple en dessous).
◦ Le contenu en caractères imprimables.
• Si un caractère est non-imprimable il sera remplacé par un point.
• Chaque ligne doit gérer seize caractères.
• Si size est égale à 0, rien ne sera affiché.
• Exemple :
```
$> ./ft_print_memory
000000010a161f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
000000010a161f50: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo
000000010a161f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on 
000000010a161f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.
000000010a161f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
000000010a161f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .
$> ./ft_print_memory | cat -te
0000000107ff9f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin$
0000000107ff9f50: 6368 6573 090a 0963 2020 6573 7420 666f ches...c est  fo$
0000000107ff9f60: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on $
0000000107ff9f70: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.$
0000000107ff9f80: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..$
0000000107ff9f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .$
$>
```
• Elle devra être prototypée de la façon suivante :
```
void *ft_print_memory(void *addr, unsigned int size);
```
• Elle devra renvoyer addr.
# Correction

```C

```
# Algorithme

# Démonstration

```C

```

```

```
# Explications
