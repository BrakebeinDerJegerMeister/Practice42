/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 07:10:35 by kaos              #+#    #+#             */
/*   Updated: 2024/06/27 07:28:33 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;
	char	s;
	char	e;

	i = '0';
	s = ',';
	e = ' ';
	while (i <= '7')
	{
		j = i+1;
		while (j <= '8')
		{
			k = j+1;
			while (k <= '9')
			{
				write(1, &i, 1);
				write(1, &j, 1);
				write(1, &k, 1);
				if ((i != '7') & (j != '8') & (k != '9'))
				{
					write(1, &s, 1);
					write(1, &e, 1);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	ft_print_comb();
	return 0;
}
