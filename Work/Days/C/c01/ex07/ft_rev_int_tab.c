/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:29:04 by kaos              #+#    #+#             */
/*   Updated: 2024/07/01 07:13:58 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	ex;

	i = size / 2;
	while (--i >= 0)
	{
		ex = tab[size - i - 1];
		tab[size - i - 1] = tab[i];
		tab[i] = ex;
	}
}

/*void	nextnumber(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
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
	nextnumber(nb);
}

void	print_tab(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		ft_putnbr(tab[i]);
		write(1, " ", 1);
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int	tab1[5];
	int	tab2[6];
	int	i;

	i = -1;
	while (++i < 5)
	{
		tab1[i] = (i + 1) * 2;
	}
	i = -1;
	while (++i < 6)
	{
		tab2[i] = (-3) * i;
	}
	print_tab(tab1, 5);
	ft_rev_int_tab(tab1, 5);
	print_tab(tab1, 5);
	print_tab(tab2, 6);
	ft_rev_int_tab(tab2, 6);
	print_tab(tab2, 6);
}*/
