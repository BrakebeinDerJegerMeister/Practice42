/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:20:32 by profchaos         #+#    #+#             */
/*   Updated: 2024/08/02 11:06:18 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	nextnumber(long int nb)
{
	char		disp;
	long int	next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		nextnumber(nb);
	}
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

/*int	main(void)
{
	ft_putnbr(42);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(420);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(0);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(-4200);
	write(1, &(char){'\n'}, 1);
	ft_putnbr(-42);
	write(1, &(char){'\n'}, 1);
	return (0);
}*/
