/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 16:51:51 by kaos              #+#    #+#             */
/*   Updated: 2024/06/30 19:46:21 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a / *b;
	mod = *a - div * *b;
	*a = div;
	*b = mod;
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
	*b = 8;
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
	ft_ultimate_div_mod(a, b);
	ft_putnbr2(*a);
	write(1, &"\n", 1);
	ft_putnbr2(*b);
	write(1, &"\n", 1);
}*/
