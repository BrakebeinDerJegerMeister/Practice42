# Énoncé

| Exercice : 05                                                       |
| ------------------------------------------------------------------- |
| do-op                                                               |
| Dossier de rendu : ex05/                                            |
| Fichiers à rendre : Tous les fichiers nécessaires a votre programme |
| Fonctions Autorisées : write                                        |
• Écrire un programme qui s’appelle do-op.
• Le programme devra être lancé avec trois arguments : do-op valeur1 operateur
valeur2
• Exemple :
```
$>./do-op 42 "+" 21
63
$>
```
• Vous devriez utilisé un tableau de pointeur sur fonction afin d’appeler la fonction correspondant à un operateur.
• En cas d’opérateur inconnu votre programme doit afficher 0.
• Si le nombre d’arguments n’est pas correct, do-op n’affiche rien.
• Votre programme doit accepter et afficher le résultat avec les opérateurs suivant :
```
’+’ ’-’ ’/’ ’*’ et ’%’
```
• En cas de division par 0 votre programme doit afficher :
```
Stop : division by zero
```
• En cas de modulo par 0 votre programme doit afficher :
```
Stop : modulo by zero
```
• Voici un exemple de tests de la Moulinette :
```
$> make clean
$> make
$> ./do-op
$> ./do-op 1 + 1
2
$> ./do-op 42amis - --+-20toto12
62
$> ./do-op 1 p 1
0
$> ./do-op 1 + toto3
1
$>
$> ./do-op toto3 + 4
4
$> ./do-op foo plus bar
0
$> ./do-op 25 / 0
Stop : division by zero
$> ./do-op 25 % 0
Stop : modulo by zero
$>
```
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
