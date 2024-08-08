/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:53:46 by kaos              #+#    #+#             */
/*   Updated: 2024/06/30 11:18:30 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*int	nextnumber(int nb)
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
	int		loop;
	char	c;

	if (nb < 0)
	{
		nb = -nb;
		write(1, &(char){'-'}, 1);
	}
	nextnumber(nb);
}

int	main(void)
{
	int	n;

	ft_ft(&n);
	ft_putnbr(n);
	return (0);
}*/
