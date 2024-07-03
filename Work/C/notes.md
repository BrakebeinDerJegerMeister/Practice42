
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

# ft_putnbr

```C
void	put_positive_nbr(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		put_positive_nbr(nb);
	}
	write(1, &disp, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -nb;
		write(1, &(char){'-'}, 1);
	}
	put_positive_nbr(nb);
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

