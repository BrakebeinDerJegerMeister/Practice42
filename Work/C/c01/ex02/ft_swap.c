/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:04:11 by kaos              #+#    #+#             */
/*   Updated: 2024/06/30 16:40:42 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
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
	int	*a;
	int	*b;

	*a = 42;
	*b = 41;
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
	ft_swap(a, b);
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
}*/
