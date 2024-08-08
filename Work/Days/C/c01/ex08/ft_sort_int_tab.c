/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 09:03:29 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/01 09:33:15 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	ex;

	i = size;
	while (--i > 0)
	{
		if (tab[i] < tab[i - 1])
		{
			ex = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = ex;
			ft_sort_int_tab(tab, i + 1);
		}
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
	int	tab[5];

	tab[0] = 27;
	tab[1] = 0;
	tab[2] = 42;
	tab[3] = 43;
	tab[4] = -9;
	print_tab(tab, 5);
	ft_sort_int_tab(tab, 5);
	print_tab(tab, 5);
}*/
