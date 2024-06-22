# Notes personnelles

Here are my practice doc files in order to be ready for the piscine 42 experience on September 2024 the 16th.
I don't know if the docs are outdated. I just found them somewhere in gitHub.
Open for every one who may need, however i'll do most of my comments in french.

Je tiens à préciser que j'utilise Ubuntu 24.04 avec Gnome sur gdm3


# Avertissement

Dans les dossier des exercices Days C et Shell j'ai laissé des fichiers md et tout ce qui est nécéssaire à la réalisation de l'exercice, il ne faut pas faire cela en contion réelle quand vous rendez votre travail, `il faut envoyer uniquement ce qui est demandé.`

# Installation de Norminette

```bash
sudo apt update
sudo apt install python3-setuptools
sudo apt install pipx
pipx install norminette
pipx ensurepath
```

1. `sudo apt update` : Cette commande met à jour la liste des paquets disponibles et leurs versions, mais elle ne les installe ni ne les met à jour. Cela garantit que vous obtenez les dernières informations sur les paquets disponibles avant d'installer ou de mettre à jour des paquets.

2. `sudo apt install python3-setuptools` : Cette commande installe `setuptools`, un package qui simplifie le processus de construction et d'installation des modules Python. Il est nécessaire pour la plupart des installations Python, surtout lors de l'utilisation de paquets qui doivent être compilés.

3. `sudo apt install pipx` : `pipx` est un outil qui permet d'installer et de gérer des applications Python dans des environnements virtuels isolés. Cette commande installe `pipx` sur votre système.

4. `pipx install norminette` : `norminette` est un linter pour les projets en C, utilisé principalement dans le contexte de l'éducation pour s'assurer que les normes de codage sont respectées. Cette commande installe `norminette` dans un environnement virtuel isolé via `pipx`.

5. `pipx ensurepath` : Cette commande assure que le chemin vers les binaires installés par `pipx` est ajouté à votre variable d'environnement `PATH`. Cela permet de lancer les applications installées avec `pipx` depuis n'importe quel endroit dans votre terminal.


# Utilisation de Norminette
```bash
norminette monfichiersource.c
```
