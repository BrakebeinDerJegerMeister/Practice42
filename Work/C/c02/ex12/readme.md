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
#include <unistd.h>

char	nib_to_hexchar(int val)
{
	char	hex;

	if (val > 9)
		hex = val + 'a' - 10;
	else
		hex = val + '0';
	return (hex);
}

void	strprint_char_or_dot(char *str, int len)
{
	int		i;
	char	c;

	i = 0;
	while (i < len)
	{
		c = str[i];
		if (c > 31 && c < 127)
			write(1, &c, 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	print_hexstr(char *str, int len)
{
	int		i;
	char	c1;
	char	c2;

	i = 0;
	while (i < 16)
	{
		if (!(i % 2))
		{
			write(1, " ", 1);
		}
		if (i < len)
		{
			c1 = nib_to_hexchar(str[i] >> 4);
			c2 = nib_to_hexchar(str[i] & 0xF);
			write(1, &c1, 1);
			write(1, &c2, 1);
		}
		else
		{
			write(1, "  ", 2);
		}
		i++;
	}
	write(1, " ", 1);
}

void	print_hexaddr(char *addr)
{
	unsigned long long	l_addr;
	int					sz;
	char				disp;

	sz = 16;
	l_addr = (unsigned long long)addr;
	while (--sz >= 0)
	{
		disp = nib_to_hexchar((l_addr >> (4 * sz)) & 0xF);
		write(1, &disp, 1);
	}
	write(1, ":", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	int				len;
	char			*p_addr;

	p_addr = (char *)addr;
	k = 0;
	while (k < (1 + size / 16))
	{
		i = 0;
		len = 0;
		while (i < 16)
		{
			if ((k * 16 + i) < size)
				len++;
			i++;
		}
		print_hexaddr(p_addr + k * 16);
		print_hexstr(p_addr + k * 16, len);
		strprint_char_or_dot(p_addr + k * 16, len);
		write(1, "\n", 1);
		k++;
	}
	return (addr);
}
```
# Démonstration

```C
void	put_ulonglong_number(unsigned long long nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		put_ulonglong_number(nb);
	}
	write(1, &disp, 1);
}

int	main(void)
{
	int					*addr;
	unsigned long long	l_addr;
	char				str[] = "Bonjour les aminches"
		"\x09\x0a\x09"
		"c  est fou\x09tout\x09"
		"ce qu on peut faire avec\x09\x0a\x09print_memory\x0a\x0a\x0a\x09lol\x2elol\x0a \0";

	addr = ft_print_memory(str, 92);
	l_addr = (unsigned long long)addr;
	write(1, "\n", 1);
	put_ulonglong_number(l_addr);
	write(1, "\n", 1);
	return (0);
}
```

```
Repo Git : Practice42/Work/C/c02/ex12  (main *) $ norminette -RCheckForbiddenSourceHeader ft_print_memory.c
ft_print_memory.c: Error!
Error: TOO_MANY_FUNCS       (line: 116, col:   1):	Too many functions in file
Error: TOO_MANY_FUNCS       (line: 131, col:   1):	Too many functions in file
Error: DECL_ASSIGN_LINE     (line: 135, col:  31):	Declaration and assignation on a single line
Error: LINE_TOO_LONG        (line: 138, col:  92):	line too long
Repo Git : Practice42/Work/C/c02/ex12  (main *) $ gcc -Wall -Wextra -Werror -o ft_print_memory ft_print_memory.c 
Repo Git : Practice42/Work/C/c02/ex12  (main *) $ ./ft_print_memory
00007ffe94496760: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
00007ffe94496770: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo
00007ffe94496780: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on 
00007ffe94496790: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.
00007ffe944967a0: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
00007ffe944967b0: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .

140731386259296
Repo Git : Practice42/Work/C/c02/ex12  (main *) $ ./ft_print_memory | cat -te
00007fffbc185f70: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin$
00007fffbc185f80: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo$
00007fffbc185f90: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on $
00007fffbc185fa0: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.$
00007fffbc185fb0: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..$
00007fffbc185fc0: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .$
$
140736349101936$
Repo Git : Practice42/Work/C/c02/ex12  (main *) $ 
```
# Explications

Voici une version détaillée des fonctions avec des explications sur les segments de code potentiellement complexes :

### Fonction `nib_to_hexchar`

```c
char nib_to_hexchar(int val) {
    char hex;
    if (val > 9)
        hex = val + 'a' - 10;  // Convertit les nombres 10-15 en 'a'-'f'
    else
        hex = val + '0';       // Convertit les nombres 0-9 en '0'-'9'
    return hex;
}
```
**Explications :**
- `val + 'a' - 10`: Ajoute la valeur ASCII de 'a' à `val` et soustrait 10 pour aligner 10 avec 'a'.
- `val + '0'`: Transforme le chiffre en son équivalent ASCII.

---

### Fonction `strprint_char_or_dot`

```c
void strprint_char_or_dot(char *str, int len) {
    int i;
    char c;
    i = 0;
    while (i < len) {
        c = str[i];
        if (c > 31 && c < 127)  // Vérifie si le caractère est imprimable
            write(1, &c, 1);
        else
            write(1, ".", 1);  // Remplace les caractères non imprimables par '.'
        i++;
    }
}
```
**Explications :**
- `if (c > 31 && c < 127)`: Vérifie si `c` est dans la plage des caractères ASCII imprimables.

---

### Fonction `print_hexstr`

```c
void print_hexstr(char *str, int len) {
    int i;
    char c1, c2;
    i = 0;
    while (i < 16) {
        if (!(i % 2))
            write(1, " ", 1);  // Ajoute un espace entre chaque paire d'hexadécimaux
        if (i < len) {
            c1 = nib_to_hexchar((str[i] >> 4) & 0xF);  // Premier nibble
            c2 = nib_to_hexchar(str[i] & 0xF);         // Deuxième nibble
            write(1, &c1, 1);
            write(1, &c2, 1);
        }
        else {
            write(1, "  ", 2);  // Imprime des espaces pour les données manquantes
        }
        i++;
    }
    write(1, " ", 1);  // Espace final après la chaîne hexadécimale
}
```
**Explications :**
- `(str[i] >> 4) & 0xF`: Décale les bits de 4 positions à droite et masque le reste pour obtenir le nibble haut.
- `str[i] & 0xF`: Masque tous sauf les 4 bits les plus bas pour obtenir le nibble bas.

---

### Fonction `print_hexaddr`

```c
void print_hexaddr(char *addr) {
    unsigned long long l_addr;
    int sz;
    char disp;
    sz = 16;
    l_addr = (unsigned long long)addr;
    while (--sz >= 0) {
        disp = nib_to_hexchar((l_addr >> (4 * sz)) & 0xF);  // Extrait chaque nibble
        write(1, &disp, 1);
    }
    write(1, ":", 1);
}
```
**Explications :**
- `(l_addr >> (4 * sz)) & 0xF`: Décale l'adresse pour isoler chaque nibble de gauche à droite.
- `sz` commence à 16 et décrémente pour générer chaque caractère hexadécimal.

---

### Fonction `ft_print_memory`

```c
void *ft_print_memory(void *addr, unsigned int size) {
    unsigned int i, k;
    int len;
    char *p_addr;
    p_addr = (char *)addr;
    k = 0;
    while (k < (1 + size / 16)) {
        i = 0;
        len = 0;
        while (i < 16) {
            if ((k * 16 + i) < size)
                len++;  // Compte le nombre de caractères valides dans le bloc
            i++;
        }
        print_hexaddr(p_addr + k * 16);  // Imprime l'adresse du bloc
        print_hexstr(p_addr + k * 16, len);  // Imprime la représentation hexadécimale
        strprint_char_or_dot(p_addr + k * 16, len);  // Imprime les caractères ou points
        write(1, "\n", 1);
        k++;
    }
    return addr;
}
```
**Explications :**
- `p_addr + k * 16`: Calcule l'adresse du bloc de 16 octets courant.
- `len`: Stocke le nombre de caractères valides dans le dernier bloc qui pourrait être moins de 16.
