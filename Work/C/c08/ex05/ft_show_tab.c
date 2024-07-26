/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:11:06 by kaos              #+#    #+#             */
/*   Updated: 2024/07/26 18:28:15 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

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

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		nextnumber(par[i].size);
		write(1, "\n", 1);
		par[i].copy[0] = 'Z';
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

/*#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	char		*cpy;
	t_stock_str	*stk;

	cpy = NULL;
	stk = (t_stock_str *)malloc(sizeof(t_stock_str) * (1 + ac));
	if (!stk)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stk[i].size = ft_strlen(av[i]);
		stk[i].str = av[i];
		free(cpy);
		stk[i].copy = malloc((stk[i].size + 1) * sizeof(char));
		if (!stk[i].copy)
			return (NULL);
		ft_strcpy(stk[i].copy, av[i]);
		i++;
	}
	stk[ac].str = 0;
	free(cpy);
	return (stk);
}

int	main(void)
{
	char		*av[] = {"Hello", "World", "Test", "Example"};
	t_stock_str	*stk;

	stk = ft_strs_to_tab(4, av);
	if (stk != NULL)
	{
		ft_show_tab(stk);
	}
	return (0);
}*/
