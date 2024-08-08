# Énoncé

| Exercise 04               |
| ------------------------- |
| midLS                     |
| Turn-in directory : ex04/ |
| Files to turn in : midLS  |
| Allowed functions : None  |
• Placez dans un fichier midLS la ligne de commande à taper pour lister les fichiers et
les répertoires du répertoire courant, mais pas les fichiers cachés, ni "." ni ".." (rien
ne commençant par un point), séparés par des virgules, triés par date de création
et de manière à ce que les répertoires soient suivis d’un caractère slash.

# Correction

```shell
ls -p -m --sort=time --time=creation
```

# Explications

- **`-p`** ajoute un slash (`/`) à la fin des noms des répertoires pour les distinguer facilement.
- **`-m`** liste les fichiers séparés par des virgules.
- **`--sort=time`** spécifie que le tri doit être effectué en fonction du timestamp.
- **`--time=creation`** indique que le timestamp à utiliser pour le tri est le temps de création (si disponible sur votre système).


En se basant sur le FM quand on RTFM  :

```shell
man ls
```

```console

-m     fill width with a comma separated list of entries


-p, --indicator-style=slash
	  append / indicator to directories


--sort=WORD
	  sort by WORD instead of name: none (-U), size (-S), time (-t), version (-v), extension (-X), width

			  
--time=WORD
	  select  which  timestamp used to display or sort; access time (-u): atime, access, use; metadata change
	  time (-c): ctime, status; modified time (default): mtime, modification; birth time: birth, creation;

	  with -l, WORD determines which time to show; with --sort=time, sort by WORD (newest first)
	  
```
