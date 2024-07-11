/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:35:47 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/11 16:24:03 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	put_positive_nbrbase(int nb, int ibase, char *base)
{
	int		current;

	current = nb % ibase;
	nb = (nb - current) / ibase;
	if (nb != 0)
	{
		put_positive_nbrbase(nb, ibase, base);
	}
	write(1, &base[current], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	ibase;
	int	i;

	i = 0;
	ibase = ft_strlen(base);
	if (ibase == 0 || ibase == 1)
		return;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return;
	}
	if (nbr< 0)
	{
		nbr = -nbr;
		write(1, &(char){'-'}, 1);
	}
	put_positive_nbrbase(nbr, ibase, base);
}

#include <stdio.h>

void	test(int nbr, char *base)
{
	printf("\nnbr : {%d}", nbr);
	printf("\nbase : {%s}\n", base);
	ft_putnbr_base(nbr, base);
	printf("\n");
}

int	main(void)
{	
	test(789456, "0123456789");
	test(5814, "01");
	test(484529100, "poneyvif");
	test(484529100, "foin");
	return (0);
}
