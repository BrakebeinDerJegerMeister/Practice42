/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: profchaos <temp@temp.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:35:47 by profchaos         #+#    #+#             */
/*   Updated: 2024/07/14 13:29:24 by kaos             ###   ########.fr       */
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

void	put_positive_nbrbase(long nb, int ibase, char *base)
{
	long	current;

	current = nb % ibase;
	nb = (nb - current) / ibase;
	if (nb != 0)
	{
		put_positive_nbrbase(nb, ibase, base);
	}
	write(1, &base[current], 1);
}

int	check_base_error(char *base, int ibase)
{
	int	i;
	int	j;

	if (ibase == 0 || ibase == 1)
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		ibase;
	long	new_nbr;

	ibase = ft_strlen(base);
	new_nbr = nbr;
	if (check_base_error(base, ibase))
		return ;
	if (new_nbr < 0)
	{
		new_nbr = -new_nbr;
		write(1, &(char){'-'}, 1);
	}
	put_positive_nbrbase(new_nbr, ibase, base);
}

/*#include <stdio.h>

void	test(int nbr, char *base)
{
	printf("\nnbr : {%d}", nbr);
	printf("\nbase : {%s}\n", base);
	ft_putnbr_base(nbr, base);
	printf("\n");
}

int	main(void)
{	
	test(581499, "0123456789");
	test(581499, "0123456789ABCDEF");
	test(581499, "01");
	test(581499, "");
	test(581499, "coucou");
	test(-484529100, "poneyvif");
	test(-484529100, "foin");
	return (0);
}*/
