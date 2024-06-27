/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 07:10:35 by kaos              #+#    #+#             */
/*   Updated: 2024/06/27 22:19:37 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combinaison(char n2d, char n2u, char n1d, char n1u)
{
	char	s;
	char	e;

	s = ',';
	e = ' ';
	write(1, &n2d, 1);
	write(1, &n2u, 1);
	write(1, &e, 1);
	write(1, &n1d, 1);
	write(1, &n1u, 1);
	if ((n2d != '9') || (n2u != '8') || (n1d != '9') || (n1u != '9'))
	{
		write(1, &s, 1);
		write(1, &e, 1);
	}
}

void	compute(char n2d, char n2u, char n1d, char n1u)
{
	while ((n2d < '9') || (n2u <= '8'))
	{
		if (n2u > '9')
		{
			n2u = '0';
			n2d++;
		}
		n1d = n2d;
		n1u = n2u + 1;
		while ((n1d < '9') || (n1u <= '9'))
		{
			if (n1u > '9')
			{
				n1u = '0';
				n1d++;
			}
			print_combinaison(n2d, n2u, n1d, n1u);
			n1u++;
		}
		n2u++;
	}
}

void	ft_print_comb2(void)
{
	char	n2d;
	char	n2u;
	char	n1d;
	char	n1u;

	n2d = '0';
	n2u = '0';
	compute(n2d, n2u, n1d, n1u);
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
