/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 07:10:35 by kaos              #+#    #+#             */
/*   Updated: 2024/06/27 11:25:21 by profchaos        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_combinaison(char i, char j, char k)
{
	char	s;
	char	e;

	s = ',';
	e = ' ';
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &k, 1);
	if ((i != '7') || (j != '8') || (k != '9'))
	{
		write(1, &s, 1);
		write(1, &e, 1);
	}
}

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			k = j + 1;
			while (k <= '9')
			{
				print_combinaison(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
