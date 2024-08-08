/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 21:08:41 by kaos              #+#    #+#             */
/*   Updated: 2024/08/02 10:35:12 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	ft_strlen(char *str)
{
	int	nb;

	nb = 0;
	while (*str)
	{
		nb++;
		str++;
	}
	return (nb);
}

/*int	ft_putnbr2(int nb)
{
	char	disp;
	int		next;

	next = nb % 10;
	disp = next + '0';
	nb = (nb - next) / 10;
	if (nb != 0)
	{
		ft_putnbr2(nb);
	}
	write(1, &disp, 1);
}

int	main(void)
{
	ft_putnbr2(ft_strlen("Hello"));
	write(1, "\n", 1);
	ft_putnbr2(ft_strlen("42"));
	write(1, "\n", 1);
	return (0);
}*/
