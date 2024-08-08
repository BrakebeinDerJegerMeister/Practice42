# ft_str_len

```C
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}
```

# ft_putchar

```C
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
```

# ft_putstr

```C
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
```

# ft_strcpy

```C
char	*ft_strcpy(char *dest, char *src)
{
	char	*save;

	save = dest;
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (save);
}
```
# ft_strncmp

```C
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
```
# ft_putnbr

```C
void	nextnumber(long int nb)
{
	char		disp;
	long int	next;

	next = nb % 10;
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
	disp = next + '0';
	write(1, &disp, 1);
}

void	ft_putnbr(int old_nb)
{
	long int	nb;

	nb = (long int)old_nb;
	if (nb < 0)
	{
		nb = -nb;
		write(1, &(char){'-'}, 1);
	}
	nextnumber(nb);
}
```

# ft_div_mod

```C
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a - *div * b;
}
```


# put_ulonglong_number

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
```

# put_ulonglong_number_to_hex
```C
void	put_ulonglong_number_to_hex(unsigned long long nb, int nbchars)
{
	char	disp;
	int		current;

	current = nb & 0xF;
	if (current > 9)
	{
		disp = current + 'a' - 10 ;
	}
	else
	{
		disp = current + '0';
	}
	nbchars--;
	if (nbchars)
		put_ulonglong_number_to_hex(nb >> 4, nbchars);
	write(1, &disp, 1);
}
```


