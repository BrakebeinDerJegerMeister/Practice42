# Énoncé

| Exercice : 11                                 |
| --------------------------------------------- |
| ft_putstr_with_non_printable                  |
| Dossier de rendu : ex11/                      |
| Fichiers à rendre : ft_putstr_non_printable.c |
| Fonctions Autorisées : write                  |
• Écrire une fonction qui affiche une chaîne de caractères à l’écran. Si cette chaîne
contient des caractères non-imprimables, ils devront être affichés sous forme hexa-
décimale (en minuscules) en les précédant d’un "backslash".
• Par exemple, avec ce paramètre :
```
Coucou\ntu vas bien ?
```
• La fonction devra afficher :
```
Coucou\0atu vas bien ?
```
• Elle devra être prototypée de la façon suivante :
void
```C
ft_putstr_non_printable(char *str);
```
# Correction

```C
#include <unistd.h>

void	print_char_to_hex(char c)
{
	char	c1;
	char	c2;

	c1 = 48 + (c >> 4);
	c2 = 48 + (c & 0xF);
	if (c2 > '9')
		c2 = c2 + 39;
	write(1, "\\", 1);
	write(1, &c1, 1);
	write(1, &c2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c > 31 && c < 127)
		{
			write(1, &c, 1);
		}
		else
		{
			print_char_to_hex(c);
		}
		i++;
	}
}
```

# Démonstration

```C
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	test(char *str)
{
	ft_putstr(str);
	write(1, "\n", 1);
	ft_putstr_non_printable(str);
	write(1, "\n", 1);
}

int	main(void)
{
	char	str1[] = "Coucou\ntu vas bien ?";
	char	str2[] = "Un \x13 \x07 essai \x16 \x25 \x48\x65\x6c\x6c\x6f";

	test(str1);
	test(str2);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex11  (main) $ norminette -RCheckForbiddenSourceHeader ft_putstr_non_printable.c 
ft_putstr_non_printable.c: Error!
Error: DECL_ASSIGN_LINE     (line:  69, col:  20):	Declaration and assignation on a single line
Error: DECL_ASSIGN_LINE     (line:  70, col:  20):	Declaration and assignation on a single line
Repo Git : Practice42/Work/C/c02/ex11  (main) $ gcc -Wall -Wextra -Werror ft_putstr_non_printable.c 
Repo Git : Practice42/Work/C/c02/ex11  (main) $ ./a.out 
Coucou
tu vas bien ?
Coucou\0atu vas bien ?
Un   essai  % Hello
Un \13 \07 essai \16 % Hello
Repo Git : Practice42/Work/C/c02/ex11  (main) $ 
```
# Explications

### 1. **Traitement des caractères non imprimables**
La fonction principale, `ft_putstr_non_printable`, est conçue pour gérer spécialement les caractères qui ne sont pas directement imprimables sur un terminal ou un écran. En ASCII, les caractères considérés comme imprimables se situent entre 32 (espace) et 126 (tilde `~`). Les caractères hors de cette plage pourraient interférer avec la lecture correcte d'une chaîne si affichés directement. La fonction remplace donc ces caractères non imprimables par une représentation hexadécimale. Cela assure que toute la chaîne peut être affichée d'une manière lisible et uniforme, quel que soit son contenu.

### 2. **Conversion des caractères en hexadécimal avec `print_char_to_hex`**
Cette fonction prend un caractère individuel et le transforme en deux chiffres hexadécimaux, chacun représentant la moitié des bits du caractère. Voici comment cela fonctionne :
   - **Extraction du chiffre supérieur :** Le caractère est décalé de quatre bits vers la droite (`c >> 4`). Cela déplace les quatre bits de poids fort à la position des bits de poids faible, permettant leur utilisation comme un nombre hexadécimal.
   - **Extraction du chiffre inférieur :** L'opération `AND` avec `0xF` (soit `15` en décimal) isole les quatre bits de poids faible du caractère. 
   - **Conversion en caractère ASCII :** Les résultats de ces opérations sont initialement sous forme numérique entre 0 et 15. Pour les rendre lisible en tant que caractères, ils sont convertis en caractères ASCII. Si le chiffre est supérieur à 9, il faut le convertir en lettre ('a' à 'f') ; c'est ce que fait l'ajout de 39 (`+39`) pour obtenir les lettres correspondantes en ASCII. (Voir votre table ASCII !!!)
