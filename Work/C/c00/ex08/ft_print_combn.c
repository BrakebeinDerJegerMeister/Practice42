/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaos <temp@temp.com>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:25:39 by kaos              #+#    #+#             */
/*   Updated: 2024/06/30 01:22:21 by kaos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_max_number(char *comb, int nb)
{
	int	i;

	i = -1;
	while (++i < nb)
	{
		if (comb[i] != ('0' + 10 - nb + i))
		{
			return (0);
		}
	}
	return (1);
}

void	loop(char *numbers, int *limits, int rank, int stop)
{
	int	i;
	int	new_limits[2];

	i = limits[0] - 1;
	while (++i <= limits[1])
	{
		numbers[rank] = '0' + i;
		if (rank == stop)
		{
			write(1, numbers, stop);
			if (! is_max_number(numbers, stop))
			{
				write(1, ", ", 2);
			}
			return ;
		}
		new_limits[0] = i + 1;
		new_limits[1] = limits[1] + 1;
		loop(numbers, new_limits, rank + 1, stop);
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	positions[10];
	int		limits[2];

	i = -1;
	while (++i < n)
	{
		positions[i] = '0' + i;
	}
	positions[n - 1]--;
	limits[0] = 0;
	limits[1] = 10 - n;
	loop(positions, limits, 0, n);
}

/*int	main(void)
{
	ft_print_combn(3);
	write(1, "\n\n", 2);
	ft_print_combn(2);
	write(1, "\n\n", 2);
	ft_print_combn(5);
	write(1, "\n\n", 2);
	ft_print_combn(9);
	return (0);
}*/
